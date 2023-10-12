#ifndef SERVER_HPP
#define SERVER_HPP

#include "client.hpp"
#include "command.hpp"
#include "messages.hpp"
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <cstring>

class Server {
	public:
		Server(int port, std::string const & pass);
		Server();
		~Server();

		void findHostname();
		void initialize();
		void launch();

	private:
		int	_port;
		std::string	_pass;
		std::string	_IP;
		std::list<Client> _clients;
		Command	_command; 

		struct sockaddr_in _address;
		int	_head_socket;
		fd_set _readfds;
		int	_addrlen;
};

#endif
