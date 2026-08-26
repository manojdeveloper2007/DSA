#include <iostream>
using namespace std;

// Creating a Node
class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Covert Array into LinkedList
Node* convertLL(int arr[5]) {
    Node* head = new Node(arr[0]);

    Node* temp = head;

    for(int i = 1;i < 5;i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// Traverse a LinkedList
void traverseLL(Node* head) {
    Node* temp = head;

    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
}

// Search Element
Node* search(Node* head,int target) {
    Node* temp = head;

    while(temp) {
        if(temp->data == target) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    Node* head = convertLL(arr);
    traverseLL(head);
    cout<<endl;
    
    Node* node = search(head,3);
    cout<<node<<endl;
    cout<<node->data<<endl;
}