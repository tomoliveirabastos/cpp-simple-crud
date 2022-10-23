#include "./connect-mysql.cpp"
#include "./query-builder.hpp"

void getRows()
{
    auto builder = std::make_shared<QueryBuilder>();

    builder->setParameter(":id1", "2");

    builder->createQuery("select nome from pessoa where id = :id1");

    auto querySql = builder->getQuery();

    std::cout << querySql << std::endl;

    std::shared_ptr<HandleConnectMysql> connectMysql = std::make_shared<HandleConnectMysql>();

    auto pessoas = connectMysql->findQuery(querySql.c_str());

    for (auto pessoa : pessoas)
    {
        for (int i = 0; i < pessoa.size(); i++)
        {
            std::cout << pessoa[i] << std::endl;
        }
    }
}

void insertRow()
{
    std::shared_ptr<HandleConnectMysql> connectMysql = std::make_shared<HandleConnectMysql>();

    auto builder = std::make_shared<QueryBuilder>();

    builder->setParameter(":nome", "Nome qualquer");

    builder->createQuery("insert into pessoa(nome) value (':nome'), (':nome'), (':nome')");

    std::string querySql = builder->getQuery();

    std::cout << querySql << std::endl;

    connectMysql->insertQuery(querySql.c_str());
}

int main(int argc, char **argv)
{
    insertRow();
    getRows();

    return 0;
}