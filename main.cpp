#include "./connect-mysql.cpp"

int main(int argc, char **argv)
{
    std::shared_ptr<HandleConnectMysql> connectMysql = std::make_shared<HandleConnectMysql>();

    connectMysql->insertQuery("insert into pessoa(nome) value('nome random')");

    auto pessoas = connectMysql->findQuery("select id, nome from pessoa");


    for (auto pessoa : pessoas)
    {   
        for(int i = 0; i < pessoa.size(); i++) {
            std::cout << pessoa[i] << std::endl;
        }
    }

    return 0;
}