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

Node* Brute(Node* head , int n){
     int cnt = 0;
     Node* temp = head;

     while(temp){
          cnt++;
          temp  = temp->next;
     }

     if(cnt == n) {
      return head->next;
     }

     int res = cnt - n;
     temp = head;
     while(temp){
          res--;
          if(res == 0) break;
          temp = temp->next;
     }

     Node* DNode = temp->next;
     temp->next = DNode->next;
     free(DNode);

     return head;
}


Node* Optimal(Node* head , int n){
     Node* slow = head;
     Node* fast = head;

     for(int i=0; i<n; i++){
          fast = fast->next;
     }

     if(fast == NULL) return head->next;

     while(fast->next){
          slow = slow->next;
          fast = fast->next;
     }

     Node* Dnode = slow->next;
     slow->next = slow->next->next;
     free(Dnode);

     return head;


}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ArrayToLinkedList(arr);

    //head = Brute(head , 2);
     head = Optimal(head,5);
    print(head);
    return 0;
}