#include <iostream>
#include "Node.hpp"
#include "Student.hpp"
#include <cstring>

using namespace std;

void add(Student* student, Node* &head);
void print(Node* head);
void deleteStudent(Node* &head);
void newStudent(Node* &head);
void eraseAll(Node* &head);

int main(){
  Node* head = NULL;
  /*add(new Student("Danila", "Fedorin", 3.76, 452434), head);
  add(new Student("Artur", "Drobot", 3.86, 405502), head);
  add(new Student("Jason", "Galbraith", 5.00, 999555), head);
  deleteStudent(head);
  print(head);*/
  char input[128];
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, or \"DELETE\" to delete a student entry." << endl;
  cout << "Enter \"q\" at any time to quit the program." << endl;
  while(true){ //Primary loop
    cout << "Type a command: ";
    cin >> input;
    cout << endl;
    //Convert input to lower case
    int i = 0;
    while(input[i]){
      input[i] = tolower(input[i]);
      i++;
    }
    if(strcmp(input, "q") == 0 || strcmp(input, "quit") == 0){//quit
      //Wipe everything--delete every student in the list.
      eraseAll(head);
      return 0;
    }
    else if(strcmp(input, "add") == 0){
      newStudent(head);
    }
    else if(strcmp(input, "print") == 0){
      print(head);
    }
    else if(strcmp(input, "delete") == 0){
      deleteStudent(head);
    }
    else{
      cout << "Command not found." << endl;
    }
  }
}

void add(Student* student, Node* &head){
  Node* node = new Node(student);
  node->setNext(head);
  head = node;
}

void print(Node* current){
  if(current != NULL){
    cout << current->getData()->lname << ", " << current->getData()->fname << " (" << current->getData()->id << ") GPA:";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << current->getData()->gpa << "." << endl;
    print(current->getNext());
  }
}

void deleteStudent(Node* &head){
  //Get an id.
  int id;
  cout << "Type the ID of the student to delete: ";
  cin >> id;
  cout << endl;
  if(head == NULL){
    cout << "The list is empty." << endl;
    return;
  }
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
      cout << "Student removed form the database." << endl;
      return;
    }
    if(current->getNext() != NULL){
      prev = current;
      current = current->getNext();
    }
    else{
      cout << "No student found with the given ID." << endl;
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

void eraseAll(Node* &head){
  Node* prev;
  while(head!=NULL){
    prev = head;
    head = head->getNext();
    delete prev;
  }
}
