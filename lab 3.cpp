#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL){}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL){}

    void insertAtStart(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        display();
    }

    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if (!head){
            head=newNode;
        } 
		else{
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        display();
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<" NULL "<<endl;
    }
};

int main(){
    LinkedList list;
    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtEnd(30);
    return 0;
}
