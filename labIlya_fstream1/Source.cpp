#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverse_String(string& greet, int n, int i) {

	if (n <= i) 
	{
		return; 
	}
	swap(greet[i], greet[n]);
	reverse_String(greet, n - 1, i + 1);
}

int main()
{
	ifstream file;
	ofstream file2;

	string longstr, strfile;
	int len = 0, n = 0, i = 1, k = 1, countr1 = 0, num = 0, maximum = -99999, allsentences = 0;
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
			char* pch = strtok((char*)strfile.c_str(), ".");
			while (pch != NULL)
			{
				longstr = pch;
				len = longstr.length();
				n = len - 1;
				reverse_String(longstr, n, i);
				file2 << longstr << ".";
				pch = strtok(NULL, ".");
				countr1++;
				allsentences++;
			}
			cout << "Sentensec in string #" << k << ": " << countr1 << endl;
			file2 <<"\n";
			if (maximum < countr1)
			{
				maximum = countr1;
				num = k;
			}
			countr1 = 0;
			k++;
		}
		cout << "Total reverse sentences: " << allsentences << endl;
		cout << "Maximum sentences in string #" << num << endl;
	}
	file.close();
	file2.close();
	return 0;
}