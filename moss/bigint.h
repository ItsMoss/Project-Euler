#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <sstream>
#include <string>

class Bigint {
  private:
    std::string number;

    size_t max(std::string str1, std::string str2) const;
    void padZerosLeft(std::string & str, size_t length);
    int char2int(char digit);
    void removeExtraZeros(std::string & str1, std::string & str2);
    bool lessThan(std::string & str);
    void swap(std::string & str1, std::string & str2);
    void carryTheOne(std::string & str, size_t pos);

  public:
    Bigint();
    Bigint(std::string n);
    Bigint(const char * n);
    Bigint(int n);
    Bigint(const Bigint & rhs);
    Bigint & operator=(const Bigint & rhs);
    bool operator>(Bigint & rhs);
    bool operator>=(Bigint & rhs);
    bool operator<(Bigint & rhs);
    bool operator<=(Bigint & rhs);
    ~Bigint() {}
    std::string add(std::string plus);
    Bigint & operator+=(std::string plus);
    Bigint & operator+=(int plusi);
    std::string subtract(std::string minus);
    Bigint & operator-=(std::string minus);
    Bigint & operator-=(int minusi);
    std::string multiply(std::string times);
    Bigint & operator*=(std::string times);
    Bigint & operator*=(int timesi);
    std::string divide(std::string divisor);
    Bigint & operator/=(std::string divisor);
    Bigint & operator/=(int divisori);
    std::string pow(int exp);
    Bigint & sqrt();
    std::string operator%(std::string divisor);
    std::string operator%(int divisori);
    std::string get();
    std::string get() const;
   
};

#endif
