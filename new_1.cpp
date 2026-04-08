#include<iostream>
using namespace std;

template<class a>
class test
{
    public:
        a a1;
    
        a print(a tmp)
        {
            a tmp2=tmp+1;
            cout<<tmp2<<endl;
            return tmp2;
        }

        void test2();
};

template<class a>
void test<a>::test2()
{
    
}

template<>
class test<float>
{
    public:
    void print(float a)
    {
        cout<<"floatÌØ»¯Àà:"<<a<<endl;
    }

    
};

template<class s>
void test1()
{
    cout<<"normal"<<endl;
}

template<>
void test1<int>()
{

}

int main()
{
    test<int> s1;
    test<float> s2;
	s1.print(4);
    s2.print(3.14);
	return 0;
}