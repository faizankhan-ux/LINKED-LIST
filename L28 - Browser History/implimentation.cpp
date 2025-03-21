#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
          string data;
          Node* next;
          Node* prev;

          Node(string data){
               this->data = data;
               next = nullptr;
               prev = nullptr;
          }
          Node(string data, Node* next, Node* prev){
               this->data = data;
               this->next = next;
               this->prev = prev;
          }
};

class Browser{
     
     public:
          Node* currPage;
          Browser(string homepage){        //O(1)
               currPage = new Node(homepage);
          }

          void visit(string URL){                 //O(1)
               Node* newPage = new Node(URL);
               currPage->next = newPage;
               newPage->prev = currPage;

               currPage = newPage;
          }

          string forward(int n){                  //O(n)
               
               while(currPage->next && n){
                    currPage = currPage->next;
                    n--;
               }

               return currPage->data;
          }

          string back(int n){                     //O(n)
               
               while(currPage->prev && n){
                    currPage = currPage->prev;
                    n--;
               }

               return currPage->data;
          }


};
void pt(string s){
     cout<<'\n'<<s<<'\n';
}

int main() {

     Browser b1("www.google.com");
     b1.visit("takeyouforward.org");
     b1.visit("neetcode.io");
     b1.visit("www.codingninjas.com");


     pt(b1.currPage->data);
     pt(b1.forward(8));
     pt(b1.back(4));
     


    return 0;
}


