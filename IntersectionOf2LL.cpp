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


//Naive TC:O(n1*n2) & SC:O(1)
node* solveBrute(node* headA, node* headB){
    while(headB){
        node* temp = headA;
        while(temp){
            if(temp == headB)
                return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }
    return NULL;
}

//Better ~ Hashing TC:O(n + m) & SC:O(n)
node* solveBetter(node* headA, node* headB){
    unordered_set<node*>s;
    while(headA){
        s.insert(headA);
        headA = headA->next;
    }

    while(headB){
        if(s.find(headB) != s.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

//Optimal 1 TC:O(M) + O(N) + O(M-N) ~ worst case O(2N) & SC:O(1)
//find length of the the both LL, x = abs(n1-n2)
//move pointer in greater length by x
//then move both pointers by one until they meet
//point they'd meet is the intersection point, return
node* solveOptimal(node* headA, node* headB){
    node* d1 = headA;
    node* d2 = headB;
    int n1 = 0, n2 = 0;

    while(d1){
        ++n1;
        d1 = d1->next;
    }
    while(d2){
        ++n2;
        d2 = d2->next;
    }

    int diff = n1 - n2;
    if(diff < 0){ //n2 > n1
        while(diff++ != 0) headB = headB->next;
    }
    else{
        while(diff-- != 0) headA = headA->next;
    }

    while(headA){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

//Optimal 2 TC:O(2*max(n1, n2)) & SC:O(1)
//must remember intuition
node* solveOptimal2(node* &headA, node* &headB){
    node* d1 = headA;
    node* d2 = headB;

    while(d1 != d2){
        d1 = d1 == NULL? headB : d1->next;
        d2 = d2 == NULL? headA : d2->next; 
    }
    return d1;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 4);
    insertAtTail(head, 1);
    insertAtTail(head, 8);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    node* headA = head;
    head = head->next->next->next; //4

    node* headSec = NULL;
    insertAtTail(headSec, 5);
    insertAtTail(headSec, 6);
    insertAtTail(headSec, 1);
    insertAtTail(headSec, 8);

    node* headB = headSec;
    headSec->next->next->next->next = head; //8->next = 4->5

    display(headA);
    display(headB);

    node* ansNode = solveOptimal(headA, headB);
    if(!ansNode) 
        cout<<0;
    else
        cout<<ansNode->data;

    return 0;
}   

// 4->1->8->4->5->NULL
// 5->6->1->8->4->5->NULL