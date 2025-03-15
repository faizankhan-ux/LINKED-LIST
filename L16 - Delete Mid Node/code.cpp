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

int GetLen(Node* head){
     int len = 0;
     Node* temp = head;
     while(temp){
          len++;
          temp = temp->next;
     }
     return len;
}

Node* Brute(Node* head){
     if(head == NULL || head->next == nullptr) return nullptr;
     Node* temp = head;
     int mid = GetLen(head)  / 2;
     int cnt = 0;

     while(temp){
          cnt++;
          if(cnt == mid) break;
          temp = temp->next;
     }

     Node* del = temp->next;
     temp->next = temp->next->next;
     delete del;
     return head;
     //Time complexity : O(N + N / 2);
     //Space : O(1)
}

Node* MidNode(Node* head){ // Gives node just before middle node

     Node* slow = head;
     Node* fast = head;

     fast = fast->next->next; //since we want to reach just before middle node 
                              // we are skipping one slow step
     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;
 }

 Node* Optimal(Node* head) {
     if(head == NULL || head->next == nullptr) return NULL;
     Node* mid = MidNode(head);
     Node* del = mid->next;
     mid->next = mid->next->next;
     delete del;
    

     return head;
 }



int main() {
    vector<int> arr = {1, 2};
    Node* head = ArrayToLinkedList(arr);

   // Brute(head);
   Optimal(head);

    print(head);
    return 0;
}