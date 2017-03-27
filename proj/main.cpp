#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Person.h"
#include "Phonebook.h"
 
using namespace std;
 
PhoneBook *myBook;
 
void readFromFile(string fname) {
    int n = 0, i;
    string name, phone, nstr;
    ifstream fin(fname.c_str());
 
    getline(fin, nstr);
    n = atoi(nstr.c_str());
 
    for (i = 0; i < n; i++) {
        getline(fin, name);
        getline(fin, phone);
 
        myBook->addPerson(name, phone);
    }
 
    fin.close();
}


void show_menu(){
	cout << "-----------------------" << endl;
	cout << "   1 .add new_number" << endl;
	cout << "   2. search number " << endl;
	cout << "   3. print all number "<< endl;
	cout << "   4. exit phone book " << endl;
	cout << "-----------------------" << endl;
}
	
 
int main(int argc, char** argv) {
    myBook = new PhoneBook();
 
    readFromFile("people.txt");
 	while(true){
 		int command;
 		show_menu();
 		cin >> command;
 		if(command == 1){
 			string name, number;
 			cout << " input name you want to add" << endl;
 			cin >> name;
 			cout << " input phone number" << endl;
 			cin >> number;
 			myBook->addPerson(name, number);
 		}
 		
 		else if(command == 2){
	   		list<Person> search;
	   		string input;
	   		int in;
		    list<Person>::iterator it;
	   		char command;
	   		cout << "input number or name you want to find" << endl;
	   		cin >> input;
	   		if(isdigit(input[0])){
	    		search = myBook->searchByPhoneNumber(input);
				cout << "Search by phone number containing " << input << endl;
			}
			else{
			    search = myBook->searchByName(input);
				cout << "Search by name containing "<< input << endl;
			}
	    	for (it = search.begin(); it != search.end(); it++) {
	        	cout << ((Person) (*it)).getFullName() << " -- " << ((Person) 	(*it)).getPhoneNumber() << endl;
	        }
	    }
	 
		else if(command == 3){
			cout << "All people in my phone book:" << endl << endl;
			myBook->listAllPeople();
		}
		else if(command ==4){
			myBook -> save_in_file("people.txt");
			break;
		}
	}	 
    return 0;
}
