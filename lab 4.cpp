#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            int count = 1;
            while (temp && count < pos - 1) {
                temp = temp->next;
                count++;
            }

            if (!temp) {
                cout << "Position out of bounds!" << endl;
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
        display();
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtPosition(10, 1);
    list.insertAtPosition(30, 10); 
    return 0;
}
