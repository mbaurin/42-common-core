<h1 align="center">
  <br>
  Push_swap
  <br>
</h1>

<h4 align="center">Stack sorting algorithm</h4>

<p align="center">
  <img src="https://github.com/mbaurin/42-common-core/blob/main/Push_swap/public/assets/preview.png?raw=true" alt="logo"/>
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
</p>

## Key Features

* There is two stack A and B
* Initially, Stack A contains a random amount of negative and/or positive numbers that cannot be duplicated. Pile b is empty
* The algorithm sort the numbers in pile A in ascending order
* To do this the algorithm can do the following:
    * sa (swap a): swaps the first 2 elements at the top of stack a. Does nothing if there is only one or none
    * sb (swap b ): Swaps the first 2 elements at the top of stack b. Does nothing if there is only one or none
    * ss : sa and sb at the same time
    * pa (push a): Takes the first element at the top of b and puts it on a. Does nothing if b is empty
    * pb (push b): Takes the first element on top of a and sets it to b. Does nothing if a is empty.
    * ra (rotate a): Shifts all elements in stack a upwards by one position. The first element becomes the last.
    * rb (rotate b): Shifts all elements in stack b up one position. The first element becomes the last.
    * rr: ra and rb at the same time.
    * rra (reverse rotate a): Shifts all stack elements down one position of A stack. The last element becomes the first.
    * rrb (reverse rotate b): Shifts all stack elements b down one position.
    * b stack. The last element becomes the first. rrr: rra and rrb at the same time.

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/Push_swap

# Go into the repository
$ cd Push_swap

# Build all the files
$ make

# Sort stack
$ ./push_swap 1 54 23 -12 34

# Clean the repository
$ make fclean
```
