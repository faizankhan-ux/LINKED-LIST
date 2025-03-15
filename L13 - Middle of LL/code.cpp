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
     int n = GetLen(head);

     int cnt = 0;
     int mid = (n/2) + 1;

     Node* temp = head;

     while(temp){
          cnt++;
          if(cnt == mid) return temp;
          temp = temp->next;
     }
     return nullptr;
     //Time complexity : O(N + N/2)
}

/*
  Tortise and hares algorithm : using slow and a fast pointer
*/

Node* Optimal(Node* head){
     Node* slow = head;
     Node* fast = head;

     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = ArrayToLinkedList(arr);

    head = Brute(head);


    print(head);
    return 0;
}