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

void insert(node* &head, int val){
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


//Naive Approach TC:O(k*n) & SC:O(1)
//for k number of times, take the last node , put it in front
node* solveBrute(node* head, int k){
    if(!head || !head->next)
        return head;

    for(int i=0; i<k; i++){
        node* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        node* last = temp->next;
        temp->next = NULL;
        last->next = head;
        head = last;
   }
   return head;

}


//Optimal Approach
//compute length of the LL
//last node->next = first node  O(N)
//point len-k node->next = NULL; O(N-(N%k))
node* solve(node* head, int k){
    if(!head || !head->next || k == 0) 
        return head;

    node* temp = head;
    int len = 1;
    while(temp->next){ 
        len++;
        temp = temp->next;
    }

    temp->next = head; //make loop
    k = k%len;
    k = len-k;

    while(k--){
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;

}

int main(){
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    display(head);

    int k = 4;
    node* ansNode = solveBrute(head, k);
    display(ansNode);

    return 0;
}



