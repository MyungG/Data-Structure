#include "Calculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

int IsNumber(char Cipher)
{
	int i;
	int Length = sizeof(NUMBER);

	for (i = 0; i < Length; i++)
	{
		if (Cipher == NUMBER[i])
		{
			return 1;
		}
	}
	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* Type)
{
	int i;

	for (i = 0; Expression[i] != 0; i++) // NULL값은 0 OR /
	{
		Token[i] = Expression[i];

		if (IsNumber(Expression[i]) == 1)
		{
			*Type = OPERAND;

			if (IsNumber(Expression[i + 1]) != 1) // 피연산자 전체를 한번에 나타내기 위해
				break;
		}
		else
		{
			*Type = Expression[i];
			break;
		}
	}
	Token[++i] = '\0';
	return i;
}

int GetPriority(char Operator, int InStack)
{
	int Priority;

	switch(Operator)
	{
	case LEFT_PARENTHESIS: 
		if (InStack)
			Priority = 0; // Pop할때 토큰의 연산자와상관없이 빠져나와야함
		else
			Priority = 3; // 토큰의 '('가 나오면 스택에 바로 삽입하기 위해
		break;

	case MULTIPLY:
	case DIVIDE:
		Priority = 2;
		break;

	case PLUS:
	case MINUS:
		Priority = 1;
		break;
	}

	return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;

	char Token[32];
	int Type = 0;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	Create_Stack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type);

		if (Type == OPERAND)
		{
			strcat(PostfixExpression, Token); 
			strcat(PostfixExpression, " "); // 숫자와 연산자를 구분해서 출력
		}
		else if (Type == RIGHT_PARENTHESIS) // ')'를 만날때까지 모든 연산자 Pop
		{
			while (!IsEmpty(Stack))
			{
				Node* Popped = Stack_Pop(Stack);

				if (Popped->Data[0] == LEFT_PARENTHESIS)
				{
					Destroy_Node(Popped);
					break;
				}
				else
				{
					strcat(PostfixExpression, Popped->Data);
					Destroy_Node(Popped);
				}
			}
		}
		else
		{
			while (!IsEmpty(Stack) && IsPrior(Stack_Top(Stack)->Data[0], Token[0])) // 스택의 최상위 연산자와 토큰의 연산자 우선순위 비교
			{
				Node* Popped = Stack_Pop(Stack);

				if (Popped->Data[0] != LEFT_PARENTHESIS)
				{
					strcat(PostfixExpression, Popped->Data);
					Destroy_Node(Popped);
				}
			}
			Stack_Push(Stack,Create_Node(Token));
		}
	}

	// Stack에 남겨져 있는 모든 연산자 출력
	while (!IsEmpty(Stack))
	{
		Node* Popped = Stack_Pop(Stack);
		if (Popped->Data[0] != LEFT_PARENTHESIS)
		{
			strcat(PostfixExpression, Popped->Data);
			Destroy_Node(Popped);
		}
	}
	Destroy_Stack(Stack);
}

double Calculate(char* PostfixExpression)
{
	LinkedListStack* Stack;
	Node* ResultNode;

	char Token[32];
	int Type = 0;
	unsigned int Position = 0;
	unsigned int Length = strlen(PostfixExpression);
	double Result;

	Create_Stack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken(&PostfixExpression[Position], Token, &Type);

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
		{
			Node* NewNode = Create_Node(Token); // 계산은 스택에 피연산자를 Push
			Stack_Push(Stack, NewNode);
		}
		else
		{
			double num1, num2, TempResult;
			char ResultString[32];
			Node* NumNode;

			NumNode = Stack_Pop(Stack);
			num2 = atof(NumNode->Data); // 문자열을 실수값으로 변환
			Destroy_Node(NumNode);

			NumNode = Stack_Pop(Stack);
			num1 = atof(NumNode->Data);
			Destroy_Node(NumNode);

			switch (Type)
			{
			case PLUS: TempResult = num1 + num2; break;
			case MINUS: TempResult = num1 - num2; break;
			case MULTIPLY: TempResult = num1 * num2; break;
			case DIVIDE: TempResult = num1 / num2; break;
			}

			gcvt(TempResult, 10, ResultString); // 연산결과(실수)를 문자열로 변환
			Stack_Push(Stack, Create_Node(ResultString)); // 변환된 문자열을 Stack에 Push
		}
	}

	ResultNode = Stack_Pop(Stack); 
	Result = atof(ResultNode->Data); // 문자열을 실수값으로 변환 후 저장
	Destroy_Node(ResultNode);

	Destroy_Stack(Stack);

	return Result;
	
}