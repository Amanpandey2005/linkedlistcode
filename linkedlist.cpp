#include<iostream>
using namespace std;

class Node{
public:
int data ;
Node* link;
// constructor
Node( int data){
     this -> data = data;
     this -> link = NULL;
}
// destructor


};

void insertathead(Node* &head , int data){
    Node*temp = new Node(data);
    temp -> link = head;
    head = temp;
}

void print(Node* &head ){
Node* temp = head;
while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> link;
}
 }

 void insertattail(Node* &tail, int data){
   
    Node *temp = new Node(data);
    tail -> link = temp;
    tail = temp;
 }

 // by inserting at position
 void insertatposition(Node* &head , int position, int value){
     if(position == 1 ){
        insertathead(head,value);
    }
    Node *temp = head;
    int count = 1;

    while(count < position -1){
        temp = temp -> link ;
        count ++;
    }
    Node* nodetoinsert= new Node(value);
     nodetoinsert-> link = temp -> link;
     temp -> link = nodetoinsert;
 }


 // code for deletion in linked list
 void deletionatstart(Node* &head){
    Node* temp = head;
    head = head -> link;
    free(temp);
 }

 // node for delete at position
  void deleteatposition(Node* & head, int position){
   Node* temp = head ;
   Node * gate = temp -> link;
   int count = 1;
   while(count < position-1){
    temp = temp -> link;
    gate = gate -> link;
    count ++;
   }
    temp -> link = gate -> link;
    free(gate);
  }
 
 void deletionatlast(Node* &head){
    Node* p = head;
    Node* ptr = head->link;
    while(ptr->link != nullptr){
        p = p->link;
        ptr = ptr->link;
    }
    p->link = nullptr;
    delete ptr;
}
int main(){
    Node* node1 = new Node(10);
   // cout << node1 -> data << endl;
   // cout << node1-> link << endl;

    Node*head = node1;
    insertathead(head, 34);
   
    Node*tail = node1;
    insertattail(tail , 65);
   // print(head);
    cout << endl;

    insertatposition(head , 2, 45);
     print(head);
     cout << endl;

     //deletionatstart(head);
     //print(head);


     //deleteatposition(head, 2);
     //print(head);

     deletionatlast(head);
     print(head);
}