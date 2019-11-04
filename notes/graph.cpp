/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:17:51 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 17:17:52 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"

Graph::Graph(int calibration)
{
    int x = 0;
    int y = 0;

    while(x < 10)
    {
        y = 0;
        while(y < 25)
        {
            this->_graphshow[x][y] = ' ';
            y++;
        }
        x++;
    }
    this->calibration = calibration;
    return ;
}

Graph::~Graph()
{
    return ;
}

Graph::Graph(const Graph &obj)
{
    *this = obj;
    return ;
}

Graph &Graph::operator=(const Graph &obj)
{
    int x = 0;
    int y = 0;
    while(x < 10)
    {
        y = 0;
        while(y < 25)
        {
            this->_graphshow[x][y] = obj._graphshow[x][y];
            y++;
        }
        x++;
    } 
    return(*this);
}

std::string Graph::reveal()
{
    std::string toreturn;
    int x = 0;
    int y = 0;

    while(x < 10)
    {
        y = 0;
        while(y < 25)
        {
            toreturn = toreturn + this->_graphshow[x][y];
            y++;
        }
        toreturn = toreturn + '\n';
        x++;
    } 
    return(toreturn);
}


//we want to shift the y, while maintaining all of the x
void Graph::moveposition()
{
    int x = 0;
    int y = 24;

    //the y should be shifted

    while(y > 0)
    {
        x = 0;
        while(x < 10)
        {
            this->_graphshow[x][y] = this->_graphshow[x][y - 1];
            x++;
        }
        y--;
    }

    return ;
}

//we must turn the d into an integer
void Graph::setpoint(double d)
{
    int x = 0;
    int i;

    i = (d/calibration * 10);

    moveposition();

    while(x < i)
    {
        this->_graphshow[x][0] = 'x';
        x++;
    }
    return ;
}
