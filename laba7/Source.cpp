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
	cout << "Меню" << endl;
	cout << "1 - Добавить преподавателя" << endl;
	cout << "2 - Распечатать информацию о всех преподавателях" << endl;
	cout << "3 - Поиск преподавателя по фио" << endl;
	cout << "4 - Сортировка по предмету преподователей" << endl;
	cout << "0 - Выход " << endl;
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
				cout << "Пункт меню: ";
				cin >> menu;
				if (!cin) throw - 1; //если menu не типа int выбрасывается исключение 
				if (menu > 10 || menu < 0) throw - 1;
				check = false;
			}
			catch (int error) {
				cout << endl << "Допустимы только цифры 1-10 и 0! Попробуйте еще!" << endl;
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

		default:cout << "Введите нужную цифру!" << endl;
			goto TryAgain;
			break;
		}
	}
}