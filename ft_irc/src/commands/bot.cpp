#include "../../headers/command.hpp"
#include <chrono> 
#include <thread>

void Command::bot(std::vector<std::string> cmds, Client &client) {
    std::string header = "PRIVMSG ";
    std::string message = "I am a bot and I want to talk for ";
    int speakTimes = atoi(cmds[1].c_str());
    while (speakTimes > 0) {
        for (std::list<Client>::iterator it = clients.begin(); it != clients.end(); it++)
            sendConfirmTo(*it, client, header + message + std::to_string(speakTimes) + " times", "");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        speakTimes--;
    }
}
