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
    while(temp->next){ //remember temp->next
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){;
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

//bruteforce TC:O(N + N) & SC:O(1)
node* solve(node* &head, int n){
    node* temp = head;
    int count = 0;

    while(temp){
        count++;
        temp = temp->next;
    }
    if(n == count){  //base case if you need to delete first ele
        node* n = head;
        head = head->next;
        delete n;
    }

    temp = head;
    for(int i=1; i<count-n; i++){
        temp = temp->next;
    }
    node* nextToN = temp->next->next;
    delete temp->next;
    temp->next = nextToN;
    return head;
}

//Optimal TC:O(N) & SC:O(1)
node* solveOptimal(node* &head, int n){
    node* dummy = new node(0); //initialize 
    dummy->next = head;
    node* fast = dummy;
    node* slow = dummy;

    for(int i=1; i<=n; i++){ //always use for loop
        fast = fast->next;
    }

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    node* todelete = slow->next;
    slow->next = slow->next->next;
    delete todelete;
    return dummy->next;
}



int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    int n = 3;

    display(head);
    node* newHead = solveOptimal(head, n);
    display(newHead);
}