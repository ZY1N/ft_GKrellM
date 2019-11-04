/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nameModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:54:16 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/02 18:54:17 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nameModule.hpp"

size_t HOST_NAME_MAX = 64;
size_t LOGIN_NAME_MAX = 64;

nameModule::nameModule()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

    this->_hostname = hostname;
    this->_username = username;
    return ;
}

nameModule::nameModule(const nameModule &obj)
{
    *this = obj;
    return ;
}

nameModule::~nameModule()
{
    return ;
}

nameModule &nameModule::operator=(const nameModule &obj)
{
    this->_hostname = obj.getHost();
    this->_username = obj.getUser();
    return(*this);
}

std::string nameModule::getHost() const
{
    return(this->_hostname);
}

std::string nameModule::getUser() const
{
    return(this->_username);
}
