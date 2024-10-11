#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void printlist(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(node* &tail, int data) {
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void deleteAtPosition(node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty, deletion not possible." << endl;
        return;
    }

    node* curr = head;
    node* pre = NULL;
    int count = 1;

    while (count < position && curr != NULL) {
        pre = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        cout << "Position exceeds the length of the list." << endl;
        return;
    }

    if (pre == NULL) {
        // Deleting the head node
        head = curr->next;
    } else {
        pre->next = curr->next;
    }

    curr->next = NULL;
    delete curr;
}

int main() {
    node* node1 = new node(1);
    node* tail = node1;
    node* head = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);

    cout << "Original List:" << endl;
    printlist(head);

    deleteAtPosition(head, 4);

    cout << "List after deleting node at position 4:" << endl;
    printlist(head);

    // Cleanup
    delete head;

    return 0;
}
