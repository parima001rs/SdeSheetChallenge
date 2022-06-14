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
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
//Bruteforce
//traverse through the LL, count the no. of nodes = n
//then if odd x = n/2+1, if even , second middle: x = n/2+1, first middle: x = n/2
//traverse till x and return x->data;

//TC:O(N) + O(N/2) & SC:O(1)
node* middleBrute(node* head){
    node* temp = head;
    int count = 0;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    
    temp = head;
    for(int i=0; i<count/2; i++){ //count/2-1 for first middle
        temp = temp->next;
    }
    return temp;
    
}

//NAIVE APPROACH
//if even, return second middle
node* middleOfTheLL(node* head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Optimal ~ Tortoise-Hare-Approach TC:O(N) & SC:O(1)
//Intuition: In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double than that of the slow pointer. So when the fast ptr will be at the end of Linked List, slow ptr would have covered half of Linked List till then. So slow ptr will be pointing towards the middle of Linked List.
//if even, return first middle
node* middle(node* head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);

    node* newHead = middleBrute(head);
    display(newHead);

    return 0;
}