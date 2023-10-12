#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <vector>
#include <string>
#include <utility>
#include <cstdint>

class Client {
	public:
		Client(int sd, char *IP, uint32_t port );
		~Client();

		std::string	&getBuff();
		std::vector<std::string> &getChannels();
		std::string	const &getIP() const;
		uint32_t getPort() const;

		void setSocket(int sd);
		int	getSocket() const;
		void setNick(std::string const &val);
		std::string	const &getNick() const;
		void setPass(std::string const &val);
		std::string	const &getPass() const;
		void setUser(std::string const &val);
		std::string	const &getUser() const;
		void setMode(std::string const &val);
		std::string	const &getMode() const;
		void setUnused(std::string const &val);
		std::string	const &getUnused() const;
		void setRealname(std::string const &val);
		std::string	const &getRealname() const;
		void setConnected(bool val);
		bool getConnected() const;
		void setNicked(bool val);
		bool getNicked() const;
		void setUsed(bool val);
		bool getUsed() const;
		void setRegistered(bool val);
		bool getRegistered() const;
		void setbeDeleted(bool val);
		bool getbeDeleted() const;
		void setOperator(bool val);
		bool getOperator() const;

		bool isInChan(std::string const &str) const ;
			
		void deleteChan(std::string const &str);

	private:
		int	_socket;
		std::string	_IP;
		uint32_t _port;
		std::string	_buffer;
		std::string	_nick;
		std::string	_pass;
		std::string _user;
		std::string _mode;
		std::string _unused;
		std::string _realname;
		bool _connected;
		bool _nicked;
		bool _used;
		bool _registered;
		bool _beDeleted;
		bool _Operator;
		std::vector<std::string> _channels;
};

#endif
