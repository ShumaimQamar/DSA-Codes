#include "Stack.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool Bracket_Validity1(string infix_exp)
{
	Stack<char> s(infix_exp.size());
	for (int i = 0; i < infix_exp.size(); i++)
	{
		char next_char = infix_exp[i];
		if (next_char == '(')
		{
			s.push(next_char);
		}
		if (next_char == ')')
		{
			if (s.isempty())
			return 0;
			char stacktop = s.pop();
			if (stacktop != '(')
			{
				return 0;
			}
		}
	}
	if (s.isempty())
		return 1;
	else
		return 0;
}


bool Bracket_Validity2(string infix_exp)
{
	Stack<char> s(infix_exp.size());
	for (int i = 0; i < (infix_exp.size()); i++)
	{
		char next_char = infix_exp[i];
		if (next_char == '(' || next_char == '{' || next_char == '[')
		{
			s.push(next_char);
		}
		if (next_char == ')' || next_char == '}' || next_char == ']')
		{
			if (s.isempty())
				return 0;
			char stacktop = s.pop();
			if ((stacktop == '(' && next_char != ')') ||
				(stacktop == '{' && next_char != '}') ||
				(stacktop == '[' && next_char != ']'))
			{
				return 0;
			}
		}
	}
	if (s.isempty())
		return 1;
	else
		return 0;
}
int precendence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	return 0;
 }


string Infix_to_postfix(string infix_str)
{
	Stack<char> s_oper(infix_str.size());
	string post_s;
	for (int i = 0; i < infix_str.size(); i++)
	{
		char n_char = infix_str[i];
		if (n_char >= '0' && n_char <= '9')
		{
			post_s += n_char;
		}
		else if(n_char == '+' || n_char == '-' ||
			n_char == '*' || n_char == '/' ||
			n_char == '^')
		{
				while (!s_oper.isempty() && precendence(s_oper.StackTop()) >= precendence(n_char)) {
					post_s = post_s + s_oper.pop();
				}
				s_oper.push(n_char);
		}
		else if (n_char == '(')
		{
			s_oper.push(n_char);
		}
		else if (n_char == ')')
		{
			while (!s_oper.isempty() && s_oper.StackTop() != '(')
			{
				post_s = post_s + s_oper.pop();
			}
			s_oper.pop();
		}
	}
	while (!s_oper.isempty())
	{
		post_s = post_s + s_oper.pop();
	}
	return post_s;
}

float postfix_evaluation(string post_str)
{
	Stack<float> s(post_str.size());
		for (int i = 0; i < post_str.size(); i++)
		{
			char n_char = post_str[i];
			if (n_char >= '0' && n_char <= '9')
			{
				s.push(n_char - '0');
			}
			else if (n_char == '+' || n_char == '-' ||
				n_char == '*' || n_char == '/' ||
				n_char == '^')
			{
					float operand2 = s.pop();
					float operand1 = s.pop();

					float result;
					switch (n_char)
					{
					case '+':
						result = operand1 + operand2;
						break;
					case '-':
						result = operand1 - operand2;
						break;
					case '*':
						result = operand1 * operand2;
						break;
					case '/':
						if (operand2 == 0) throw ("Division in zero!");
						result = operand1 / operand2;
						break;
					case '^':
						result = pow(operand1, operand2);
						break;
					}

					s.push(result);
			}	
	}	

	float res = s.pop();
	return res;
}

string Infix_to_Postfix(string infix_str)
{
	Stack<char> operator_stack(infix_str.size());
	Stack<char> operand_stack(infix_str.size());

	for (int i = 0; i < infix_str.size(); i++)
	{
		char n_char = infix_str[i];
		if (n_char >= '0' && n_char <= '9')
		{
			operand_stack.push(n_char - '0');
		}
		else if (n_char == '+' || n_char == '-' ||
			n_char == '*' || n_char == '/' ||
			n_char == '^')
		{
			while (!operator_stack.isempty() && precendence(operator_stack.StackTop()) > precendence(operator_stack.StackTop()))
			{
				float operand2 = operand_stack.pop();
				float operand1 = operand_stack.pop();
				char operator1 = operator_stack.pop();

				float result;
				switch (operator1)
				{
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					if (operand2 == 0) throw ("Division in zero!");
					result = operand1 / operand2;
					break;
				case '^':
					result = pow(operand1, operand2);
					break;
				}

				operand_stack.push();
			}
		}
	}
}
int main()
{
	try {
		string s = "(2+3)+3*(2/2)";
		bool b = Bracket_Validity1(s);
		cout << b << endl;
		string s2 = Infix_to_postfix(s);
		cout << s2 << endl;
		float res = postfix_evaluation(s);
		cout << res << endl;
		return 0;
	}
	catch (const char* e)
	{
		cout << "Error: " << e << endl;
	}
}