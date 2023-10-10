<h1 align="center">
  <br>
  Inception
  <br>
</h1>

<h4 align="center">Virtualise several Docker images by creating them in a virtual machine</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a>
</p>

## Key Features

* A Docker container that contains NGINX with TLSv1.3
* A Docker container that contains WordPress + php-fpm without nginx
* A Docker container that contains MariaDB without nginx
* A volume that contains the WordPress database
* A second volume that contains the WordPress website files
* A docker-network that establishes the connection between the containers

## How To Use

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/mbaurin/Inception

# Go into the repository
$ cd Inception

# Build all the files
$ make

# Clean the repository
$ make fclean
```
