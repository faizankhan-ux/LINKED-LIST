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

Node* Insert_BF_head(Node* head , int ele){

     Node* temp = new Node(ele);
     if(head == NULL) return temp;

     temp->next = head;
     head->prev = temp;

     return temp;
}

Node* Insert_BF_tail(Node* head, int ele){
     if(head == NULL) return new Node(ele);
     if(head->next == nullptr){
         return Insert_BF_head(head,ele);
     }

     Node* temp = head;
     while(temp->next != nullptr) temp = temp->next;

    
     Node* prev = temp->prev;
     Node* X = new Node(ele , temp , prev);
     prev->next = X;

     return head;

}

Node* Insert_BF_kth(Node* head , int ele , int k){
     if(head == NULL) return nullptr;
     if(k == 1) return Insert_BF_head(head,ele);

     int count = 0;
     Node* mover = head;
     while(mover){
          count++;
          if(count == k) break;
          mover = mover->next;
     }
     Node* back = mover->prev;
     Node* Knode = new Node(ele,mover,back);
     back->next = Knode;
     mover->prev = Knode;
     return head;
}

void Insert_BF_Node(Node* Tnode,int ele){
     if(Tnode == NULL) return ;

     Node* back = Tnode->prev;
    
    Node* newNode = new Node(ele,Tnode,back);

     back->next = newNode;
     Tnode->prev = newNode;
     return;
    

   
}

int main(){
     int arr[7] = {2,4,6,8,10};
     Node* head = Array_to_DLL(arr,5);

     // head = Insert_BF_head(head , 1);
     // head = Insert_BF_tail(head , 9);
     // head = Insert_BF_kth(head , 100 ,1);
     Insert_BF_Node(head->next->next->next->next , 34);

     Print(head);



     return 0;
}