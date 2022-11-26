/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserver.utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:06:55 by zkasmi            #+#    #+#             */
/*   Updated: 2022/11/25 18:07:08 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.hpp>
#include <webserver.hpp>

string trim(string s, const string set)
{
    size_t start = s.find_first_not_of(set);
    s = (start == std::string::npos) ? "" : s.substr(start);
    start = s.find_last_not_of(set);
    return (start == std::string::npos) ? "" : s.substr(0, start + 1);
}

vector<string> split(string s, const string set)
{
    size_t pos = 0;
    string token;
    vector<string> line;
    while ((pos = s.find(set)) != std::string::npos)
    {
        token = s.substr(0, pos);
        if (token != "")
            line.push_back(token);
        s.erase(0, pos + set.length());
    }
    token = s.substr(0, pos);
    if (token != "")
        line.push_back(token);
    return line;
}

size_t value_len(string str, size_t i)
{
    while (i < str.length())
    {
        if (!(isspace(str[i])))
            break;
        i++;
    }
    return i;
}

size_t key_len(string str)
{
    size_t i = 0;
    while (i < str.length())
    {
        if (isspace(str[i]))
            break;
        i++;
    }
    return i;
}

int empty_brackets(string line)
{
    int brackets = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == '{')
            brackets++;
        if (line[i] == '}')
            brackets--;
    }
    if (brackets != 0)
        return 1;
    else
        return 0;
}

int num_check(string value)
{
    for (size_t i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]))
            return 1;
    }
    return 0;
}

int syntax_block(string line)
{
    size_t len;

    if (line.find("server ") != string::npos)
        len = line.find("server ");
    if (line.find("server{") != string::npos)
        len = line.find("server{");
    for (size_t i = 0; i < len; i++)
    {
        if (!isspace(line[i]))
            return (1);
    }
    return (0);
}