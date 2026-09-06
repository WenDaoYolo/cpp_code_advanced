#include<iostream>

//函数模板
template<class T1,class T2>
void TypeInfo(T1 a,T2 b,T2 c)
{
    std::cout<<a<<" "<<b<<" "<<c<<std::endl;
}

//函数模板的全特化:指定类型(T1为bool,T2为float)
template<>
void TypeInfo<bool,float>(bool a,float b,float c)
{
    if(a)
        std::cout<<"true ";
    else
        std::cout<<"false ";

    std::cout<<b<<" "<<c<<std::endl;
}

//类模板
template<class B1,class B2>
class Type
{
    public:
        B1 data1;
        B2 data2;
        Type(B1 d1,B2 d2);
};

//类外实现方法
template<class B1,class B2>
Type<B1,B2>::Type(B1 d1,B2 d2):data1(d1),data2(d2)
{
    std::cout<<"normal class"<<std::endl;
}

//类模板的偏特化：指定类型(B1为bool，B2保持泛型)
template<class TTT>
class Type<bool,TTT>
{
    public:
        bool data1;
        TTT data2;

        Type(bool d1,TTT d2):data1(d1),data2(d2)
        {
            std::cout<<"unnormal class"<<std::endl;
        }
};

//类模板的偏特化：类型相同(B1和B2的类型相同时)
template<class SSS>
class Type<SSS,SSS>
{
    public:
        SSS data1;
        SSS data2;

        Type(SSS d1,SSS d2):data1(d1),data2(d2)
        {
            std::cout<<"unnormal class(type same)"<<std::endl;
        }
};

void test1()
{
    TypeInfo<char,float>('A',3.14,4.13);
    TypeInfo<bool,float>(true,3.14,4.13);
}

void test2()
{
    Type<char,int> t1('A',4);
    Type<bool,int> t2(true,4);
    Type<float,float> t3(3.14,3.14);
}

int main()
{
    test1();
    test2();

    return 0;
}