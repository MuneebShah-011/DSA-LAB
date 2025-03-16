#include <iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val): data(val), next(NULL), prev(NULL){}
};

class DoublyLinkedList{
private:
    DNode* head;
public:
    DoublyLinkedList(): head(NULL){}

    void insertAtLast(int val){
        DNode* newNode = new DNode(val);
        if(!head) head = newNode;
        else{
            DNode* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void mergeList(DoublyLinkedList& other){
        if(!head) head = other.head;
        else{
            DNode* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = other.head;
            if(other.head) other.head->prev = temp;
        }
        other.head = NULL;
    }

    void displayList(){
        DNode* temp = head;
        while(temp){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    DoublyLinkedList n1, n2;
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
