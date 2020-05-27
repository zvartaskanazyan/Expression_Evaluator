#pragma once
#include <iostream>


class PostFixConverter 
{
public:
	 PostFixConverter(std::string infix);
	 std::string convert(std::string infix) ;
	 double evalute(std::string infix) ;
	 int priority(char);
	 bool isOperand(char);
	 bool isOperator(char);
	 double applyOp(double, double, char);
	 
private:
	std::string m_infix;
};

