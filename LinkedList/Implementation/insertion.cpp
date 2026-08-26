#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int dataa,Node* nextt) {
        data = dataa;
        next = nextt;
    }

    Node(int dataa) {
        data = dataa;
        next = nullptr;
    }

};

Node* convertLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1;i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void traverse(Node* head) {
    Node* temp = head;

    while(temp) {
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

// insert at beginning
Node* insertAtBegin(Node* head,int value) {
    return new Node(value,head);
}

// insert at end
Node* insertAtEnd(Node* head,int value) {
    Node* temp = head;

    while(temp->next != nullptr) {
        temp = temp -> next;
    }
    Node* newNode = new Node(value);
    temp->next = newNode;
    return head;
}

// insert at position
Node* insertAtPosition(Node* head,int pos,int value) {
    if (pos == 1) {
        Node* newHead = new Node(value,head);
        return newHead;
    }

    Node* temp = head;
    Node* prev;

    int cnt = 0;

    while(temp) {
        cnt++;

        if(cnt == pos) {
            Node* newNode = new Node(value,prev->next);
            prev->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

// insert based on value
Node* insertAtValue(Node* head,int value,int data) {
    if(head->data == value) {
        return new Node(data,head);
    }

    Node* temp = head;
    Node* prev;

    while(temp) {
        if(temp->data == value) {
            Node* newNode = new Node(data,prev->next);
            prev->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {2,5};
    Node* head = convertLL(arr);
    traverse(head);
    head = insertAtBegin(head,1);
    traverse(head);
    head = insertAtEnd(head,6);
    traverse(head);
    head = insertAtPosition(head,3,10);
    traverse(head);
    head = insertAtValue(head,10,20);
    traverse(head);
}