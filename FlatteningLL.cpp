#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    node* bottom;
    int data;
    bool point = true;

    node(int val, bool pointer){
        data = val;
        next = NULL;
        bottom = NULL;
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

node* mergeLL(node* a, node* b){
    node* temp = new node(0);
    node* res  = temp;

    while(a && b){
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if(a) temp->bottom = a;
    else temp->bottom = b;
    return res->bottom;
}

node* flatten(node* root){
    if(!root || !root->next)
        return root;

    root->next = flatten(root->next);
    root = mergeLL(root, root->next);
    return root;
}

int main(){
    node* head = NULL;
    insert()
    return 0;
}