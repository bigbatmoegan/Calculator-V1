#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command: public Binary_Op_Command
{
public:
	//Default constructor
	Subtract_Command (void);
	
	//Constructor with stack
	Subtract_Command (Stack<int> * s);
	
	//Destructor
	~Subtract_Command (void);
	
	//Evauation
	virtual int evaluate (int n1, int n2) const;
	
private:

	Stack<int> * stack_;
};

#endif