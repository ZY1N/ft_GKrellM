/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:17:55 by yinzhang          #+#    #+#             */
/*   Updated: 2019/11/03 17:17:56 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

class Graph
{
    public:
        Graph(int calibration);
        ~Graph();
        Graph(const Graph &obj);
        Graph &operator=(const Graph &obj);
        //have setpoint also move position
        void setpoint(double d);
        void moveposition();
        std::string reveal();
    private:
        char _graphshow[10][25];
        int calibration;
};

#endif
