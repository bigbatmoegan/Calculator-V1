#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command: public Expr_Command
{
public:
	//Default construtor
	Binary_Op_Command (void);
	
	//Execute function
	void execute (void);
	
	//Evaluate function to be created in derived classes
	virtual int evaluate (int n1, int n2) const =0;
	
	~Binary_Op_Command (void);

protected: 
	//Constructor with stack
	Binary_Op_Command(Stack <int> * s);
	
private:
	Stack <int> * s_; 
	
	int n1;
	
	int n2;
	
	int result;
	
};

#endif 