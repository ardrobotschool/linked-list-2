#include <iostream>
#include "Node.hpp"
#include "Student.hpp"

using namespace std;

int main(){
  Node* head = NULL;
}

void add(Student* student, Node* &head){
  Node* node = new Node(student);
  node->setNext(head);
  head = node;
}

void print(Node* head){
  while(head != NULL){
    cout << head->getStudent()->getFirstName() << endl;
    head = head->getNext();
  }
}

void deleteStudent(int id, Node* &head){
  Node* prev = NULL, *current = head;
  while(true){
    if(current->getStudent()->id == id){
      if(prev!=NULL){
	prev->setNext(current->getNext());
      }
      else{
	head = current->getNext();
      }
      delete current;
      return;
    }
    if(current->getNext() != NULL){
      prev = current;
      current = current->getNext();
    }
    else{
      return;
    }
  }
}
