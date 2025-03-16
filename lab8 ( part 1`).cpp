#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val): data(val), next(NULL){}
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(): head(NULL){}

    void insertAtLast(int val){
        Node* newNode = new Node(val);
        if(!head) head = newNode;
        else{
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void mergeList(LinkedList& other){
        if(!head) head = other.head;
        else{
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = other.head;
        }
        other.head = NULL;
    }

    void displayList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList n1, n2;
    n1.insertAtLast(10);
    n1.insertAtLast(20);
    n1.insertAtLast(30);
    n2.insertAtLast(40);
    n2.insertAtLast(50);
    n2.insertAtLast(60);
    n1.mergeList(n2);
    n1.displayList();
    return 0;
}
