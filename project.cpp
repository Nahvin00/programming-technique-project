#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void enterData(char []);
void displayData(string [30][7], int); //pass by ref because we want to increment the value of row
void readData(string [30][7], int&);

int main() {
	
	char Question[5]; //The five questions
	string evaluation[30][7];
	int row = 0;

	//enterData(Question);
	readData(evaluation, row);
	displayData(evaluation, row);

	return 0;
}

void enterData(char Question[]) {
	int instructorNum, courseCode;
	
	ofstream outFile("evaluationSummary.txt");

	while (cin >> instructorNum >> courseCode >> Question[0] >> Question[1] >> Question[2] >>
		Question[3] >> Question[4]) {
		outFile << instructorNum << " " << courseCode << " " << Question[0] << " " << Question[1] << " " << Question[2] 
			<< " " << Question[3] << " " << Question[4] << endl;
	}
}

void displayData(string question[30][7], int row) {

	ifstream inFile("evaluationSummary.txt");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 7; j++) {
			cout << question[i][j] << " ";
		}
		cout << endl;
	}
}

void readData(string arr[30][7], int& row) {

	ifstream inFile("evaluationSummary.txt");

	if (!inFile) {
		cerr << "Error finding input file" << endl;
		exit(1);
	}

	while (!inFile.eof()) {
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 7; j++) {
				inFile >> arr[i][j];
			}
			if (arr[i][0].compare(" ") == true) { //if first element of the array is string, hence not the end of file, row++
				row++;
			}
		} 
	}
}
