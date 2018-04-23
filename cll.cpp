//program for a circular linked list
//We will add a 2 to the beginning of the linked list
//We will remove all odd numbers from the LL

#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* prev;
  Node* next;
  Node(int num) {
    value = num;
    prev = NULL;
    next = NULL;
  }
};

void print(Node* head) {
  if (head == NULL) {
    cout << "The linked list is empty." << endl;
  } else {
    Node* temp = head;
    cout << head->value << ", ";
    while (temp->next != head) {
      cout << temp->next->value << ", ";
      temp = temp->next;
    }
  }
}

void add(Node *& head, Node* listhead, int num) {
  if (head == NULL) {//Make from empty list
    cout << "test 1" << endl;
    head = new Node(num);
    head->next = head;
    head->prev = head;
  } else if (head->next == listhead) {//If on last node, add
    Node* temp = head;
    head = new Node(num);
    head->next = listhead;
    head->prev = temp;
  } else {//Else go to next node
    add(head->next, listhead, num);
    cout << "test 2";
  }
}

void add2(Node *& head) {
  Node* temp = head;
  head = new Node(2);
  head->next = temp;
}

void remove(Node *& head) {
  if (head == NULL) {
    cout << "There is nothing more to remove" << endl;
  } else {
    Node* temp = head;
    if (((temp->value) % 2) != 0) {
      head = temp->next;
      delete temp;
      remove(head);
    } else {
      remove(temp->next);
    }
  }
}

int main() {
  char input;

  Node* head = NULL;
  
  cout << "This is a program that makes a circular linked list" << endl;
  add(head, head, 9);
  cout << "test 1.5";
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
