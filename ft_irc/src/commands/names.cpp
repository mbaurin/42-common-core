#include "../../headers/command.hpp"

void Command::names(std::vector<std::string> cmds, Client &client) {
    if (!client.getRegistered()) {
        sendMessage(client, "451", "", ERR_NOTREGISTERED);
		return ;
	}
    if (cmds.size() == 1) {
        std::string message, channel;
        for (std::map<std::string, Channel>::iterator itMap = chanMap.begin(); itMap != chanMap.end(); itMap++) {
            if (!message.empty())
                message = "";
            if (!channel.empty())
                channel = "";
            for(std::list<Client>::iterator	itClient = clients.begin(); itClient != clients.end(); itClient++) {
                if (itMap->second.isChanOp(*itClient) == true)
                    message.append(itClient->getNick() + " ");
                else if (itClient->isInChan(itMap->first) == true)
                    message.append(itClient->getNick() + " ");
                else if (itClient->getChannels().size() == 0)
                    channel.append(itClient->getNick() + " ");
            }
            sendMessage(client, "353", itMap->first + ":", message);
        }
        if (channel.size() > 0)
            sendMessage(client, "353", ":", channel);
    } else if (cmds.size() > 1) {
        std::vector<std::string> keys = ft_split(cmds[1], ",");
        std::string message;    
        for (std::vector<std::string>::iterator iChan = keys.begin(); iChan != keys.end(); iChan++) {
            if (!message.empty())
                message = "";
            for (std::map<std::string, Channel>::iterator itMap = chanMap.begin(); itMap != chanMap.end(); itMap++) {
                if (itMap->first == *iChan) {
                    for (std::list<Client>::iterator itClient = clients.begin(); itClient != clients.end(); itClient++) {
                        if (itMap->second.isChanOp(*itClient) == true)
                            message.append(itClient->getNick() + " ");
                        else if (itClient->isInChan(itMap->first) == true)
                            message.append(itClient->getNick() + " ");
                    }
                    sendMessage(client, "353", itMap->first + ":", message);
                }
            }
        }
    }
    if (cmds.size() == 1)
        sendMessage(client, "366", "", ":End of /NAMES list.");
    else    
        sendMessage(client, "366", cmds[1] +  ":End of", "/NAMES list.");
    return ;
}
