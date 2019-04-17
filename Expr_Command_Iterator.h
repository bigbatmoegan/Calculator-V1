#ifndef _EXPR_COMMAND_ITERATOR_H_
#define _EXPR_COMMAND_ITERATOR_H_

#include "Stack.h"
template <typename T>
class Expr_Command_Iterator
{
public:
	Expr_Command_Iterator (void);
	
	Expr_Command_Iterator (Stack <T> &s);
	
	~Expr_Command_Iterator (void);
	
	bool is_done (void);
	
	bool advance (void);
	
	T & operator * (void);
	
	T * operator -> (void);

private:
	Stack <T> & s_;
	
	size_t curr_;
	
}; 
#include "Expr_Command_Iterator.cpp"

#endif