#include <iostream>
#include <vector>
using namespace std;

// Creating a Node
class Node {
    public:
    int data;
    Node* next;

    // Creating a constructor
    public:
    Node(int data1,Node* next1) {
        data = data;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert Array into LinkedList
Node* convertLL(vector<int> arr) {
    Node* head = new Node(arr[0]);

    Node* temp = head;

    // Store all elements in an array
    for(int i = 1;i < arr.size();i++) {
        Node* newNode = new Node(arr[i]);
        temp -> next = newNode;
        temp = temp->next;
    }
    return head;
}

// Traverse LinkeList
void traverse(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Delete Head
Node* deleteHead(Node* head) {

    if(head == NULL || head->next == nullptr) {
        return NULL;
    }

    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

// Delete Tail
void deleteTail(Node* head) {
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nullptr;
}

// Delete K value
void deleteK(Node* head,int k) {
    Node* temp = head;
    if(k == 1) {
        head = head -> next;
        delete temp;
        return;
    }
    int cnt = 0;
    Node* prev;
    
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Delete Based on Value
Node* deleteValue(Node* head,int value) {

    Node* prev;

    if(head->data == value) {
        
       Node* temp = head;
       head = head->next;
       delete temp;
       return head; 
    }

    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == value) {
            prev->next = prev->next->next;
            delete temp;
            return head;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {1,3,5,7,9};
    Node* head = convertLL(arr);
    traverse(head);
    deleteK(head,3);
    traverse(head);
    head = deleteValue(head,3);
    traverse(head);
}