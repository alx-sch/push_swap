# WIP!! WIP!! 42_push_swap WIP!! WIP!!

<p align="center">
    <img src="https://github.com/alx-sch/42_push_swap/assets/134595144/795f4f85-b51d-4a21-887a-fcd6369aaa2a"
      alt="libft" />
</p>

-- Current version (2024/2/10): push_swap handles argument input and memory allocation correctly; NO sorting (rules) whatsoever though.

Valid input for the push_swap program:
-	Integers with one optional sign ('+'/'-') followed by digits, within the range of 'int' data type.
-	Integers must not be duplicates.
-	Strings: If values are separated by one or more space characters.
-	Mix of strings and integers.
-	Leading zeroes before numbers are allowed.

Examples of valid input:
-	`./push_swap 42 -2 +0'`
-	`./push_swap 1 "42 -2" 2 "5 6"`
-	`./push_swap 00042 -05`

Invalid input:
-	Floats or non-integer numeric values (e.g. "4.2" or "2147483650").
-	Special characters, symbols, or more than one sign (e.g. "++42").
-	Duplicates (e.g. `./push_swap 00042 +42`).
-	Incorrectly formatted numbers (e.g., "1a" or "42-").
