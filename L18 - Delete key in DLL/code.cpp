#include<iostream>
#include<vector>
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

Node* Brute(Node* head, int x){
     Node* temp = head;
     while(temp){
       if(temp->val == x){
         
          Node* prev = temp->prev;
          Node* next = temp->next;

          if (temp == head) {
               head = next;
               if (head) head->prev = NULL;
          }

          if(next) next->prev = prev;
          if(prev) prev->next = next;
          
          delete temp;
          temp = next;
       } else temp = temp->next;
     }
   
   return head;

   //Time complexity : O(N)
}

int main() {
    vector<int> arr = {4, 1, 2, 3, 4, 4, 5};
    Node* head = Array_to_DLL(arr);

   head =  Brute(head , 4);


    print(head);
    return 0;
}