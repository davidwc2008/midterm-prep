//program for a doubly linked list
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

void print(Node* head) { //print forwards
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
    while (temp->next != NULL) {
      temp = temp->next;
    }
    if (temp->next == NULL) {
      temp->next = new Node(num);
      temp->next->prev = temp;
    }
  }
}

void add2(Node *& head) {
  Node* temp = head;
  head = new Node(2);
  head->next = temp;
  temp->prev = head;
}

void remove(Node *& head) {
  if (head == NULL) {
    cout << "There is nothing more to remove" << endl;
  } else {
    if (((head->value) % 2) != 0) {
      cout << "odd:" << head->value << endl;
      if (head->prev == NULL && head->next == NULL) {
	cout << "Single node" << head->value;
	delete head;
	head = NULL;
      } else if (head->prev == NULL) { //begining
	cout << "Beginnning node" << head->value;
	head->next->prev = NULL;
	head = head->next;
	Node* next = head->next;
	delete head;
	remove(next);
      } else if (head->next == NULL) { //end
	cout << "End node" << head->value;
	Node* temp = head;
	temp->prev->next = NULL; //prev next needs temp
	delete temp;
      } else {
	/*
	cout << "Middle node:" << head->value << endl;
	Node* temp = head;
	temp->prev->next = temp->next;
	cout << "temp's value: " << temp->value << endl;
	cout << "temp's prev next: " << temp->prev->next->value << endl;
	temp->next->prev = temp->prev;
	Node* next = head;
	cout << temp->value << "calling on" << next->value << endl;
	*/
	Node* temp = head;
	head->next->prev = head->prev;
	head = head->next;
	delete temp;
	remove(head);
      }
    } else {
      cout << "even:" << head->value;
      remove(head->next);
    }
  }
}

int main() {
  char input;

  Node* head = NULL;
  
  cout << "This is a program that makes a doubly linked list" << endl;
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
