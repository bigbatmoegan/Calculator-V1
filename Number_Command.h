#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Number_Command: public Expr_Command
{
public:
	//Default construtor
	Number_Command (void);
	
	//Constructor with value and stack
	Number_Command(Stack <int> * s, int num);
	
	//push number to stack
	void execute (void);
	
	//Destructor
	~Number_Command (void);
	
private:
	int number;
	
	Stack <int> * s_;
};

#endif 