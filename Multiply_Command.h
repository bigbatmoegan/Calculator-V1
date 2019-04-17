#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command: public Binary_Op_Command
{
public:
	//Default constructor
	Multiply_Command (void);
	
	//Constructor with stack
	Multiply_Command (Stack<int> * s);
	
	//Destructor
	~Multiply_Command (void);
	
	//Evaluation
	virtual int evaluate (int n1, int n2) const;
	
private:

	Stack<int> * stack_;
};

#endif