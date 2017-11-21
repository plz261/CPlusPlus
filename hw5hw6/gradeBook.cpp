/* Programmer:  <PUT YOUR NAME HERE>
   File:  gradeBook.cpp
   Description: Interactive grade-book program used to demonstrate parallel and 2D arrays, searching of arrays
                and text-file usage.
*/
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Global Constant
const int CLASS_SIZE = 100;
const int MAX_SCORES = 50;
const int NAME_SIZE = 50;

// Prototypes
void displayMenu();

void getScoresInteractively(double scores[], int & count);

void printScores(char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], 
		 int studentCount, int scoresCount);

double averageScores(double scores[], int count);

void saveScoresToFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], 
		      int & studentCount, int & scoreCount);

double averageColumn(double scores[][MAX_SCORES], int columnNumber, int studentCount, int scoreCount);

void possiblySaveScoresToFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], 
			      double scores[][MAX_SCORES], int & studentCount, int & scoreCount);

void readScoresFromFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], 
			int & studentCount, int & scoreCount);

void gradeBookMenu(char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], 
		   int & studentCount, int & scoreCount);

int main() {
	double scores[CLASS_SIZE][MAX_SCORES];
	char fileName[NAME_SIZE], studentNames[CLASS_SIZE][NAME_SIZE];
	char columnTitles[MAX_SCORES][NAME_SIZE];
	int numberOfScores, numberOfStudents;
	
	readScoresFromFile(fileName, studentNames, columnTitles, scores, numberOfStudents, numberOfScores);

	printScores(studentNames, columnTitles, scores, numberOfStudents, numberOfScores);

	gradeBookMenu(studentNames, columnTitles, scores, numberOfStudents, numberOfScores);

	possiblySaveScoresToFile(fileName, studentNames, columnTitles, scores, numberOfStudents, numberOfScores);
	
} // end main


// Display the Grade Book Menu
void displayMenu() {
	cout << endl << "Grade Book Menu" << endl << endl;

	cout << "(D)isplay all scores" << endl;
	cout << "(A)dd column of scores " << endl;
	cout << "(N)ew student" << endl;
	cout << "(C)hange a score" << endl;
	cout << "(E)xit program" << endl;
	
} // end displayMenu


// Repeatedly process Grade Book requests until user decides to Quit.
void gradeBookMenu(char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], int & studentCount, int & scoreCount) {
	char response[NAME_SIZE];

	while (true) {
		displayMenu();
		cout << endl << "Enter your choice: ";
		cin.getline(response, NAME_SIZE);
		if (strcmp(response, "D") == 0 || strcmp(response, "d") == 0) {
			cout << endl << "Display of all scores:" << endl << endl;
			printScores(students, columnTitles, scores, studentCount, scoreCount);
		
		} else if (strcmp(response, "A") == 0 || strcmp(response, "a") == 0) {
		
		} else if (strcmp(response, "N") == 0 || strcmp(response, "n") == 0) {
		
		} else if (strcmp(response, "C") == 0 || strcmp(response, "c") == 0) {

		} else if (strcmp(response, "E") == 0 || strcmp(response, "e") == 0) {
			break;
		} else {
			cout << "Invalid response!  Please select from the following." << endl << endl;
		} // end if
	} // end while

} // end gradeBookMenu


// This function interactively reads scores into the scores array 
// until a negative score is read as a sentinel value.  The count returns
// the number of scores read.
void getScoresInteractively(double scores[], int & count) {
	double score;

	count = 0;
	while (true) {  // infinite loop
		cout << "Enter a score (or a negative value when done): ";
		cin >> score;
		cin.ignore(NAME_SIZE,'\n');
		if (score < 0) {
			return;
		} else {
			scores[count] = score;
			count++;
		} // end if
	} // end while
} // end getScoresInteractively


