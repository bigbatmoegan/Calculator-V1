#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"
#include "Stack.h"

class Add_Command: public Binary_Op_Command
{
public:
	//Default constructor
	Add_Command (void);
	
	//Constructor with stack
	Add_Command (Stack<int> * s);
	
	//Destructor
	~Add_Command (void);
	
	//Evaluation
	virtual int evaluate (int n1, int n2) const;

private:

	Stack<int> * stack_;
};

#endif