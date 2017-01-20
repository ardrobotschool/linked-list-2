#include <iostream>
#include "Student.hpp"

using namespace std;

Student::Student(char* newFname, char* newLname, float newGpa, int newId) : fname(newFname), lname(newLname) {
  gpa = newGpa;
  id = newId;
}

Student::~Student(){
  delete fname;
  delete lname;
}
