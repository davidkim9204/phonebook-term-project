#ifndef PERSON_H
#define	PERSON_H
 
#include <string>

using namespace std;
 
class Person {
    string fullName;
    string phoneNumber;

public:
    Person();  //default
    Person(string, string); //����� ���������� �̸�,��ȣ 
    Person(const Person&); //person Ÿ�� ��������. 
 
    string getFullName();
    string getPhoneNumber();
    bool setFullName(string);
    bool setPhoneNumber(string);
};
 
#endif	/* PERSON_H */
