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

void createCycle(node* &head,int pos) {
    node* ptr = head;
    node* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

node* solve(node* head){
    node* slow = head;
    node* fast = head;
    node* entry = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main(){
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 6);
    createCycle(head,2);//creating cycle in the list

    node* ansNode = solve(head);
    if(ansNode == NULL) cout<<"No Cycle";
    else{
        node* temp = head;
        int pos = 0;
        while(temp != ansNode){
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos: "<<pos<<endl;
    }
    return 0;
}