#include<iostream>
using namespace std;
// Polymorphism - Constructor Overloading
class Student{
    public:
    int a;
    Student(){
        cout<<"non parameterized"<<endl;
    }
    Student(int val){
        this->a=val;
        cout<<"parameterized";
    }
};
int main2(){
    return 0;
}
int main(){
    Student s;
    Student s2(2);
    return 0;

}