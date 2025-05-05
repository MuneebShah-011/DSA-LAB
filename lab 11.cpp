#include <iostream>
using namespace std;

class Array{
private:
    int front, rear;
    int arr[100];

public:
    Array(){
        front = 0;
        rear = -1;
    }

    void enqueue(int val){
        if (rear >= 99){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear]=val;
        cout<<val<<" "<<endl;
    }

    void dequeue(){
        if (front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front++]<<" "<<endl;
    }

    void display(){
        if (front>rear){
            cout<<"Queue is empty (Array)"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* front;
    Node* rear;

public:
    LinkedList(){
        front=rear=NULL;
    }

    void enqueue(int val){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=NULL;
        if (rear == NULL){
            front=rear=newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout<<val<<" "<<endl;
    }

    void dequeue(){
        if (front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        cout<<temp->data<<" "<<endl;
        front=front->next;
        if(front == NULL)
            rear=NULL;
        delete temp;
    }

    void display(){
        if (front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Array obj1;
    cout<<"Testing Queue with Array"<<endl;
    obj1.enqueue(10);
    obj1.enqueue(20);
    
    obj1.display();
    
    cout<<"Dequeuing...."<<endl;
    obj1.dequeue();
    cout<<"New queue: "<<endl;
    obj1.display();

    LinkedList obj2;
    cout << "\nTesting Queue with Linked List\n";
    obj2.enqueue(100);
    obj2.enqueue(200);
    
    obj2.display();
    
    cout<<"Dequeuing...."<<endl;
    obj2.dequeue();
    cout<<"New queue: "<<endl;
    
    obj2.display();

    return 0;
}

