/*Student class. Holds a student's data.*/
#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student {
public:
  const char* fname;
  const char* lname;
  float gpa;
  int id;
  Student(char* fname, char* lname, float gpa, int id);
  ~Student();
};

#endif
