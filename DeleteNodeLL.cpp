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

node* getNode(node* head, int val){
    while(head->data != val){
        head = head->next;
    }
    return head;
}

//Dumb solution TC:O(1) & SC:O(1)
//1->4->2->3->NULL
//let's say you need to delete node 2
//we'll copy toDeleteNode->next to toDeleteNode
//1->4->3-/>3->NULL
//then point copied 3 to toDeleteNode->next->next
void deleteNode(node* n){
    n->data = n->next->data; //It is guaranteed that the node to be deleted is not a tail node in the list.
    n->next = n->next->next;
    return;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    insertAtTail(head, 9);
    display(head);

    node* t = getNode(head, 5);
    deleteNode(t);
    display(head);
    return 0;
}