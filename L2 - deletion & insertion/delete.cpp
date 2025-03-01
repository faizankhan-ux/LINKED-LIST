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

Node* Delete_head(Node* head){
     Node* temp = head;
     head =  head->next;

     free(temp); // delets the Node present in memory without any refrence

     return head;
}

Node* Delete_tail(Node* head){
     if(head->next == NULL || head == NULL) return NULL;

     Node* mover = head;
     if(mover->next->next == nullptr){
          mover->next = nullptr;
          delete mover->next->next;
          return head;
     }

     while(mover){
          if(mover->next->next == nullptr){
               delete mover->next->next;
               mover->next = nullptr;
               break;
          }
          mover = mover->next;
     }
     
     return head;
}

Node* Delete_position(Node* head , int k){
     if(head == NULL || head->next == nullptr) return NULL;
     if(k == 1){
          Node* temp = head;
          head = head->next;
          free(temp);
          return head;
     }
     int cnt = 0;
     Node* mover = head;
     Node* prev = nullptr;
     while(mover){
         cnt++;
         if(cnt == k){
               prev->next = mover->next; // or prev->next->next
               free(mover);
               break;
         }
         prev = mover;
         mover = mover->next;
     }

     return head;

}

Node* Delete_Element(Node* head , int ele){
     if(head == NULL || head->next == nullptr) return NULL;
     if(head->val == ele){
          Node* temp = head;
          head = head->next;
          free(temp);
          return head;
     }
     
     Node* mover = head;
     while(mover){
         
         if(mover->next->val == ele){
               Node* temp = mover->next;
               mover->next = mover->next->next; // or prev->next->next
               free(temp);
               break;
          }
         
         mover = mover->next;
     }

     return head;
}


int main(){

     int arr[5] = {2,4,6,8,10};
     Node* head = ArrayToLinkedlist(arr,5);

     // head = Delete_tail(head);
     // head = Delete_head(head);
     // head = Delete_position(head ,4);
     head = Delete_Element(head , 2 );

     print(head);




     return 0;
}