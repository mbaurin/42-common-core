#include "../../headers/command.hpp"

void Command::privatemsg(std::vector<std::string> cmds, Client &client) {
    if(!client.getRegistered()) {
        sendMessage(client, "451","", ERR_NOTREGISTERED);
        return ;
    } else if(cmds.size() == 1) {
        sendMessage(client, "411", "", ERR_NORECIPIENT);
        return ;
    } else if(cmds.size() == 2) {
        sendMessage(client, "412", "", ERR_NOTEXTTOSEND);
        return ;
    } else if (cmds[1][0] == '#') {
        std::map<std::string, Channel>::iterator itMap = chanMap.find(cmds[1]);
        if (itMap != chanMap.end()) {
            if (!client.isInChan(itMap->first)) {
                sendMessage(client, "404", cmds[1], ERR_CANNOTSENDTOCHAN);
                return ;
            }
            itMap->second.sendConfirmChan(client, cmds[0] + " " + cmds[1], cmds[2]);
            return ;
        } else {
            sendMessage(client, "401", cmds[1], ERR_NOSUCHNICK);
            return ;
        }
    } else {
        std::list<Client>::iterator	it = clients.begin();
        for (; it != clients.end(); it++)
            if (cmds[1] == it->getNick())
                break ;
        if (it == clients.end()) {
            sendMessage(client, "401", "", ERR_NOSUCHNICK);
            return ;
        } else {
            sendConfirmTo(*it, client, cmds[0] + " " + cmds[1], cmds[2]);
            return ;
        }
    }
}
