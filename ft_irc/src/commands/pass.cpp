#include "../../headers/command.hpp"

void Command::pass(std::vector<std::string> cmds, Client &client) {
	if (cmds.size() == 1) {
		sendMessage(client, "461", "", ERR_NEEDMOREPARAMS);
		return ;
	} else if (client.getRegistered()) {
		sendMessage(client, "462", "", ERR_ALREADYREGISTRED);
		return ;
	} else if (password != cmds[1]) {
		sendMessage(client, "464", "", ERR_PASSWDMISMATCH);
        return ;
	}
	client.setPass(cmds[1]);
}
