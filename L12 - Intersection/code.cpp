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
    cout<<'\n';
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

Node* Brute(Node* head1 , Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    unordered_map<Node* , int> mp;

    while(temp1){
        mp[temp1]++;
        temp1 = temp1->next;
    }

    while(temp2){
        if(mp.find(temp2) != mp.end()) return temp2;
        temp2 = temp2->next;
    }
    return nullptr;
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

Node* CollisonPoint(Node* h1 , Node* h2 ,int dis){ // assuming h2 has greater length
    Node* t1 = h1;
    Node* t2 = h2;

    int cnt = 0;
    while(dis){
        dis--;
        t2 = t2->next;
    }

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }

    return t1;

}

Node* Better(Node* head1, Node* head2){
    int n1 = GetLen(head1);
    int n2 = GetLen(head2);

    if(n1 < n2){
       return  CollisonPoint(head1,head2,n2-n1);
    }else{
       return  CollisonPoint(head2 , head1 , n1-n2);
    }

    
}

Node* Optimal(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1->next && temp2->next){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;

    }

    return temp1;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* head = ArrayToLinkedList(arr);
    Node* head2 = head->next->next->next;

   //cout<<(Brute(head , head2))->val;
   //cout<< (Better(head,head2))->val;
   // cout<< (Optimal(head,head2))->val;

    print(head);
    print(head2);
    return 0;
}