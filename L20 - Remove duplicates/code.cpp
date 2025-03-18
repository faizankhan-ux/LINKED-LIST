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

Node* Optimal(Node* head){
    Node* temp = head;
    while(temp && temp->next){
        Node* front = temp->next;

        while(front && front->val == temp->val){
            Node* duplicate = front;
            front = front->next;
            delete duplicate;
        }
        temp->next = front;
        if(front != NULL) front->prev = temp;

        temp = temp->next;
    }
    return head;

    //Time complexity : O(N)
    //Space complexity : O(1)
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 4, 5, 5};
    Node* head = Array_to_DLL(arr);

     Optimal(head);

    print(head);
    return 0;
}