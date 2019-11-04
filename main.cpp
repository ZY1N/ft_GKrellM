/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:07:05 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 16:47:28 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>
#include <curses.h>
#include "modules/nameModule.hpp"
#include "modules/osModule.hpp"
#include "modules/cpuModule.hpp"
#include "structs.hpp"

#define PCT(d)	(d * 100) << "%"
int main(void)
{
	nameModule nmod;
	osModule omod;
	cpuModule cmod;

	//inits the screen
	initscr();

	mvprintw(1, 25, "FT_GKRELLM");
	refresh();

	//make window (nlines, columns, ybegin, xbegin)
	WINDOW *mainw = newwin(40, 50, 5, 1);
	box(mainw, 0, 0);

	while(1)
	{
		std::string topinfo = get_command_info("top -l 1 -n 0");
		mvwprintw(mainw, 1, 1, nmod.getHost().c_str());
		mvwprintw(mainw, 2, 1, nmod.getUser().c_str());
		mvwprintw(mainw, 3, 1, omod.getProductName().c_str());
		mvwprintw(mainw, 4, 1, omod.getProductVersion().c_str());
		mvwprintw(mainw, 5, 1, omod.getBuildVersion().c_str());
		mvwprintw(mainw, 6, 1, cmod.getcpuinfo().c_str());
		mvwprintw(mainw, 7, 1, "Core# : ");
		mvwprintw(mainw, 7, 1+8, std::to_string(cmod.getcpunumber()).c_str());


		struct cpu_module cpu = get_cpu_module(topinfo);
		mvwprintw(mainw, 12, 1, ("model: " + cpu.model).c_str());
		mvwprintw(mainw, 13, 1, ("cores: " + std::to_string(cpu.cores)).c_str());
		mvwprintw(mainw, 14, 1, "activity: ");


		mvwprintw(mainw, 15, 1, ("user: " + std::to_string(cpu.user)).c_str());
		mvwprintw(mainw, 15, 25, ("sys: " + std::to_string(cpu.sys)).c_str());
		mvwprintw(mainw, 16, 25, ("idle: " + std::to_string(cpu.idle)).c_str());

		mvwprintw(mainw, 17, 1, ("model: " + cpu.model).c_str());

		struct network_module network = get_network_module(topinfo);
		mvwprintw(mainw, 18, 1, ("in: " + network.in).c_str());
		mvwprintw(mainw, 19, 1, ("out: " + network.out).c_str());

		struct ram_module ram = get_ram_module(topinfo);
		mvwprintw(mainw, 20, 1, (("PhysMem used: " + std::to_string(ram.phys_mem_used)).c_str()));
		mvwprintw(mainw, 21, 1, ("PhysMem unused: " + std::to_string(ram.phys_mem_unused)).c_str());
		//mvwprintw(mainw, 22, 25, ("PhysMem ratio: " + PCT(ram.ratio)).c_str());

		struct os_module os = get_os_module();
		mvwprintw(mainw, 23, 1, ("username: " + os.username).c_str());
		mvwprintw(mainw, 24, 1, ("kernel name: " + os.sysname).c_str());
		mvwprintw(mainw, 25, 1, ("network node hostname: " + os.nodename).c_str());
		mvwprintw(mainw, 26, 1, ("kernel release: " + os.release).c_str());
		mvwprintw(mainw, 27, 1, ("kernel version: " + os.version).c_str());
		mvwprintw(mainw, 28, 1, ("machine hardware name: " + os.machine).c_str());
		mvwprintw(mainw, 29, 1, ("processor type: " + os.processor).c_str());

		struct time_module time = get_time_module();
		mvwprintw(mainw, 31, 1, (time.datestr));
		mvwprintw(mainw, 32, 1, (time.timestr));


		wrefresh(mainw);
		sleep(1);
	}

	getch();
	//resets the screen
	endwin();
}
