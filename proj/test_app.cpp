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
 
    readFromFile("test.txt");
 	while(true){
 		int command;
 		cin >> command;
 		switch(command);
 		case 1:
			cout << "All people in my phone book:" << endl << endl;
			myBook->listAllPeople();
		case 2:
			cout << "All people in my phone book:" << endl << endl;
			myBook->listAllPeople();
		case 3:
			for(int i = 0; i < 10; ++i){
				string name, number;
				cin >> name >> number;
				myBook -> addPerson(name, number);
			}
			myBook -> save_in_file("test.txt");
			cout << "All people in my phone book:" << endl << endl;
			myBook->listAllPeople();
		case 4:
			cout << "All people in my phone book:" << endl << endl;
			myBook->listAllPeople();
		case 5:
			list<Person> search;
	   		string input;
		    list<Person>::iterator it;
		    
			cout << "input name you want to find" << endl;
	   		cin >> input;
	    	search = myBook->searchByName(input);
			cout << "Search by phone name containing " << input << endl;
			for (it = search.begin(); it != search.end(); it++) {
	        	cout << ((Person) (*it)).getFullName() << " -- " << ((Person) 	(*it)).getPhoneNumber() << endl;
	        }
		
		case 6:
			list<Person> search;
	   		string input;
		    list<Person>::iterator it;
		    cout << "input number you want to find" << endl;
		    cin >> input;
		    search = myBook->searchByPhoneNumber()
		    cout << "Search by phone number containing "<< input <<endl;
			for (it = search.begin(); it != search.end(); it++) {
	        	cout << ((Person) (*it)).getFullName() << " -- " << ((Person) 	(*it)).getPhoneNumber() << endl;
	        }
		   return 0;
}
