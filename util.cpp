#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>

#define BUFSIZE 1028
std::string	get_command_info(std::string command)
{
	std::string osInfo;
	char line[BUFSIZE];
	FILE *sw_vers = popen(command.c_str(), "r");
	while(fgets(line, sizeof(line), sw_vers) !=NULL)
	{
		osInfo = osInfo + line;
	}
	pclose(sw_vers);
	return (osInfo);
}

std::string	substr_between(std::string str, std::string begin, std::string end)
{
	size_t	begin_index = str.find(begin) + begin.length();
	str.erase(0, begin_index);
	size_t	end_index = str.find(end);

	return (str.substr(0, end_index));
}