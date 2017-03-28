#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include "Person.h"
#include "Phonebook.h"
 
using namespace std;
 
PhoneBook::PhoneBook() {    
    nr = 0;
}

void PhoneBook::save_in_file(string fname){
	int n = 0;
	list<Person>::iterator it;
	ofstream fout(fname.c_str());
	fout << nr << endl;
	for(it = people.begin(); it != people.end(); ++it){
		fout << ((Person) (*it)).getFullName()  << endl;
		fout << ((Person) (*it)).getPhoneNumber() << endl; 
	}
	fout.close();
}
 
bool PhoneBook::addPerson(string name, string phone) {
    if (nr == 0) {
        people.push_back(Person(name, phone));
        nr++;
        return true;
    }
 
    bool found = false;
    list<Person>::iterator it, itLast;
    for (it = people.begin(); it != people.end() && found == false; it++) {
        if (((Person) (*it)).getFullName().compare(name) > 0) {
            itLast = it;
            found = true;
        } else if (((Person) (*it)).getFullName().compare(name) == 0) {
            return false;
        }
    }
 
    if (found == false) {
        people.push_back(Person(name, phone));
        nr++;
        return true;
    }
 
    people.insert(itLast, Person(name, phone));
    nr++;
    return true;
}
 
bool PhoneBook::addPerson(Person &person) {
    return addPerson(person.getFullName(), person.getPhoneNumber());
}
 
list<Person> PhoneBook::searchByName(string name) {
    list<Person> l;
    if (nr == 0) {
        return l;
    }
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        if (((Person) (*it)).getFullName().find(name) != string::npos) {
            l.push_back((Person) (*it));
        }
    }
    return l;
}
 
list<Person> PhoneBook::searchByPhoneNumber(string phone) {
    list<Person> l;
    if (nr == 0) {
        return l;
    }
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        if (((Person) (*it)).getPhoneNumber().find(phone) != string::npos) {
            l.push_back((Person) (*it));
        }
    }
    return l;
}
 
void PhoneBook::listAllPeople() {
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        cout << ((Person) (*it)).getFullName() << " -- " << ((Person) (*it)).getPhoneNumber() << endl;
    }
    cout << endl;
}
