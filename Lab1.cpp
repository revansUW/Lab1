// Ryan Evans
// Lab 1

#include<fstream>
#include<string>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

string promptUser(void);

int main()
{
	double first = 0;
	double second = 0;
	double secLast = 0;
	double last = 0;

	ifstream inFile;
	string filename;

	filename = promptUser();
	inFile.open(filename);

	if (!inFile)    // error case: cannot open file
	{
		cout << "File \"" << filename << "\" could not be opened" << endl;
		inFile.clear();
		system("pause");
		return 0;
	}

	int temp = 0;    // temporary variable storage
	int i = 0;    // iterator
	while (true)
	{
		inFile >> temp;

		if (inFile.eof())    // stop the loop when end of file is encountered
		{
			break;
		}

		if (i == 0)	   // assigns first value to first variable
		{
			first = temp;
			i++;
			continue;
		}

		if (i == 1)    // assigns second value to second variable
		{
			second = temp;
			i++;
			continue;
		}

		secLast = last;    // assigns secondlast to previous last value
		last = temp;    // assigns last to new last value
		i++;
	}

	cout << "The first two values are " << first << " and " << second << ", the last two values are " << secLast << " and " << last << ", and the total number of values is " << i << endl;
	inFile.close();
	system("pause");
	return 0;
}

string promptUser()
{
	string input;
	cout << "Please enter the filename to read from: ";
	cin >> input;
	return input;
}