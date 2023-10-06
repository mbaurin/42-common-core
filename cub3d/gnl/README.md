<h1 align="center">
  <br>
  get_next_line
  <br>
</h1>

<h4 align="center">Code a function that store, in the parameter “line”, a line that has been read from the given file descriptor</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
</p>

## Key Features

* get_next_line reads an entire line from a file indexed by a file descriptor fd
* Then alocates a string with the contents of that line without the linebreak '\n' and points line to it
* This project is about understanding the way these functions work, implementing and learning to use them
* The project is written in C
* All heap allocated memory space are properly freed when necessary
* A Makefile is available to compile 

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/get-next-line

# Go into the repository
$ cd get-next-line

# Build all the files
$ make bonus

# Clean the repository
$ make fclean
```