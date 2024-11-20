## How to run

1. Compile the final implementation
```
make 8inf
```
2. Compile the first implementation
```
make first
```  

3. Execute 8inf code
```
./8inf file/code.8f
```




## File structure

```
root/
├── experiments/          # Directory for experimental scripts and related files
│   ├── megaloop.8f       # Experimental file written in 8f format
│   ├── megaloop.c        # C implementation of the megaloop functionality
│   └── megaloop.py       # Python script for megaloop-related processing
│
├── first_implementation/ # Initial implementations and related files
│   ├── First_8inf.c      # C implementation of the first approach
│   └── first_8inf.h      # Header file for First_8inf.c
│
├── inc/                  # Include files (header files)
│   ├── 8inf.h            # Core header file for 8inf implementation
│   └── lexer_preprocessor.h # Header file for the lexer preprocessor module
│
├── scripts/              # Additional scripts for testing and comparisons
│   ├── hello_world.8f    # Example "Hello World" program in 8f format
│   ├── integer_ops.8f    # Integer operations script in 8f format
│   └── loop.8f           # Loop demonstration script in 8f format
│
├── src/                  # Source code directory
│   └──  lexer_preprocessor.c  # Source code for the lexer preprocessor module
│
├── 8inf.c                # Source code for the 8inf implementation
├── Exam-Inf-1100.pdf     # Report outlining the development
├── Makefile              # Build system configuration for the project
├── README.md             # Project documentation (this file)
```


## 8Inf documentation 

* anything enclosed in `()` is a comment
* anything enclosed in `~~` is a string
* anything prefaced by `.` is an operation 
* anything else is an integer
* words are separated by spaces or newlines; tabs are NOT SUPPORTED



## Supported operations

### Operators on integers
For any operator where order matters, eg. subtraction, multiplication, etc., we
always use the top of the stack as the "second" number. IE. if the stack
contains `a b` where `b` is the top of the stack, `.-` will push `a - b`. For
example `3 2 .-` will push the result `1` to the stack; not `-1`.

* `.+` pops two numbers from the stack and pushes their sum
* `.-` pops two numbers from the stack and pushes their difference
* `.*` pops two numbers from the stack and pushes their multiple
* `./` pops two numbers from the stack and pushes the quotient of the second
  divided by the first.
* `.mod` pops two numbers from the stack and pushes the remainder of the second
  divided by the first.
* `.=?` pops two numbers from the stack and pushes `1` if they are equal, `0`
  otherwise
* `.>?` pops two numbers from the stack and pushes `1` if the second one is
  larger than the first one, `0` otherwise

### Stack operations
* `.dup` push a copy of the top word 
* `.swap` swaps the two top values on the stack 

### Control flow operations
* `.cjump` pops two numbers off the stack. if the second number is not `0` the
  program jumps by as many words as the first number indicates. eg. in 
  `1 -3 .cjump` the number `1` indicates that a jump should happen and the
  number `-3` indicates that the program should jump three words back. If the
  program for instance is `... 5 6 .* 1 -3 .cjump` we will jump back to the
  word `.*`.

### I/O operations
* `.print` pop a word from the stack and print it to terminal
* `.newline` output a newline character to terminal; does not alter the stack.