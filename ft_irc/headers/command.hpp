#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "client.hpp"
#include "channel.hpp"
#include "messages.hpp"
#include <list>
#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class Command {
	typedef void (Command::*pfunc)(std::vector<std::string>, Client &);

	public:
		Command(std::string const &pass, std::list<Client> &clients, std::string const &IP);
		~Command();

		void sendMessage(Client const &client, std::string nb, std::string opt, std::string err);
		void sendConfirm(Client const &client, std::string const &cmd, std::string const &opt);
		void sendConfirmTo(Client const &client, Client const &terminator, std::string const &cmd, std::string const &opt);
		void sendSpecConfirm(Client const &client, std::string const &prefix, std::string const &cmd, std::string const &opt);

		void closeLink(Client const &client, std::string const &arg, std::string const &opt);

		bool isSpecialChar(char c) const;

		void setIP(std::string const &val);

		std::vector<std::string> ft_split(std::string const &s, std::string const &separator);
		std::vector<std::string> splitCmd(std::string const &s, std::string const &separator);

		void parsCmd(Client &client);

		void registerClient(Client &client);

		void nick(std::vector<std::string> cmds, Client &client);
		void user(std::vector<std::string> cmds, Client &client);
		void pass(std::vector<std::string> cmds, Client &client);
		void quit(std::vector<std::string> cmds, Client &client);
		void oper(std::vector<std::string> cmds, Client &client);	
		void join(std::vector<std::string> cmds, Client &client);
		void part(std::vector<std::string> cmds, Client &client);
		void mode(std::vector<std::string> cmds, Client &client);
		void ping(std::vector<std::string> cmds, Client &client);
		void privatemsg(std::vector<std::string> cmds, Client &client);
		void notice(std::vector<std::string> msg, Client &client);
		void invite(std::vector<std::string> cmds, Client &client);
		void topic(std::vector<std::string> cmds, Client &client);
		void names(std::vector<std::string> cmds, Client &client);
		void list(std::vector<std::string> cmds, Client &client);	
		void kick(std::vector<std::string> cmds, Client &client);
		void bot(std::vector<std::string> cmds, Client &client);

		std::string	usedMods(std::string channel);

	private:
		std::string	password;
		std::list<Client> &clients;
		std::string	IP;
		std::map<std::string, pfunc> cmdMap;
		std::vector<std::string> mods;
		std::map<std::string, Channel> chanMap;
};

#endif
