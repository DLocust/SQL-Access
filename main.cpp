#include "sqlex.h"

#include <iostream>

int main(){
	string database;
	SQLclass* s1 = new SQLclass();
	while(1){
	cout << "What would you like to do: " << endl;
	int choice = 0;
	cout << "1. Change Active Database" << endl << "2. Create a new Database" << endl;
	cout << "3. Display Databases" << endl << "4. Help" << endl << "5. Command" << endl << "6. Quit" << endl;
	cout << "Enter choice: ";
	cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter the name of the db you want to set" << endl;
				cin >> database;
				s1->setDB(database);
				break;
			case 2:
				cout << "Enter the name of the database you want to create: ";
				cin >> database;
				s1->createDB(database);
				cout << "Database created..." <<  endl;
				break;
			case 3:
				cout << "Displaying Databases..." << endl;
				s1->displayDB();
				break;
			case 4:
				cout << "Displaying Help Details" << endl;
				s1->helpDisp();
				break;
				
			case 5:
				s1->command();
				break;
			default:
				cout << "Exiting program..." << endl;
				return 0;
				break;
		}
	}
	delete s1;
	return 0;
}
