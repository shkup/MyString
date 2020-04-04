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

	// The string value (immutable pointer)
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

	// cout and cin helpers
	friend ostream& operator<<(ostream& os, const MyString& string);
	friend istream& operator >> (istream& is, MyString& string);
};
