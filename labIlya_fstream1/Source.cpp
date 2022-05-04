#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	string word, strfile;
	int dots = 0, commas = 0;
	file.open("file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Invalid!";
	}
	else
	{
		while (getline(file, strfile))
		{
			for (int i = 0; i < strfile.size();i++)
			{
				if (strfile[i] == ',')
				{
					commas++;
				}
				if (strfile[i] == '.')
				{
					dots++;
				}
			}
		}
		cout << "The number of dots: " << dots << endl;
		cout << "The number of commas: " << commas << endl;
		file.close();
	}
	return 0;
}