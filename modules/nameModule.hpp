/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nameModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:54:12 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/02 18:54:13 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMEMODULE_H
#define NAMEMODULE_H

#include <iostream>
#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>

class nameModule
{
    public:
        nameModule();
        nameModule(const nameModule &obj);
        ~nameModule();
        nameModule &operator=(const nameModule &obj);
        std::string getHost() const;
        std::string getUser() const;
    private:
        std::string _hostname;
        std::string _username;
};

#endif
