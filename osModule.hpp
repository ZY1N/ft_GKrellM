/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+ q +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:33:50 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 12:33:51 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_H
#define OSMODULE_H

#include <iostream>
#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <thread>
#include <sys/sysctl.h>

class osModule
{
    public:
        osModule();
        osModule(const osModule &obj);
        ~osModule();
        osModule &operator=(const osModule &obj);
        std::string getProductName() const;
        std::string getProductVersion() const;
        std::string getBuildVersion() const;
    private:
        std::string _productName;
        std::string _productVersion;
        std::string _buildVersion;
};

#endif
