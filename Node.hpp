/*Node: Linked list :w
node containing void pointer to data and pointer to next node
 * */

#ifndef NODE_HPP
#define NODE_HPP

#include "student.hpp"

class Node {
	public:
		Node(Student* data); //create node with data
		~Node(); //destroy node and delete its data
		Node* getNext(); //get next node pointer
		Student* getData(); //get pointer to data
		Node* setNext(Node* next); //set the pointer to the next node, returns old pointer to next
	private:
		Node* next;
		Student* data;
};

#endif
