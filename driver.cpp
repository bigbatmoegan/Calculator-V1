#include "Array_Base.h"
#include "Array.h"
#include "Stack.h"
#include "Expr_Command.h"
#include "Binary_Op_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>



int main ()
{
	Stack <int> *result=new Stack<int>;
	Array <Expr_Command *> array;
	Stack_Expr_Command_Factory factory (result);
	bool keepGoing=true;
	while(keepGoing)
	{
		result->clear();
		std::string expression="";
		std::cout << "Enter an Expression: ";
		std::getline(std::cin, expression);
		if(expression=="QUIT")
		{
			delete result;
			return 0;
		}
		else
		{
			factory.infix_to_postfix(expression, factory, array);
			int res=result->top();
			std::cout<<res<<std::endl;
		}
	}
}