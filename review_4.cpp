#include<iostream>
#include<string>

template<class T>
class container
{
    public:
        T data;
        std::string data_type;

        container(T d):data(d) { data_type="unknown"; }
        void disinfo(){ std::cout<<data<<":"<<data_type<<std::endl; }
};

template<>
class container<int>
{
    public:
        int data;
        std::string data_type;

        container(int d):data(d) { data_type="integer"; }
        void disinfo(){ std::cout<<data<<":"<<data_type<<std::endl; }
};

template<>
class container<char>
{
    public:
        char data;
        std::string data_type;

        container(char d):data(d) { data_type="character"; }
        void disinfo(){ std::cout<<data<<":"<<data_type<<std::endl; }
};

template<>
class container<float>
{
    public:
        float data;
        std::string data_type;

        container(float d):data(d) { data_type="float"; }
        void disinfo(){ std::cout<<data<<":"<<data_type<<std::endl; }
};

void test()
{
    container<int> c1(3);
    container<char> c2('A');
    container<float> c3(3.14);

    c1.disinfo();
    c2.disinfo();
    c3.disinfo();
}

int main()
{
    test();

    return 0;
}