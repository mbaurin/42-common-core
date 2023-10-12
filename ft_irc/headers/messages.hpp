#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# define CLIENT client.getNick() + "!" + client.getUser() + "@" + client.getIP()
# define TERMINATOR terminator.getNick() + "!" + terminator.getUser() + "@" + terminator.getIP()

# define RPL_WELCOME ":Welcome to the ft_IRC Internet Relay Network " + CLIENT
# define RPL_NOTOPIC ":No topic is set"
# define RPL_YOUREOPER ":You are now an IRC operator"

# define ERR_NOTREGISTERED ":You have not registered"
# define ERR_NOSUCHNICK ":No such nick/channel"
# define ERR_NORECIPIENT ":No recipient given (PRIVMSG)"
# define ERR_NOTEXTTOSEND ":No text to send"
# define ERR_CANNOTSENDTOCHAN ":Cannot send to channel"
# define ERR_CHANOPRIVSNEEDED ":You're not channel operator"
# define ERR_USERNOTINCHANNEL ":They aren't on that channel"
# define ERR_NEEDMOREPARAMS ":Not enough parameters"
# define ERR_ALREADYREGISTRED ":Unauthorized command (already registered)"
# define ERR_PASSWDMISMATCH ":Password incorrect"
# define ERR_NOSUCHCHANNEL ":No such channel"
# define ERR_NOTONCHANNEL " :You're not on that channel"
# define ERR_USERONCHANNEL ":is already on channel"
# define ERR_INVITEONLYCHAN " :Cannot join channel (+i)"
# define ERR_BADCHANNELKEY " :Cannot join channel (+k)"
# define ERR_UNKNOWNCOMMAND ":Unknown command"
# define ERR_NONICKNAMEGIVEN ":No nickname given"
# define ERR_NICKNAMEINUSE ":Nickname is already in use"
# define ERR_ERRONEUSNICKNAME ":Erroneous nickname"
# define ERR_UMODEUNKNOWNFLAG ":Unknown MODE flag"
# define ERR_USERSDONTMATCH ":Cannot change mode for other users"

#endif
