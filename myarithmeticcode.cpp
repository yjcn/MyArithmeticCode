#include "myarithmeticcode.h"
//析构函数
MyArithmeticCode::~MyArithmeticCode()
{
}
//构造函数
MyArithmeticCode::MyArithmeticCode(const map<char,long double> pa)
{
    this->paa=pa;
    map<char,long double>::iterator it;
    double s=0;
    for(it=paa.begin();it!=paa.end();it++)
    {
        prr[it->first]=s;
        s+=it->second;
    }
}
string MyArithmeticCode::Code(const string &s)
{
    this->length=s.length(); //确定译码时输出序列长度
    string result;
    long double ss=0,pab=1;//初始化累积概率ss和序列符号概率
    int result_length;
    for(unsigned int i=0;i<s.length();i++)
    {
        char index=s[i];
        ss=ss+prr[index]*pab,pab=pab*paa[index];
    }
    //计算出要编码序列累积概率ss和序列符号概率pab
    result_length =int(-log(pab)/log(2))+1; //确定编码结果序列长度
    int *pint = new int [result_length];
    long double bh=ss,old=0;  //累积概率由十进制转换为二进制要用的的一些变量
    for(int i=0;i<result_length;i++)
    {
        if(bh*2>=1)
        {
            bh=2*bh-1;
            pint[i]=1;
        }
        else
        {
            bh=bh*2;
            pint[i]=0;
        }
    }
    //先将积累概率转换为二进制
    for(int i=0;i<result_length;i++)
    {
            old=old+pint[i]*pow(2,-(i+1));
    }
    if(old<ss)
    {
        old=old+pow(2,-result_length);
    }
    //判断是否需要进位，如果需要在累积概率(十进制)上加
    for(int i=0;i<result_length;i++)
    {
        if(old*2>=1)
        {
            old=2*old-1;
            result.append("1");
        }
        else
        {
            old=old*2;
            result.append("0");
        }
    }
    return result;
    delete [] pint;
    pint = NULL;
}
string MyArithmeticCode::Decode(const string &s)
{
    string result;
    long double number=0,range=0,rangelow=0;  //初始化译码过程中需要的变量
    for(unsigned int i=0;i<s.length();i++)
    {
        number=number+int(s[i]-'0')*pow(2,-(long double)(i+1));
    }
    //将01序列转换为累积概率
    for(int i=0;i<this->length;i++)
    {
        for(map<char,long double>::reverse_iterator it=this->prr.rbegin();it!=this->prr.rend();it++)
        {
            if(number>=it->second)
            {
                result.append(1,it->first);
                range=paa[it->first];
                rangelow=it->second;
                break;
            }
        }
        number=(number-rangelow)/range;
    }
    //使用累积概率按照相应公式实现译码
    return result;
}
