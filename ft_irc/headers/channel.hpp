#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "client.hpp"
#include "messages.hpp"
#include <vector> 
#include <iostream>
#include <string>
#include <ctime>
#include <sys/socket.h> 

class Channel {
	public:
		Channel();
		~Channel();

		void addClient(Client *client);
		void deleteClient(Client *client);

		void addChanOp(Client *client);

		void addInvited(Client *client);
		bool isInvited(Client &client) const;
		void deleteInvited(Client *client);

		void setInvite(bool set);
		bool getInvite();

		void setTopic(std::string const &val, Client &client);
		std::string	const &getTopic();
			
		void enableTopic(bool val);
		bool getEnableTopic();

		void setPassword(std::string const &str);
		std::string const &getPassword(void) const;

		void sendConfirmChan(Client const &client, std::string const &cmd, std::string const &opt);

		bool isChanOp(Client const &client);
		bool chanEmpty() const;
		std::string getTopicAuthor();

	private:
			std::vector<Client *> _clients;
			std::vector<Client *> _chanOp;
			std::vector<Client *> _invited;
			bool _invite;
			bool _topicEnabled;
			std::string _topicAuthor;
			std::string	_topic;
			std::string	_password;
};

#endif
