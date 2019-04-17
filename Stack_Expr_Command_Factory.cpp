#include "Stack_Expr_Command_Factory.h"
#include "Binary_Op_Command.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (void)
:stack_(nullptr)
{
	
}

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack<int> * stack)
:stack_(stack)
{
	
}

Number_Command* Stack_Expr_Command_Factory::create_number_command (int num)
{
	return new Number_Command(stack_, num);
}

Add_Command* Stack_Expr_Command_Factory::create_add_command (void)
{
	return new Add_Command(stack_);
}

Subtract_Command* Stack_Expr_Command_Factory::create_subtract_command (void)
{
	return new Subtract_Command(stack_);
}

Multiply_Command* Stack_Expr_Command_Factory::create_multiply_command (void)
{
	return new Multiply_Command(stack_);
}

Divide_Command* Stack_Expr_Command_Factory::create_divide_command (void)
{
	return new Divide_Command(stack_);
}

Modulus_Command* Stack_Expr_Command_Factory::create_modulus_command (void)
{
	return new Modulus_Command(stack_);
}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
	
}

int Stack_Expr_Command_Factory::precedence(std::string c)
{
	if(c=="*" || c=="/" || c=="%")
	{
		return 3;
	}
	else if(c=="+" || c=="-")
	{
		return 2;
	}
	else //number
	{
		return 1;
	}
}
	

bool Stack_Expr_Command_Factory::infix_to_postfix (const std::string infix, Expr_Command_Factory & factory, Array<Expr_Command *> & postfix)
{
	std::istringstream input(infix);
	std::string token;
	std::string postfix2;
	Expr_Command * cmd=0;
	Stack <Expr_Command *> temp;
	Stack <std::string> temp2;
	temp2.push("A");
	while(!input.eof()){
		input >> token;
		//check if a number and add to postfix stack
		if(token!="*" && token!="/" && token!="+" && token!="-" && token!="(" && token!=")" && token!="%")
		{
			postfix2+=token;
		}
		//check if (
		else if(token=="(")
		{
			temp2.push(token);
		}
		//check for ending ) and pop until matching ( is found
		else if(token==")")
		{
			while(!temp2.is_empty() && temp2.top()!="(")
			{
				std::string s= temp2.top();
				temp2.pop();
				postfix2+=s;
			}
			if(temp2.top()=="(")
			{
				std::string s=temp2.top();
				temp2.pop();
			}
		}
		else //any other poerand is scanned
		{
			//check for precedence
			while(temp2.top()!="A" && precedence(token)<=precedence(temp2.top()))
			{
				std::string s =temp2.top();
				temp2.pop();
				postfix2+=s;
			}
			temp2.push(token);
			std::string s=temp2.top();
		}
	}
	while(temp2.size()!=1)
	{
		std::string s=temp2.top();
		temp2.pop();
		postfix2+=s;
	}
	//Take converted string and make objects as needed
	for(int i=0;i<postfix2.length();i++)
	{
		if(postfix2[i]=='+')
		{
			cmd=factory.create_add_command();
			postfix[i]=cmd;
		}
		else if(postfix2[i]=='-')
		{
			cmd=factory.create_subtract_command();
			postfix[i]=cmd;
		}
		else if(postfix2[i]=='*')
		{
			cmd=factory.create_multiply_command();
			postfix[i]=cmd;
		}
		else if(postfix2[i]=='/')
		{
			cmd=factory.create_divide_command();
			postfix[i]=cmd;
		}
		else if(postfix2[i]=='%')
		{
			cmd=factory.create_modulus_command();
			postfix[i]=cmd;
		}
		else //rest is a number object
		{
			//convert char into int 
			int number=postfix2[i]-'0';
			cmd=factory.create_number_command(number);
			postfix[i]=cmd;
		}
	}
	//run through array and do calculations
	for(int a=0;a<postfix2.length();a++)
	{
		postfix[a]->execute();
		delete postfix[a];
	}
	return true;
}