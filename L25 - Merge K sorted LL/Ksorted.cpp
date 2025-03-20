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

Node* Brute(vector<Node*> arr){
     int n = arr.size();
     if(n == 0 ) return nullptr;
     vector<int> ans;

     for(int i = 0 ;i < n ;i++){
         Node* head = arr[i];


         while(head != NULL) {
             ans.push_back(head->val);
             head = head->next;
         }
     }

     sort(ans.begin(),ans.end());
     if(ans.empty()) return nullptr;
     Node* head = ArrayToLinkedList(ans);

     return head;

     //Time complexity : O(N x K) + O(M log M) + O(M) . . M is (N x K)
     //Space : O(M)
} 


Node* merge(Node* head1 , Node* head2) {
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

Node* Better(vector<Node*>& arr) {
     int n = arr.size();
     if (n == 0) return nullptr;

     Node* head = arr[0];
     for (int i = 1; i < n; i++) {
         head = merge(head, arr[i]); // Fix: Store the merged result
     }

     return head;
     //Time complexity : O(N) x O(k(k+1) / 2) ~ O(N^3)
     //Space : O(1)
}
     

Node* Optimal(vector<Node*> arr){
    priority_queue<pair<int,Node*> , vector<pair<int,Node*>> , greater<pair<int,Node*>>> pq;

    //Inserting all the heads from the list
    for(int i=0; i<arr.size(); i++){
        if(arr[i]){
            pq.push({arr[i]->val , arr[i]});
        }
    }


    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(!pq.empty()){

      /*Getting the minimum from Queue*/
        pair<int,Node*> pr = pq.top();
        pq.pop(); //Deleting the minimum

        if(pr.second->next){ //Inserting next Node if exits
            pq.push({pr.second->next->val , pr.second->next});
        }

        temp->next = pr.second; // Pointing temp to minimum
        temp = temp->next; // MOving pointer to minimum
    }
    
    return dummy->next;

    /* Time Complexity : O(k log k) + O(N) x O(k log k)  ....N --> Worst possible length of linked list form array
       Space : O(k)
    */

}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 5};
    vector<int> arr3 = {0, 3, 4, 5};
    vector<int> arr4 = { 4, 5, 8, 9};
    Node* head1 = ArrayToLinkedList(arr1);
    Node* head2 = ArrayToLinkedList(arr2);
    Node* head3 = ArrayToLinkedList(arr3);
    Node* head4 = ArrayToLinkedList(arr4);

    vector<Node*> arr = {head1 , head2 , head3 , head4};

     head1 = Optimal(arr);


    print(head1);
    return 0;
}