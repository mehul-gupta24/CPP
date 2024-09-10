#include<iostream>
using namespace std;
// Static Keyword
        // Static variables - variables declared as static in a function are created and initialised once for the lifetime of the program //in function
                         // - Static variables in a class are created and initialised once . They are shared by all the objects of the class. //in Class
        // Static Objects - 


void fun(){
    static int x=0;
    cout<<"x : "<<x<<endl;
    x++;
}

class Parent{ 
public:
     int x;
    void set_x(){
        x=x+1;
    }
};
int main(){
    // fun();
    // fun();
    Parent p1;
    p1.x=100;
    p1.set_x();
    Parent p2;
    p2.x=200;
    p2.set_x();
    cout<<p1.x<<endl;
    cout<<p2.x<<endl;
    
}