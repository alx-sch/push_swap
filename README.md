# WIP # 42_push_swap WIP

<p align="center">
    <img src="https://github.com/alx-sch/42_push_swap/assets/134595144/795f4f85-b51d-4a21-887a-fcd6369aaa2a"
      alt="push_swap_badge.png" />
</p>

<p align="center">
    <img src="https://github.com/alx-sch/42_push_swap/assets/134595144/89df423e-ee54-4232-adeb-77492f19fd20"
      alt="push_swap_visualization.gif" />
</p>

Push_swap is a sorting algorithm implementation designed to efficiently sort numbers using two stacks and a fixed set of instructions (push, swap, rotate).
It takes an unordered stack of integers as input and outputs a series of instructions to sort the stack in ascending order, aiming to accomplish this with the least number of moves possible.

## Features
- **Enhanced Turk Algorithm**: This implementation builds upon the [Turk Algorithm by Ali Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), further improving its efficiency by incorporating additional checks for circular sorting.
- **Keeping it fast and simple**: Utilizing arrays instead of linked lists for faster execution and a more streamlined coding layout.
- **Robust Input Handling:** Accepts various forms of input, including a mix of strings and numbers.
- **Insightful Diagnostics:** The ['diagnostic mode'](https://github.com/alx-sch/42_push_swap/tree/main/_diagnostic_mode) offers comprehensive insights into the inner workings of the sorting algorithm, providing a detailed description of steps taken to sort a given set of parameters.

## Sorting Algorithm

#### The Setup

Stacks, operations, comparison 'wheel of fortune'

#### Traditional Sorting Algorithms
While there are several established sorting algorithms available for tackling push_swap, such as [radix sort](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) or [insertion sort](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a), I found these approaches less intuitive due to the restrictive set of rules that need to be considered. With only two stacks and a limited set of allowed moves (explained [here](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)), using traditional sorting algorithms often necessitates additional preprocessing steps like normalizing the numbers or dividing them into chunks. They also don't seem to leverage double rotations or double-reverse rotations, which are essential for achieving solutions with the fewest number of operations.

#### The Turk Algorithm
That's why I opted to seek a solution tailored to the specific requirements of push_swap.  Ali Ogun describes a simple yet effective approach in [this](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) wonderful article, which he coined the "Turk Algorithm". In a nutshell, these are the key steps:
1. **Initialization:** Begin by pushing the first two elements from stack 'A' to stack 'B'.
2. **Sorting 'B':** Move elements from stack 'A' to stack 'B' in such a way that 'B' becomes sorted in descending order.
	- This involves finding suitable targets in 'B' for each element in 'A'.
	- The target is as close as possible to but smaller than the 'A' element. If no smaller element is found in stack 'B', the largest value in 'B' is selected as the target.
	- Move the 'A' element and its corresponding target in 'B' to the top of their respective stacks, choosing the pair that requires the fewest operations to reach the top (the 'cheapest' pair).
 	- Push the 'A' element onto its target on top of stack 'B'.
3. **Reducing 'A' to Three Elements:**  Repeat the sorting process above until only three elements remain in stack 'A'.
4. **Sort 'A'**: Sort the three remaining elements in stack 'A' in ascending order.
5. **Restoring 'A'**: Push elements from stack 'B' back to stack 'A' while ensuring that the resulting stack 'A' is sorted.
	- The target in stack 'A' for the top element in stack 'B' is as close as possible but larger. If no larger element is found in stack 'A', the smallest value in 'A' is selected as the target.
	- In most cases, the target element in stack 'A' is already positioned at the top. However, the target can also be the bottom element in stack 'A', which is then brought to the top with a single reverse-rotation.
6. **Move Smallest Value to Top**: Rotate stack 'A' either clockwise or counterclockwise until the smallest value is positioned at the top, resulting in a sorted stack in linear order.

#### Enhancing the Turk Algorithm
XX 

![turk_21](https://github.com/alx-sch/42_push_swap/assets/134595144/134c8fb0-29b6-44c0-9444-7582254bc446)

![TURK_PLUS_7](https://github.com/alx-sch/42_push_swap/assets/134595144/88016e7e-e75c-462c-9954-9e9dbb6e66ff)


## Data Structure

A data structure named 't_stacks' was implemented to hold all necessary information needed for sorting. This way, you can pass the 't_stacks' variable as the sole parameter to functions, making the sorting process and coding layout more streamlined and cohesive.
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
### Arrays vs. Linked Lists

Both arrays and linked lists can be used to store integer values. In an array, each value is stored in an element, while in a linked list, each value is stored in a node.  

#### Arrays:
- **Memory Efficiency:** Arrays typically use contiguous memory allocation, which can be more memory-efficient than linked lists because they don't require extra memory for pointers.
- **Cache Locality:** Accessing elements in an array can be faster due to better cache locality. CPUs often utilize caching mechanisms that work more efficiently with contiguous memory accesses.
- **Random Access:** Arrays allow for constant-time random access to elements using indices, which can be advantageous for certain operations.
- **Fixed Size:** Arrays have a fixed size, which means you need to know the maximum size of your data in advance. This limitation can be a drawback if your data size is dynamic or unknown.

#### Linked Lists:

- **Dynamic Size:** Linked lists can dynamically grow and shrink in size, making them more flexible for handling variable-sized data.
- **Dynamic Memory Allocation:** Linked lists allocate memory dynamically as nodes are added, allowing efficient memory usage, especially for large datasets.
- **Insertions and Deletions:** Insertions and deletions at arbitrary positions in a linked list are generally faster than in an array because they involve only pointer manipulation.
- **Memory Overhead:** Linked lists have additional memory overhead due to the pointers linking nodes, which can be a disadvantage if memory usage is a concern.

#### Why Arrays?

- The maximum size of the stacks is known: It's the number of passed integer values. Therefore, there is no need to dynamically allocate or deallocate memory every time a stack grows or shrinks. Instead, you can initialize with fixed-size arrays and keep track of the stack sizes via members in the data structure ('size_a' and 'size_b').
- Managing arrays is more straightforward compared to linked lists/nodes, as you can access elements directly using indices.
- Arrays offer better cache locality, resulting in faster access times for elements, which drastically increases the performance for larger data inputs (tested via `time ./push_swap [LIST OF 1000 RANDOM INT VALUES]`:
  
	- Sorting 1,000 values using linked lists (as implemented [here](https://github.com/ayogun/push_swap)): **13.27s**
	![turk_linked_lists_1000](https://github.com/alx-sch/42_push_swap/assets/134595144/ecc05b0a-233a-48a1-ad85-21639894a8c1)
	- Sorting 1,000 values using arrays: **0.26s** (50 times faster!)
	![turk_arrays_1000](https://github.com/alx-sch/42_push_swap/assets/134595144/e12940f9-ee67-4888-af23-7d209eddb7cd)




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

