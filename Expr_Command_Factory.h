#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Expr_Command.h"
#include "Binary_Op_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Modulus_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Number_Command.h"
#include "Stack.h"
class Expr_Command_Factory
{
public:
	Expr_Command_Factory (void);
	
	virtual ~Expr_Command_Factory (void)=0;
	
	//create number
	virtual Number_Command* create_number_command (int num)=0;
	
	//create add
	virtual Add_Command* create_add_command (void)=0;
	
	//create sub
	virtual Subtract_Command* create_subtract_command (void)=0;
	
	//create multiply
	virtual Multiply_Command* create_multiply_command (void)=0;
	
	//create divide
	virtual Divide_Command* create_divide_command (void)=0;
	
	//create modulus
	virtual Modulus_Command* create_modulus_command (void)=0;
	
	//infix to postfix
	virtual bool infix_to_postfix (const std::string infix, Expr_Command_Factory & factory, Array<Expr_Command *> & postfix)=0;
};

#endif
