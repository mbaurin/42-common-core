#include "../../headers/command.hpp"

void Command::part(std::vector<std::string> cmds, Client &client) {
	if (!client.getRegistered()) {
		sendMessage(client, "451", "", ERR_NOTREGISTERED);
		return ;
	} else if (cmds.size() < 2) {
		sendMessage(client, "461", cmds[0], ERR_NEEDMOREPARAMS);
		return ;
	}
	std::vector<std::string> chans = ft_split(cmds[1], ",");
	for (std::vector<std::string>::iterator it = chans.begin(); it != chans.end(); it++) {
		std::map<std::string, Channel>::iterator itMap = chanMap.find(*it);
		if (itMap == chanMap.end())
			sendMessage(client, "403", cmds[0], *it + ERR_NOSUCHCHANNEL);
		else {
			if (client.isInChan(*it)) {
				sendConfirm(client, cmds[0] + " " + *it, "");
				itMap->second.sendConfirmChan(client, cmds[0] + " " + *it, "");
				itMap->second.deleteClient(&client);
				client.deleteChan(*it);
				if (itMap->second.chanEmpty())
					chanMap.erase(itMap);
			} else
				sendMessage(client, "442", cmds[0], *it + ERR_NOTONCHANNEL);
		}
	}
}
