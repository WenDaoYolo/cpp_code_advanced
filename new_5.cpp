#include<iostream>
using namespace std;

int test()
{
    return 666;
}

class tt{
    public: 
        int Get()
        {
            cout<<"ok"<<endl;
            return 33;
        }
};

tt t1;

int k;

void tes2t()
{
    int s;
    {
        [s]{return s;};
    }
}

int main()
{
    
    
    int w=333;
    auto f=[&w](){w++;};      //[]只能捕获非静态区的变量->外部变量?
    f();                      //无参()可有可无
                              //每个匿名函数有独特的类型，只能用auto推导再存储
    f();                   
    cout<<w;                  
    []{t1.Get();};

    int a=[=]()->int{return 133;}(); //->可省略:于指定返回类型，通常也会自动类型推导
    cout<<" "<<a<<endl;

    int cc=200;
    [cc]()mutable{cc++;cout<<cc;}();

    return 0;
}