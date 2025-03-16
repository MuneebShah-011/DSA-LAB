#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val): data(val), next(NULL){}
};

class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(): head(NULL){}

    void insertAtFirst(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            newNode->next = head;
        }
        else{
            Node* temp = head;
            while(temp->next != head) temp = temp->next;
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }

    void insertAtLast(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            newNode->next = head;
        }
        else{
            Node* temp = head;
            while(temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int n, int val){
        if(n == 1){
            insertAtFirst(val);
            return;
        }
        Node* temp = head;
        for(int i = 1; temp->next != head && i < n - 1; i++) temp = temp->next;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtCentre(int val){
        if(!head){
            insertAtFirst(val);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(val);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    void displayInOrder(){
        if(!head) return;
        Node* temp = head;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        }while(temp != head);
        cout << "HEAD" << endl;
    }

    void displayInReverse(Node* current){
        if(!current || current->next == head) return;
        displayInReverse(current->next);
        cout << current->data << " <- ";
    }

    void displayReverse(){
        if(!head) return;
        displayInReverse(head->next);
        cout << head->data << " <- HEAD" << endl;
    }
};

int main(){
    CircularLinkedList n;
    n.insertAtFirst(10);
    n.insertAtLast(20);
    n.insertAtLast(30);
    n.insertAtNth(2, 15);
    n.insertAtCentre(25);
    n.displayInOrder();
    n.displayReverse();
    return 0;
}
