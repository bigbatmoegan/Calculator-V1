#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

class Divide_Command: public Binary_Op_Command
{
public:
	//Default constructor
	Divide_Command (void);
	
	//Constructor with stack
	Divide_Command (Stack<int> * s);
	//Destructor
	~Divide_Command (void);
	
	//Evaluation
	virtual int evaluate (int n1, int n2) const;

private:

	Stack<int> * stack_;
	
};

#endif