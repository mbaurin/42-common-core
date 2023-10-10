<h1 align="center">
  <br>
  Philosophers
  <br>
</h1>

<h4 align="center">This project introduce the use of threads. Among a group of philosophers, it's up to you to anticipate precisely the moment when each philosopher in the group will have to pick up forks and eat spaghetti, without any of them dying of hunger</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a>
</p>

## Key Features

* Each philosopher is a thread
* There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table
* To prevent philosophers from duplicating forks, the forks state is protected with a mutex

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/Philosophers

# Go into the repository
$ cd Philosophers

# Build all the files
$ make

# Launch the program with arguments
$ ./philo <"number_of_philosophers" "time_to_die" "time_to_eat" "time_to_sleep" ("number_of_times_each_philosopher_must_eat")>

# Clean the repository
$ make fclean
```
