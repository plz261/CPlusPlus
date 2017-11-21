// Demo of C++ string class and struct 
// Reads a comma separated line of text and splits it into substrings, and then stores it into a struct.
// I used an array of Student struct called myClass and stored at index 0.

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

struct Student {
  string studentID;
  string name;
  string yearInSchool;
  string gpa;
}; // end Student struct


// prototypes
void splitLineByCharacter(string myLine, char delimiter, string substrings[], int & substringCount);

int main() {
	int substringCount, index;
	string myLine;
	string substrings[SIZE];
	Student myClass[50];

	cout << "Enter your by commas separated data (student #, name, year, GPA): ";
	getline(cin, myLine);		// reads a whole line of text including whitespace characters
	cout << "You entered address " << myLine << endl;
	
	splitLineByCharacter(myLine, ',', substrings, substringCount);

	cout << "There are " << substringCount << " <,> delimited strings.  The strings are:" << endl;
	for (index = 0; index < substringCount; index++) {
		cout << substrings[index] << endl;
	} // end for
	index = 0;
	myClass[index].studentID = substrings[0];
	myClass[index].name = substrings[1];
	myClass[index].yearInSchool = substrings[2];
	myClass[index].gpa = substrings[3];
	cout << "GPA: " << myClass[index].gpa << endl;
} // end main


void splitLineByCharacter(string myLine, char delimiter, string substrings[], int & substringCount) {
	int startOfSubstring, endOfSubstring;

	substringCount = 0;
	startOfSubstring = 0;
	while (true) {
		if (substringCount == SIZE) {
			cout << "Array full:  string entered was not all processed!" << endl;
			return;
		} else {
			endOfSubstring = myLine.find(delimiter, startOfSubstring);
			if (endOfSubstring >=0) {
				substrings[substringCount] = myLine.substr(startOfSubstring, 
					                                          (endOfSubstring - startOfSubstring));
				substringCount++;
				startOfSubstring = endOfSubstring + 1;
			} else {
				endOfSubstring = myLine.length();
				substrings[substringCount] = myLine.substr(startOfSubstring, 
					                                          (endOfSubstring - startOfSubstring));
				substringCount++;
				return;
			
			} // end if
		} // end if
	} // end while

} // end splitLineByCharacter
