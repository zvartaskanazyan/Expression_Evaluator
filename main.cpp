#include <iostream>
#include <string>
#include "PostFixConverter.h"

using std::cout;
using std::endl;

int main()
{
	std::string infix;
	cout << "Please enter the expression : ";
	std::getline(std::cin, infix);
	PostFixConverter postfix(infix);
	cout <<"The result of postfix convertion is : "<< postfix.convert(infix) << endl;
	cout <<"The value of expression is : "<< postfix.evalute(postfix.convert(infix)) << endl;

	return 0;
}

