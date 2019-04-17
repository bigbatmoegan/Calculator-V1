#include "Divide_Command.h"
#include <iostream>

Divide_Command::Divide_Command (void)
{
	
}

Divide_Command::Divide_Command (Stack<int> * s)
:Binary_Op_Command (s)
{
	
}

Divide_Command::~Divide_Command (void)
{
	
}

int Divide_Command::evaluate(int n1, int n2) const
{
	return n1/n2;
}