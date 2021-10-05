#include <stdio.h>
int max = 100;
struct stack
{
    char a[100];
    int top;
};
//to initialize top=-1;
void init(struct stack *st)
{
    st->top = -1;
}

//push each digit as a character
void push(struct stack *st, char digit)
{
    if (st->top < max)
    {
        st->a[++st->top] = digit;
    }
    else
    {
        printf("Stack is full");
    }
}

//pop
char pop(struct stack *st)
{
    if (st->top >= 0)
    {
        return st->a[st->top--];
    }
    else
        return '\0';
}
int main()
{
    struct stack st;
    char number[100], x;
    int i = 0;
    init(&st);
    printf("Enter a number\n");
    scanf("%s", number);
    while (number[i] != '\0')
    {
        push(&st, number[i]);
        i++;
    }

    while ((x = pop(&st)) != '\0')
    {
        printf("%c", x);
    }
    return 0;
}