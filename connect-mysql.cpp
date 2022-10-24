#include <vector>
#include <mysql.h>
#include "./connect-mysql.hpp"
#include "./config-db.hpp"

class HandleConnectMysql
{
private:
    auto handleCredentials()
    {
        auto db = new ConfigDb();
        auto c = std::make_shared<ConnectMysql>();

        c->setHost(db->host.c_str())
            ->setUsername(db->username.c_str())
            ->setPassword(db->password.c_str())
            ->setDb(db->db.c_str())
            ->setPort(db->port);

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

    void insertQuery(std::string strQuery)
    {
        const char *query = strQuery.c_str();

        MYSQL *con = config();

        mysql_query(con, query);

        mysql_close(con);
    }

    auto findQuery(std::string strQuery)
    {
        const char *query = strQuery.c_str();

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