# WIP!! WIP!! 42_push_swap WIP!! WIP!!

<p align="center">
    <img src="https://github.com/alx-sch/42_push_swap/assets/134595144/795f4f85-b51d-4a21-887a-fcd6369aaa2a"
      alt="libft" />
</p>

The push_swap project is a sorting algorithm implementation designed to sort numbers with minimal moves using two stacks and a fixed set of instructions (push, swap, rotate). The program takes an unordered stack of integers as input and outputs a series of instructions to sort that stack in ascending order.

## Features
- **Robust Input Validation:** Validates user input for correctness, accepting various representations of integer sequences to ensure robustness.
- **Instruction Set:** Utilization of a fixed set of stack operations including push, swap, and rotate to manipulate the stacks during sorting.
- **Sorting Approach:** Experimenting with different sorting techniques while adhering to the specified rules.
- **Validation Checker:** Implementation of a program to confirm the correctness of push_swap's sorting outputs.

########

-- Current version (2024/2/10): push_swap handles argument input and memory allocation correctly; NO sorting (rules) whatsoever though.

Valid input for the push_swap program:
-	Integers with one optional sign ('+'/'-') followed by digits, within the range of 'int' data type.
-	Integers must not be duplicates.
-	Strings: If values are separated by one or more space characters.
-	Mix of strings and integers.
-	Leading zeroes before numbers are allowed.

Examples of valid input:
-	`./push_swap 42 -2 +0`
-	`./push_swap 1 "42 -2" 2 "5 6"`
-	`./push_swap 00042 -05`

Invalid input:
-	Floats or non-integer numeric values (e.g. "4.2" or "2147483650").
-	Special characters, symbols, or more than one sign (e.g. "++42").
-	Duplicates (e.g. `./push_swap 00042 +42`).
-	Incorrectly formatted numbers (e.g., "1a" or "42-").

Struct

In computer programming, a struct (short for "structure") is a composite data type that groups together a collection of variables under a single name for easier manipulation. Structs are commonly used in languages like C, C++, C#, and many others.

Structs allow you to define your own custom data types by specifying different types of variables and grouping them together. Each variable within a struct is called a member or field. These members can be of any data type, including primitive types like integers or floats, or even other structs.

Examples: Target finding, cost calculation

target:
Stack A: -3 1 99 7 -2 2 -99 
Stack B: 4 0 -4 13 
Target for A in B: 2 1 3 0 2 1 3 

