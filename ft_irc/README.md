<h1 align="center">
  <br>
  ft_irc
  <br>
</h1>

<h4 align="center">Creating an IRC server</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a>
</p>

## Key Features

* The server must be capable of handling multiple clients at the same time
* Communication between client and server is done via TCP/IP
* The project is written in C++
* You can authenticate, set a nickname, a username, join a channel, send and receive private messages using your reference client
* Channel operators can use KICK, INVITE; TOPIC, MODE

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/ft_irc

# Go into the repository
$ cd ft_irc

# Build all the files
$ make

# Clean the repository
$ make fclean
```