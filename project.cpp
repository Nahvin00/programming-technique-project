#include <iostream> //to display output on the screen and read input from the keyboard
#include <iomanip> //to defines the manipulator functions 
#include <fstream> //to perform input/output operations on a file
using namespace std; //to provide a scope to the identifiers

					 //prototype of fuctions
bool test(char, char, char, char, char);
double total(char);
double average(double, double);
void display(int, int, int, double, double, double, double, double, double);

int main() //main function
{
	//declaration and initialization of variables
	int res, insc, courc;
	double total_Q1 = 0, total_Q2 = 0, total_Q3 = 0, total_Q4 = 0, total_Q5 = 0,
		avg_Q1 = 0, avg_Q2 = 0, avg_Q3 = 0, avg_Q4 = 0, avg_Q5 = 0, ins_avg, size = 0;

	ofstream outputFile("DataOutput.txt", ios::out); //to output a file named as "DataOutput"

													 //this if condition is to exit program if the file could not be opened
	if (!outputFile) {
		cerr << "File could not be opened \n";
		exit(1);
	}
	//prompt user to enter value
	cout << "Getting started with Evaluation process." << endl << endl
		<< "Enter number of respondent: ";
	cin >> res;
	//to create arrays with the size of the input
	int ins[res], cour[res];
	char Q1[res], Q2[res], Q3[res], Q4[res], Q5[res], q[5];
	cout << "Enter Instructor number followed by course code, and answer for five questions(A,E,G,U,P): " << endl;

	//this for loop is to enter value into the arrays created
	for (int i = 0; i<res; i++) {
		cout << "Data set: " << (i + 1) << endl;
		cin >> ins[i] >> cour[i] >> Q1[i] >> Q2[i] >> Q3[i] >> Q4[i] >> Q5[i];
		//this while loop is to only enter A,E,G,U,P
		while (test(Q1[i], Q2[i], Q3[i], Q4[i], Q5[i]) != true) {
			cout << "Invalid Characters! Only  re-enter either 'A', 'E', 'G', 'U', or 'P' for five questions: " << endl;
			cin >> Q1[i] >> Q2[i] >> Q3[i] >> Q4[i] >> Q5[i];
			test(Q1[i], Q2[i], Q3[i], Q4[i], Q5[i]);
		}
		//to compare the values with the previous values
		if (i>0) {
			while (ins[i] != ins[i - 1]) {
				cout << "Instructor Number doesn't match!" << endl << "Please re-enter the Instructor Number: " << endl;
				cin >> ins[i]; //ask the user to re-enter the value if it doen't match
			}
			while (cour[i] != cour[i - 1]) {
				cout << "Course Code doesn't match!" << endl << "Please re-enter the Course Code: " << endl;
				cin >> cour[i]; //ask the user to re-enter the value if it doen't match
			}
		}
		//to output in the file
		outputFile << ins[i] << "    " << cour[i] << "  " << Q1[i] << " " << Q2[i] << " " << Q3[i] << " " << Q4[i] << " " << Q5[i] << endl;
	}
	
	ifstream inputFile("DataOutput.txt");
    if(!inputFile)
    {
        cout<<"File could not be opened\n";
    }
    
    while(inputFile>>insc>>courc>>q[0]>>q[1]>>q[2]>>q[3]>>q[4])
    {
        //to total up the values using fucntion call
        total_Q1 += total(q[0]);
        total_Q2 += total(q[1]);
        total_Q3 += total(q[2]);
        total_Q4 += total(q[3]);
        total_Q5 += total(q[4]);
        size++;
    }

	//use functions to calculate the average for each questions
	avg_Q1 = average(total_Q1, size);
	avg_Q2 = average(total_Q2, size);
	avg_Q3 = average(total_Q3, size);
	avg_Q4 = average(total_Q4, size);
	avg_Q5 = average(total_Q5, size);

	//use formulae to calculate the instructor average
	ins_avg = (0.15*avg_Q1) + (0.23*avg_Q2) + (0.08*avg_Q3) + (0.32*avg_Q4) + (0.22*avg_Q5);

	//fucntion call to diplay output
	display(ins[0], cour[0], res, avg_Q1, avg_Q2, avg_Q3, avg_Q4, avg_Q5, ins_avg);



	return 0;
}

//funtion to check whether input is within (A,E,G,U,P,)
bool test(char a, char b, char c, char d, char e) {
	bool x;
	if ((a == 'A' || a == 'E' || a == 'G' || a == 'U' || a == 'P') &&
		(b == 'A' || b == 'E' || b == 'G' || b == 'U' || b == 'P') &&
		(c == 'A' || c == 'E' || c == 'G' || c == 'U' || c == 'P') &&
		(d == 'A' || d == 'E' || d == 'G' || d == 'U' || d == 'P') &&
		(e == 'A' || e == 'E' || e == 'G' || e == 'U' || e == 'P')) {
		x = true;

	}
	else {
		x = false;
	}
	return x;
}

//function to translate a character to a integer value    
double total(char x) {
	int z;
	switch (x) { //swich to check the character and assign a particular integer value
	case 'E':
		z = 4;
		break;
	case 'G':
		z = 3;
		break;
	case 'A':
		z = 2;
		break;
	case 'P':
		z = 1;
		break;
	case 'U':
		z = 0;
		break;
	}
	return z;
}

//function to calculate the average
double average(double x, double y) {
	double z = x / y;
	return z;
}

//function to display output
void display(int a, int b, int c, double d, double e, double f, double g, double h, double i) {
	std::cout << std::fixed << std::setprecision(2) << endl << endl //set two decimal points for double values
		<< "COURSE/INSTRUCTOR EVALUATION SUMMARY" << endl << endl << endl
		<< "INSTRUCTOR NUMBER: " << a << endl
		<< "COURSE NUMBER: " << b << endl
		<< "NUMBER OF PARTICIPANTS: " << c << endl
		<< "AVERAGES:" << endl
		<< "QUESTION 1\t" << d << endl
		<< "QUESTION 2\t" << e << endl
		<< "QUESTION 3\t" << f << endl
		<< "QUESTION 4\t" << g << endl
		<< "QUESTION 5\t" << h << endl
		<< "INSTRUCTOR AVERAGE: " << i << endl << endl << endl
		<< "END OF PROGRAM.";

}

