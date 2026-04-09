#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<list>
using namespace std;

char test1(int a,float b){cout<<"test1";return 'X';}

void test2()
{
	auto f2=[](int,float)->char{cout<<"f2";return 'Y';};
	auto f3=[](int,float)->char{cout<<"f3";return 'Z';};
	
	std::function<char(int,float)> task1;                   //创建char(int,float)签名类型的包装器task1
	std::function<char(int,float)> task2;                   //创建包装器task2
	std::function<char(int,float)> task3;                   //创建包装器task3
	
	task1=test1;                                            //用task1对函数进行包装
	task2=f2;                                               //用task2对lambda进行包装
	task3=f3;                                               //用task3对lambda进行包装
	
	task1=task2;                                            //类型相同可以赋值
	task2=task3;                                            //类型相同可以赋值
	function<char(int,float)> tasks[3]={task1,task2,task3}; //类型相同，存储到一个容器中
	
	tasks[0](1,1.2);                                        //调用容器中的任务(lambda表达式)
	tasks[1](2,2.2);
	tasks[2](3,3.2);

    queue<function<char(int,float)>> task_queue;
    task_queue.push(task1);
    task_queue.pop();
}

void test3()
{
    auto f1=[]{ cout<<"test"<<endl;};
    function<void()> task1=f1;

    task1=nullptr;
    if(!task1){ cout<<"\n非空!"<<endl; }
}

int main()
{
    auto f1=[]{cout<<"test1111"<<endl;};
    auto f2=[]{cout<<"test2222"<<endl;};
    function<void()> func1=f1;   //通过包装器包装(擦除类型)
    function<void()> func2=f2;   //通过包装器包装(擦除类型)
    f1();
    f2();

    func1=func2;                 //包装后类型相同
    func1();                     
    function<void()> array[10]={func1,func2};  //创建标签类型的包装器数组 
    test2();
    test3();

    return 0;
}