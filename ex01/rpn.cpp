#include "rpn.hpp"

rpn ::rpn ()
{
}

/*--------------------------------------------------------*/
rpn::rpn (const rpn &a)
{
	this->operator=(a);
}

/*--------------------------------------------------------*/
rpn::~rpn ()
{
}

/*--------------------------------------------------------*/
rpn & rpn::operator = (const rpn &a)
{
		(void)a;
	return (*this);
}

int rpn::CalculationResult(int n1, int n2, char o)
{
	switch (o)
	{
		case '+':
			return (n1 + n2);
		case '-':
			return (n1 - n2);
		case '*':
			return (n1 * n2);
		case '/':
		{
			if (n2 == 0)
				throw std::invalid_argument("Floating Point Exception Dividing on Zero\n");
			return (n1 / n2);
		}
	}
	return (0);
}


void    rpn::ReadInput(std::string input)
{
	int dig = 0;
	int op = 0;

	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (isdigit(input[i]))
		{
			this->_numbers.push(input[i] - '0');
			dig++;
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			this->_operators.push(input[i]);
			op++;
		}
		else if (isspace(input[i]))
			continue;
		else
			throw std::invalid_argument("Invalid Input\n");
	}
	if (op + 1 != dig)
		throw std::invalid_argument("Number of operators less or greater than numbers\n");
	this->Calculation();
}

void    rpn::Calculation()
{
	while (!(this->_operators.empty()))
	{
		if (this->_numbers.size() == 1)
			break;
		int n1 = this->_numbers.top();
		_numbers.pop();
		_numbers.top() = CalculationResult(n1, _numbers.top(), _operators.top());
		_operators.pop();
	}
	std::cout << "-> " << _numbers.top() << "\n";
}

void    rpn::PrintStack(char c)
{
	if (c == 'n')
	{
		while (!this->_numbers.empty())
		{
			std::cout << _numbers.top() << "\n";
			_numbers.pop();
		}
	}
	else if (c == 'o')
	{
		while (!this->_operators.empty())
		{
			std::cout << _operators.top() << "\n";
			_operators.pop();
		}
	}
}


