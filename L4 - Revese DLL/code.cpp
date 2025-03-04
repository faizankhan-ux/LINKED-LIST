#include<iostream>
#include<bits/stdc++.h>
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
Node* Array_to_DLL(vector<int> arr, int n){
     Node* head = new Node(arr[0]); // head --> [2]
     Node* prev = head; // head --> [2] <-- prev

     for(int i=1; i<n; i++){
          Node* temp = new Node(arr[i], nullptr , prev);//head-->[2]<--[4]
          prev->next = temp; // head --> [2] <--> [4]
          prev = temp; // head --> [2] <--> [4] <--prev
     }
     return head;
}


Node* My_sol(Node* head){
 vector<int> DLL;

 Node* temp = head;
 while(temp){
     DLL.push_back(temp->val);
     temp = temp->next;
 }

 reverse(DLL.begin(),DLL.end());
 return Array_to_DLL(DLL , DLL.size());

}


Node* Brute(Node* head){
     Node* temp = head;
     stack<int> st;
     while(temp){
          st.push(temp->val);
          temp = temp->next;
     }

     temp = head;
     while(temp){
          temp->val = st.top();
          st.pop();
          temp = temp->next;
     }
     return head;
}


Node* OPtimal(Node* head){
     Node* curr = head;
     Node* last;
     

    while(curr != NULL){

          last = curr->prev; // store last
          curr->prev = curr->next; // previous will become next
          curr->next = last; // next will become previous

          curr = curr->prev; // since we interchanged links curr->prev will take us to
                             //  next node 
    }

     return last->prev;
}


int main(){

     vector<int> arr = {2,4,6,8,10};
     Node* head = Array_to_DLL(arr,5);

     // head = My_sol(head);
     // head = Brute(head);
     // head = OPtimal(head);
     
     Print(head);


     return 0;
}