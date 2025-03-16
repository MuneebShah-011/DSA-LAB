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

    void insertAtFirst(int val){
        Node* newNode = new Node(val);
        if(!head) head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtLast(int val){
        Node* newNode = new Node(val);
        if(!head) head = newNode;
        else{
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void insertAtNth(int n, int val){
        if(n == 1){
            insertAtFirst(val);
            return;
        }
        Node* temp = head;
        for(int i = 1; temp && i < n - 1; i++) temp = temp->next;
        if(!temp) return;
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
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(val);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    void displayInOrder(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList n;
    n.insertAtFirst(10);
    n.insertAtLast(20);
    n.insertAtLast(30);
    n.insertAtNth(2, 15);
    n.insertAtCentre(25);
    n.displayInOrder();
    return 0;
}
