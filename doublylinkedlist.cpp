#include<iostream> 
using namespace std;
class node{
public:
int data;
    node* prev;
    node* next;
    node(int data){
        this -> data = data ;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertathead(node* & head, int data){
node * temp = new node(data);
temp -> prev = NULL;
temp -> next = head;
head -> prev = temp;
head = temp;
}

void insertattail(node * &tail, int data){
    node *temp = new node(data);
    tail -> next =  temp;
    temp -> prev = tail;
    temp -> next = NULL;
    temp = tail;
}

void insertatposition(node * & head, int data, int position){
    node*temp = head;
    node *gate = new node(data);
    node *gate2 = head -> next;
    int count = 1;
    while (count < position -1 ){
        temp = temp -> next;
        gate2 = gate2 -> next;
        count ++;
    }
    temp -> next = gate;
    gate -> prev = temp;
    gate -> next = gate2;
    gate2-> prev = gate;
}

void print(node* & head){
    node * temp = head ;
    while (temp!= NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
    }
    cout << endl;
}

void deleteatfirst(node * &head){
    node * temp = head -> next;
temp -> prev = NULL;
delete head;
head = temp;
}

void deleteattail(node * &head){
    node *temp = head;
    node *gate = head -> next;
    while(gate -> next != NULL){
    temp = temp -> next;
    gate = gate -> next;
    }
    temp -> next = NULL;
    gate -> prev = NULL;
    delete gate;
}

void deleteatposition(node* &head , int position){
    node*temp = head;
     node *gate = head -> next;
     node * gate2 = gate -> next;
     int count = 1;
     while(count < position-1){
        temp = temp -> next;
        gate = gate -> next;
        gate2 = gate2-> next;
        count ++;
    }
     temp -> next = gate2;
     delete gate ;
}

int main(){
node*node1 = new node(89);
node*head = node1;
node*tail = node1;
insertathead(head,44);
insertathead(head,34);
insertathead(head,56);
insertathead(head,45);
insertattail(tail, 999);
print(head);

insertatposition(head, 111,3);
print(head);
deleteatfirst(head);
print(head);
deleteattail(tail);
print(head);
deleteatposition(head , 3);
print(head);
}