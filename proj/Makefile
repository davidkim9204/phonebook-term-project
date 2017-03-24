Phonebook : main.o Phonebook.o Person.o
	gcc -o Phonebook main.o Phonebook.o main.o
main.o : main.cpp
	gcc -c -o main.o main.cpp
Phonebook.o : Phonebook.cpp
	gcc -c -o Phonebook.o Phonebook.cpp
Person.o : Person.cpp
	gcc -c -o Person.o Person.cpp
clean:
	rm *.o Phonebook
