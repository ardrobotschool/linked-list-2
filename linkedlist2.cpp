#include <iostream>
#include "Node.hpp"
#include "Student.hpp"
#include <cstring>

using namespace std;

void add(Student* &student, Node *& head, Node* &curr);
void print(Node* head);
bool deleteStudent(int id, Node* &head, Node* null);
void newStudent(Node* &head);
void eraseAll(Node* &head);
float avg(Node* head, float curavg, int count);

int main(){
  Node* head = NULL;
  Node** ptr = &head;
  //Student* danila = new Student("Danila", "Fedorin", 3.76, 452434);
  //add(danila, ptr);
  //add(new Student("Artur", "Drobot", 3.86, 405502), ptr);
  //add(new Student("Jason", "Galbraith", 5.00, 999555), ptr);
  //deleteStudent(head);
  //Node *node = new Node(danila);
  //cout << node->getNext() << endl;
  print(head);
  char input[128];
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, \"AVERAGE\" to print out the average GPA of all students in the list, or \"DELETE\" to delete a student entry." << endl;
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
    else if(strcmp(input, "average") == 0){
      if(head == NULL){
	cout << "The list is empty." << endl;
      }
      else{
	cout << "Average GPA: " << avg(head, 777, 0) << endl;
      }
    }
    else if(strcmp(input, "delete") == 0){
      //Get an id.
      int id;
      cout << "Type the ID of the student to delete: ";
      cin >> id;
      cout << endl;
      if(head == NULL){
		cout << "The list is empty." << endl;
      }
      else if(deleteStudent(id, head, NULL)){
		cout << "Student deleted." << endl;
	  }
	  else{
		cout << "No student found with given ID." << endl;
	  }
    }
    else{
      cout << "Command not found." << endl;
    }
  }
}

void add(Student* &student, Node *& head, Node* &current){
  if(head == NULL){
    Node* node = new Node(student);
    node->setNext(NULL);
    head = node;
    return;
  }
  if(current == head){
    if(student->id <= head->getData()->id){
      Node* node = new Node(student);
      node->setNext(head);
      head = node;
      return;
    }
    else{
      if(current->getNext() != NULL){
	if(student->id <= current->getNext()->getData()->id){
	  Node* node = new Node(student);
	  node->setNext(current->getNext());
	  current->setNext(node);
	  return;
	}
	else{
	  Node* next = current->getNext();
	  add(student, head, next);
	  return;
	}
      }
      else{
	Node* node = new Node(student);
	node->setNext(NULL);
	head->setNext(node);
	return;
      }
    }
  }
  else if(current->getNext()!=NULL){
    if(student->id <= current->getNext()->getData()->id){
      Node* node = new Node(student);
      node->setNext(current->getNext());
      current->setNext(node);
      return;
    }
    else{
      Node* next = current->getNext();
      add(student, head, next);
      return;
    }
  }
  else{
    Node* node = new Node(student);
    node->setNext(NULL);
    current->setNext(node);
  }
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
  else{
    cout << endl;
  }
}

bool deleteStudent(int id, Node* &current, Node* prev){
  if(current == NULL){ //Reached end of list.
    return false;
  }
  if(current->getData()->id == id){
    if(prev != NULL){
		prev->setNext(current->getNext());
		delete current;
	}
	else{ // Current == head
		prev = current;
		current = current->getNext();
		delete prev;
	}
	return true;
  }
  else{
	  Node* nextPtr = current->getNext();
	  return deleteStudent(id, nextPtr, current);
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
  Student *student = new Student(fname, lname, gpa, id);
  add(student, head, head);
}

void eraseAll(Node* &head){
  if(head!=NULL){
    Node* next = head->getNext();
    delete head;
    eraseAll(next);
  }
}

float avg(Node* node, float currAvg, int count){
  //We assume that head != NULL.
  if(node == NULL){
    return currAvg;
  }
  return avg(node->getNext(), (node->getData()->gpa + currAvg*count)/(count + 1), count+1);
}
