#ifndef SQLEX_H
#define SQLEX_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class SQLclass {
	public:
		SQLclass();
		void initialize();
		void createDB(string dbName);
		void displayDB();
		void setDB(string dbName);
		void helpDisp();
		void command();
	
	private:
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		string dbName;
		string execString;
		ifstream infile;
};
#endif
