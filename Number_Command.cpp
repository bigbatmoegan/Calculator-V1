#include "Number_Command.h"
#include <iostream>

Number_Command::Number_Command (void)
:Expr_Command()
{
	
}

Number_Command::Number_Command (Stack <int> *s, int num)
:s_(s), number(num)
{
	number=num;
}

Number_Command::~Number_Command (void)
{
	
}

void Number_Command::execute (void)
{
	s_->push(number);
}