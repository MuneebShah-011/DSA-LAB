#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val), next(NULL){}
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList():head(NULL){}  // Constructor properly closed

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (!head){
            head=newNode;
        } 
        else{
            Node* temp = head;
            while (temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void displayFirstNode(){
        if (head){
            cout << "First Node: " << head->data << endl;
        } else {
            cout << "List is empty." << endl;
        }
    }

    void displayLastNode() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        cout<<"Last Node: "<<temp->data<<endl;
    }

    void displayNthNode(int n){
        Node* temp=head;
        int count = 1;
        while(temp && count < n){
            temp=temp->next;
            count++;
        }
        if (temp){
            cout<<"Node at position "<<n<<": "<<temp->data<<endl;
        } else {
            cout<<"Position out of bounds."<<endl;
        }
    }

    void displayCentreNode(){
        if (!head){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Centre Node: "<<slow->data<<endl;
    }
};

int main() {
    LinkedList n;
    n.insertAtEnd(10);
    n.insertAtEnd(20);
    n.insertAtEnd(30);
    n.insertAtEnd(40);
    n.insertAtEnd(50);

    n.displayFirstNode();
    n.displayLastNode();
    n.displayNthNode(3);
    n.displayCentreNode();

    return 0;
}
