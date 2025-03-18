#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val, Node* next = nullptr) { this->val = val; this->next = next; }
};

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* ArrayToLinkedList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

Node* Brute(Node* head1, Node* head2){
     // store nodes value in array
     // sort array 
     // insert in linked list

     //Time complexity : O(N + NlogN)
     //Space complexity : (N)
}

Node* Better(Node* head1, Node* head2){

     Node* t1 = head1;
     Node* t2 = head2;
     Node* dummy = new Node(-1);
     Node* newHead = dummy;

     while(t1 && t2){
          if(t1->val <= t2->val){
               Node* X = new Node(t1->val);
               dummy->next = X;
               t1 = t1->next;
               dummy = dummy->next;
          }else{
               Node* X = new Node(t2->val);
               dummy->next = X;
               t2 = t2->next;
               dummy = dummy->next;
          }

     }
     dummy->next = t1 ? t1 : t2;
     return newHead->next;
     /*
          Time complexity : O(N)
          Space : O(N)
     */
}

Node* Optimal(Node* head1, Node* head2){

     Node* t1 = head1;
     Node* t2 = head2;
     Node* dummy = new Node(-1);
     Node* newHead = dummy;

     while(t1 && t2){
          if(t1->val <= t2->val){
               dummy->next = t1;
               dummy = dummy->next;
               t1 = t1->next;
          }else{
               dummy->next = t2;
               dummy = dummy->next;
               t2 = t2->next;
          }

     }
     dummy->next = t1 ? t1 : t2;
     return newHead->next;
     /*
          we were creating new nodes , here we are changing lenghts
          Time complexity : O(N)
          Space : O(1)
     */
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2,3,5,6,7};
    Node* head2 = ArrayToLinkedList(arr);
    Node* head = ArrayToLinkedList(arr2);

    //head = Better(head,head2);
    head = Optimal(head,head2);




    print(head);
    return 0;
}