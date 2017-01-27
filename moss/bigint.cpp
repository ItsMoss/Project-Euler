#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "bigint.h"

size_t Bigint::max(std::string str1, std::string str2) const {
  if (str1.length() > str2.length()) return str1.length();
  return str2.length();
}

void Bigint::padZerosLeft(std::string & str, size_t length) {
  if (str.length() < length) {
    std::stringstream sstrm;
    for (size_t i = 0; i < length - str.length(); i++) {
      sstrm << '0';
    }
    std::string zeros = sstrm.str();
    str = zeros + str;
  }
}

int Bigint::char2int(char digit) {
  return digit - '0';
}

void Bigint::removeExtraZeros(std::string & str1, std::string & str2) {
  while (str1.length() > 1 && str1[0] == '0') {
    str1.erase(str1.begin());
  }
  while (str2.length() > 1 && str2[0] == '0') {
    str2.erase(str2.begin());
  }
}

bool Bigint::lessThan(std::string & str) {
  if (number.length() > str.length()) return false;
  if (number.length() < str.length()) return true;
  for (size_t i = 0; i < number.length(); i++) {
    if (number[i] > str[i]) return false;
    if (number[i] < str[i]) return true;
  }
  return false;
}

void Bigint::swap(std::string & str1, std::string & str2) {
  std::string temp = str1;
  str1 = str2;
  str2 = temp;
}

void Bigint::carryTheOne(std::string & str, size_t pos) {
  if (str[pos-1] == '0') carryTheOne(str, pos-1);
  str[pos-1]--;
  if (str[pos-1] - '0' < 0) str[pos-1] += 10;
}

Bigint::Bigint() : number(std::string("0")) {}

Bigint::Bigint(std::string n) : number(n) {}

Bigint::Bigint(const Bigint & rhs) {
  number = rhs.number;
}

Bigint & Bigint::operator=(const Bigint & rhs) {
  if (this == &rhs) return *this;
  number = rhs.number;
  return *this;
}

std::string Bigint::add(std::string plus) {
  removeExtraZeros(number, plus);
  size_t len = max(number, plus);
  padZerosLeft(number, len);
  padZerosLeft(plus, len);
  int remainder = 0;
  std::stringstream sstrm;
  for (size_t i = len; i > 0; i--) {
    int sum = char2int(number[i-1]) + char2int(plus[i-1]) + remainder;
    if (sum > 9) remainder = 1;
    else remainder = 0;
    sstrm << sum % 10;
  }
  if (remainder) sstrm << remainder;
  std::string ans = sstrm.str();
  std::reverse(ans.begin(), ans.end());
  number = ans;
  return number;
}

std::string Bigint::subtract(std::string minus) {
  removeExtraZeros(number, minus);
  size_t len = max(number, minus);
  padZerosLeft(number, len);
  padZerosLeft(minus, len);
  std::stringstream sstrm;
  bool negate = false;
  if (lessThan(minus)) {
    swap(number, minus);
    negate = true;
  }
  for (size_t i = len; i > 0; i--) {
    int diff = char2int(number[i-1]) - char2int(minus[i-1]);
    if (diff < 0) {
      diff += 10;
      carryTheOne(number, i-1);
    }
    sstrm << diff;
  }
  if (negate) sstrm << '-';
  std::string ans = sstrm.str();
  std::reverse(ans.begin(), ans.end());
  number = ans;
  return number;
}

std::string Bigint::multiply(std::string times) {
  removeExtraZeros(number, times);
  // determine whether number or times is larger
  if (lessThan(times)) swap(number, times);
  // swap number and times if times is larger
  // create a vector of stringstreams with same length as number
  std::vector<std::string> products;
  // double for loop where outer is times length, inner is number length
  for (size_t i = times.length(); i > 0; i--) {
    // init remainder to 0
    int remainder = 0;
    std::stringstream strm;
    std::string zeros = std::string(times.length()-i, '0');
    strm << zeros;
    for (size_t j = number.length(); j > 0; j--) {
    // product = number[len-j] * times[len-i] + remainder
      int product = char2int(number[j-1]) * char2int(times[i-1]) + remainder;
    // remainder = product / 10
      remainder = product / 10;
    // vector[i] << product % 10
      strm << product % 10;
    }
    strm << remainder;
    std::string str = strm.str();
    std::reverse(str.begin(), str.end());
    products.push_back(str);
  }
  // set number to vector[0]
  number = products[0];
  // loop through rest of vector and do add(vector[i])
  for (size_t k = 1; k < products.size(); k++) {
    add(products[k]);
  }
  return number;
}

std::string Bigint::divide(std::string divisor) {
  if (lessThan(divisor)) {
    number = std::string("0");
    return number;
  }
  Bigint multiple = Bigint(divisor);
  int ans = 0;
  std::string m = multiple.get();
  while (!lessThan(m)) {
    multiple.add(divisor);
    ans++;
    m = multiple.get();
  }
  std::stringstream strm;
  strm << ans;
  number = strm.str();
  return number;
}

std::string Bigint::pow(int exp) {
  std::string n = number;
  if (exp > 0) {
    for (int i = 1; i < exp; i++) multiply(n);
  }
  else if (exp == 0) number = std::string("1");
  else {
    number = std::string("0");
  }

  return number;
}

std::string Bigint::get() const {
  return number;
}
