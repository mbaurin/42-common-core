#include "../../headers/command.hpp"

void Command::invite(std::vector<std::string> cmds, Client &client) {
	if (!client.getRegistered()) {
		sendMessage(client, "451", "", ERR_NOTREGISTERED);
		return ;
	} else if (cmds.size() < 2) {
		sendMessage(client, "461", cmds[0], ERR_NEEDMOREPARAMS);
		return ;
	}
	std::list<Client>::iterator	it;
	for (it = clients.begin(); it != clients.end(); it++)
		if (it->getNick() == cmds[1])
			break ;
	if (it == clients.end()) {
        sendMessage(client, "401", cmds[1], ERR_NOSUCHNICK);
        return ;
	} else if (!client.isInChan(cmds[2])) {
		sendMessage(client, "442", cmds[2], ERR_NOTONCHANNEL);
		return ;
	} else if (!chanMap[cmds[2]].isChanOp(client)) {
		sendMessage(client, "482", cmds[2] + " ", ERR_CHANOPRIVSNEEDED);
		return ;
	} else if (it->isInChan(cmds[2])) {
		sendMessage(client, "443", cmds[1] + " " + cmds[2], ERR_USERONCHANNEL);
		return ;
	}
	sendMessage(client, "341", cmds[1] + " " + cmds[2], "");
	sendConfirmTo(*it, client, cmds[0] + " " + it->getNick(), cmds[2]);
	std::map<std::string, Channel>::iterator itMap = chanMap.find(cmds[2]);
	if (itMap != chanMap.end())
		itMap->second.addInvited(&(*it));
}
