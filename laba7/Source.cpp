#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "prepod.h"
#include "fio.h"
#include <list>

using namespace std;
int prepod::count;
void printMenu()
{
	cout << endl;
	cout << "����" << endl;
	cout << "1 - �������� �������������" << endl;
	cout << "2 - ����������� ���������� � ���� ��������������" << endl;
	cout << "3 - ����� ������������� �� ���" << endl;
	cout << "4 - ���������� �� �������� ��������������" << endl;
	cout << "0 - ����� " << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<prepod> t;
	int menu;
	loadTeacher("data.txt", t);
	bool check = true;
	while (1) {
		check = 1;
		printMenu();
		while (check)
		{
		TryAgain:
			try {
				cout << "����� ����: ";
				cin >> menu;
				if (!cin) throw - 1; //���� menu �� ���� int ������������� ���������� 
				if (menu > 10 || menu < 0) throw - 1;
				check = false;
			}
			catch (int error) {
				cout << endl << "��������� ������ ����� 1-10 � 0! ���������� ���!" << endl;
				cin.clear();
				cin.ignore(4096, '\n');
				check = true;
			}
		}
		switch (menu) {

		case 1:
			t.push_back(prepod());
			cin >> t.back();
			t.front().setcount(t.front().getcount() + 1);
			break;

		case 2: prepod::printTable();
			t.back().PrintAll(t);
			for (int i = 0; i < 140; i++) {
				cout << "-";
			}
			cout << endl;
			break;

		case 3:
			t.back().searchFio(t);
			break;

		case 4:
			t.back().Sort(t);
			break;

		case 0: saveTeacher("data.txt", t);
			return 0;
			break;

		default:cout << "������� ������ �����!" << endl;
			goto TryAgain;
			break;
		}
	}
}