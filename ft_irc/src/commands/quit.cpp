#include "../../headers/command.hpp"

void Command::quit(std::vector<std::string> cmds, Client &client) {
	if (client.getRegistered()) {
		if (cmds.size() > 1 && client.getConnected()) {
			sendConfirm(client, cmds[0], cmds[1]);
		} else if (client.getConnected())
			sendConfirm(client, cmds[0], client.getNick());
		for (std::vector<std::string>::iterator it = client.getChannels().begin(); it != client.getChannels().end(); it++) {
			std::map<std::string, Channel>::iterator itMap = chanMap.find(*it);
			itMap->second.deleteClient(&client);
			if(itMap->second.chanEmpty())
				chanMap.erase(itMap);
		}
		for (std::list<Client>::iterator itClient = clients.begin(); itClient != clients.end(); itClient++) {
			if (&(*itClient) != &client) {
				for (std::vector<std::string>::iterator it = client.getChannels().begin(); it != client.getChannels().end(); it++) {
					if (itClient->isInChan(*it)) {
						if (cmds.size() > 1)
							sendConfirmTo(*itClient, client, cmds[0], cmds[1]);
						else
							sendConfirmTo(*itClient, client, cmds[0], client.getNick());
						break ;
					}
				}
			}
		}
	}
	if (client.getConnected())
		closeLink(client, "Closing Link", client.getIP() + " (Client Quit)");
	std::cout <<  "Host disconnected Socket fd: " << client.getSocket() << " IP: " << client.getIP() << " Port Client: " << client.getPort() << std::endl;
	close(client.getSocket());
	client.setbeDeleted(true);
}
