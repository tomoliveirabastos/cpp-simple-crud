#include "./query-builder.hpp"

std::vector<std::map<std::string, std::string>> QueryBuilder::getParameters()
{
    return parameters;
}

QueryBuilder *QueryBuilder::setParameter(std::string param, std::string value)
{
    std::map<std::string, std::string> m;

    m[param] = value;

    parameters.push_back(m);

    return this;
}
QueryBuilder *QueryBuilder::createQuery(std::string sql)
{
    customQuery = sql;
    return this;
}

std::string replaceAll(std::string str, const std::string &from, const std::string &to)
{
    int start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

std::string QueryBuilder::getQuery()
{
    for (auto params : parameters)
    {
        for (auto imap : params)
        {
            customQuery = replaceAll(customQuery, std::string(imap.first), std::string(imap.second));
        }
    }
    
    return customQuery;
}