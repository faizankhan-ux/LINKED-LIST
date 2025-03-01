#include<iostream>
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
     while(temp){
          cout<<temp->val<<" ";
          temp = temp->next;
     }
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


Node* Insert_head(Node* head , int ele){
     if(head == NULL || head->next == nullptr) {
          Node* temp = new Node(ele,nullptr);
          return temp;
     }
     Node* temp = new Node(ele,head);
     return temp;
}

int main(){

     int array[5] = {2,4,6,7,8}; 
     Node* head = ArrayToLinkedlist(array,1);

     head = Insert_head(head , 0);

     print(head);




     return 0;
}