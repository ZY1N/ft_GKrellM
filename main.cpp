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
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "structs.hpp"

#define WIDTH 45

void	print_os_mod(int start)
{
	struct os_module os = get_os_module();

	WINDOW *w = newwin(11, WIDTH, start, 2);
	box(w, 0, 0);

	mvwprintw(w, 1, 1, ("             username: " + os.username).c_str());
	mvwprintw(w, 2, 1, ("network node hostname: " + os.nodename).c_str());
	mvwprintw(w, 3, 1, ("          kernel name: " + os.sysname).c_str());
	mvwprintw(w, 4, 1, ("       kernel release: " + os.release).c_str());
	mvwprintw(w, 5, 1, ("machine hardware name: " + os.machine).c_str());
	mvwprintw(w, 6, 1, ("       processor type: " + os.processor).c_str());
	mvwprintw(w, 7, 1, ("         product name: " + os.p_name).c_str());
	mvwprintw(w, 8, 1, ("      product version: " + os.p_version).c_str());
	mvwprintw(w, 9, 1, ("        build version: " + os.b_version).c_str());

	wrefresh(w);
}

void	print_time_mod(int start)
{
	struct time_module m = get_time_module();
	
	WINDOW *w = newwin(4, WIDTH, start, 2);
	box(w, 0, 0);

	mvwprintw(w, 1, 1, (m.datestr));
	mvwprintw(w, 2, 1, (m.timestr));

	wrefresh(w);
}

void	print_graph(int start, double bottom, double top)
{
	static std::vector<int> stalagmite;
	static std::vector<int> stalactite;

	stalagmite.insert(stalagmite.begin(), round(bottom));
	if (stalagmite.size() >= WIDTH - 2)
		stalagmite.pop_back();
	stalactite.insert(stalactite.begin(), round(top));
	if (stalactite.size() >= WIDTH - 2)
		stalactite.pop_back();

	WINDOW *g = newwin(10 + 2, WIDTH - 2, start, 3);
	box(g, 0, 0);
	for (int jj = 0; jj + 1 < (int)stalagmite.size(); ++jj)
	{
		for (int i = 1; i <= 10; ++i)
		{
			if (i <= stalagmite[jj])
				mvwprintw(g, 11 - i, 1 + jj, "*");
			if (i <= stalactite[jj])
				mvwprintw(g, i, 1 + jj, "o");
		}
	}
	wrefresh(g);
}

void	print_cpu_mod(int start, std::string topinfo)
{
	struct cpu_module cpu = get_cpu_module(topinfo);

	WINDOW *w = newwin(18, WIDTH, start + 1, 2);
	box(w, 0, 0);
	mvwprintw(w, 1, 1, ("   model: " + cpu.model).c_str());
	mvwprintw(w, 2, 1, ("   cores: " + std::to_string(cpu.cores)).c_str());

	mvwprintw(w, 4, 1, ("\t~activity~"));
	mvwprintw(w, 4, 25, ("user: " + cpu.user + "%").c_str());
	mvwprintw(w, 3, 25, (" sys: " + cpu.sys + "%").c_str());
//	mvwprintw(w, 6, 25, ("idle: " + std::to_string(cpu.idle) + " %").c_str());

	wrefresh(w);

	print_graph(start + 6, std::stod(cpu.user) / 10, std::stod(cpu.sys) / 10);
//	print_graph(start + 6, 50 / 10, 50 / 10);
}

void	print_network_mod(int start, std::string topinfo)
{
	struct network_module network = get_network_module(topinfo);

	WINDOW *w = newwin(4, WIDTH, start, 2);
	box(w, 0, 0);

	mvwprintw(w, 1, 1, ("in: " + network.in).c_str());
	mvwprintw(w, 2, 1, ("out: " + network.out).c_str());

	wrefresh(w);
}

void	print_ram_mod(int start, std::string topinfo)
{
	struct ram_module ram = get_ram_module(topinfo);

	WINDOW *w = newwin(4, WIDTH, start, 2);
	box(w, 0, 0);

	mvwprintw(w, 1, 1, ("  used: " + std::to_string(ram.phys_mem_used)).c_str());
	mvwprintw(w, 2, 1, ("unused: " + std::to_string(ram.phys_mem_unused)).c_str());
	//mvwprintw(w, start + 2, 25, ("PhysMem ratio: " + PCT(ram.ratio)).c_str());

	wrefresh(w);
}

int main(void)
{

	//inits the screen
	initscr();
	curs_set(0);

	//colors
//	start_color();
//	init_pair(1, COLOR_RED, COLOR_BLACK);

	mvprintw(1, 25, "FT_GKRELLM");
	refresh();

	//make window (nlines, columns, ybegin, xbegin)
	WINDOW *mainw = newwin(44, WIDTH + 2, 5, 1);
	box(mainw, 0, 0);

//	Graph test(100);
	while(1)
	{
		std::string topinfo = get_command_info("top -l 1 -n 0");

		print_time_mod(6);//	height: 4
		print_os_mod(10);//	height: 7
		print_cpu_mod(20, topinfo); //height 8
		print_ram_mod(39, topinfo); // height 4
		print_network_mod(43, topinfo); //height 4

		wrefresh(mainw);
		sleep(1);
	}

	getch();
	//resets the screen
	endwin();
}
