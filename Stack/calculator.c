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

	for (i = 0; Expression[i] != 0; i++) // NULL���� 0 OR /
	{
		Token[i] = Expression[i];

		if (IsNumber(Expression[i]) == 1)
		{
			*Type = OPERAND;

			if (IsNumber(Expression[i + 1]) != 1) // �ǿ����� ��ü�� �ѹ��� ��Ÿ���� ����
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
			Priority = 0; // Pop�Ҷ� ��ū�� �����ڿͻ������ �������;���
		else
			Priority = 3; // ��ū�� '('�� ������ ���ÿ� �ٷ� �����ϱ� ����
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
			strcat(PostfixExpression, " "); // ���ڿ� �����ڸ� �����ؼ� ���
		}
		else if (Type == RIGHT_PARENTHESIS) // ')'�� ���������� ��� ������ Pop
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
			while (!IsEmpty(Stack) && IsPrior(Stack_Top(Stack)->Data[0], Token[0])) // ������ �ֻ��� �����ڿ� ��ū�� ������ �켱���� ��
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

	// Stack�� ������ �ִ� ��� ������ ���
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
			Node* NewNode = Create_Node(Token); // ����� ���ÿ� �ǿ����ڸ� Push
			Stack_Push(Stack, NewNode);
		}
		else
		{
			double num1, num2, TempResult;
			char ResultString[32];
			Node* NumNode;

			NumNode = Stack_Pop(Stack);
			num2 = atof(NumNode->Data); // ���ڿ��� �Ǽ������� ��ȯ
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

			gcvt(TempResult, 10, ResultString); // ������(�Ǽ�)�� ���ڿ��� ��ȯ
			Stack_Push(Stack, Create_Node(ResultString)); // ��ȯ�� ���ڿ��� Stack�� Push
		}
	}

	ResultNode = Stack_Pop(Stack); 
	Result = atof(ResultNode->Data); // ���ڿ��� �Ǽ������� ��ȯ �� ����
	Destroy_Node(ResultNode);

	Destroy_Stack(Stack);

	return Result;
	
}