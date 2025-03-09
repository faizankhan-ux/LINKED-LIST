#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) { this->val = val, this->next = nullptr;}
    Node(int val , Node* next){
        this->val = val;
        this->next = next;
    }
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

Node* Brute(Node* head){ // Changing data
    int zero = 0;
    int one = 0;
    int two =  0;

    Node* temp = head;
    while(temp){
        if(temp->val == 0) zero++;
        else if(temp->val == 1) one++;
        else two++;
        temp = temp->next;
    }

    temp = head;
    while(temp){
        if(zero){
            temp->val = 0;
            zero--;
        }
        else if(one){
            temp->val = 1;
            one--;
        }else{
            temp->val = 2;
            two--;
        }
        temp = temp->next;
    }

    return head;

    //Time complextity : O(2N)
    // Space complexity : O(1)
}

Node* Optimal(Node* head){
    if(head == NULL || head->next == nullptr) return head;
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroHead = new Node(-1);

    Node* one = oneHead;
    Node* two = twoHead;
    Node* zero = zeroHead;
   
    Node* temp = head;
    while(temp){
        if(temp->val == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->val == 1){
            one->next = temp;
            one = one->next;
        }else{
             two->next = temp;
             two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    return zeroHead->next;
}

int main() {
    vector<int> arr = {2,1,1,1,1,1,1,1,1};
    Node* head = ArrayToLinkedList(arr);

    //head = Brute(head);
    head = Optimal(head);

    print(head);
    return 0;
}