#include "../headers/server.hpp"

Server::Server(int port, std::string const &pass): _port(port), _pass(pass), _command(pass, _clients, _IP) {
	findHostname();
	_command.setIP(_IP);
}

Server::Server(): _port(4242), _pass(""), _command(_pass, _clients, _IP) {
	findHostname();
	_command.setIP(_IP);
}

Server::~Server() { close(_head_socket); }

void Server::findHostname() {
	char host[256];
	struct hostent *host_entry;
	gethostname(host, sizeof(host));
	host_entry = gethostbyname(host);
	_IP = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0]));
}

void Server::initialize() {
	int	opt = 1;
	if ((_head_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1)
		throw std::runtime_error("socket");
	if (setsockopt(_head_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
		throw std::runtime_error("setsockopt");
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(_port);
	if (fcntl(_head_socket, F_SETFL, O_NONBLOCK) < -1)
		throw std::runtime_error("fcntl");
	if (bind(_head_socket, (struct sockaddr *)&_address, sizeof(_address)) < 0)
		throw std::runtime_error("bind failed");
	std::cout << "Listening on port: " << _port << std::endl << "Password is: " << _pass << std::endl;
	if (listen(_head_socket, 3) < 0)
		throw std::runtime_error("listen");
	_addrlen = sizeof(_address);
	std::cout << "Waiting for connection..." << std::endl << std::endl;
}

void Server::launch() {
	int	sd, max, res;
	char buf[2048];
	while(true) {
		FD_ZERO(&_readfds);
		FD_SET(_head_socket, &_readfds);  
		max = _head_socket;
		for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
			if (it->getbeDeleted())
				it = _clients.erase(it);
			sd = it->getSocket();
			FD_SET(sd, &_readfds);
			if (sd > max)
				max = sd;
		}
		timeval time_out;
		time_out.tv_sec = 1;
		time_out.tv_usec = 0;
		if ((res = select(max + 1 , &_readfds , NULL , NULL , &time_out)) < 0)  
			throw std::runtime_error("select error");
		if (FD_ISSET(_head_socket, &_readfds)) {
			res = accept(_head_socket, (struct sockaddr *)&_address, (socklen_t*)&_addrlen);
			if (res < 0)
				throw std::runtime_error("accept");
			fcntl(res, F_SETFL, O_NONBLOCK);
			Client client(res, inet_ntoa(_address.sin_addr), ntohs(_address.sin_port));
			_clients.push_back(client);
			std::cout << "New connection Socket fd: " << client.getSocket() << " IP: " << client.getIP() << " Port Client: " << client.getPort() << std::endl;
		}
		for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
			sd = it->getSocket();
			if (FD_ISSET(sd, &_readfds)) {
				res = recv(sd, reinterpret_cast<void *>(buf), sizeof(buf), 0);
				int check = std::string(buf).find('\n');
				if (res <= 0 || check == -1) {
					it->setConnected(false);
					it->getBuff().append("QUIT :Remote host closed the connection\r\n");
					_command.parsCmd(*it);
					break ;
				} else {
					buf[res] = '\0';
					it->getBuff().append(buf);
				}
				if (it->getBuff()[it->getBuff().length() - 1] == '\n') {
					_command.parsCmd(*it);
					it->getBuff().clear();
				}
				bzero(buf, res);
			}
		}
	}
}
