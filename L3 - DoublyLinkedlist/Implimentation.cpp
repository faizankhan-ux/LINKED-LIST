#include<iostream>
using namespace std;

class Node{
     public:
     int val;
     Node* next; // pointing to next Node
     Node* prev; // Pointing to prevois Node

     Node(int data,Node* next1 , Node* prev1){ //  Constructor
          val = data;
          next = next1;
          prev = prev1;
     }
     Node(int data){ // next = prev = nullptr (constructor)
          val = data;
          next = nullptr;
          prev = nullptr;
     }
};
void Print(Node* head){
     Node* temp = head;
     while(temp){
          cout<<temp->val<<" <--> ";
          temp = temp ->next;
     }cout<<"NULL\n";
}

Node* Array_to_DLL(int arr[] , int n){
     Node* head = new Node(arr[0]); // head --> [2]
     Node* prev = head; // head --> [2] <-- prev

     for(int i=1; i<n; i++){
          Node* temp = new Node(arr[i], nullptr , prev);//head-->[2]<--[4]
          prev->next = temp; // head --> [2] <--> [4]
          prev = temp; // head --> [2] <--> [4] <--prev
     }
     return head;
}


int main(){
     int arr[5] = {2,4,6,8,10};

     Node* head = Array_to_DLL(arr,5);
     Print(head);



     return 0;
}