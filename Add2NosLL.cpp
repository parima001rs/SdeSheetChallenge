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

// TC:O(max(n1,n2)) & SC:O(max(m, n)) atmost be O(max(m,n)+1)
node* solve(node* head1, node* head2){

    node* dummy = new node(0);
    node* temp = dummy;
    int carry = 0;
    while(head1 || head2 || carry){
        int sum = 0;
        if(head1){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum/10;
        node* n = new node(sum%10);
        temp->next = n;
        temp = temp->next;
   }
   return dummy->next;
}

int main(){
    node* head1 = NULL;
    insertAtTail(head1, 2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 3);

    node* head2 = NULL;
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    insertAtTail(head2, 4);

    display(head1);
    display(head2);

    node* newHead = solve(head1, head2);
    display(newHead);

    return 0;
}