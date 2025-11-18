#include<iostream>
using namespace std;

template<class flag>              //或者<typename flag>,声明下一个函数为函数模板
void MySwap_0(flag& a,flag& b){   //注意只对该声明以下的第一个函数有作用，若想定义多个函数模板，则需要分别声明
	flag tmp=a;
	a=b;
	b=tmp;
}

int main(){
	int a1=10;
	int b1=20;
	double a2=1.13;
	double b2=1.14;
	char a3='A';
	char b3='B';
	
	cout<<"a1:"<<a1<<"  b1:"<<b1<<endl;
	cout<<"a2:"<<a2<<"  b2:"<<b2<<endl;
	cout<<"a3:"<<a3<<"  b3:"<<b3<<endl;
	
	MySwap_0(a1,b1);                    //调用方式1：隐式自动类型推导
	MySwap_0<double>(a2,b2);            //调用方式2：显式指定类型调用
	MySwap_0<char>(a3,b3);
	
	cout<<"a1:"<<a1<<"  b1:"<<b1<<endl;
	cout<<"a2:"<<a2<<"  b2:"<<b2<<endl;
	cout<<"a3:"<<a3<<"  b3:"<<b3<<endl;
	
	return 0;
}