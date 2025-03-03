#include<iostream>
using namespace std;

class Node{
     public:
     int val;
     Node* next; // Pointing to next Node
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

Node* Delete_head(Node* head){
     if(head == NULL || head->next == NULL) return nullptr; //One element or null
     
     Node* temp = head; // store head
     head = head->next; // move head forward

     head->prev = nullptr; // break next element's prev link
     temp->next = nullptr; // break head to next element link

     delete temp; // delete 1st element | head pointer
     return head;
}

Node* Delete_tail(Node* head){
     if(head == NULL) return NULL;
     if(head->next == NULL) { // If only one node exists
          delete head;
          return NULL;
     }

     Node* tail = head;
     while(tail->next != nullptr) tail = tail->next; //traverse till tail

     tail->prev->next = nullptr; // break prev-element and next element link
     tail->prev = nullptr; // break tail to prev-element link

     delete tail;//delete tail from heap memory
     return head;
}

Node* Delete_kth_pos(Node* head , int k){
     if( head == NULL) return nullptr;
     
     int count = 0;
     Node* Knode = head;
     while(Knode){
          count++;
          if(count == k) break;
          Knode = Knode->next;
     }

     Node* prevND = Knode->prev;
     Node* nextND = Knode->next;

     if(prevND == nullptr && nextND == nullptr){ // Single element Doubly LL
          delete head;
          return nullptr;
     }
     else if(prevND == nullptr) Delete_head(head); // Delete head;
     else if(nextND == nullptr) Delete_tail(head); // Delete tail;

     else{     //Standing at some Node
          prevND->next = Knode->next;
          nextND->prev = Knode->prev;
          delete Knode;
          return head;
     } 
}

void Delete_Node(Node* node){

     Node* back = node->prev;
     Node* front = node->next;

     if(front == nullptr){
          back->next = nullptr;
          node->prev = nullptr;
          delete node;
          return;
     }

}

int main(){
     int arr[7] = {2,4,6,8,10,11};
     Node* head = Array_to_DLL(arr,6);

     // head = Delete_head(head);
     // head = Delete_tail(head);
     // head = Delete_kth_pos(head,2);
     Delete_Node(head->next->next);

     Print(head);




     return 0;
}