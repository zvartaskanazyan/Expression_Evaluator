#include "PostFixConverter.h"
#include <stack>


PostFixConverter::PostFixConverter(std::string infix){
	m_infix = infix;
}

int PostFixConverter::priority(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	else
		return 0;
}

bool PostFixConverter::isOperand(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

bool PostFixConverter::isOperator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-' || c == '^')
		return true;
	else
		return false;
}

double PostFixConverter::applyOp(double operand1, double operand2, char operation)
{
	switch (operation)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	case '^':
		return pow(operand1, operand2);
	default:
		return 0;
	}
}

std::string PostFixConverter::convert(std::string infix)
{
		std::stack<char> opStack;
		std::string postfix;

		for (size_t i = 0; i < infix.size(); ++i)
		{
			if (infix[i] == ' ')
				continue;

			else if (infix[i] == '(')
			{
				opStack.push('(');
			}
			else if (isOperator(infix[i]))
			{
				while (!opStack.empty() && priority(infix[i]) <= priority(opStack.top()) && opStack.top() != '(')
				{
					postfix += opStack.top();
					postfix += ' ';
					opStack.pop();
				}
				opStack.push(infix[i]);
			}

			else if (infix[i] == ')')
			{
				while (!opStack.empty() && opStack.top() != '(')
				{
					postfix += opStack.top();
					postfix += ' ';
					opStack.pop();
				}
				opStack.pop();
			}


			else
			{
				while (i < infix.size() && isOperand(infix[i]))
				{
					postfix += infix[i];
					++i;
				}
				--i;
				postfix += ' ';
			}


		}
			while (!opStack.empty())
			{
				postfix += opStack.top();
				postfix += ' ';
				opStack.pop();
			}
		return postfix;
}

double PostFixConverter::evalute(std::string postfix)
{
	std::stack<double> values;
		for (size_t i = 0; i < postfix.length(); ++i)
		{
			if (postfix[i] == ' ')
				continue;
					   
			else if (isOperand(postfix[i])) {
				int val = 0;
				while (i < postfix.length() && isOperand(postfix[i]))
				{
					val = (val * 10) + (postfix[i] - '0');
					++i;
				}
				values.push(val);
			}

			else if (isOperator(postfix[i]))
			{
				char op = postfix[i];
				double val2 = values.top();
				values.pop();

				double val1 = values.top();
				values.pop();

				values.push(applyOp(val1, val2, op));
			}
		}
	return values.top();
}





