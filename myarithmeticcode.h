#ifndef MYARITHMETICCODE_H
#define MYARITHMETICCODE_H
#include <string>
#include <map>
#include <cmath>
using namespace std;
class MyArithmeticCode
{
public:
    MyArithmeticCode(const map<char,long double> paa);
    ~MyArithmeticCode();
    string Code(const string & s);
    string Decode(const string & s);
private:
    int length; //编码学号或姓名长度，译码时需要用到
    map<char,long double> prr; //存放各个符号累积概率 自动按符号ASCII码大小排序
    map<char,long double> paa; //存放各个符号符号概率
};

#endif // MYARITHMETICCODE_H
