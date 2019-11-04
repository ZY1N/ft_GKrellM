/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:24:57 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/02 15:24:58 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>


size_t HOST_NAME_MAX = 64;
size_t LOGIN_NAME_MAX = 64;

int main(/*int argc, char **argv*/)
{
	//hostname/username module
	std::cout << "==========================================================" << std::endl;
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);
	std::cout << hostname << std::endl;
	std::cout << username << std::endl;

	
	//os info module using fgets and string
	std::cout << "==========================================================" << std::endl;
	std::string osInfo;
	char line[256];
	FILE *sw_vers = popen("sw_vers", "r");

	while(fgets(line, sizeof(line), sw_vers) !=NULL)
	{
		osInfo = osInfo + line;
	}
	pclose(sw_vers);
	std::cout << osInfo << std::endl;

	
	//date/time module - MOLLY MADE THIS ASK HER FOR IT
	std::cout << "==========================================================" << std::endl;
	

	
	//CPU module(model, clock speed, number of core, activity)
	std::cout << "==========================================================" << std::endl;
    
	//model, clockspeed
	char buffer[1024];
    size_t size=sizeof(buffer);

    if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0) < 0) {
        perror("sysctl");
    }
    std::cout << buffer << '\n';	

	//num of cores
	unsigned int nthreads = std::thread::hardware_concurrency();
	std::cout << "Number of Cores: " << nthreads << std::endl;

	//activity...
	
	//RAM module
	std::cout << "==========================================================" << std::endl;

	
	//network throughput module
	std::cout << "==========================================================" << std::endl;
	



	/*
    if(argc == 1)
        gographical();
    if(argc > 2)
        std::cout << "Usage: "	//inits screen
	//sets up memory and clears screen
	initscr();


	//moves the cursor to location
	//move(y, x);
	int x, y;
	y = x = 10;

	move(y, x);

	//prints a string(const char *) to a window
	printw("Hello World");

	//refersh screen to match memory
	refresh();

	//waits for user input return int value of that key
	int c = getch();

	clear();
	move(0, 0);
	printw("%d", c);

	//mvprintw(0, 0, "%d", c);
	getch();

	//clears screen
	//clear();

	endwin();
	//deallocates memory and ends ncurses */
}