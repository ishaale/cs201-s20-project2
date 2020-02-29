# Project 2

Due date: March 13 at 11:59pm.

**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered plagiarism (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

The `Makefile` provided with this project compiles and builds all of the required programs.<br>
(If you wish to learn more about the Makefiles, you can do so by following the [Make Tutorial](https://github.com/stewartweiss/Make-Tutorial) or any number of other online resources. We do not expect you to be able to write your own Makefiles in this
class, but they do simplify compiling and building code, so we will give you a Makefile for each assignment. )

__You should NOT modify the Makefile for this assignment.__

To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2
    ...

To run programs for each problem you can either execute

    ./problem1
    ./problem2
    ...

or, you can use the rules defined in the `Makefile`:

    make run_problem1
    make run_problem2
    ...

Finally, to run programs using `valgrind` you can use the rules
defined in the `Makefile`:

    make test_prob1
    make test_prob2
    ...

To remove all previously compiled and built files, run

    make clean

(It is a good idea to use the `make clean` option when you want a clean start and to make sure you are not using any old binary files.)


## General Requirements

__Documentation__

Your code has to be documented.

Every function that you write yourself, should have a description of what it does, what the parameters and what it returns.

Functions should have inline comments that state what the code is doing. These should be general comments outlining the algorithm, not line by line comments stating what each C instruction is doing.

Each file that you submit should have your name listed as the author at the top of the file.

(Do not use Javadoc style documentation.)

__Memory management__

Your code should free all memory that it allocates and should not be miss-using any memory location when the program is executing.
Use `valgrind` to see any errors that it might report and try to resolve them.
Additionally, read the warning messages that the compiler produces and make sure they are not going to lead to errors that you should be dealing with.

__Committing your changes and backing up your code__

As you are working on the assignment make sure that you commit your changes frequently. It is also a good idea to push those changes to GitHub repository so that you have a backup.

You are expected to make many commits as you are working on this project.


## Problem 1 (20 points)

The program in  `problem1.c` is a very simple _triangle validator_. Your task is to implement the

```C
int is_valid_triangle ( int n ) ;
```

function.

The three sides of the triangle are
encoded using sets of 10 bits from the
32-bit int parameter `n`. The bits should be interpreted as unsigned.  The lowest order
10 bits (i.e., bits at positions 0-9) are the value for one side, the
next 10 bits  (i.e., bits at positions 10-19)  are the value for the second
side, the next 10 bits  (i.e., bits at positions 20-29)  are the value
for the third side. The highest order 2
bits are ignored and their values do not tell you anything about validity of the triangle.

In a valid triangle the sum of two shortest
sides has to be larger than the value
of the largest side. This means that if s1 <= s2 <= s3, then s1 + s2 > s3.

__Input__

The program expects a single integer from the standard input stream (i.e., it expects the user to enter a single number).  

__Output__

The program prints to the standard output stream the word _valid_ if the integer represents a valid triangle, or _invalid_ if the integer does not represent a valid triangle.

__Example 1__

```
Input
1050627

Output
invalid
```
because the three sides are 1, 2, 3

__Example 2__

```
Input
5246979
Output
valid
```
because the three sides are 3, 4, 5

__Example 3__

```
Input
-1070590972
Output
valid
```
because the three sides are 3, 4, 5

__Example 4__

```
Input
18892818

Output
valid
```
because the three sides are 18, 18, 18




__Deliverables__

Implementation of the program in file `problem1.c`. Any helper functions that you
wish to implement should be declared above `main()` and implemented below in the same
file.



Submit your code on Gradescope to the link project1_problem1. You should submit only files for this problem.


## Problem 2 (20 points) Big- or Little- Endian

All computer memory is organized into 8-bit bytes.
For integer values that require a type with more than 8-bits, such as the typical 2-byte, 4-byte, and 8-byte integral types available on most modern hardware, there is no universal agreement as to how to order those bytes and two incompatible storage schemes exist.

The first stores integers as groups of consecutive 8-bit bytes with the least significant byte occupying the lowest memory address within the group and the most significant byte occupying the highest memory address.

The second is just the reverse; the least significant byte is stored in the highest memory address within the group, and the
most significant byte is stored in the lowest memory address.

Those schemes have been dubbed Little Endian and Big Endian, respectively.

We assume that signed integers are stored using two's complement representation.

When binary integer data is shared between a Little Endian and Big Endian machine, a data
conversion must be performed which involves reversing the bytes of the data. Once the bytes have been reversed the integer is then correctly interpreted by the hardware as the original value from the opposite-endian machine.
Your task is to write a program that will read an
integer and report what its value would have been  on an opposite-endian machine if the appropriate byte reversal was not performed.

__Input__

A number `n`, `-2147483648 <= n <= 2147483647`.

__Output__

The number `n` followed by the phrase "converts to" followed by the other endian-value (single space between the three parts).

__Example 1__

```
Input:
123456789
Output:
123456789 converts to 365779719

```

because `0x075BCD15` reversed is `0x15CD5B07`

__Example 2__

```
Input:
-123456789
Output:
-123456789 converts to -349002504

```

because `0xF8A432EB` reversed is `0xEB32A4F8`

__Example 3__

```
Input:
1
Output:
1 converts to 16777216

```

because `0x00000001` reversed is `0x01000000`

__Example 4__

```
Input:
16777216
Output:
16777216 converts to 1

```
because `0x01000000` reversed is `0x00000001`



__Restrictions__

For full credit, your implementation of this program should not use the multiplication, division or modulus operations. <br>
HINT: everything can be done using the bit-level operations that you learned in the last couple of weeks.


__Deliverables__

Implementation of the program in file `problem2.c`. Any helper functions that you
wish to implement should be declared above `main()` and implemented below in the same
file.

Submit your code on Gradescope to the link project2_problem2. You should submit only files for this problem.


## Problem 3 (40 points)

The floating point numbers are represented using the rules outlined in the IEEE 754
standard.
In the program, you will be working with the single precision numbers
(i.e., values of type `float` in C).  

Your task is to _disassemble_ a floating point number into three separate components:
- `s` sign (either 1 or -1)
- `E` exponent (an integer in base 10)
- `M` mantissa/significand (a floating point number in base 10 in the range [0.0,2.0)  )

The original floating point number should then be equal to the product  s \* M \* 2^E.


__Input__

A floating point number (positive or negative).

_Note_:
1. Your program should not prompt the user for anything. Assume that the user
will enter a single value, as described above, unprompted.
1. Your program does not
need to validate the input. You are guaranteed that it will be a floating point number
as described above.

__Output__

Three numbers each on a seperate line corresponding to `s`, `E` and `M`.
`s` should be always either `1` or `-1`.
`E` should be printed as an integer in base 10.
`M` should be printed as a floating point number in base 10 with exactly 1 digit before
the decimal point and 20 digits after the decimal point.

__Example 1__

```
Input:
3.1415927

Output:
1
1
1.57079637050628662109

```


__Example 2__

```
Input:
5.877472e-39

Output:
1
-126
0.50000000000000000000

```

Note: you do not need to do anything special for your program to read in a value like the one above 5.877472e-39. Simply use the `scanf` function with `%f` specifier.

__Example 3__

```
Input:
-0.5

Output:
-1
-1
1.00000000000000000000 	

```

__Example 4__

```
Input:
-0.1

Output:
1
-4
1.60000002384185791016

```



__Restrictions__

<p style="color:red">Your program is not allowed to use ANY of the functions defined in the `math.h` header file.</p>



__Deliverables__

Implementation of the program in `problem3.c` file. Any functions related to calculating the sign, expontent and mantissa should be declared in the file `float.h` and implemented in the file `float.c`.


Submit your code on Gradescope to the link project2_problem3. You should submit only files for this problem.



## Problem 4 (20 points)

By now you should have realized that a single binary vector can have many different interpretations depending on the type of data and the encoding used.

In this problem you will write a program that displays several different interpretations of a single 32-bit vector. Your program will take the initial bit vector as a two's complements encoded `int`. It should display the values/interpretations of that
bit vector using the following type/encoding combinations:

- individual bytes of the number (this is not really any type or encoding, but may help with debugging when you run into problems)
- unsigned char
- unsigned short
- two's complements short
- unsigned int
- two's complements  int (this should result in 1 value, this value should be the same one as was entered by the user)
- IEEE 754 single precision float (this should result in 1 value)


__Input__

A number `n`, `-2147483648 <= n <= 2147483647`.

_Note_:
1. Your program should not prompt the user for anything. Assume that the user
will enter a single value, as described above, unprompted.
1. Your program does not
need to validate the input. You are guaranteed that it will be an integer
as described above.

__Output__

Seven lines of output as follows:


- individual bytes of the number (this is not really any type or encoding, but may help with debugging when you run into problems); use `%02x` format specified for `printf` to print exactly two hexadecimal symbols for each byte
- unsigned char (this should result in 4 characters); each character should be surrounded in a set of single quotes (this way unprintable characters can still be _visible_ in the output of the program)
- unsigned short (this should result in 2 values); use `%ud` format specified for `printf`
- two's complements short (this should result in 2 values); use `%d` format specified for `printf`
- unsigned int (this should result in 1 value); use `%ud` format specified for `printf`
- two's complements  int (this should result in 1 value, this value should be the same one as was entered by the user)
- IEEE 754 single precision float (this should result in 1 value);  use `%g` format specified for `printf`

Each of the lines above should be preceeded by a short heading as follows:
- `bytes: `
- `char: `
- `ushort: `
- `short: `
- `uint: `
- `int: `
- `float: `

When multiple values are printed, they should be separated by a single space.


__Example 1__

```
Input:
0

Output:
bytes: 00 00 00 00
char: '' '' '' ''
ushort: 0 0
short: 0 0
uint: 0
int: 0
float: 0

```

__Example 2__

```
Input:
1347506771

Output:
bytes: 53 52 51 50
char: 'S' 'R' 'Q' 'P'
ushort: 21075 20561
short: 21075 20561
uint: 1347506771
int: 1347506771
float: 1.40473e+10

```

__Example 3__

```
Input:
65

Output:
bytes: 41 00 00 00
char: 'A' '' '' ''
ushort: 65 0
short: 65 0
uint: 65
int: 65
float: 9.10844e-44

```

__Example 4__

```
Input:
-529891295

Output:
char: '!' '�' 'j' '�'
ushort: 32801 57450
short: -32735 -8086
uint: 3765076001
int: -529891295
float: -6.75902e+19

```
