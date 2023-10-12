#include "../headers/server.hpp"

int	main(int argc, char **argv) {
	if (argc == 3) {
		int	port = atoi(argv[1]);
		Server server(port, argv[2]);
		signal(SIGPIPE, SIG_IGN);
		server.initialize();
		server.launch();
	} else {
		std::cout << "Right syntax is ./ircserv <port> <password>" << std::endl;
		return 1;
	}
	return 0;
}