// Prints grade book scores to console 
void printScores(char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], double scores[][MAX_SCORES], int studentCount, int scoreCount) {
	int row, column;

	cout << "There are " << studentCount << " students with " << scoreCount << " scores." << endl << endl;

	// Print Column Titles
	cout << left << setw(17) << "Student Names";
	for (column = 0; column < scoreCount; column++) {
		cout << right << setw(6) << columnTitles[column] << " ";		
	} // end for (column...
	cout << endl;

	// Print student names and scores
	for (row = 0; row < studentCount; row++) {
		cout << left << setw(15) << students[row];
		cout << ": ";
		for (column = 0; column < scoreCount; column++) {
			cout << right << setw(6) << scores[row][column] << " ";		
		} // end for (column...
		cout << "Average Score = " << fixed << setprecision(1) << averageScores(scores[row],scoreCount) << endl;
	} // end for (row...

	// print column averages
	cout << left << setw(17) << "Column Averages";
	for (column = 0; column < scoreCount; column++) {
		cout << right << setw(6) << averageColumn(scores, column, studentCount, scoreCount) << " ";		
	} // end for (column...
	cout << endl << endl;

} // end printScores


// Returns the average of a column in the 2D scores array
double averageColumn(double scores[][MAX_SCORES], int columnNumber, int studentCount, int scoreCount) {
	double total;
	int row;

	if (studentCount <= 0) {
		cout << "Error: To calculate the average, you must have one or more scores!" << endl;
		exit(EXIT_FAILURE);
	} // end if

	total = 0;
	for(row = 0; row < studentCount; row++) {
		total += scores[row][columnNumber];
	} // end for
	return total / studentCount;

} // end averageColumn


// Returns the average of a row in the 2D scores array
double averageScores(double scores[], int count) {
	double total;
	int index;

	total = 0;
	for(index = 0; index < count; index++) {
		total += scores[index];
	} // end for

	if (count <= 0) {
		cout << "Error: To calculate the average, you must have one or more scores!" << endl;
		exit(EXIT_FAILURE);
	} else {
		return total / count;
	} // end if

} // end averageScores


// Saves the complete grade book to a text file
void saveScoresToFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE],
					  double scores[][MAX_SCORES], int & studentCount, int & scoreCount) {
	int row, column;
	ofstream outFile;

	outFile.open(fileName);
	outFile << studentCount << " " << scoreCount << endl;

	for (row = 0; row < studentCount; row++) {
		outFile << students[row] << endl;
		for (column = 0; column < scoreCount; column++) {
			outFile << scores[row][column] << " ";
		} // end for (column...
		outFile << endl;
	} // end for (row...

	for (column = 0; column < scoreCount; column++) {
		outFile << columnTitles[column] << endl;
	} // end for (column...

	outFile.close();
} // end saveScoresToFile


// Reads a grade book file into the arrays
void readScoresFromFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], 
						double scores[][MAX_SCORES], int & studentCount, int & scoreCount) {
	int row, column;
	double score;
	ifstream inFile;

	cout << "Enter the file containing student scores: ";
	cin.getline(fileName, NAME_SIZE);
	inFile.open(fileName);
	if (!inFile) {
		cout << "Error opening file <" << fileName << "> for reading!";
	} else {
		inFile >> studentCount;
		inFile >> scoreCount;

		inFile.ignore(NAME_SIZE, '\n');
		for (row = 0; row < studentCount; row++) {
			inFile.getline(students[row],NAME_SIZE);

			for (column = 0; column < scoreCount; column++) {
				inFile >> score;
				scores[row][column] = score;
			} // end for (column...

			inFile.ignore(NAME_SIZE, '\n');
		} // end for (row...

		for (column = 0; column < scoreCount; column++) {
			inFile.getline(columnTitles[column], NAME_SIZE);
		} // end for (column...

		inFile.close();
	} // end if
} // end readScoresFromFile


// Determines if the user wants to save the grade book information to a file
void possiblySaveScoresToFile(char fileName[], char students[][NAME_SIZE], char columnTitles[][NAME_SIZE], 
							  double scores[][MAX_SCORES], int & studentCount, int & scoreCount) {
	char response[NAME_SIZE];

	while (true) {
		cout << "Would you like to save the scores to a file (y or n)?: ";
		cin.getline(response, NAME_SIZE);
		if (strcmp(response, "n") == 0) {
			cout << "Scores not saved" << endl;
			break;
		} else if (strcmp(response, "y") == 0) {
			cout << "Enter the file name where you want the scores saved: ";
			cin.getline(fileName, NAME_SIZE);
			saveScoresToFile(fileName, students, columnTitles, scores, 
				studentCount, scoreCount);
			break; 
		} else {
			cout << "Invalid response!  Please enter only y or n. " << endl;
		} // end if
	} // end while

} // end possiblySaveScoresToFile
