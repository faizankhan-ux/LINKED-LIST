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

int len(Node* head){
     Node* temp = head;
     int len = 0;
     while(temp) len++, temp = temp->next;
     return len;
}

Node* OPtimal(Node* head, int k){
     if(!head || !head->next || !k) return head;
     int n = len(head);

     if(k % n == 0) return head;
     k = k % n;

     Node* slow = head;
     Node* fast = head;

     while(fast && k){
          k--;
          fast = fast->next;
     }

     while(fast->next){
          slow = slow->next;
          fast = fast->next;
     }

     Node* newHead = slow->next;
     slow->next = nullptr;
     fast->next = head;

     return newHead;

     //Time complexity : O(2N)
     //Space : O(1)
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ArrayToLinkedList(arr);


     head = OPtimal(head,2);

    print(head);
    return 0;
}