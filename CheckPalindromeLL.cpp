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
    temp->next - n;
}

//1. find middle using slow and fast pointer
//2. reverse
//3. comp

node* listReverse(node* head){
    node* dummy = NULL;

    while(head){
        node* nex = head->next;
        head->next = dummy;
        dummy = head;
        head = nex;
    }
    return dummy;
}

bool isPalindrome(node* head){
    if(head==NULL || head->next==NULL) return true;

    node* slow = head;
    node* fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = listReverse(slow->next);
    slow = slow->next;

    while(slow != NULL){
        if(head->data != slow->data)
            return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}

int main(){
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    // insert(head, 2);
    // insert(head, 2);
    // insert(head, 1);

    isPalindrome(head) ? cout<<"True" : cout<<"False";
    
    return 0;
}