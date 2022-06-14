#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){ //by reference
    node* n = new node(val);
    if(!head){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){ //by value
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node* head, int key){
    if(head == NULL) {
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != key){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

//Iterative TC:O(N) & SC:O(1) where n is number of nodes
node* reverseLL(node* &head){
    node* dummy = NULL;
    while(head != NULL) {
        node* next = head->next;
        head->next = dummy;

        dummy = head;
        head = next;
    }
    return dummy;
}

//Recursive TC:O(N) & SC:O(1)
node* reverseRecursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);

    node* newHead = reverseRecursive(head);
    display(newHead);

    return 0;
}