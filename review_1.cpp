#include<iostream>

//函数模板
template<class T>
void MySwap(T& a,T& b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

//类模板
template<typename Flag>
class output
{
    public:
        Flag a;
        
        void display(){ std::cout<<a<<std::endl; }
};


void test1()
{
    int a=1,b=2;
    float c=1.1,d=2.2;
    char e='A',f='B';

    //显示调用
    MySwap<int>(a,b);
    //隐式调用
    MySwap(c,d);
    MySwap<char>(e,f);

    std::cout<<"a,b:"<<a<<" "<<b<<std::endl;
    std::cout<<"c,d:"<<c<<" "<<d<<std::endl;
    std::cout<<"e,f:"<<e<<" "<<f<<std::endl;
}

void test2()
{
    //类模板只能显示调用
    output<int> o1;
    output<char> o2;
    output<float> o3;
    o1.a=3;
    o2.a='B';
    o3.a=3.14;

    o1.display();
    o2.display();
    o3.display();
}

int main()
{
    test1();
    test2();

    return 0;
}