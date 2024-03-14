#define CHAR_NULL '\0'

/* Stack implementation */

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        ;    // raise error
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (!stack->array)
        ;    // raise error
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    // printf("%c pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_NULL;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_NULL;
    return stack->array[stack->top];
}

/* Driver program to the problem */

bool isValid(char* s)
{
    struct Stack* st = createStack(10000);
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
        case ')':
            if (peek(st) != '(')
                push(st, s[i]);
            else
                pop(st);
            break;
        case ']':
            if (peek(st) != '[')
                push(st, s[i]);
            else
                pop(st);
            break;
        case '}':
            if (peek(st) != '{')
                push(st, s[i]);
            else
                pop(st);
            break;
        default:
            push(st, s[i]);
        }
    }
    return isEmpty(st) ? true : false;
}