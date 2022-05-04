#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	ofstream file2;

	string longstr, strfile;
	int len = 0, n = 0;
	file.open("file.txt", ios::in);
	file2.open("file2.txt", ios::out);
	if (!file.is_open() && !file2.is_open())
	{
		cout << "Invalid!";
	}
	else
	{
		while (getline(file, strfile))
		{
			char* pch = strtok((char*)strfile.c_str(), ".!?");
			while (pch != NULL)
			{
				longstr += strfile;
				pch = strtok(NULL, ".!?");
			}
			cout << longstr << endl;
			len = longstr.length();
			n = len - 1;
			for (int i = 0; i < (len / 2); i++)
			{
				swap(longstr[i], longstr[n]);
				n = n - 1;
			}
			file2 << longstr;
			cout << longstr << endl;
		}
	}
	file.close();
	file2.close();
	return 0;
}