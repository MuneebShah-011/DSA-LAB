#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtNth(int n, int val) {
        if (n == 1) {
            insertAtFirst(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < n - 1; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        if (!newNode->next) tail = newNode;
    }

    void insertAtCentre(int val) {
        if (!head) {
            insertAtFirst(val);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(val);
        newNode->next = slow->next;
        if (slow->next) slow->next->prev = newNode;
        slow->next = newNode;
        newNode->prev = slow;
        if (!newNode->next) tail = newNode;
    }

    void displayInOrder() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayInReverse() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList n;
    n.insertAtFirst(10);
    n.insertAtLast(20);
    n.insertAtLast(30);
    n.insertAtNth(2, 15);
    n.insertAtCentre(25);

    n.displayInOrder();
    n.displayInReverse();

    return 0;
}
