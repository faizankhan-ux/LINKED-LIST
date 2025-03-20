#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node* bottom;
    Node(int val, Node* next = nullptr) { this->data = data; this->next = next; }
};

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
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

Node* Brute(Node* root){
    if(!root || !root->next ) return root;
    Node* temp = root;
    vector<int> arr;
    while (temp) {
        Node* t2 = temp;
        while(t2){
            arr.push_back(t2->data);
            t2 = t2->bottom;
        }
        temp = temp->next;
    }
    
    sort(arr.begin() , arr.end());
    Node* newLL = new Node(-1);
    temp = newLL;
    
    for(int i : arr){
        Node* X = new Node(i);
        temp->bottom = X;
        temp = temp->bottom;
    }
    
    return newLL->bottom;
    //Time complexity : O(2 x N x M) + O(X log X) . . . X = N x M
    //Space complexity : O(N x M)
}



    Node* Merge(Node* head1, Node* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        
        Node* dummy = new Node(-1);
        Node* newHead = dummy;
        Node* t1 = head1;
        Node* t2 = head2;

        while (t1 && t2) {
            if (t1->data <= t2->data) {
                dummy->bottom = t1;
                t1 = t1->bottom;
            } else {
                dummy->bottom = t2;
                t2 = t2->bottom;
            }
            dummy = dummy->bottom;
        }
        
        // Attach remaining elements
        dummy->bottom = t1 ? t1 : t2;
        
        Node* result = newHead->bottom;
        delete newHead; // Prevent memory leak
        return result;
    }


    Node* Optimal(Node* head){
        if(head == NULL || head->next == nullptr) return head;

        Node* merged_head = Optimal(head->next);

    return Merge(head,merged_head);

    //Time complexity : O(2 x N x M)
    //Space : O(N) . . . recursive stack space
    }


int main() {
    // vector<int> arr = {1, 2, 3, 4, 5};
    // Node* head = ArrayToLinkedList(arr);



    //print(head);
    return 0;
}