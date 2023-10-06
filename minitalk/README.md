<h1 align="center">
  <br>
  minitalk
  <br>
</h1>

<h4 align="center">Small data exchange program using UNIX signals</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
</p>

## Key Features

* A communication program in the form of a client and a server
* The server must be launched first and display its PID after launch
* The client takes two parameters: The server's PID and a character string to be transmitted
* The Communication between the two programs only take place using UNIX signals
* The server confirms receipt of each message by sending a signal to the client
* Support for Unicode characters 

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/minitalk

# Go into the repository
$ cd minitalk

# Build all the files
$ make

# Launch the server
$ ./server

# Launch the client
$ ./client

# Clean the repository
$ make fclean
```