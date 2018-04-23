//program for a singly linked circular linked list
//We will add a 2 to the beginning of the linked list
//We will remove all odd numbers from the LL

#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next;
  Node(int num) {
    value = num;
    next = NULL;
  }
};

void print(Node* head) {
  if (head == NULL) {
    cout << "There is nothing in the list" << endl;
  } else
}

void add(Node *& head, Node* listhead, int num) {
  if (head == listhead) {
    head = new Node(num);
  } else if (head->next = listhead) {
    Node* temp = new Node(num);
    head->next = temp;
    temp->next = listhead;
  } else {
    add(head->next, listhead, num);
  }
}

void add2(Node *& head) {

}

void remove(Node *& head) {

}

int main() {
  char input;

  Node* head = NULL;
  
  cout << "This is a program that makes a circular linked list" << endl;
  add(head, head, 9);
  add(head, head, 10);
  add(head, head, 3);
  add(head, head, 2);
  add(head, head, 5);
  
  while (input != 'Q') {
    cout << "\nPress P to print the list, A to add the 2 to the beginning, R to remove every odd number, Q to quit" << endl;
    cin >> input;
    
    if (input == 'P') {
      print(head);
    } else if (input == 'A') {
      //add2(head);
    } else if (input == 'R') {
      //remove(head);
    }
  }
  return 0;
}
