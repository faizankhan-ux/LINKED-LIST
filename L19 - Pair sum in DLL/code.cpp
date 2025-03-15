#include<iostream>
#include<vector>
#define val data
using namespace std;

class Node {
public:
    int val;
    Node* next; // Pointing to next Node
    Node* prev; // Pointing to previous Node

    Node(int data, Node* next1, Node* prev1) { // Constructor
        val = data;
        next = next1;
        prev = prev1;
    }

    Node(int data) { // Default constructor
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " <--> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* Array_to_DLL(vector<int> arr) {
    int n = arr.size();
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]); // head --> [2]
    Node* prev = head; // head --> [2] <-- prev

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr, prev); // head-->[2]<--[4]
        prev->next = temp; // head --> [2] <--> [4]
        prev = temp; // head --> [2] <--> [4] <-- prev
    }
    return head;
}


vector<int> brute(Node* head){
     //Using two pointers as i and j same as N^2 in two sum 
     return {0,0};
}

Node* Tail(Node* head){
     Node* temp = head;
     while(temp->next) temp = temp->next;
     
     return temp;
}

vector<pair<int,int>> Optimal(Node* head , int target){
     Node* left = head;
     Node* right = Tail(head);
     vector<pair<int, int>> ans;

     while (left && right && left != right && left->prev != right) {
         int sum = left->data + right->data;

         if (sum == target) {
             ans.push_back({left->data, right->data});
             left = left->next;  // Move left forward
             right = right->prev; // Move right backward
         }
         else if (sum < target) 
             left = left->next;
         else 
             right = right->prev;
     }
     return ans;

     //Time Complexity : O(N)
 
}

int main() {
    vector<int> arr = {0,1,1,1,2,2,3,3,4,4,5};
    Node* head = Array_to_DLL(arr);

    vector<pair<int,int>> ans = Optimal(head,5);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }


    //print(head);
    return 0;
}