#include<stdio.h>
#include<string.h>
#define MAX 10
int isEmpty(int top)
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isFull(int top)
{
	if(top>=MAX)
	return 1;
	else
	return 0;
}
int pop(char stack[],int* top)
{
    if(isEmpty(*top))
        printf("���|�w��!\n");
    else
        return stack[(*top)--];
}
void push(char stack[],int* top,char item)
{
    if(isFull(*top))
        printf("���|�w��!\n");
    else
        stack[++(*top)]=item;
}
int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 12;
        case '*': case '/': case '%': return 13;
        default:            return 0;
    } 
} 
void InToPostfix(char infix[], char postfix[])
{ 
    char stack[MAX];
    
    int i, j, top;
    for(i=0;i<MAX;i++)
    stack[i]='0';
    top=-1;
    for(i=0, j=0; i<strlen(infix); i++) 
        switch(infix[i]) 
        { 
            case '(':  // �B��l���| 
                /*  1. push infix[i] �� stack �� */
                push(stack,&top,infix[i]);
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(infix[i])) {  // ����u���v
                    /*  2. �N stack ���� pop �X �s�J postfix[j++] ��*/
                    postfix[j++]=pop(stack,&top);
                } 
                /*  2. push infix[i] �� stack �� */  //�N�ӹB��l�[�J���|
                push(stack,&top,infix[i]);
                break; 
            case ')': 
                while(stack[top] != '(') { // �J ) ��X�� ( 
                    /*  3. �N stack ���� pop �X �s�J postfix[j++] �� */
                   postfix[j++] = pop(stack,&top);
                } 
                /* �N stack ���� pop �X */  // ����X ( 
                pop(stack,&top);
                break; 
            default:  // �B�⤸������X 
                postfix[j++] = infix[i];
	    }
    while(top>-1)  //�N���|���Ҧ��B�⤸��X
        /*  5. �N stack ���� pop �X �s�J postfix[j++] �� */
        postfix[j++]=pop(stack,&top);
} 

int main()
{
	char a[100],b[100];
	scanf("%s",a);
	InToPostfix(a,b);
	printf("%s",b);
} 
