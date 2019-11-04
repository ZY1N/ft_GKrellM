/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:08:17 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 13:08:18 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>

class cpuModule
{
    public:
        cpuModule();
        cpuModule(const cpuModule &obj);
        ~cpuModule();
        cpuModule &operator=(const cpuModule &obj);
        unsigned int getcpunumber() const;
        std::string getcpuinfo() const;
    private:
        unsigned int _cpuNumber;
        std::string _cpuInfo;
};

#endif
