#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Friend
{
	string last_name;
	string name;
	string telephone;
	int day;
	int month;
	int year;
};

void enter_save(char* fname);
void load_print(char* fname);
void telephone_find(char* fname, char* ftelephone);

int main()
{
	char fname[61];
	char ftelephone[151];
	char ch;
	do
	{
		cout << "--------------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n"<< endl;
		cout << "[1] - Enter & Save Data\n" << endl;
		cout << "[2] - Load & Print Data\n" << endl;
		cout << "[3] - Find Friend By Telephone\n" << endl;
		cout << "[0] - Exit\n";
		cout << "--------------------------------\n";
		cout << "Your Choise: "; cin >> ch;
			switch (ch)
			{
			case '0':
				cout << "Goodbye! See Ya Later, Aligator!!!";
				break;
			case '1':
				cout << "You Chosen [1] - Enter & Save Data:\n";
				cin.get();
				cin.sync();
				cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
				enter_save(fname);
				break;
			case '2':
				cout << "You Chosen [2] - Load & Print Data:\n";
				cin.get();
				cin.sync();
				cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
				load_print(fname);
				break;
			case '3':
				cout << "You Chosen [3] - Find Friend By Telephone:\n";
				cin.get();
				cin.sync();
				cout << "Enter File Name: "; cin.getline(fname, sizeof(fname));
				cout << "Enter Telephone Number: "; cin.getline(ftelephone, sizeof(ftelephone));
				telephone_find(fname, ftelephone);
				break;
			default:
				cout << endl;
				cout << "--------------------------------\n";
				cout << "Main Menu\n";
				cout << "Please make your selection\n";
				cout << "[1] - Enter & Save Data\n" << endl;
				cout << "[2] - Load & Print Data\n" << endl;
				cout << "[3] - Find Friend By Telephone\n" << endl;
				cout << "[0] - Exit\n";
				cout << "--------------------------------\n";
				cout << "Your Choise: "; cin >> ch;
			}
	} while (ch != '0');
	return 0;
}
void enter_save(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Friend friends;
	char ch;
	do
	{
		cout << endl;
		cout << "Last Name: "; cin.sync();
		cin >> friends.last_name;
		cout << "Name: "; cin.sync();
		cin >> friends.name;
		cout << "Telephone: "; 
		cin >> friends.telephone;
		cout << "Birthday Day: "; 
		cin >> friends.day;
		cout << "Birthday Month: ";
		cin >> friends.month;
		cout << "Birthday Year: ";
		cin >> friends.year;

		if (!f.write((char*)& friends, sizeof(Friend)))
		{
			cerr << "Error writing file." << endl;
		}
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void load_print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Friend friends;
	while (f.read((char*)& friends, sizeof(Friend)))
	{
		cout << endl;
		cout << "Last Name: " << friends.last_name << endl;
		cout << "Name: " << friends.name << endl;
		cout << "Telephone: " << friends.telephone << endl;
		cout << "Birthday Day: " << friends.day << endl;
		cout << "Birthday Month: " << friends.month << endl;
		cout << "Birthday Year: " << friends.year << endl;
	}
}
void telephone_find(char* fname, char* ftelephone)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Friend friends;
	while (f.read((char*)&friends, sizeof(Friend)))
	{
		if (friends.telephone == ftelephone) {
			cout << endl;
			cout << "Found Friend With Telephone (" << ftelephone << ") :"<< endl;
			cout << endl;
			cout << "Last Name: " << friends.last_name << endl;
			cout << "Name: " << friends.name << endl;
			cout << "Telephone: " << friends.telephone << endl;
			cout << "Birthday Day: " << friends.day << endl;
			cout << "Birthday Month: " << friends.month << endl;
			cout << "Birthday Year: " << friends.year << endl;
		}
		else
		{
			cout << "...";
			cout << endl;
		}
	}
}