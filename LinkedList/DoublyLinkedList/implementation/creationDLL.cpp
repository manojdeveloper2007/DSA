#include <iostream>
#include <vector>
using namespace std;

// Implemenation of Doubly LinkedList

class Node {
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int dataa) {
        data = dataa;
        prev = nullptr;
        next = nullptr;
    }

    Node(int dataa,Node* prevv,Node* nextt) {
        data = dataa;
        prev = prevv;
        next = nextt;
    }
};

Node* convertDLL(vector<int> &arr) {
    // head
    Node* head = new Node(arr[0]);
    head->prev = nullptr;

    // temp
    Node* temp = head;

    // loop
    for(int i = 1;i < arr.size();i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp -> next;
    }

    return head;
}

// Traverse
void traverse(Node* head) {
    Node* temp = head;

    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Delete Head
Node* deleteAtBegin(Node* head) {
    Node* temp = head;
    head = temp->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

// delete End
Node* deleteAtEnd(Node* head) {
    Node* temp = head;

    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}

// delete a Position
Node* deleteByPosition(Node* head,int pos) {
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prevv;
    int cnt = 0;

    while(temp) {
        cnt++;
        if (cnt == pos) {
            prevv->next = temp->next;
            temp->next->prev = prevv;
            return head;
        }
        prevv = temp;
        temp = temp->next;
    }
}

// Delete by Value
Node* deleteByValue(Node* head,int value) {
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev;

    while(temp) {
        if(temp->data == value) {
            prev->next = temp->next;
            temp->next->prev = prev;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Insert at Beginning
Node* insertAtBegin(Node* head,int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    temp->prev = newNode;
    newNode->next = temp;
    newNode->prev = nullptr;
    return newNode;
}

// Insert at End
Node* insertAtEnd(Node* head,int value) {
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nullptr;
    return head;
}

// Insert Based on Value
Node* insertAtPosition(Node* head,int pos,int value) {
    if (pos == 1) {
        Node* newNode = new Node(value);
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    Node* prev;
    int cnt = 0;
    Node* newNode = new Node(value);
    while(temp) {
        cnt++;
        if(cnt == pos) {
            newNode->prev = prev;
            newNode->next = temp;

            prev->next = newNode;
            temp->prev = newNode;

            return head;
        }
        prev = temp;
        temp = temp -> next;
    }
}

// Insert Based on Value
Node* insertByValue(Node* head,int value,int data) {
    if(head->data == value) {
        Node* newNode = new Node(data);
        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    Node* prev;

    while(temp) {
        if(temp->data == value) {
            Node* newNode = new Node(data);
            newNode->prev = prev;
            newNode->next = temp;
            prev->next = newNode;
            temp->prev = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertDLL(arr);
    traverse(head);
    head = insertAtEnd(head,6);
    traverse(head);
    head = insertAtPosition(head,3,10);
    traverse(head);
    head = insertByValue(head,10,20);
    traverse(head);
    head = deleteByValue(head,10);
    traverse(head);
    head = deleteByValue(head,1);
    traverse(head);
    head = insertAtPosition(head,1,0);
    traverse(head);
}