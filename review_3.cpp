#include<iostream>
#define DATA_LEN 10

template<class T>
void PrintArray(T* array,int len)
{
    for(int i=0;i<len;i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

template<>
void PrintArray<bool>(bool* array,int len)
{
    for(int i=0;i<len;i++)
    {
        if(array[i])
            std::cout<<"true ";
        else
            std::cout<<"false ";
    }
    std::cout<<std::endl;
}

void test()
{
    int a1[DATA_LEN]={1,2,3,4,5,6,7,8,9,10};
    char a2[DATA_LEN]={'A','B','C','D','E','F','G','H','I','J'};
    bool a3[DATA_LEN]={true,true,true,false,false,false,false,true,true,true};
    
    PrintArray<int>(a1,DATA_LEN);
    PrintArray<char>(a2,DATA_LEN);
    PrintArray<bool>(a3,DATA_LEN);
}

int main()
{
    test();

    return 0;
}