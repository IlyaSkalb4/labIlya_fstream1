#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	string word, strfile;
	int countr = 0;
	file.open("file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Invalid!";
	}
	else
	{
		cout << "Enter word: ";
		cin >> word;
		while(getline(file,strfile))
		{
			char* pch = strtok((char*)strfile.c_str(), " ,.:;!?");
			while (pch != NULL)
			{
				if (strcmp(pch, (char*)word.c_str()) == 0)
				{
					countr++;
				}
					pch = strtok(NULL, " ,.:;!?");
			}
		}
		cout << "The number of the word " << word << ": " << countr << endl;
		file.close();
	}
	return 0;
}