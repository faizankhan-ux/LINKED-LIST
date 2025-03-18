#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val, Node* next = nullptr) { this->val = val; this->next = next; }
};

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* ArrayToLinkedList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

Node* Reverse(Node* head){
     Node* temp = head;
     Node* prev = nullptr;

     while(temp){
          Node* next = temp->next;
          temp->next = prev;
          prev = temp;
          temp = next;
     }
     return prev;
}

Node* GetK(Node* head, int k){
     Node* temp = head;
     k-=1;

     while(temp && k){
          k--;
          temp = temp->next;    
     }
     return temp;
}

Node* Optimal(Node* head ,int k){
     Node* temp = head;
     Node* prev = NULL;
     while(temp){
          
          Node* kth = GetK(temp,k);
          if(kth == NULL){
              if(prev)  prev->next = temp;
               break;
          }
          Node* nextNode = kth->next;
         
          kth->next = nullptr;

          Reverse(temp);

          //If it is first k group update head
          if(temp == head){
               head = kth;
          }else{
               prev->next = kth;
          }
          prev = temp;
          temp = nextNode;
     }
     return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = ArrayToLinkedList(arr);
     
    head = Optimal(head,3);



    print(head);
    return 0;
}