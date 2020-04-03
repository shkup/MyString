#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
private:
	char* data;

	void safeDeleteCurrentData();

	MyString& switchToOtherString(const MyString& other);

public:
	// Constructors

	// Default constructor
	MyString();

	// Constructor - Simple characters array assignment
	MyString(const char* charsArr);

	// Copy constructor
	MyString(const MyString& other);

	// De-constructor
	virtual ~MyString();

	// Current length
	size_t length() const;

	// Append method
	MyString& append(const MyString& str);

	// Indication if there is data or not in our string
	bool isEmpty() const;

	/* TODO: Not sure about it at ALL. I think it's better to return char[] which is a full copy!!! of the data in other memory segment. 
	   Although the pointer is constant it's still exposing the internal implementation...
	   Moreover... You use this function to check other instances private data which is bad practice.
	   Strings need to be immutable by definition. Deep copy ensures no one will mess with your pointer.
	*/
	const char* value() const;

	// Assignment operator. 
	MyString& operator=(const char* str);

	// Assignment operator. Data copy only.
	MyString& operator=(const MyString& other);

	// Comparator smaller than operator
	bool operator<(const MyString& other) const;

	// Equality operator (Value comparison)
	bool operator==(const MyString& other) const;

	// Non equal operator
	bool operator!=(const MyString& other) const;

	// Concatenate operator
	MyString& operator+(const MyString& other);

	/* TODO: I don't remember ostream, istream... 
	Generally speaking you MUST have a VERY GOOD reason to let someone friend accessibility!
	Friend is violating encapsulation so there must be some very exceptional good reason for this...*/
	friend ostream& operator<<(ostream& os, const MyString& string);
	friend istream& operator >> (istream& is, MyString& string);
};
