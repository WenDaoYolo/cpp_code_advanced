#include<iostream>
#include<functional>
using namespace std;

struct task1
{
    int(*fun_ptr)(int,int);
    int num1,num2;
};

int add(int a,int b){ return a+b; }

void test()
{
    int x=100,y=200;
    task1 t1={add,x,y};                    //存储函数指针和参数
    int res1=t1.fun_ptr(t1.num1,t1.num2);  //回调的方式调用加法任务
    cout<<"task1:"<<res1<<endl;

    auto task2=[x,y]{return add(x,y);};     //lambda表达式创建闭包
    int res2=task2();                       //直接调用闭包
    cout<<"task2:"<<res2<<endl;
}

void test2()
{
    auto f1=[](int,char)->int{return 666;};
    auto f2=[](int,char)->int{return 777;};
    char(*fun_ptr)(int,float)=[](int,float){return 'W';};
    [](auto a1,auto a2){cout<<"yes!"<<endl;}(3.14,'x');
}

int main()
{
    test();
    return 0;
}