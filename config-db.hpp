#include <fstream>
#include <Poco/JSON/Parser.h>

class ConfigDb
{
public:
    std::string host;
    std::string username;
    std::string password;
    std::string db;
    int port;
    ConfigDb();
};

ConfigDb::ConfigDb()
{
    Poco::JSON::Parser parser;

    std::fstream file("./config-db.json", std::fstream::in);

    std::string content;
    getline(file, content, '\0');
    file.close();

    std::cout << content << std::endl;

    auto result = parser.parse(content);
    auto obj = result.extract<Poco::JSON::Object::Ptr>();
    Poco::Dynamic::Var _host = obj->get("host");
    Poco::Dynamic::Var _username = obj->get("username");
    Poco::Dynamic::Var _password = obj->get("password");
    Poco::Dynamic::Var _db = obj->get("db");
    Poco::Dynamic::Var _port = obj->get("port");

    host = _host.toString();
    username = _username.toString();
    password = _password.toString();
    db = _db.toString();
    port = stoi(_port.toString());
}
