#include "MyString.h"
#include<stdexcept>

// Default constructor
MyString::MyString()
{
	this->data = NULL;
}

// Constructor with starting string value
MyString::MyString(const char* string)
{
	this->data = NULL;

	if (string && strlen(string) > 0) {
		// Allocate and initialize
		this->data = new char[strlen(string) + 1];

		// Copy the value into the allocated array
		strcpy_s(this->data, strlen(string) + 1, string);
	}
}

// Copy Constructor 
MyString::MyString(const MyString& string) {

	this->data = NULL;

	// Someone gave us ourself... No copy at such a case
	if (this == &string) return;

	/*TODO: You can NOT call string.string or any other member of another instance! string member is a private implementation!
	 for checking it you will create a method isEmpty. Never call private members of other instances. Always via methods */

	if (!string.isEmpty()) {
		this->data = new char[string.length() + 1];
		strcpy_s(this->data, string.length() + 1, string.value());
	}
	else {

		// Free current data if needed
		if (!this->isEmpty()) {
			delete this->data;
		}

		this->data = NULL;
	}
}

// Deletes the current data if necessary
void MyString::safeDeleteCurrentData()
{
	if (!this->isEmpty()) {
		delete[] this->data;
		this->data = NULL;
	}
}

// Returns the amount of characters in the string 
size_t MyString::length() const {
	// 0 for empty string,otherwise measure the length
	return this->isEmpty() ? 0 : strlen(this->data);
}

// Appends data to this string
MyString& MyString::append(const MyString& other)
{
	// The other one is empty. Nothing to copy.
	if (other.isEmpty()) return *this;

	if (this->isEmpty()) {
		// We don't have a value. Just assign this instance to point at the other one and return it.
		*this = other;
		return *this;
	}
	else {

		// Copy the other ones data...
		
		int unifiedLength = this->length() + other.length() + 1;

		// Allocate memory for a unified string
		char* temp;
		temp = new char[unifiedLength];

		// Copy our data
		strcpy_s(temp, unifiedLength, this->data);

		// Append the other one's data
		strcat_s(temp, unifiedLength, other.value());

		// Delete (Free) the old data
		this->safeDeleteCurrentData();

		// Set the new unified data
		this->data = temp;

		return *this;
	}
}

// Indication if the string is empty or not
bool MyString::isEmpty() const
{
	return this->data == NULL || strlen(this->data) == 0;
}

//Assignment of data
MyString& MyString::operator=(const char* other)
{
	// Delete the current data if necessary
	this->safeDeleteCurrentData();

	// Allocate memory and copy if there is data in this given string
	if (other && strlen(other) > 0) {
		this->data = new char[strlen(other) + 1];
		strcpy_s(this->data, strlen(other) + 1, other);
	}

	return *this;
}

// Assignment operator
MyString& MyString::operator=(const MyString& other)
{
	// Delete the current data if necessary
	this->safeDeleteCurrentData();

	// Allocate and copy if the other string has data in it
	if (!other.isEmpty()) {
		int otherLength = other.length() + 1;
		this->data = new char[otherLength];
		strcpy_s(this->data, otherLength, other.value());
	}

	return *this;
}

// Comparator. Smaller than
bool MyString::operator<(const MyString& other) const
{
	// If we are empty and the other one is not we can say that we are "smaller"
	if (this->isEmpty() && !other.isEmpty()) return true;

	// If we are not empty and the other one is we can say that we are "bigger"
	if (!this->isEmpty() && other.isEmpty()) return false;

	// We both have values. No NULL risk. compare them.
	return strcmp(this->data, other.value()) < 0;
}

// Comparator. Equals
bool MyString::operator==(const MyString& other) const
{
	// If one is empty and the other one is not they are not equal!
	if ((!this->isEmpty() && !other.isEmpty()) || (this->isEmpty() && !other.isEmpty())) return false;

	// We both have values. No NULL risk. compare them.
	return strcmp(this->data, other.value()) == 0;
}

// Comparator. Not Equal
bool MyString::operator!=(const MyString& other) const
{
	return !(*this == other);
}

// Append
MyString& MyString::operator+(const MyString& other)
{
	return this->append(other);
}

ostream& operator<<(ostream& os, const MyString& string) {
	if (!string.isEmpty()) {
		os << string.value();
	}

	return os;
}

istream& operator >> (istream& is, MyString& string)
{
	char buffer[1024];
	is >> buffer;

	string.safeDeleteCurrentData();

	string.data = new char[strlen(buffer) + 1];
	strcpy_s(string.data, strlen(buffer) + 1, buffer);

	return is;
}

// Value return as constant immutable
const char* MyString::value() const {
	return data;
}

MyString::~MyString()
{
	// Safe deletion (free) of the data
	this->safeDeleteCurrentData();
}