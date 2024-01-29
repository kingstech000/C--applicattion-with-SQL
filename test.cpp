#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <statement.h>
#include <mysql_error.h>
#include <driver.h>
#include <sqlstring.h>
#include <jdbc.h>
#include <mysql.h>
#include <field_types.h>
#include <my_list.h>
#include <mysql/udf_registration_types.h>
#include <mysql/client_plugin.h>

using namespace std;
using namespace sql;

int main()
{
    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("dsn=mysourcename", "admin", "admin");
        con->setSchema("c++test");
        if (con->isValid())
        {
            cout << "The database is connected." << std::endl;
        }
        else
        {
            cout << "The database is not connected." << std::endl;
        }

        // Create and execute a query
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM user");

        // Process the results
        while (res->next())
        {
            cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("firstname") << std::endl;
        }

        // Close connections
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}
