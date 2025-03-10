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

bool Brute(Node* head){
     Node* temp = head;
     stack<int> st;

     while(temp){
          st.push(temp->val);
          temp = temp->next;
     }

     temp = head;

     while(temp){
          if(temp->val != st.top()) return false;
          st.pop();
          temp = temp->next;
     }

     return true;
     //Time complexity : O(2N)
     //Space complexity : O(N)
}

Node* Reverse(Node* head){
     Node* prev = nullptr;
     Node* curr = head;
     while(curr){
         Node* next = curr->next;
         curr->next = prev;
         prev = curr;

         curr = next;
     }
     return prev;
 }
 
 bool Optimal(Node* head) {
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newH = Reverse(slow);

     Node* temp = head;
    while(newH){
         if(newH->val != temp->val) return false;
             temp = temp->next;
             newH = newH->next;
     }
     Reverse(newH);
    return true;
    //Time complexity : O(2N)
    //Space Complexity : O(1)
}

int main() {
    vector<int> arr = {1,1,12,2,2};
    Node* head = ArrayToLinkedList(arr);

     cout<<Brute(head);
     cout<<Optimal(head);


    
    return 0;
}