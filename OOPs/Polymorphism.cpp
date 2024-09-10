#include<iostream>
using namespace std;
// Polymorphism - It is the ability of an Objects to take on different forms or behave in different ways depending on the context in which they are used.
// Polymorphism - Constructor Overloading

// 1) Compile Time Polymorphism - (decides at compile time) - example - 1) constructor overloading(means 2 constructor of same name but different parameterized constructor)
                                                                         //   2) Funciton overloading (means 2 or more functions of same name but different parameters - (that could be by changing the number of paramters or by changing the type of constructor,return type doesnt matter , it can be of same tyoe or of different type))

                                                                        //  3) Operator overloading - '+,-,*,/' any type of operator overloading

// 2) Run Time Polymorphism (Dynamic Polymorphism) - (decides at run time) - 1) Function Overriding - Parent and child both contain the same function with different implementation . The parent class is said to be overriden (child override kr leta h)
                                                  //  2) Virtual Functions - A virtual Function is a member function that you expect to be redefined in derived class - 1)Virtual functions are Dynamic in nature
                                                                //2)Define by the keyword "virtual" inside a base class and are always declared with a base class and overriden in a child class
                                                                //3)A virtual function is called during Runtime


// overloading is when 2 things are there in one class only
// but overriding is there in 2 different classes - (dimag me inheritance aa jana chahiye)

class Student{
    public:
    int a;
    // Student(){
    //     cout<<"non parameterized"<<endl;
    // }
    Student(int val){
        this->a=val;
        cout<<"parameterized"<<endl;
    }
    // this is constructor overloaidng - compile time polymorphism
    void showw(int x){
        cout<<x<<endl;
    }
    void showw(char ch){
        cout<<ch<<endl;
    }
    // function overloading
};

class Parent{
public:
    void get_info(){
        cout<<"Parent class"<<endl;
    }
    virtual void hello(){
        cout<<"Hello from parent"<<endl;
    }
    // virtual function i declared meaning that we want child class to re implement it
};
class Child : public Parent{
    public:
    void get_info(){
        cout<<"Child class"<<endl;
    }
    // function overriding
    void hello(){
        cout<<"Hello from child"<<endl;
    }
};
int main2(){
    return 0;
}
int main(){
    // Student s;
    // Student s1(2);
    // s1.showw(3);
    // s1.showw('4');

    // Child c1;
    // c1.get_info();
    // Parent p1;
    // p1.get_info();
    // // this is runtime polymorphism

    Parent p2;
    p2.hello();
    Child c2;
    c2.hello();
    return 0;

}