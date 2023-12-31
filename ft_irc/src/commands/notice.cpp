#include "../../headers/command.hpp"

void Command::notice(std::vector<std::string> cmds, Client &client) {
    if(!client.getRegistered()) {
        sendMessage(client, "451", "", ERR_NOTREGISTERED);
        return ;
    } else if (cmds.size() == 3) {
        std::list<Client>::iterator	it = clients.begin();
        for (; it != clients.end(); it++)
            if (cmds[1] == it->getNick())
                break ;
        if (it != clients.end()) {
            sendConfirmTo(*it, client, cmds[0] + " " + cmds[1], cmds[2]);
            return ;
        }
    }
    return ;
}
