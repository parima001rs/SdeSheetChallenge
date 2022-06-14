#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    int data;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(!head){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void deleteNode(node* n){
    node* temp = n->next;
    *n = temp;
    delete temp;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    insertAtTail(head, 9);
    display(head);

    deleteNode(5);
    display(head);
    return 0;
}