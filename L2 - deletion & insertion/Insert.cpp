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
     cout<<'\n';
     while(temp){
          cout<<temp->val<<" -> ";
          temp = temp->next;
     }
     cout<<"NULL\n";
}
Node* ArrayToLinkedlist(int arr[] , int n){
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


Node* Insert_head(Node* head , int ele){
     if(head == NULL) {
          Node* temp = new Node(ele,nullptr);
          return temp;
     }
     Node* temp = new Node(ele,head);
     return temp;
}

Node* Insert_tail(Node* head , int ele){
     if(head == NULL){
          return new Node(ele,nullptr);
     }
     Node* temp = head;

     while(temp->next != nullptr){
         temp = temp->next;
     }
     temp->next = new Node(ele,nullptr);
     return head;
}

Node* Insert_kth_pos(Node* head , int ele , int k){
     if(head == NULL){
          if(k == 1){
               return  new Node(ele,nullptr);
          }else{
               return nullptr;
          }
     }
     if(k == 1){
          Node* temp = new Node(ele , head);
          return head;
     }

     Node* temp = head;
     int count = 0;

     while(temp != NULL){
          count++;
          if(count == k-1){
               Node* X = new Node(ele,temp->next);
               temp->next = X;
               return head;
          }
          temp = temp->next;
     }
}

Node* Insert_before_val(Node* head , int val, int ele){
     if(head == NULL) return nullptr;
     if(head->val == val) return new Node(ele , head);

     Node* temp = head;
     while(temp){
          if(temp->next->val == val){
               Node* X = new Node(ele , temp->next);
               temp->next = X;
               return head;
          }
          temp = temp->next;
     }

     
}

int main(){

     int array[5] = {2,3,4,5,6}; 
     Node* head = ArrayToLinkedlist(array,5);

     // head = Insert_head(head , 0);
     // head = Insert_tail(head , 8);
     // head = Insert_kth_pos(head , 10 ,4);
     head = Insert_before_val(head , 6 ,100);

     print(head);




     return 0;
}