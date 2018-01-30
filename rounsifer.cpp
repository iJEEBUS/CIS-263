#include <iostream>
#include "MyStack.h"
using namespace std;

/* Stack implemented using a vector */

/*****************************************************************
 * Pushes an item to the top of the stack
 * @param item - item to add to stack
 *****************************************************************/
void MyStack_vector::push(const int &item) {
    this->elements.push_back(item);
}
/*****************************************************************
 * Removes the top element of the stack
 *****************************************************************/
void MyStack_vector::pop() {
    if (this->elements.size() > 0)
        this->elements.pop_back();
    else
        cout<<"The Stack is now empty! No item is popped!"<<endl;
}
/*****************************************************************
 * Returns the top element on the current stack
 * @return int - top element of stack
 *****************************************************************/
int MyStack_vector::top() const {
    return this->elements.back();
}
/*****************************************************************
 * Returns whether the current stack is empty
 * @return bool
 *****************************************************************/
bool MyStack_vector::empty() const {
    if (this->elements.size() == 0)
        return true;
    return false;
}
/*****************************************************************
 * Returns the size of the current stack
 * @return int - size of stack
 *****************************************************************/
int MyStack_vector::GetSize() const {
    return this->elements.size();
}


/* Stack implemented using a list */

/*****************************************************************
 * Pushes an item to the top of the stack.
 * @param item - item to add to stack
 *****************************************************************/
void MyStack_list::push(const int &item) {
    this->elements.push_back(item);
}
/*****************************************************************
 * Removes the top element of the stack
 *****************************************************************/
void MyStack_list::pop() {
    if (this->elements.size() > 0)
        this->elements.pop_back();
    else
        cout<<"The Stack is now empty! No item is popped!"<<endl;
}
/*****************************************************************
 * Returns the top element of the current stack
 * @return int - top element of stack
 *****************************************************************/
int MyStack_list::top() const {
    return this->elements.back();
}
/*****************************************************************
 * Returns whether the current stack is empty
 * @return bool
 *****************************************************************/
bool MyStack_list::empty() const {
    if (this->elements.size() == 0)
        return true;
    return false;
}
/*****************************************************************
 * Returns the size of the current stack
 * @return int - size of stack
 *****************************************************************/
int MyStack_list::GetSize() const {
    return this->elements.size();
}