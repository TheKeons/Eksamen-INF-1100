#ifndef INF_H_
#define INF_H_

// Forward declaration of Stack structure
struct stack;
typedef struct stack Stack;

// Forward declaration of Stack_Element structure
struct Stack_Element;
typedef struct Stack_Element stack_element_t;

// Stack operations

/**
 * Removes and returns the top element of the stack.
 */
stack_element_t pop(Stack *stack);

/**
 * Adds an element to the top of the stack.
 */
void push(Stack *stack, stack_element_t value);

/**
 * Duplicates the top element of the stack.
 */
void dup(Stack *stack);

/**
 * Swaps the two top elements of the stack.
 */
void swap(Stack *stack);

/**
 * Checks if the stack is full.
 * Returns 1 if full, 0 otherwise.
 */
int is_full(Stack *stack);

/**
 * Checks if the stack is empty.
 * Returns 1 if empty, 0 otherwise.
 */
int is_empty(Stack *stack);

// Arithmetic operations

/**
 * Pops two numbers from the stack and pushes their sum.
 */
void sum(Stack *stack);

/**
 * Pops two numbers from the stack and pushes their difference.
 */
void difference(Stack *stack);

/**
 * Pops two numbers from the stack and pushes their product.
 */
void multiply(Stack *stack);

/**
 * Pops two numbers from the stack and pushes their quotient.
 * Handles division by zero appropriately.
 */
void quotient(Stack *stack);

/**
 * Pops two numbers from the stack and pushes their modulus.
 */
void modulus(Stack *stack);

// Comparison operations

/**
 * Pops two numbers from the stack and pushes 1 if they are equal, 0 otherwise.
 */
void is_equal(Stack *stack);

/**
 * Pops two numbers from the stack and pushes 1 if the second number is greater, 0 otherwise.
 */
void is_greater_than(Stack *stack);

// Control flow operations

/**
 * Pops two numbers from the stack. If the second number is not 0,
 * the program pointer jumps by the value of the first number.
 * Returns the updated program pointer.
 */
char **cjump(Stack *stack, char **program);

// Miscellaneous

/**
 * Checks if a string is a valid numerical value.
 * Returns 1 if valid, 0 otherwise.
 */
int is_valid_number(char *string);

#endif // INF_H_