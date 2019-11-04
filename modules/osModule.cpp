/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:33:56 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 12:33:57 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osModule.hpp"


osModule::osModule()
{
	std::string pname;
	char line[256];
	FILE *sw_vers = popen("sw_vers | grep \"ProductName\"", "r");

	while(fgets(line, sizeof(line), sw_vers) !=NULL)
	{
		pname = pname + line;
	}
	pclose(sw_vers);
    this->_productName = pname;

    std::string pversion;
	FILE *sw_vers1 = popen("sw_vers | grep \"ProductVersion\"", "r");

	while(fgets(line, sizeof(line), sw_vers) !=NULL)
	{
		pversion = pversion + line;
	}
	pclose(sw_vers1);
    this->_productVersion = pversion;

    std::string pbuildversion;
	FILE *sw_vers2 = popen("sw_vers | grep \"BuildVersion\"", "r");

	while(fgets(line, sizeof(line), sw_vers) !=NULL)
	{
		pbuildversion = pbuildversion + line;
	}
	pclose(sw_vers2);
    this->_buildVersion = pbuildversion;
    return ;
}

osModule::osModule(const osModule &obj)
{
    *this = obj;
    return ;
}

osModule::~osModule()
{
    return ;
}

osModule &osModule::operator=(const osModule &obj)
{
    this->_productName = obj.getProductName();
    this->_productVersion = obj.getProductVersion();
    this->_buildVersion = obj.getBuildVersion();
    return(*this);
}

std::string osModule::getProductName() const
{
    return(this->_productName);
}

std::string osModule::getProductVersion() const
{
    return(this->_productVersion);
}

std::string osModule::getBuildVersion() const
{
    return(this->_buildVersion);
}
