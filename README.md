# White paper

This is implementation of python3 interpreter but in C

Interpreter is software that executes source code without first compiling it to machine code.(https://en.wikipedia.org/wiki/Interpreter_(computing))

# Design Patterns

**fgets**- I choose this for taking input as there are multiple ways this seems the most bare bone to me. It was quite easy to implement and also stores to the character array automatically.

**Token**- Token is the smallest unit of program. 
In my case token can have two things:-
  1. Type- Wether the value is operator or number
  2. Value- the value itself
```bash
typedef struct {
  int type;
  char value;
}Token;
```
