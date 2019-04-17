#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

class Expr_Command
{
public:
	//Default constructor
	Expr_Command(void);
	
	//Constructor with stack
	Expr_Command(Stack <int> * s);
	//Execute function
	virtual void execute (void)=0;
	
	//Destructor
	~Expr_Command(void);
	
protected:
	Stack <int> * s_;
};

#endif