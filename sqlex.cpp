#include "sqlex.h"

SQLclass::SQLclass(){
	initialize();
}

void SQLclass::initialize(){
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "");//No pw for root
	execString = "";
	dbName = "";
}

void SQLclass::setDB(string dbName){
	try{
		con->setSchema(dbName);
		cout << "Database set to: " << dbName << endl;
	}
	catch(sql::SQLException &e){
		cout << "An error has occured..." << endl;
		cout << "ERR: " << e.what() << endl;
	}
}

void SQLclass::displayDB(){
	stmt = con->createStatement();
	execString = "SHOW DATABASES";
	stmt->execute(execString.c_str());
	res = stmt->getResultSet();
	while(res->next()){
		cout << res->getString(1) << endl;
	}
	delete stmt;
	delete res;
}

void SQLclass::createDB(string dbName){
	try{
		stmt = con->createStatement();
		execString = "CREATE DATABASE IF NOT EXISTS " + dbName;
		stmt->execute(execString.c_str());
		delete stmt;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
  		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  		cout << "# ERR: " << e.what();
  		cout << " (MySQL error code: " << e.getErrorCode();
  		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

void SQLclass::helpDisp(){
	char ch;
	infile.open("help.txt");
	while(infile.get(ch)){
		cout << ch;
	}
}

void SQLclass::command(){
	cout << "Enter your custom command:" << endl;
	cin.ignore();
	getline(cin, execString);
	stmt = con->createStatement();
	try{
		stmt->execute(execString.c_str());
		res = stmt->getResultSet();
		while(res->next()){
				cout << res->getString(1) << endl;
		}
	}
	catch(sql::SQLException &e){
		cout << "Error: " << e.what() << endl;
		cout << "Error Code: " << e.getErrorCode() << endl;
	}
	delete res;
	delete stmt;

}
