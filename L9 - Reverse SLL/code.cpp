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

Node* Brute(Node* head){ //Using Stack
     if(head == NULL || head->next == nullptr) return head;
     stack<int> st;
     Node* temp = head ;
     while(temp){
         st.push(temp->val);
         temp = temp->next;
     }

     temp = head;
     while(temp){
         temp->val = st.top();
         st.pop();
         temp = temp->next;
     }

     return head;
}

Node* Optimal_1(Node* head){ //Iterative Changing links
     Node* curr = head;
     Node* prev = nullptr;

     int cnt = 0;
     while(curr){
          Node* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
     }

     return prev;

}

Node* My_Optimal_2(Node* curr , Node* prev){
     if(curr == NULL) return prev;

     Node* next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;

     return My_Optimal_2(curr,prev);
}

Node* Optimal_2(Node* head){ // Recursive
     if(head == NULL || head->next == nullptr) return head;

     Node* Newhead = Optimal_2(head->next);
     Node* front = head->next;
     front->next = head;
     head->next = nullptr;

     return Newhead;

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ArrayToLinkedList(arr);

    //head = Brute(head);
    //head = Optimal_1(head);
   // head = My_Optimal_2(head,nullptr);
   head = Optimal_2(head);

    print(head);
    return 0;
}