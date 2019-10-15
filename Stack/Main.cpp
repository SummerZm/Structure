#include "assert.h"
#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"

bool isValid(const char* str)
{
	ArrayStack<char, 2>  charArr;
	for(int i=0; i<strlen(str); i++) 
	{
		if (str[i]=='(' || str[i]=='[' || str[i]=='{') {
			charArr.push(str[i]);
		}
		else if (str[i]==')' || str[i]==']' || str[i]=='}')
		{
			if(charArr.isEmpty()) 
			{
				std::cout<<"Error"<<std::endl;
				return false;
			}

			char tmp = charArr.peek();
			if(tmp=='(' && str[i]!=')' || tmp=='[' && str[i]!=']' || tmp=='{' && str[i]!='}' ) {
				std::cout<<"Error"<<std::endl;
				return false;
			}
			charArr.pop();
		}

		if(i==strlen(str)-1 && charArr.isEmpty()) {
			std::cout<<"success"<<std::endl;
			return true;
		}
	}

}

void testArrayStack()
{
	std::cout<<"============Test ArrayStack============="<<std::endl;
	ArrayStack<std::string, 5> sArr;
	std::cout<<"Stack is empty: "<<sArr.isEmpty()<<std::endl;
	sArr.push("Aa");
	sArr.push("Bb");
	sArr.push("Cc");
	std::cout<<"Stack is empty: "<<sArr.isEmpty()<<std::endl;
	sArr.display();
	std::cout<<sArr.pop()<<std::endl;
	std::cout<<sArr.peek()<<std::endl;
	std::cout<<sArr.getSize()<<std::endl<<std::endl;
	sArr.display();
	std::cout<<std::endl<<std::endl;
	isValid("(b)[a]{c}");
	isValid("([)]{}");
	isValid("([])]{}");
}

void testListStack()
{
	std::cout<<"============Test LinkedStack============="<<std::endl;
	LinkedStack<char> Ls;
	Ls.push('A');
	Ls.push('b');
	Ls.display();
	Ls.pop();
	Ls.push('R');
	Ls.push('L');
	Ls.peek();
	Ls.display();
	Ls.push('M');
	Ls.push('Y');
	Ls.display();
}

int main(int argc, char** argv)
{
    testArrayStack();
	testListStack();
    return 0;
}
