42_push_swap

<p align="center">
    <img src="https://github.com/alx-sch/42_push_swap/assets/134595144/795f4f85-b51d-4a21-887a-fcd6369aaa2a"
      alt="libft" />
</p>

Push_swap is a sorting algorithm implementation designed to efficiently sort numbers using two stacks and a fixed set of instructions (push, swap, rotate).
It takes an unordered stack of integers as input and outputs a series of instructions to sort that stack in ascending order with the least number of moves possible.

## Features
- **Enhanced Turk Algorithm**: This implementation builds upon the [Turk Algorithm by Ali Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) and incorporates additional checks for circular sorting, further improving its efficiency.
- **Keeping it fast and simple**: Utilizes integer arrays instead of linked lists for faster execution of push_swap.
- **Robust Input Handling:** Accepts various forms of input, such as a mix of strings and numbers.
  
## Data Structure

The following data structure named 't_stacks' was implemented to hold all necessary information for sorting management. This way, you can pass the 't_stacks' variable as the sole parameter to functions, making the sorting process more streamlined and cohesive.
```C
typedef struct s_stacks
{
	size_t    size_a;    // Number of elements in stack 'A'.
	size_t    size_b;    // Number of elements in stack 'B'.
	int       *stack_a;  // An array containing the elements of stack 'A'.
	int       *stack_b;  // An array containing the elements of stack 'B'.
	size_t    *target_a; // An array storing the target indices in 'B' for each element in 'A'.
	size_t    target_b;  // The target index in stack 'A' for the first element in stack 'B'.
	int       *cost;     // An array representing the cost associated with moving respective
                             // element in stack 'A' and its target in stack 'B' to the top.
	int       *rr;       // A flag array showing if double rotation(s) is the cheapest way to move
                             // respective element in stack 'A' and its target in stack 'B' to the top.
	int       *rrr;      // A flag array showing if double reverse-rotation(s) is the cheapest way to move
                             // respective element in stack 'A' and its target in stack 'B' to the top.
}	t_stacks;
```
#### Integer Arrays VS. Linked Lists


## XXXX






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

