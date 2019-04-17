#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Binary_Op_Command.h"

class Modulus_Command: public Binary_Op_Command
{
public:
	//Default constructor
	Modulus_Command (void);
	
	//Constructor with stack
	Modulus_Command (Stack<int> * s);
	
	//Destructor
	~Modulus_Command (void);
	
	//Evaluation
	virtual int evaluate (int n1, int n2) const;

private:

	Stack<int> * stack_;
	
};

#endif