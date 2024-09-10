#include <iostream>
using namespace std;
// Abstraction - Hiding all unnecessary details and showing only the important parts
            // - by access modifier we make private 
            // abstract classes - abstract we have to use before class word - it is used to provide a base class from which other classes can be derived 
            // they cannot be instantiated (means objects cannot be crearted) and are meant to be inherited
            // Abstract classes are typically used to define an interface for derived classes
            // it is like a blueprint for its inherited class/derived class/child class
            // instance means object

class Shape{
    public:
    virtual void draw()=0;            // pure virtual function - whenever there is pure virtual function that class is abstract class
};
// cant make objects of abstract class Shape
class Circle : public Shape{
    public:
    void draw(){
        cout<<"circle is drawn"<<endl;
    }
};
int main(){
    Circle c1;
    c1.draw();
}