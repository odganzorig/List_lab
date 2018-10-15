//  Person.cpp
//
//  Function implementations for Person class, CS 223, Lab 1
//
//  Name: Od Ganzorig
//  Date: 01/23/2018
//
//    Person Class Instance Variables
//    std::string first; // the person's first name
//    std::string last;  // the person's last name
//    int age;           // the person's age

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// CONSTRUCTORS for the Person class

/*
*  Person
*  Precondition: May be called with 0 parameters, 1 parameter (fname),
*                2 parameters (fname, lname), or three parameters.
*  Precondition: fname has size 1 or more
*  Precondition: lname has size 1 or more
*  Precondition: A cannot be negative
*  Postcondition: An instance of a Person has been created with
*                 first name `fname`, last name `lname`, and age `age`.
*/
Person::Person (string fname, string lname, int A)
{
	first = fname;
	last = lname;
	age = A;

}

// ACCESSOR MEMBER FUNCTIONS

/*
 *  getFirstName
 *  Precondition: None
 *  Postcondition: person's first name is returned
 */
string Person::getFirstName() const
{
	return first;		
}

/*
 *  getLastName
 *  Precondition: None
 *  Postcondition: person's last name is returned
 */
string Person::getLastName() const
{
	return last;		
}

/*
 *  getAge
 *  Precondition: None
 *  Postcondition: person's age is returned
 */
int Person::getAge() const
{
	return age;		
}

/*
 *  getFullName
 *  Precondition: None
 *  Postcondition: person's full name (first and last) is returned
 *
 *  Example:  If first name is "Chris" and last name is "Smith", return value
 *     is "Chris Smith".
 */
string Person::getFullName() const
{
	
	return first + " " + last;		
}

// MODIFICATION MEMBER FUNCTIONS

/*
 *  setFirstName
 *  Precondition: newName has size 1 or more
 *  Postcondition: person's first name is now newName
 */
void Person::setFirstName(std::string newName)
{
	first = newName;
			
}

/*
 *  setLastName
 *  Precondition: newName has size 1 or more
 *  Postcondition: person's last name is now newName
 */
void Person::setLastName(std::string newName)
{
	last = newName;
			
}

/*
 *  setAge
 *  Precondition: newAge >= 0
 *  Postcondition: person's age is now newAge
 */
void Person::setAge(int newAge)
{
	age = newAge;
			
}

/*
 *  agePerson
 *  Precondition: None
 *  Postcondition: person's age is now one year older
 */
void Person::agePerson()
{
	age = age + 1;
			
}

// OPERATOR OVERLOADING
/*
 *  equality operator (==)
 *
 *  Note: personA and personB are "equal" iff they have:
 *     - the same first name,
 *     - the same last name, and
 *     - the same age
 */
bool operator==(const Person& personA, const Person& personB)
{
	return (personA.getFirstName() == personB.getFirstName()
			&&
			personA.getLastName() == personB.getLastName()
			&&
			personA.getAge() == personB.getAge());

	
	
}

/*
 * inequality operator (!=), the logical opposite of the equality operator
 *
 *  Note:  != returns true iff == returns false
 */

bool operator!=(const Person& personA, const Person& personB)
{
	return !(personA.getFirstName() == personB.getFirstName()
			&&
			personA.getLastName() == personB.getLastName()
			&&
			personA.getAge() == personB.getAge());

	
	
	 
}

/*
 * addition operator (+)
 *
 *  Note:  as in real life, when you add two people together you get a newborn person:
 *    - the new person's first name is "Baby"
 *    - the new person's last name is the hyphenation of the parents' last names:
 *      "Jane Doe" + "Juan Sanchez" == "Baby Doe-Sanchez, age 0"
 */
Person operator+(const Person& personA, const Person& personB)
{
	Person baby;
	baby.setFirstName("Baby");
	baby.setLastName(personA.getLastName() + "-" + personB.getLastName());
	baby.setAge(0);
	return baby;



}

/*
 * output stream operator (<<)
 *
 * output a person to a stream
 * returns the `out` parameter to allow for chaining (see p.340-341 in textbook)
 *
 * Example:  A Person named "John Doe" with age 8 would produce the output:
 *    Person: John Doe, age 8
 * The above sample output begins with 'P' and ends with '8' (no whitespace
 * before 'P' or after the age).
 */
std::ostream& operator<<(std::ostream& out, const Person& person)
{
	out << "Person: " << person.getFullName() << ", age "<< person.getAge();
	return out;
	
}

/*
 * input stream operator (>>)
 *
 * read in data for a person from a stream
 * returns the `in` parameter to allow for chaining
 *    - assumes the input is formatted as specified for the output stream operator
 *    - takes data from the input stream and assigns new values to the instance
 *      variables of the person
 *
 * Example: If the input stream `in` holds the message,
 *             "Person: John Doe, age 8"
 *      then `in >> person` will cause person's data to become:
 *      first name: "John"; last name: "Doe"; age: 8
 */
std::istream& operator>>(std::istream& in, Person& person)
{
	
	in.ignore(8);
	in >> person.first >> person.last;
	in.ignore(5);
	in >> person.age;
	string str = person.last.substr(0,person.last.length()-1);
	person.setLastName(str);
	return in;

}

/*
 * Less-than operator (<)
 *
 *  Note:  personA and personB are compared as follows:
 *    - by last name: "Jane Doe, age 5" < "Jane Smith, age 5"
 *    - if last names are the same, then by first name:  "Jane Doe, age 5" < "Pete Doe, age 5"
 *    - if full names are the same, then by age:  "Jane Doe, age 5" < "Jane Doe, age 12"
 */
bool operator<(const Person& personA, const Person& personB)
{
	if (personA.getLastName() < personB.getLastName()) 
		return true;

	else if (personA.getLastName() == personB.getLastName() 
			&& 
			personA.getFirstName() < personB.getFirstName())
		return true;

	else if (personA.getLastName() == personB.getLastName() 
			&& 
			personA.getFirstName() == personB.getFirstName() 
			&& 
			personA.getAge() < personB.getAge())
		return true;
	else
		return false;
}

