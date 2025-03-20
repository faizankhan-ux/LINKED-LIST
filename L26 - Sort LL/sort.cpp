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

Node* Brute(Node* head) {
     Node* temp = head;
     vector<int> arr;
 
     while(temp) {                 // O(N)
         arr.push_back(temp->val);
         temp = temp->next;
     }
 
     sort(arr.begin(), arr.end()); // O(N log N)
 
     temp = head;
     int i = 0;
 
     while(temp) {                 // O(N)
         temp->val = arr[i];
         i++;
         temp = temp->next;
     }
     return head;

     //Time complexity : O(2N + N log N)
     //Space : O(N)
}

Node* merge(Node* head1, Node* head2) {
     Node* t1 = head1;
     Node* t2 = head2;
     Node* dummy = new Node(-1);
     Node* newHead = dummy;
 
     while (t1 && t2) {
         if (t1->val <= t2->val) {
             dummy->next = t1;
             dummy = dummy->next;
             t1 = t1->next;
         } else {
             dummy->next = t2;
             dummy = dummy->next;
             t2 = t2->next;
         }
     }
     dummy->next = t1 ? t1 : t2;
     return newHead->next;
}
 
Node* middleNode(Node* head) {
     if (!head || !head->next) return head;
 
     Node* slow = head;
     Node* fast = head->next;
 
     while (fast && fast->next) {
         slow = slow->next;
         fast = fast->next->next;
     }
 
     return slow;
}
 
Node* MergeSort(Node* head) {
     if (!head->next) return head; //One element left
     
     Node* mid = middleNode(head); // O(N/2)
 
     Node* left = head; //Left part 
     Node* right = mid->next; // right part
 
     mid->next = NULL; // Breaking link
 
     left = MergeSort(left);
     right = MergeSort(right);
 
     return merge(left, right); // O(N)
 }
 
 Node* Optimal(Node* head) {
     if (!head || !head->next) return head;
 
     return MergeSort(head);

     // Time Complexity: O(N log N)
     // Space Complexity: O(1) 
 }
 



int main() {
    vector<int> arr = {3,5,1,2,8,9,0,45,32,98};
    Node* head = ArrayToLinkedList(arr);

    //Brute(head);
    Optimal(head);



    print(head);
    return 0;
}