#include <iostream>
#include "Node.hpp"
#include "Student.hpp"

using namespace std;

void add(Student* student, Node* &head);
void print(Node* head);
void deleteStudent(int id, Node* &head);
void newStudent(Node* &head);

int main(){
  Node* head = NULL;
  add(new Student("Danila", "Fedorin", 3.76, 452434), head);
  add(new Student("Artur", "Drobot", 3.86, 405502), head);
  add(new Student("Jason", "Galbraith", 5.00, 999555), head);
  print(head);
}

void add(Student* student, Node* &head){
  Node* node = new Node(student);
  node->setNext(head);
  head = node;
}

void print(Node* head){
  while(head != NULL){
    cout << head->getData()->lname << ", " << head->getData()->fname << " (" << head->getData()->id << ") GPA:";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << head->getData()->gpa << "." << endl;
    head = head->getNext();
  }
}

void deleteStudent(int id, Node* &head){
  Node* prev = NULL, *current = head;
  while(true){
    if(current->getData()->id == id){
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

void newStudent(Node* &head){
  char* fname = new char[128], *lname = new char[128];
  float gpa;
  int id;
  cout << "Enter student\'s first name: ";
  cin >> fname;
  cout << endl;
  cout << "Enter student\'s last name: ";
  cin >> lname;
  cout << endl;
  cout << "Enter student\'s ID: ";
  cin >> id;
  cout << endl;
  cout << "Enter student\'s GPA: ";
  cin >> gpa;
  cout << endl;
  add(new Student(fname, lname, gpa, id), head);
}
