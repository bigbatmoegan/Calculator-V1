template <typename T>
Expr_Command_Iterator <T>::Expr_Command_Iterator (void)
: s_(nullptr), curr_(0)
{
	
}

template <typename T>
Expr_Command_Iterator <T>::Expr_Command_Iterator (Stack <T> &s)
: s_(s), curr_(0)
{
	
}

template <typename T>
Expr_Command_Iterator <T>::~Expr_Command_Iterator (void)
{
	delete[] s_;
}

template <typename T>
bool Expr_Command_Iterator <T>::is_done (void)
{
	return this->curr_ >= this->s_.cur_size_();
}

template <typename T>
bool Expr_Command_Iterator <T>::advance (void)
{
	++ this->curr_;
}

template <typename T>
T & Expr_Command_Iterator <T>::operator * (void)
{
	return this->s.data_[this->curr_];
}

template <typename T>
T * Expr_Command_Iterator <T>::operator -> (void)
{
	return &this->a_.data_[this->curr_];
}


