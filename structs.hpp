#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>
#include <string>

std::string	get_command_info(std::string command);
std::string	substr_between(std::string str, std::string begin, std::string end);

struct os_module {
	std::string	username;
	std::string	sysname;
	std::string	nodename;
	std::string	release;
	std::string	version;
	std::string	machine;
	std::string	processor;

	std::string	p_name;
	std::string	p_version;
	std::string	b_version;
};
struct os_module	get_os_module(void);

struct time_module {
	time_t		rawtime;
	struct tm	timeinfo;
	char		datestr[40];
	char		timestr[40];
};;
struct time_module	get_time_module(void);

struct cpu_module {
	std::string	model;
	int			clock_speed;
	int			cores;
	std::string	user;
	std::string	sys;
	double	idle;
};
struct cpu_module	get_cpu_module(std::string topinfo);

struct network_module {
	std::string	in;
	std::string	out;
};
struct network_module	get_network_module(std::string topinfo);

struct ram_module {
	int	phys_mem_used;
	int	phys_mem_unused;
	double ratio;
};
struct ram_module	get_ram_module(std::string topinfo);