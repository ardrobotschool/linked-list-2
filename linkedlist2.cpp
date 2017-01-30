#include <iostream>
#include "Node.hpp"
#include "Student.hpp"
#include <cstring>

using namespace std;

void add(Student* &student, Node* &head);
void print(Node* head);
bool deleteStudent(int id, Node* &head, Node* null);
void newStudent(Node* &head);
void eraseAll(Node* &head);

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

void add(Student* &student, Node* &current){
  if(current == NULL){ //current == head
    Node* node = new Node(student);
    node -> setNext(NULL);
    current = node;
    return;
  }
  if(current->getNext() == NULL){
    Node* node = new Node(student);
    if(student->id >= current->getData()->id){
      node->setNext(NULL);
      current->setNext(node);
    }
    else{ //current == head
      node->setNext(current);
      current = node;
    }
    return;
  }
  if(student->id <= current->getNext()->getData()->id){
    Node* node = new Node(student);
    node->setNext(current->getNext());
    current->setNext(node);
    return;
  }
  Node* next = current->getNext();
  add(student, next);
}

void print(Node* current){
  if(current != NULL){
    cout << current->getData()->lname << ", " << current->getData()->fname << " (" << current->getData()->id << ") GPA:";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << current->getData()->gpa << "." << endl;
    print(current->getNext());
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
  add(student, head);
}

void eraseAll(Node* &head){
  if(head!=NULL){
    Node* next = head->getNext();
    delete head;
    eraseAll(next);
  }
}

int avg(Node* node, int currAvg, int count){
	if(node == NULL){
		return currAvg;
	}
	if(currAvg == -1){
		//return avg(node->getNext(), 
	}
}