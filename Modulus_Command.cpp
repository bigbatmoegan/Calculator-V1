#include "Modulus_Command.h"
#include "Binary_Op_Command.h"

Modulus_Command::Modulus_Command (void)
{
	
}

Modulus_Command::Modulus_Command (Stack<int> * s)
:Binary_Op_Command (s)
{
	
}

Modulus_Command::~Modulus_Command (void)
{
	
}

int Modulus_Command::evaluate(int n1, int n2) const
{
	return n1%n2;
}