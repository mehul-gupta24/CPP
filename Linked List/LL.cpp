#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
    Node* createLL(int val){
        Node*head=new Node(val);
    }
    void add(int val){
        if(val==-1){
            return;
        }
        Node*head=new Node(val);
        // head->next=createLL();
    }
};
int main(){
    // Node* head(5);
    // Node* head(5);
}