#include "./../includes/Logger.hpp"

int		main(void)
{
	Logger	*logger = new Logger("2173080211_space_log");

	logger->log("console", "On 'Justine' I have found one jumpfuel. Now I am able to leave this system.\n\
Just want to check last ship here 'Quiet Cruise'. Jeff had sensor issues again.\n\
I think this module isn't reliable any more. Should replace as soon as I find one.");
	logger->log("Console", "Last wrecks almost killed me. No fuel. No drons. Nothing.\n\
I have lost Chappy. Those damn nanobots broke thorugh the shield.\n\
They were not like I've seen before. Some new form. In the shiplog I have found information\n\
about trading and military outposts in 'Zetta' system. I have jumpfuel left for one more jump.\n\
I will go to 'Zetta' system and try to find new drones and replacement for broken parts.\n\
Maybe I'll meet other survivors there or at least find out what happened...");
	logger->log("file", "On 'Justine' I have found one jumpfuel. Now I am able to leave this system.\n\
Just want to check last ship here 'Quiet Cruise'. Jeff had sensor issues again.\n\
I think this module isn't reliable any more. Should replace as soon as I find one.");
	logger->log("File", "Last wrecks almost killed me. No fuel. No drons. Nothing.\n\
I have lost Chappy. Those damn nanobots broke thorugh the shield.\n\
They were not like I've seen before. Some new form. In the shiplog I have found information\n\
about trading and military outposts in 'Zetta' system. I have jumpfuel left for one more jump.\n\
I will go to 'Zetta' system and try to find new drones and replacement for broken parts.\n\
Maybe I'll meet other survivors there or at least find out what happened...");
	return (0);
}
