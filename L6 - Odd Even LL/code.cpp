#include<iostream>
#include<vector>
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
          cout<<temp->val<<" -> ";
          temp = temp->next;
     }cout<<"NULL\n";
}
Node* ArrayToLinkedlist(vector<int> arr){
     int n = arr.size();
     Node* head = new Node(arr[0] , nullptr); // head pointing to first element
     Node* mover = head; // it will be moving while iterating

     for(int i=1; i<n; i++){
          Node* temp = new Node(arr[i] , nullptr);
          mover->next = temp;
          mover = mover->next;
     }
     return head;
}

Node* Brute(Node* head){
     vector<int> arr;

     Node* temp = head;
     while(temp){
          arr.push_back(temp->val);
          temp = temp->next;
     }
     temp = head;
     int n = arr.size();
     int i = 0;
     int j = 1;
     
     while(temp){
          if(j<n) temp->val = arr[j];
          else break;
          j+=2;
          temp = temp->next;
     }
     while(temp){
          if(i<n) temp->val = arr[i];
          i+=2;
          temp = temp->next;
     }

     return head;
     //Time complexity : O(2N)
     //Space Complexity : O(N)
}

Node* Optimal(Node* head){
     if(head == NULL || head->next == nullptr) return head;
     Node* odd = head;
     Node* even = head->next;
     Node* evenHead = head->next; //store the head of even

     while(even && even->next){
          odd->next = even->next;
          odd = odd->next;
          even->next = odd->next;
          even = even->next;
     }

     odd->next = evenHead;
     return head;
     //Time complexity : ~ O(N)
     //Space Complexity : O(1)

}
int main(){
     vector<int> arr = {2, 4 ,6 ,8, 10};
     Node* head = ArrayToLinkedlist(arr);

     print(head);

     //head = Brute(head);
     head = Optimal(head);
     print(head);



     return 0;
}