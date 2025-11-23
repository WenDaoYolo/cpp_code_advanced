#include<iostream>
#include<memory>
using namespace std;

/*
系统提供的unique_ptr的使用及其析构函数多态的实现
*/

class Parent{
    public:
        Parent(){
            cout<<"Parent()..."<<endl;
        }

        virtual ~Parent(){                 //定义虚析构函数
            cout<<"~Parent()..."<<endl;
        }
};

class Child:public Parent
{
    public:
        Child():Parent()
        {
            cout<<"Child()..."<<endl;
        }
        virtual ~Child(){
            cout<<"~Child()..."<<endl;
        }
};

void test(){
    unique_ptr<Parent> ptr(new Child);  //独占指针
    Parent* ptr2=new Child;             //普通指针
}

int main(){
    test();
    
    return 0;
}