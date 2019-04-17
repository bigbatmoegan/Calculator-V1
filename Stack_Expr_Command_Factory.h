#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
#include "Stack.h"
#include "Expr_Command.h"
#include "Binary_Op_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Modulus_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Number_Command.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
 
class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:

	//Default constructor
	Stack_Expr_Command_Factory (void);
	
	//Constructor with stack
	Stack_Expr_Command_Factory (Stack<int> * stack);
	
	//Create number and operations 
	virtual Number_Command* create_number_command (int num);
	
	virtual Add_Command* create_add_command (void);
	
	virtual Subtract_Command* create_subtract_command (void);
	
	virtual Multiply_Command* create_multiply_command (void);
	
	virtual Divide_Command* create_divide_command (void);
	
	virtual Modulus_Command* create_modulus_command (void);
	
	//Conversion
	bool infix_to_postfix (const std::string infix, Expr_Command_Factory & factory, Array<Expr_Command *> & postfix);
	
	//Function that will convert passed in string to postfix
	std::string conversion (std::string infix);
	
	//Precedence for conversion
	int precedence(std::string c);
	//Destructor 
	~Stack_Expr_Command_Factory (void);
	
private:
	Stack<int> * stack_;
	
};

#endif