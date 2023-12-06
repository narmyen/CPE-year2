#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node
{
  public:
  int data;
  Node *next;
};

void insertFront(Node** head, int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void delete(Node** head, int idx){
  int idx = 0;
  
}

void printList(Node* node){
    while(node!=NULL){
      cout << node->data << "\n";
      node = node->next;
    }
    cout << endl;
}

int main(){
  Node* head = NULL;

  int m, data;
  char c;

  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> c >> data;
    if(c == 'I'){
      insertFront(&head ,data);
    }
  }

  printList(head); 

  return 1;
}