#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{ // --> [ Data , next_ptr ]
     public:
     int val; // Data
     Node *next; // pointer to next Node

     //constructor
     Node(int val , Node* next = nullptr){
          this->val = val;
          this->next = next;
     }
};
void print(Node* head){
     Node* temp = head;
     cout<<'\n';
     while(temp){
          cout<<temp->val<<" -> ";
          temp = temp->next;
     }
     cout<<"NULL\n";
}
Node* ArrayToLinkedlist(vector<int> arr , int n){
     if(n == 0) return nullptr;
     Node* head = new Node(arr[0] , nullptr); // head pointing to first element
     Node* mover = head; // it will be moving while iterating

     for(int i=1; i<n; i++){
          Node* temp = new Node(arr[i] , nullptr);
          mover->next = temp;
          mover = mover->next;
     }

     

     return head;
}

/*
  Since the given two linked list are in reverse order there first element is in unit place
  from where we start adding and keeping track of carry , then adding it into our answer LL

*/

Node* MySol(Node *num1, Node *num2){
    int carry = 0;

    Node* temp1 = num1;
    Node* temp2 = num2;
    int digit = num1->val + num2->val ;
    if(digit > 10) carry = digit%10;

    Node* ans = new Node(-(1));
    Node* mover = ans;

    while(temp1 && temp2){
      digit = temp1->val + temp2->val + carry;
      if(digit > 10) carry = digit%10;
      else carry = 0;
      Node* X = new Node(-(carry - digit));
      mover->next = X;
      mover = mover->next;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }

    return ans->next;
    
} 

Node* AddTwoNumber(Node* num1,Node* num2){
     Node* t1 = num1;
     Node* t2 = num2;
     Node* dummy = new Node(-1);
     Node* curr = dummy;

     int carry = 0;

     while(t1 || t2){
          int sum = carry; // 0
          if(t1) sum += t1->val; // 0 + 5
          if(t2) sum += t2->val; // 0 + 5 + 7 

          Node* X = new Node(sum % 10); // 12 % 10 = 2
          carry = sum / 10; // (12 / 10) = 1.2 ~ 1

          curr->next = X;
          curr = curr->next;
          if(t1) t1 = t1->next;
          if(t2) t2 = t2->next;
     }

     //If there is carry left
     if(carry){
          Node* X = new Node(carry);
          curr->next = X;
     }

     return dummy->next;

     //Time complexity : O(max(n1,n2))
     //space complexity : O(max(n1,n2))
}


int main(){
     vector<int> arr1 = {1,2,9,5};
     vector<int> arr2 = {4,5,6};

     Node* num1 = ArrayToLinkedlist(arr1,arr1.size());
     Node* num2 = ArrayToLinkedlist(arr2,3);

     Node* head = AddTwoNumber(num1,num2);

     print(head);

     



     return 0;
}