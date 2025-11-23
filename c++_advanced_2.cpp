/*
  review:普通编程的方式实现自定义unique_ptr以及析构的多态
*/

#include<iostream>
#include<memory>
#include<cstring>

class test{
  public:
    char* name;
    test(){
      this->name=new char[10];
      memset(this->name,0,10);

      strcpy(this->name,"Default");
      std::cout<<"test()..."<<std::endl;
    }

    void Display(){
      std::cout<<"Name:"<<this->name<<std::endl;
    }

    virtual ~test(){
      if(this->name!=NULL)
        delete this->name;
      std::cout<<"~test()..."<<std::endl;
    }
};

class test_c:public test
{
  public:
    test_c():test()
    {
      memset(this->name,0,10);
      strcpy(this->name,"JACK");
      std::cout<<"test_c()..."<<std::endl;
    }

    virtual ~test_c(){
      std::cout<<"~test_c()..."<<std::endl;
    }
};

class MyUnique_ptr{
  public:
    test* ptr;
  MyUnique_ptr(test* ptr)
  {
    this->ptr=ptr;
    std::cout<<"MyUnique()..."<<std::endl;
  }

  ~MyUnique_ptr(){
    if(this->ptr!=NULL)
    {
      delete this->ptr;       //heap memory的析构顺序取决于delete的时机，构造同理
      std::cout<<"~MyUnique_ptr()..."<<std::endl;
    }
  }
};

void test1(){
  std::cout<<"normal heap t1:"<<std::endl;
  test* t1=new test;
  t1->Display();

  std::cout<<"normal stack t2:"<<std::endl;
  test t2;
  t2.Display();

  std::cout<<"---------------------"<<std::endl;
  std::cout<<"myunique_ptr heap t3:"<<std::endl;
  MyUnique_ptr t3=(new test);
  t3.ptr->Display();
  (*t3.ptr).Display();

  std::cout<<"---------------------"<<std::endl;
  std::cout<<"myunique_ptr_child heap t4:"<<std::endl;
  MyUnique_ptr t4=(new test_c);

  (*t4.ptr).Display();         //若子类无新增的内容需要输出，则可以直接通过父类方法输出原有的name
  t4.ptr->Display();           
}

int main(){
    test1();
        

    return 0;
}