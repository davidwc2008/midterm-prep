//program for a singly linked list
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
    cout << "The linked list is empty." << endl;
  } else {
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->value << ", ";
      temp = temp->next;
    }
  }
}

void add(Node *& head, int num) {
  if (head == NULL) {
    head = new Node(num);
  } else {
    Node* temp = head;
    add(temp->next, num);
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
  
  cout << "This is a program that makes a singly linked list" << endl;
  add(head, 9);
  add(head, 10);
  add(head, 3);
  add(head, 2);
  add(head, 5);
  
  while (input != 'Q') {
    cout << "\nPress P to print the list, A to add the 2 to the beginning, R to remove every odd number, Q to quit" << endl;
    cin >> input;
    
    if (input == 'P') {
      print(head);
    } else if (input == 'A') {
      add2(head);
    } else if (input == 'R') {
      remove(head);
    }
  }
  return 0;
}
