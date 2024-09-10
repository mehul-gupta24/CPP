// https://youtu.be/mlIUKyZIUUU?si=qSOW_XZru56xbTv7
#include <iostream>
using namespace std;

// class Student{
// public:
//   int *data ;
//   char *ch;
//   Student(int data,char cha){
//       *this->data=data;
//     // //   this->ch
//     //   *this->ch=new char(ch);
      
//       ch = new char;
//       *ch= cha;  
//   }
// };

//Inheritance - (properties that need to be inherit from parent class)
// parent/derived class
class Person{
    public:
    string name;
    int age;
    Person(string name,int age){
        this->age=age;
        this->name=name;
    }

};
//child/derived class ,Inherit
class Student : public Person{
    public:
    //name,age,roll no
    // so need to inherit the name and age from person class
    string roll_no;
    // Student(int val){
    //     this->roll_no=val;
    // }
    void get_info(){
        cout<<"Name : "<< this->name<<endl;
        cout<<"Age : "<< this->age<<endl;
        cout<<"Roll-no : "<< this->roll_no<<endl;
    }
};

int main() {
    // Student s_1(221,'o');
    // cout<<*(s_1.data)<<endl;
    // cout<<*(s_1.ch);
    Student s;
    s.name="Mehul";
    s.age=21;
    s.roll_no="ME22BT024";
    s.get_info();
    return 0;
}