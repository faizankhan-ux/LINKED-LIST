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



vector<int> LL_to_Array(Node* head){
     vector<int> arr;
     Node* temp = head;

     while(temp){
          arr.push_back(temp->val);
          temp = temp->next;
     }
     return arr;

}

Node* Brute(Node* head, int k){
     vector<int> arr = LL_to_Array(head);
     for(int i=0; i<arr.size() - k; i+=k){
          int j = i+k;
          while(i<j){
               swap(arr[i],arr[j]);
               i++;
               j--;
          }
     }

   Node* Newhead = ArrayToLinkedList(arr);
   return Newhead;
}

int main() {
    vector<int> arr = {4,3,2,8};
    Node* head = ArrayToLinkedList(arr);

    head = Brute(head,4);



   print(head);
    return 0;
}