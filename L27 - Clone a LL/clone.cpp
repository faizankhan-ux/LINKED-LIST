#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node* random;
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


Node* Brute(Node* head){
     Node* temp = head;
     map<Node* , Node*> mpp;

     while(temp != NULL){
          Node* newNode = new Node(temp->val);
          mpp[temp] = newNode;
          temp = temp->next;
     }

     temp = head;
     while(temp){
          Node* copyNode = mpp[temp];
          copyNode->next = mpp[temp->next];
          copyNode->random = mpp[temp->random];
          temp = temp->next;
     }

     return mpp[head];

     //Time complexity : O(2N)
     //Space : O(2N)
}

Node* Optimal(Node* head){

     //Inserting newNode in between original
     Node* temp = head;
     while(temp){
          Node* copyNode = new Node(temp->val);
          copyNode->next = temp->next;
          temp->next = copyNode;

          temp = temp->next->next;
     }

     //connectiong the Random pointers
     temp = head;
     while(temp){
          Node* copyNode = temp->next;

          if(temp->random){
               copyNode->random = temp->random->next;
          }else{
               copyNode->random = NULL;
          }

          temp = temp->next->next;

     }

     //Connection the Next Pointers
     Node* dummy = new Node(-1);
     Node* res = dummy;
     temp = head;
     while(temp){
          res->next = temp->next;
          temp->next = temp->next->next;

          res = res->next;
          temp = temp->next;
     }

     return dummy->next;

     //Time complexity : O(3N)
     //Space : O(N)

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    //Node* head = ArrayToLinkedList(arr);


   //print(head);
    return 0;
}