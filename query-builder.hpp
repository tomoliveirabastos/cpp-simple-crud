
#include <iostream>
#include <map>
#include <vector>
#include <string>

class QueryBuilder
{

private:
    std::string customQuery;
    std::string tableName;
    std::vector<std::map<std::string, std::string>> parameters;

public:
    QueryBuilder *table(std::string);
    QueryBuilder *setParameter(std::string, std::string);
    QueryBuilder *createQuery(std::string sql);
    std::string getInsertedQuery();
    std::string getSelectQuery();
    std::vector<std::map<std::string, std::string>> getParameters();
    std::string getQuery();
};
