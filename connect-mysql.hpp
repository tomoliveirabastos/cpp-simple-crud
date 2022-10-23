#pragma once

#include <iostream>
#include <memory>

class ConnectMysql
{
private:
    const char *host;
    const char *username;
    const char *password;
    const char *db;
    unsigned int port;

public:
    ConnectMysql();
    ConnectMysql *setHost(const char *);
    ConnectMysql *setUsername(const char *);
    ConnectMysql *setPassword(const char *);
    ConnectMysql *setDb(const char *);
    ConnectMysql *setPort(unsigned int port);
    const char *getHost();
    const char *getUsername();
    const char *getPassword();
    const char *getDb();
    unsigned int getPort();
};

ConnectMysql::ConnectMysql()
{
}

const char *ConnectMysql::getHost()
{
    return host;
}

const char *ConnectMysql::getUsername()
{
    return username;
}
const char *ConnectMysql::getPassword()
{
    return password;
}

const char *ConnectMysql::getDb()
{
    return db;
}

unsigned int ConnectMysql::getPort()
{
    return port;
}

ConnectMysql *ConnectMysql::setHost(const char *h)
{
    host = h;
    return this;
};

ConnectMysql *ConnectMysql::setUsername(const char *h)
{
    username = h;
    return this;
};
ConnectMysql *ConnectMysql::setPassword(const char *h)
{
    password = h;
    return this;
};

ConnectMysql *ConnectMysql::setDb(const char *h)
{
    db = h;
    return this;
};

ConnectMysql *ConnectMysql::setPort(unsigned int h)
{
    port = h;
    return this;
};