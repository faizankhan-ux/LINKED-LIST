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
     Node* X = new Node(val,head->next);
     temp->next = X;

     return head;
}


int Brute(Node* head){
     unordered_map<Node* , int> mp;
     Node* temp = head;
     int cnt = 0;
     while(temp){
          cnt++;
         if(mp[temp] == 0){
          mp[temp] = cnt;
         }
         else return cnt - mp[temp];

         temp = temp->next;
     }
     return 0; // IF no loop was found
     //Time complexity : O(N) (if unordered_map was used)
     //Space : O(N)
}

int Optimal(Node* head){

     //Detect loop
     Node* fast = head;
     Node* slow = head;
     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;

          if(fast == slow) break;
          if(fast == nullptr) return 0;
     }

     /*Find length : keep a static pointer , count steps to reach static pointer again by another
          pointer*/
     int len = 1;
     fast = fast->next;
     while(fast != slow){
          len++;
          fast = fast->next;
     }
     return len;
     
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ArrayToLinkedList(arr);
    head = makeLoop(head,200);

    cout<<Optimal(head);
    //cout<<Brute(head);


    //print(head);
    return 0;
}