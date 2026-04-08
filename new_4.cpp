#include<iostream>
#include<string>
using namespace std;

template<class Type>
class storage
{
    public:
        Type v;
        string type;

        storage(Type v1)
        {
            this->v=v1;
            this->type="null";
        }
};

template<>
class storage<int>
{
    public:
        int v;
        string type;

        storage(int v1)
        {
            this->v=v1;
            this->type="int";
        }
};

template<>
class storage<float>
{
    public:
        float v;
        string type;

        storage(float v1)
        {
            this->v=v1;
            this->type="float";
        }
};

template<>
class storage<char>
{
    public:
        char v;
        string type;

        storage(char v1)
        {
            this->v=v1;
            this->type="char";
        }
};

void test()
{
    storage<int> i1(3);
    storage<float> f1(3.14);
    storage<char> c1('W');

    cout<<i1.v<<" "<<i1.type<<endl;
    cout<<f1.v<<" "<<f1.type<<endl;
    cout<<c1.v<<" "<<c1.type<<endl;
}

int main()
{
    test();

    return 0;
}