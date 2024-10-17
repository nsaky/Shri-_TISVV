# Shri++ Code Golf Task - README

## Introduction

Welcome to the **Shri++ Code Golf Task**! In this challenge, you'll be working with a custom language interpreter called **Shri++** to write the most compact solution possible. Your goal is to calculate the summation of numbers from 1 to 5 using **Shri++** commands. There are bonus points for efficiency and creativity, so let's get started!

### Directory Structure
The directory provided to you will have the following files:
1. **shri++.c** - The source code of the Shri++ interpreter.
2. **README.md** - This file containing instructions.
3. **answer.spp** - The Shri++ code file where you will write your solution.

### Step-by-Step Instructions

#### Step 1: Compiling Shri++ Interpreter
You will first compile the `shri++.c` file to create the executable `shri++`. To do this, you will use `gcc`, the GNU Compiler Collection.

1. Open the terminal or command prompt.
2. Navigate to the directory where **shri++.c** is located.
3. Run the following command to compile the file:
   ```bash
   gcc -o shri++ shri++.c
   ```

This command tells the compiler to take `shri++.c`, compile it, and produce an executable named `shri++`.

#### Step 2: Running the Shri++ Interpreter
Once you've compiled the interpreter, you can run it and test its functionality.

1. To display the help message and see the available commands, use:
   ```bash
   ./shri++ -h
   ```

2. To run your **answer.spp** file for testing(which will contain your solution), use:
   ```bash
   ./shri++ answer.spp
   ```

#### Step 3: Writing Your Shri++ Code
The **answer.spp** file is where you will write your solution to the task. The goal is to calculate the sum of numbers from 1 to 5. The challenge is to write the code in as few characters as possible.

### Shri++ Language Commands

- `@` : Move the pointer to the right.
- `#` : Move the pointer to the left.
- `^` : Increment the value at the current pointer (starts from 0).
- `_` : Decrement the value at the current pointer.
- `:` : Output the value at the current pointer.
- `;` : Input a value and store it at the pointer.
- `{` : Start of a loop.
- `}` : End of a loop.

#### Memory and Pointer
- Shri++ uses a memory array, and the pointer starts at the first memory location with the value initialized to 0. 
- As you move the pointer with `@` or `#`, you can modify values using `^` (increment) or `_` (decrement). The value at each location is an integer, and you can output the value using `:`.

#### Example of How Loops Work
Loops in Shri++ work similarly to basic loop structures, with `{}` used to define the start and end of a loop.

- The loop continues as long as the value at the current pointer is non-zero.
- When the value at the memory location that the program is at in is zero

For example, here’s a simple loop that increments a value until it reaches 5:
```spp
^    Increment (now 1)
{
    ^  Increment (2, 3, 4, 5...)
}
```

To make this work correctly, you should have a memory location initiated with a value of say 3 and then decrement it at the end of each loop, this will make the loop run 3 times

```
@^^^

{@^^^^ #_}

this saves a memory location 1 as 3 

then in the loop the pointer moves to memory location 2 and adds 4 and moves back to 1 then subtracts 1
this will continue 3 times till the value in memory location 1 is 0, at which point memory location 2 will have 4*3 = 12
```
### Bonus Points Criteria

1. **10 Points for Generalizing to Any Number**: 
   Write a solution that can calculate the summation for any number, not just 5.
   
2. **5 Points for the Fewest Characters**: 
   Try to write the most compact code possible to get the solution with the fewest characters.

3. **Extra Points for Doing Both**: 
   If you manage to both generalize the solution and keep it compact, you earn additional points!

### Submission and Testing

1. Write your solution in `answer.spp`.
2. Compile and run the interpreter with your code as explained above.
3. Ensure that the output is correct.

Submit the zip file on the form link given to you

Good luck, and may your code be as concise and elegant as possible!

### Useful Links

For those new to working with the terminal or gcc, here are some helpful resources:
- [GNU GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [How to Use the Terminal](https://www.codecademy.com/articles/command-line-commands)
