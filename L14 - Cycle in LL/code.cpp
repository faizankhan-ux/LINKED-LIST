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

Node* makeLoop(Node* head , int val){
     Node* temp = head;
     while(temp->next) temp = temp->next;
     Node* X = new Node(100,head->next);
     temp->next = X;

     return head;
}

bool brute(Node* head){
     unordered_map<Node* , int> mp;
     Node* temp = head;

     while(temp){
         if(mp[temp] == 0){
         mp[temp]++;
         temp = temp->next;
         }
         else return true;

     }

     return false;
     //Time complexity : O(N)
     //space : O(N);
}

bool Optimal(Node* head){
     if(head == NULL || head->next == nullptr) return false;
     Node* slow = head;
     Node* fast = head;

     while(fast && fast->next){
         slow = slow->next;
         fast = fast->next->next;

         if(slow == fast) return true;
     }

     return false;
     //Time complexity : ~O(N)
     //Space : O(1)
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ArrayToLinkedList(arr);
    head = makeLoop(head,200);

    if(Optimal(head)) cout<<"Loop exits\n";
    else cout<<"No loop found\n";

    //print(head);
    return 0;
}