#include<iostream>
using namespace std;

template<class Flag>
void PrintArray(Flag* arr)
{
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template<>
void PrintArray<bool>(bool* arr)
{   
    for(int i=0;i<10;i++)
    {
        if(arr[i]==true)
            cout<<"Õæ ";
        else
            cout<<"¼Ù ";
    }
    cout<<endl;
}

void test()
{
    int arr1[10]={1,2,3,4,5,6,7,8,9,10};
    char arr2[10]={'A','S','D','Q','W','E','Z','X','C','L'};
    bool arr3[10]={true,true,true,true,true,true,true,true,true,false};

    PrintArray<int>(arr1);
    PrintArray(arr2);
    PrintArray(arr3);
}

int main()
{
    test();

    return 0;
}