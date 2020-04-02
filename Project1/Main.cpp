#include "MyString.h"
#include <conio.h>

int main(int argc, char* argv[]) 
{
	MyString* myStr = new MyString();

	// Should be yes
	printf("The string is empty? %s\r\n", myStr->isEmpty() ? "yes" : "no");

	myStr->append("Yaron");

	// Should be "Yaron"
	printf("The string is %s\r\n", myStr->value());

	// Should be no
	printf("The string is empty? %s\r\n", myStr->isEmpty() ? "yes" : "no");

	// Should be 5
	printf("The string length is %d\r\n", myStr->length());

	myStr->append(" is the man");

	// Should be "Yaron is the man"
	printf("The string is %s\r\n", myStr->value());

	// Should be no
	printf("The string is empty? %s\r\n", myStr->isEmpty() ? "yes" : "no");

	// Should be 16
	printf("The string length is %d\r\n", myStr->length());

	MyString* myStr2 = new MyString("Yaron sh");

	// Should be "Yaron sh"
	printf("String 2 is %s\r\n", myStr2->value());

	// Should be no
	printf("String 2 is empty? %s\r\n", myStr2->isEmpty() ? "yes" : "no");

	// Should be 8
	printf("String 2 length is %d\r\n", myStr2->length());

	// Should be true. String 2 is bigger.
	printf("Strings 1 and 2 compare. Is 1 smaller? %s\r\n", myStr < myStr2 ? "yes" : "no");

	delete myStr;
	delete myStr2;

	printf("Press any key to exit...");
	_getch();
}