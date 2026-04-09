#include<iostream>
#include<condition_variable>
#include<mutex>
using namespace std;

class t{
    public:
        mutex mtx;
        condition_variable cv;
        
        bool Get(){return true;}

        void cvwait()
        {
            unique_lock<mutex> ul(mtx);
            //wait方法第二个参数是可调用对象
            //捕获所有变量，例如this指针变量
            cv.wait(ul,[&]{return !this->Get();});
            //捕获当前类的this指针变量
            cv.wait(ul,[this]{return !this->Get();});
        }
};

void test1()
{
	int a=20,b=30,c=50;

	{
        //无参数、无捕获、无返回
		[]{cout<<"hello"<<endl;}();                   
	}
	
	{
        //有参数、值捕获、有返回(手动指定，也可省略自动推导)、定义并调用
        [a](int w)->int{cout<<a<<endl;return a;}(3);
        //无参数、引用捕获、无返回、定义并调用       
        [&a]{a++;cout<<a<<endl;}();
	}

    {
        //无参数、全值捕获、无返回，定义并存储
        auto f1=[=]{cout<<a<<b<<c<<endl;};
        //无参数、全引用捕获、无返回、定义并存储
        auto f2=[&]{a++,b++,c++;cout<<a<<b<<c<<endl;};
        //调用闭包
        f1();
        f2();
    }
}

int main()
{
    test1();
    return 0;
}