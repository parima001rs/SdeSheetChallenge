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
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

//TC:O(n1 + n2) & SC:O(n1 + n2)
node* solve(node* &head1, node* &head2){
    node* d1 = head1;
    node* d2 = head2;
    node* res = new node(-1);
    node* temp = res;

    while(d1 && d2 ){
        if(d1->data < d2->data){
            temp->next = d1;
            d1 = d1->next;
        }
        else{
            temp->next = d2;
            d2 = d2->next;
        }
        temp = temp->next;
    }
    return res->next;
}

//In-place TC:O(n1 + n2) & SC:O(1)
node* solveOptimal(node* &head1, node* &head2){
    if(!head1) return head2;
    if(!head2) return head1;

    node* d1 = head1;
    node* d2 = head2;

    if(d1->data > d2->data) swap(d1, d2);
    node* res = d1;

    while(d1 && d2){
        node* temp = NULL;
        while(d1 != NULL && d1->data <= d2->data){
            temp = d1;
            d1 = d1->next;
        }
        temp->next = d2;
        swap(d1, d2);
    }
    return res;
}

int main(){
    node* head1 = NULL;
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);

    node* head2 = NULL;
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 8);
    insertAtTail(head2, 10);

    display(head1);
    display(head2);

    node* newHead = solveOptimal(head1, head2);
    display(newHead);
    return 0;
}