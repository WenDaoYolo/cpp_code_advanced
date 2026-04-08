#include<iostream>
using namespace std;

template<class Flag>
void Print(Flag a)
{
	cout<<"I am template function"<<endl;
}

void Print(int a)
{
	cout<<"I am normal function"<<endl;
}

int main()
{
	Print(3);             //普通函数的优先级更高
	Print<>(3);           //强制调用函数模板
	Print<float>(3.14);   //强制调用函数模板
	Print(3.33);          //类型不匹配普通函数，匹配函数模板
	
	return 0;
}