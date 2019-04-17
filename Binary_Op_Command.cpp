#include "Binary_Op_Command.h"

#include "Array_Base.h"
#include "Array.h"
#include <iostream>
#include "Stack.h"

Binary_Op_Command::Binary_Op_Command (void)
:n1(0), n2(0), s_(new Stack<int>), result (0)
{
	//Default constructor
}

Binary_Op_Command::Binary_Op_Command (Stack<int> * s)
: s_(s), n1(0), n2(0), result (0)
{
	//Constructor with actual stack
}

Binary_Op_Command::~Binary_Op_Command (void)
{
	delete[] s_;
}

void Binary_Op_Command::execute (void)
{
	n2=s_->top();
	s_->pop();
	n1=s_->top();
	s_->pop();
	result=this->evaluate(n1,n2);
	s_->push(result);
}
	