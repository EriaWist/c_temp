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
        printf("堆疊已空!\n");
    else
        return stack[(*top)--];
}
void push(char stack[],int* top,char item)
{
    if(isFull(*top))
        printf("堆疊已滿!\n");
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
            case '(':  // 運算子堆疊 
                /*  1. push infix[i] 至 stack 中 */
                push(stack,&top,infix[i]);
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(infix[i])) {  // 比較優先權
                    /*  2. 將 stack 中值 pop 出 存入 postfix[j++] 中*/
                    postfix[j++]=pop(stack,&top);
                } 
                /*  2. push infix[i] 至 stack 中 */  //將該運算子加入堆疊
                push(stack,&top,infix[i]);
                break; 
            case ')': 
                while(stack[top] != '(') { // 遇 ) 輸出至 ( 
                    /*  3. 將 stack 中值 pop 出 存入 postfix[j++] 中 */
                   postfix[j++] = pop(stack,&top);
                } 
                /* 將 stack 中值 pop 出 */  // 不輸出 ( 
                pop(stack,&top);
                break; 
            default:  // 運算元直接輸出 
                postfix[j++] = infix[i];
	    }
    while(top>-1)  //將堆疊內所有運算元輸出
        /*  5. 將 stack 中值 pop 出 存入 postfix[j++] 中 */
        postfix[j++]=pop(stack,&top);
} 

int main()
{
	char a[100],b[100];
	scanf("%s",a);
	InToPostfix(a,b);
	printf("%s",b);
} 
