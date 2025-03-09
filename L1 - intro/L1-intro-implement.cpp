#include<iostream>
using namespace std;

/*
     Node : stores the data and a pointer to next Node
     head : Points to the first Node in linked list
     tail : points to last Node of linked list

*/
// T-U-F
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

int length_of_ll(Node* head){
     Node* temp = head;
     int len = 0;
     while(temp){
          temp = temp->next;
          len++;
     }
     return len;

}

bool SearchInLL(Node* head,int target){
     Node* mover = head;
     while(mover){
          if(mover->val == target) return true;
          mover = mover->next;
     }
     return false;
}

Node* ArrayToLinkedlist(int arr[] , int n){
     Node* head = new Node(arr[0] , nullptr); // head pointing to first element
     Node* mover = head; // it will be moving while iterating

     for(int i=1; i<n; i++){
          Node* temp = new Node(arr[i] , nullptr);
          mover->next = temp;
          mover = mover->next;
     }

     

     return head;
}


int main(){
     int arr[5] = {3,4,5,6,7};

    Node* head = ArrayToLinkedlist(arr , 5);

    Node* mover = head;
    cout<< SearchInLL(head , 6)<<endl;

    while(mover){
         // cout<<mover->val<<endl;
          mover = mover->next;
     }
     
}