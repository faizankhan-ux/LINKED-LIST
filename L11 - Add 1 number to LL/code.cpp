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

Node* Reverse(Node * head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
         Node* next = curr->next;
         curr->next = prev ;
         prev = curr;

         curr = next;
    }
    return prev;
}

Node* Brute(Node* head){
    head = Reverse(head);

    int carry = 1;
    while(head){
          head->val += carry;

        if(head->val < 10){
            carry = 0;
            break;
        }else{
            head->val = 0;
            carry = 1;
        }
    }

    head = Reverse(head);
    if(carry == 1){
        Node* nHead = new Node(1 , head);
        return nHead;
    }
    return head;

    //Time complexity : O(3N)

}

int Rec(Node* temp){
    if(temp == NULL) return 1;
    int carry = Rec(temp->next);
   // if(carry == 0) return 0;
    temp->val += carry;

    if(temp->val < 10) return 0;
    temp->val = 0;
    return 1;
}

Node* Optimal(Node* head){
    int carry = Rec(head);
    if(carry == 1){
        Node* nHead = new Node(1,head);
        return nHead;
    }
    return head;

    //Time complexity : O(N)
}

int main() {
    vector<int> arr = {1, 2, 3, 9, 9};
    Node* head = ArrayToLinkedList(arr);

     head = Optimal(head);

    print(head);
    return 0;
}