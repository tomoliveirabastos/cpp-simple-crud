#include <vector>
#include <mysql.h>
#include "./connect-mysql.hpp"

class HandleConnectMysql
{
private:
    auto handleCredentials()
    {
        auto c = std::make_shared<ConnectMysql>();

        c->setHost("127.0.0.1")
            ->setUsername("root")
            ->setPassword("pass")
            ->setDb("pessoa")
            ->setPort(3306);

        return c;
    }

public:
    auto config()
    {
        auto handle = handleCredentials();

        MYSQL *con = mysql_init(NULL);

        MYSQL *connect = mysql_real_connect(con, handle->getHost(), handle->getUsername(), handle->getPassword(), handle->getDb(), 0, NULL, 0);

        return con;
    }

    void insertQuery(const char *query) {
        MYSQL *con = config();

        mysql_query(con, query);

        mysql_close(con);
    }

    auto findQuery(const char *query)
    {
        MYSQL *con = config();

        mysql_query(con, query);

        MYSQL_RES *result = mysql_store_result(con);

        int num_fields = mysql_num_fields(result);

        std::vector<std::vector<char *>> pessoas;

        while (auto row = mysql_fetch_row(result))
        {
            std::vector<char *> pessoa;

            for (int i = 0; i < num_fields; i++)
            {
                pessoa.push_back(row[i]);
            }

            pessoas.push_back(pessoa);
        }

        mysql_close(con);

        return pessoas;
    }
};