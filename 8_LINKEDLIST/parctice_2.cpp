#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

// Insert at head
void insertAtHead(node *&head, int data) {
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// Insert at tail
void insertAtTail(node *&tail, int data) {
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

// Print linked list
void print(node *&head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node *node1 = new node(0);
    node *head = node1;
    node *tail = node1;

    
    for (int i = 1; i <= 9; i++) {
        insertAtTail(tail, i);
    }

    print(head);

    node* add = head;
    print(add);
    node* temp = new node(-1);

    while(add != NULL && add->next != NULL){
        temp->next = add;
        add = add->next->next;
    }
    print(add);
    print(temp);
    return 0;
}
