#include "Multiply_Command.h"
#include "Binary_Op_Command.h"

Multiply_Command::Multiply_Command (void)
{
	
}

Multiply_Command::Multiply_Command (Stack<int> * s)
:Binary_Op_Command (s)
{
	
}

Multiply_Command::~Multiply_Command (void)
{
	
}

int Multiply_Command::evaluate(int n1, int n2) const
{
	return n1*n2;
}