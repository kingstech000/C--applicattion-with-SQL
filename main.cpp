#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>

int main()
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;

    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://192.168.66.87:3306", "admin", "admin");

    if (conn) {
        std::cout << "Connected" << std::endl;
        

    } else {
        std::cerr << "Connection failed. Error: " << conn->getWarnings() << std::endl;
    }

    delete conn; 

    return 0;
}