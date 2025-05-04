#include <iostream>
using namespace std;

class Array{
private:
    int max;
    int arr[100];

public:
    Array(){ max = -1;}

    void push(int val){
        if (max >= 99){
            cout<<"Stack is full!!!"<<endl;
            return;
        }
        arr[++max]=val;
        cout<<val<<" pushed to stack \n";
    }

    void pop() {
        if (max == -1) {
            cout << "Error!!!\n";
            return;
        }
        cout << arr[max] << " popped from stack "<<endl;
        max--;
    }

    void display() {
        if (max == -1) {
            cout << "Stack is empty "<<endl;
            return;
        }
        cout << "Stack: ";
        for (int i = max; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* max;

public:
    LinkedList(){max = NULL; }

    void push(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = max;
        max = newNode;
        cout << val << " pushed to stack"<<endl;
    }

    void pop(){
        if (max == NULL){
            cout << "Error!!!"<<endl;
            return;
        }
        Node* temp = max;
        cout << temp->data << " popped from stack "<<endl;
        max = max->next;
        delete temp;
    }

    void display(){
        if (max == NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Stack ";
        Node* temp = max;
        while(temp != NULL){
            cout<<temp->data << " ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Array obj1;
    cout << "Testing Stack with Array"<<endl;
    obj1.push(10);
    obj1.push(20);
    cout<<endl;
    obj1.display();
    obj1.pop();
    obj1.display();
    obj1.pop();
    obj1.display();

    LinkedList obj2;
    cout<< "\n Testing Stack with Linked List"<<endl;
    obj2.push(40);
    obj2.push(50);
    cout<<endl;
    obj2.display();
    obj2.pop();
    obj2.display();
    obj2.pop();
    obj2.display();

    return 0;
}
