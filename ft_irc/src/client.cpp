#include "../headers/client.hpp"

Client::Client(int sd, char * IP, uint32_t port): _socket(sd), _IP(IP), _port(port),
				_buffer(), _nick("*"), _pass(""), _user("*"), _mode("*"), _unused("*"), _realname("*"),
				_connected(true), _nicked(false), _used(false), _registered(false), _beDeleted(false),
				_Operator(false) {}

Client::~Client() {}

void Client::setSocket(int sd) { _socket = sd; }

int	Client::getSocket() const { return _socket; }

std::string &Client::getBuff() { return _buffer; }

std::string const &Client::getIP() const { return _IP; }

uint32_t Client::getPort() const { return _port; }

void Client::setNick(std::string const &val) { _nick = val; }

std::string const &Client::getNick() const { return _nick; }

void Client::setPass(std::string const &val) { _pass = val; }

std::string const &Client::getPass() const { return _pass; }

void Client::setUser(std::string const &val) { _user = val; }

std::string const &Client::getUser() const { return _user; }

void Client::setMode(std::string const &val) { _mode = val; }

std::string const &Client::getMode() const  { return _mode; }

void Client::setUnused(std::string const &val) { _unused = val; }

std::string const &Client::getUnused() const { return _unused; }

void Client::setRealname(std::string const &val) { _realname = val; }

std::string const &Client::getRealname() const { return _realname; }

void Client::setConnected(bool val) { _connected = val; }

bool Client::getConnected() const { return _connected; }

void Client::setNicked(bool val) { _nicked = val; }

bool Client::getNicked() const { return _nicked; }

void Client::setUsed(bool val) { _used = val; }

bool Client::getUsed() const { return _used; }

void Client::setRegistered(bool val) { _registered = val; }

bool Client::getRegistered() const { return _registered; }

void Client::setbeDeleted(bool val) { _beDeleted = val; }

bool Client::getbeDeleted() const { return _beDeleted; }

void Client::setOperator(bool val) { _Operator = val; }

bool Client::getOperator() const { return _Operator; }

std::vector<std::string> &Client::getChannels() { return _channels; }

bool Client::isInChan(std::string const &str) const {
	for (std::vector<std::string>::const_iterator it = _channels.begin(); it != _channels.end(); it++)
		if (str == *it)
			return true;
	return false;
}

void Client::deleteChan(std::string const &str) {
	for (std::vector<std::string>::const_iterator it = _channels.begin(); it != _channels.end(); it++) {
		if (str == *it) {
			_channels.erase(it);
			return ;
		}
	}
}
