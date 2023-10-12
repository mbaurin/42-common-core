#include "../../headers/command.hpp"

void Command::user(std::vector<std::string> cmds, Client &client) {
	if (client.getRegistered()) {
		sendMessage(client, "462", "", ERR_ALREADYREGISTRED);
		return ;
	} else if (cmds.size() <= 4) {
		sendMessage(client, "461", cmds[0], ERR_NEEDMOREPARAMS);
		return ;
	}
	client.setUser(cmds[1]);
	client.setMode(cmds[2]);
	client.setUnused(cmds[3]);
	client.setRealname(cmds[4]);
	client.setUsed(true);
	registerClient(client);
}
