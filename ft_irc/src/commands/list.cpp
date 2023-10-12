#include "../../headers/command.hpp"

void Command::list(std::vector<std::string> cmds, Client &client) {
    if (!client.getRegistered()) {
        sendMessage(client, "451", "", ERR_NOTREGISTERED);
		return ;
	}
    sendMessage(client, "321", "", "Channel: Users  Name");
    std::map<std::string, Channel>::iterator itMap;
    std::string message;
    if (cmds.size() == 1) {
        for (itMap = chanMap.begin(); itMap != chanMap.end(); itMap++) {
            std::string channel(itMap->first);
            if (!message.empty())
                message = "";
            message.append(itMap->second.getTopic());
            sendMessage(client, "322", channel + ":", message);
        }
    } else if (cmds.size() > 1) {
        std::vector<std::string> keys = ft_split(cmds[1], ",");
        for (std::vector<std::string>::iterator iChan = keys.begin(); iChan != keys.end(); iChan++) {
            if (!message.empty())
                message = "";
            for (itMap = chanMap.begin(); itMap != chanMap.end(); itMap++) {
                if (itMap->first == *iChan) {
                    message.append(itMap->second.getTopic());
                    sendMessage(client, "322", itMap->first + ":", message);
                }
            }
        }
    }
    if (cmds.size() == 1)
        sendMessage(client, "323", "", ": End of /NAMES list.");
    else    
        sendMessage(client, "323", cmds[1] +  ": End of", "/NAMES list.");
    return ;
}
