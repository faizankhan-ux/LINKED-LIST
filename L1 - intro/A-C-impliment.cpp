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
//A-C
class Linkedlist{
     public:

     Node* head;
     Node* tail;

     Linkedlist(){
          head = tail = nullptr;
     }

     void push_front(int ele){
          if(head == nullptr){
          Node* temp = new Node(ele);
          head = tail = temp;}
          else{

          Node* temp = new Node(ele , head);
          head = temp;
          }
     }
     void push_back(int ele){
          Node* temp = new Node(ele,nullptr);
          if(head == nullptr){
               head = tail = temp;
          }else{
               tail->next = temp;
               tail = temp;
          }
     }
     void pop_front(){
          if(head != nullptr){
               Node* temp = head;
               head = head->next;
               free(temp);
          }
     }
     void pop_back(){
          if(head != nullptr){
               Node* temp = head;
               while(temp->next != tail){temp = temp->next;}
               tail = temp;
               tail->next = nullptr;
               free(temp->next);

          }
     }
};
void Print(Node* head){
     Node* temp = head;
     while(temp){
          cout<<temp->val<<" -> ";
          temp = temp->next;
     }cout<<"NULL\n";
}

int main(){

     Linkedlist ll;
     ll.push_front(5); // (5) 
     ll.push_front(3);// (3) -> 5
     ll.push_front(6);// (6) -> 3 -> 5
     ll.push_front(8);// (8) -> 6 -> 3 -> 5
     ll.push_back(1); // 8 ->6 -> 3 -> 5 -> (1)
     ll.pop_back();
     Print(ll.head);



     return 0;
}