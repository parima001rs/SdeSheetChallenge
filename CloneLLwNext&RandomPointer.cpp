#include<bits/stdc++.h>
using namespace std;

//Naive Approach ~ Hashing

//Optimal Approach TC:O(3N) ~ O(N) & SC:O(1)
Node* copyRandomList(Node* head) {
        //make deep copy of nodes O(N)
        
        Node* iter = head;
        Node* front = head;
        
        while(iter){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front; //iter reaches front's pos
        }
        
        //point random pointers of copy nodes O(N)
        iter = head;
        while(iter){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        //separate new and old LL O(N)
        iter = head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        
        while(iter){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return pseudoHead->next;
    }

int main(){
    node* head = NULL;
    
}