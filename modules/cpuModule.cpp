/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:08:13 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 13:08:14 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpuModule.hpp"


cpuModule::cpuModule()
{
	char buffer[1024];
    size_t size=sizeof(buffer);

    if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0) < 0) {
        perror("sysctl");
    }
    this->_cpuInfo = buffer;

	//num of cores
	unsigned int nthreads = std::thread::hardware_concurrency();
    this->_cpuNumber = nthreads;

    return ;
}

cpuModule::cpuModule(const cpuModule &obj)
{
    *this = obj;
    return ;
}

cpuModule::~cpuModule()
{
    return ;
}

cpuModule &cpuModule::operator=(const cpuModule &obj)
{
    this->_cpuNumber = obj.getcpunumber();
    this->_cpuInfo = obj.getcpuinfo();
    return(*this);
}

unsigned int cpuModule::getcpunumber() const
{
    return(this->_cpuNumber);
}

std::string cpuModule::getcpuinfo() const
{
    return(this->_cpuInfo);
}
