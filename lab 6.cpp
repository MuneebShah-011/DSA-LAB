#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL){}
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() : head(NULL){}

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = newNode;
        } 
        else{
            Node* temp=head;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteFirstNode(){
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLastNode() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;  // Fixed here
        temp->next = NULL;
    }

    void deleteNthNode(int n){
        if (!head) return;
        if (n == 1) {
            deleteFirstNode();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < n - 1; i++){
            temp = temp->next;
        }
        if (!temp || !temp->next)
            return;
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void deleteCentreNode(){
        if (!head) return;
        if (!head->next){
            delete head;
            head = NULL;
            return;
        }
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }

    void displayList(){
        Node* temp = head;
        while (temp) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    }
};

int main(){
    LinkedList n;
    n.insertAtEnd(10);
    n.insertAtEnd(20);
    n.insertAtEnd(30);
    n.insertAtEnd(40);
    n.insertAtEnd(50);

    n.displayList();

    n.deleteFirstNode();
    n.displayList();

    n.deleteLastNode();
    n.displayList();

    n.deleteNthNode(2);
    n.displayList();

    n.deleteCentreNode();
    n.displayList();

    return 0;
}

