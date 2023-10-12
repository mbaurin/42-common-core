#include "../../headers/command.hpp"

void Command::join(std::vector<std::string> cmds, Client &client) {
	if (!client.getRegistered()) {
		sendMessage(client, "451", "", ERR_NOTREGISTERED);
		return ;
	} else if (cmds.size() < 2) {
		sendMessage(client, "461", cmds[0], ERR_NEEDMOREPARAMS);
		return ;
	}
	std::vector<std::string> chans = ft_split(cmds[1], ",");
	std::vector<std::string> keys;
	if (cmds.size() > 2)
		keys = ft_split(cmds[2], ",");
	for (std::vector<std::string>::iterator it = chans.begin(); it != chans.end(); it++) {
		std::vector<std::string>::iterator itKey = keys.begin();
		std::map<std::string, Channel>::iterator itMap = chanMap.find(*it);
		if (it->length() > 50 || (*it)[0] != '#')
			sendMessage(client, "403", cmds[0], *it + " " + ERR_NOSUCHCHANNEL);
		else if (itMap == chanMap.end()) {
			itMap =	chanMap.insert(std::pair<std::string, Channel>(*it, Channel())).first;
			itMap->second.addChanOp(&client);
			if (itKey != keys.end())
				itMap->second.setPassword(*itKey);
			client.getChannels().push_back(*it);
			sendConfirm(client, cmds[0] + " " + *it, "");
			sendMessage(client, "324", cmds[1], usedMods(cmds[1]));
			itMap->second.sendConfirmChan(client, cmds[0] + " " + *it, "");
		} else {
			if (!client.isInChan(*it)) {
				if (!itMap->second.getPassword().empty() && (itKey == keys.end() || itMap->second.getPassword() != *itKey))
					sendMessage(client, "475", *it + ERR_BADCHANNELKEY, "");
				else if (itMap->second.getInvite() && !itMap->second.isInvited(client))
					sendMessage(client, "473", *it + ERR_INVITEONLYCHAN, "");
				else {
					itMap->second.addClient(&client);
					client.getChannels().push_back(*it);
					sendConfirm(client, cmds[0] + " " + *it, "");
					sendMessage(client, "324", cmds[1], usedMods(cmds[1]));
					if (!itMap->second.getTopic().empty()) {
						sendMessage(client, "332", *it, itMap->second.getTopic());
						sendMessage(client, "333", *it, itMap->second.getTopicAuthor());
					}
					itMap->second.sendConfirmChan(client, cmds[0] + " " + *it, "");
				}
			}
		}
		if (itKey != keys.end())
			itKey++;
	}
}
