//This program opens a text file containing a list of random numbers, and reads them.
//It determines the number of entries in the file, a running total of those values,
//the maximum and minimum values in the list, and an average of the numbers.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	int counter = 1;		//The counter for the number of values in the list
	int total = 0;			//The running total of the list
	float average = 0;		//The average of the numbers in the list
	int comparison_min;		//Hold the value of the lowest number in the list so far
	int comparison_max;		//Hold the value of the highest number in the list so far
	int value;				//Hold each value read from the list

	//Format output for the program
	cout << fixed << showpoint << setprecision(2);

	//Give the user an introduction to the program
	cout << "This program opens the file \"Random.txt\" and reads the list of numbers in it.\n"
		<< "It calculates and displays the number of items in the file, the total of all the values,"
		<< "the minimum and maximum values, and an average of all the numbers.\n\n";
	cout << "Opening file \"Random.txt now...\"\n\n";

	//Open the file to be read.
	ifstream inputFile;
	inputFile.open("Random.txt");

	//Return an error message to the user if the file fails to open.
	if(inputFile.fail())
	{
		cout << "Error: could not open file.\n"
			<< "Terminating program now.\n";
	}
	//If the file opens, continue processing it.
	else
	{
		//Tell the user the file opened successfully.
		cout << "The file was opened successfully.\n\n";
		cout << "Processing data now...\n\n";

		//Get the first value in the file, and set it as a basis for comparison
		//for the rest of the file to determine the lowest and highest values
		inputFile >> value;
		comparison_min = value;
		comparison_max = value;

		//Run through the list of numbers, keeping a running total and a count of the values
		while (inputFile >> value)
		{
			inputFile >> value;
			total += value;
			if (value < comparison_min)
			{
				comparison_min = value;
			}
			if (value > comparison_max)
			{
				comparison_max = value;
			}
			counter++;
		}
		
		//After all the values in the file have been read, calculate the average of the numbers
		average = total / counter;

		//Close the file
		inputFile.close();

		//Display the information about the list for the user to see
		cout << "There are " << counter << " items in the list.\n";
		cout << "The total of all values is " << total << ".\n";
		cout << "The minimum value in the list is " << comparison_min << ",\n"
			<< "and the maximum value is " << comparison_max << ".\n";
		cout << "The average of all the values in the list is " << average << ".\n\n";
		cout << "Thank you for using this program!\n\n";

	}

	system("PAUSE");
	return 0;
}