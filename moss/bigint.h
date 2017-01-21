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
    Bigint() {}
    Bigint(std::string n);
    Bigint(const Bigint & rhs);
    Bigint & operator=(const Bigint & rhs);
    ~Bigint() {}
    std::string add(std::string & plus);
    std::string subtract(std::string & minus);
    std::string multiply(std::string & times);
    std::string divide(std::string & divisor);
    std::string get() const;
};

#endif
