// https://youtu.be/mlIUKyZIUUU?si=qSOW_XZru56xbTv7
#include <iostream>
using namespace std;

class Student{
public:
  int *data ;
  char *ch;
  Student(int data,char cha){
      *this->data=data;
    // //   this->ch
    //   *this->ch=new char(ch);
      
      ch = new char;
      *ch= cha;  
  }
};

//Inheritance
// parent/derived class
class A{
    
};
//child/derived class ,Inherit
class B{
    
};

int main() {
    Student s_1(221,'o');
    cout<<*(s_1.data)<<endl;
    cout<<*(s_1.ch);
    return 0;
}