/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:01:11 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/02 17:01:12 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.hpp"

struct os_module	get_os_module(void)
{
	struct os_module m;

	m.username = substr_between(get_command_info("whoami"), "", "\n");
	//https://explainshell.com/explain/1/uname
	m.sysname = substr_between(get_command_info("uname -s"), "", "\n");
	m.nodename = substr_between(get_command_info("uname -n"), "", "\n");
	m.release = substr_between(get_command_info("uname -r"), "", "\n");
	m.version = substr_between(get_command_info("uname -v"), "", "\n");
	m.machine = substr_between(get_command_info("uname -m"), "", "\n");
	m.processor = substr_between(get_command_info("uname -p"), "", "\n");

	m.p_name = substr_between(get_command_info("sw_vers -productName"), "", "\n");
	m.p_version = substr_between(get_command_info("sw_vers -productVersion"), "", "\n");
	m.b_version = substr_between(get_command_info("sw_vers -buildVersion"), "", "\n");
	return (m);
}

//https://en.cppreference.com/w/cpp/chrono/c/strftime
struct time_module	get_time_module(void)
{
	struct time_module m;
	m.rawtime = time(0);
	m.timeinfo = *localtime(&m.rawtime);

	strftime(m.datestr, 40, "%a %e %b", &m.timeinfo);
	strftime(m.timestr, 40, "%X", &m.timeinfo);
	return (m);
}

struct cpu_module	get_cpu_module(std::string topinfo)
{
	std::string str = substr_between(topinfo, "CPU usage:", "\n");
//	std::cout << str << std::endl;
	struct cpu_module m;

	m.user = std::stod(substr_between(str, " ", " user"));
	m.sys = std::stod(substr_between(str, "user, ", " sys"));
	m.idle = std::stod(substr_between(str, "sys, ", " idle"));

	m.model = substr_between(//	"sysctl -n machdep.cpu.model"
		get_command_info("sysctl -n machdep.cpu.brand_string"),
		"Core(TM) ", " CPU");
	m.cores = std::stoi(get_command_info("sysctl -n hw.ncpu"));

	return (m);
}

struct network_module	get_network_module(std::string topinfo)
{
	std::string str = substr_between(topinfo, "Networks:", "\n");
//	std::cout << str << std::endl;
	struct network_module m;

	m.in = substr_between(str, "packets: ", " in");
	m.out = substr_between(str, "in, ", " out");
	return (m);
}

struct ram_module	get_ram_module(std::string topinfo)
{
	std::string str = substr_between(topinfo, "PhysMem:", "\n");
//	std::cout << str << std::endl;
	struct ram_module m;

	m.phys_mem_used = std::stoi(substr_between(str, " ", " used"));
	m.phys_mem_unused = std::stoi(substr_between(str, "wired),", " unused"));
	m.ratio = (double)m.phys_mem_used / (double)(m.phys_mem_used + m.phys_mem_unused);
	return (m);
}