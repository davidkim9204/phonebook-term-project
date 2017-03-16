#ifndef PERSON_H
#define	PERSON_H
 
#include <string>

using namespace std;
 
class Person {
    string fullName;
    string phoneNumber;

public:
    Person();  //default
    Person(string, string); //제대로 저장했을때 이름,번호 
    Person(const Person&); //person 타입 변수저장. 
 
    string getFullName();
    string getPhoneNumber();
    bool setFullName(string);
    bool setPhoneNumber(string);
};
 
#endif	/* PERSON_H */
