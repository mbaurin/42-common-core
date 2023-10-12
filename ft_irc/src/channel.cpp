#include "../headers/channel.hpp"

Channel::Channel(): _invite(false), _topicEnabled(false), _topic(""), _password("") {}

Channel::~Channel() {}

void Channel::addClient(Client *client) { _clients.push_back(client); }

void Channel::deleteClient(Client *client) {
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if (client == *it) {
			_clients.erase(it);
			return ;
		}
	}
	for (std::vector<Client *>::iterator it = _chanOp.begin(); it != _chanOp.end(); it++) {
		if (client == *it) {
			_chanOp.erase(it);
			return ;
		}
	}
}

void Channel::addChanOp(Client *client) { _chanOp.push_back(client); }

void Channel::addInvited(Client *client) { _invited.push_back(client); }

bool Channel::isInvited(Client &client) const {
	for (std::vector<Client *>::const_iterator it = _invited.begin(); it != _invited.end(); it++)
		if (*it == &client)
			return true;
	return false;
}

void Channel::deleteInvited(Client *client) {
	for (std::vector<Client *>::iterator it = _invited.begin(); it != _invited.end(); it++) {
		if (client == *it) {
			_invited.erase(it);
			return ;
		}
	}
}

void Channel::setInvite(bool set) { _invite = set; }

bool Channel::getInvite() { return (_invite); }

void Channel::setTopic(std::string const &val, Client &client)  {
	_topic = val;
	_topicAuthor.assign(CLIENT);
}

std::string const &Channel::getTopic() { return (_topic); }

void  Channel::enableTopic(bool val) { _topicEnabled = val; }

bool Channel::getEnableTopic() { return (_topicEnabled); }

void Channel::setPassword(std::string const &str) { _password = str; }

std::string const &Channel::getPassword(void) const { return (_password); }

void Channel::sendConfirmChan(Client const &client, std::string const &cmd, std::string const &opt) {
	std::string message = ":" + CLIENT;
	if (opt.empty())
		message += " " + cmd + "\r\n";
	else
		message += " " + cmd + " :" + opt + "\r\n";
	std::vector<Client *>::iterator it;
	for (it = _clients.begin(); it != _clients.end(); it++)
		if (*it != &client)
			send((*it)->getSocket(), message.c_str(), message.length(), 0);
	for (it = _chanOp.begin(); it != _chanOp.end(); it++)
		if (*it != &client)
			send((*it)->getSocket(), message.c_str(), message.length(), 0);
}

bool Channel::isChanOp(Client const &client) {
	for (std::vector<Client *>::iterator it = _chanOp.begin(); it != _chanOp.end(); it++)
		if (*it == &client)
			return true;
	return false;
}

bool Channel::chanEmpty() const { return (_clients.empty() && _chanOp.empty()); }

std::string Channel::getTopicAuthor() {return (_topicAuthor);}
