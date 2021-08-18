#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include "fio.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "prepod.h"


void prepod::printTable()
{
	cout << endl;
	cout << "Список всех преподавателей" << endl;
	cout << "Фамилия";              
	cout << setw(18) << "Имя";
	cout << setw(23) << "Отчество";
	cout << setw(22) << "Кафедра";
	cout << setw(28) << "Ученое звание";
	cout << setw(22) << "Предмет" << endl;
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}
prepod::prepod() {

}
void prepod::PrintAll(list<prepod> mas)
{
	list<prepod>::iterator it;
	for (it = mas.begin(); it != mas.end(); it++) // печать списка
		(it)->Print();
	cout << "Count " << count << endl;
}

void prepod::Print()
{
	char* tf = strdup(this->_fio.getfami());
	char* tn = strdup(this->_fio.getnam());
	char* ts = strdup(this->_fio.getot());
	char* tp = strdup(this->getsubj());
	if (this->_fio.getfami()[strlen(this->_fio.getfami()) - 1] == '\n') { //замена перевода строки на пробел
		tf[strlen(this->_fio.getfami()) - 1] = ' ';
	}
	if (this->_fio.getnam()[strlen(this->_fio.getnam()) - 1] == '\n') {
		tn[strlen(this->_fio.getnam()) - 1] = ' ';
	}
	if (this->_fio.getot()[strlen(this->_fio.getot()) - 1] == '\n') {
		ts[strlen(this->_fio.getot()) - 1] = ' ';
	}
	if (this->getsubj()[strlen(this->getsubj()) - 1] == '\n') {
		tp[strlen(this->getsubj()) - 1] = ' ';
	}
	cout << tf;
	for (int j = 0; j < 15 - strlen(tf) + 7; j++) cout << " ";
	cout << tn;
	for (int j = 0; j < 15 - strlen(tn) + 3; j++) cout << " ";
	cout << ts;
	int s = 0;
	for (int j = 0; j < 15 - strlen(ts) + 8; j++) cout << " ";
	if (departament == 1) cout << "ИПОВС";
	if (departament == 2) cout << "ВМ";
	if (departament == 3) cout << "ВТ";
	if (departament == 1) s = 5;
	if (departament == 2) s = 2;
	if (departament == 3) s = 2;
	for (int j = 0; j < 15 - s + 7; j++) cout << " ";
	if (status == 1) cout << "преподаватель";
	if (status == 2) cout << "доцент";
	if (status == 3) cout << "доктор наук";
	if (status == 1) s = 13;
	if (status == 2) s = 6;
	if (status == 3) s = 11;
	for (int j = 0; j < 15 - s + 13; j++) cout << " ";
	cout << tp << endl;
}

void prepod::Addprepod() { //инициализация с клавиатуры
	cout << "Добаваление нового преподавателя" << endl;
	bool check = 1;
	char buff[255];
	int temp;
	while (check) {
		try {
			cout << "Введите кафедру (1-ИПОВС, 2-ВМ, 3-ВТ): ";
			cin >> temp;
			if (!cin) throw 0; //если не цифра
			if (!(temp == 1 || temp == 2 || temp == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только цифры 1-3! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	setdep(temp);
	check = 1;
	while (check) {
		try {
			cout << "Введите фамилию: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0;
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	prepod::_fio.fam = (char*)malloc(strlen(buff) + 1);
	this->_fio.setfami(buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите имя: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	prepod::_fio.name = (char*)malloc(strlen(buff) + 1);
	this->setname(buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите отчество: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	prepod::_fio.father = (char*)malloc(strlen(buff) + 1);
	this->setot(buff);
	check = 1; int temp1;
	while (check) {
		try {
			cout << "Введите ученое звание (1- преподаватель, 2- доцент,3-доктор наук): ";
			cin >> temp1;
			if (!cin) throw 0; //если не цифра
			if (!(temp1 == 1 || temp1 == 2 || temp1 == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только цифры 1-3! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	setSt(temp1);
	check = 1;
	while (check) {
		try {
			cout << "Введите предмет: ";
			while (getchar() != '\n');
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	prepod::subj = (char*)malloc(strlen(buff) + 1);
	this->setsubj(buff);
}
prepod::~prepod() {
}

int loadTeacher(const char* fileName, list<prepod>& t) {
	FILE* f;
	int c = 0;
	if ((f=fopen(fileName, "r")) == NULL) {
		cout << "Файла нет, инициализация с клавиатуры!"<<endl;
		cout << "Введите количество преподавателей"<<endl;
		cin >> c;
		for (int i = 0; i < c; i++)
		{
			t.push_back(prepod());
			t.back().Addprepod();
		}
		t.front().setcount(c);
		return 0;
	}
	char* estr;
	char str[100];
	estr = fgets(str, sizeof(str), f);
	c = atoi(estr);
	printf("%d", c);

	for (int i = 0; i < c; i++) {
		t.push_back(prepod());
		estr = fgets(str, sizeof(str), f);
		t.back().setdep(atoi(estr));
		estr = fgets(str, sizeof(str), f);
		t.back().setfam(_strdup(estr));
		estr = fgets(str, sizeof(str), f);
		t.back().setname(_strdup(estr));
		estr = fgets(str, sizeof(str), f);
		t.back().setot(_strdup(estr));
		estr = fgets(str, sizeof(str), f);
		t.back().setSt(atoi(estr));
		estr = fgets(str, sizeof(str), f);
		t.back().setsubj(_strdup(estr));
	}
	t.front().setcount(c);
	fclose(f);
	return 0;
}

void saveTeacher(const char* fileName, list<prepod>& t) {
	list<prepod>::iterator it;
	FILE* f;
	f = fopen(fileName, "w");
	if ((f = fopen(fileName, "w")) != NULL)
	{
		fprintf(f, "%d\n", t.front().getcount());
		for (it = t.begin(); it != t.end(); it++) {
			fprintf(f, "%d\n", it->getdep());
			fputs(it->getfam(), f);
			if (it->getfam()[strlen(it->getfam()) - 1] != '\n')
				fprintf(f, "\n");
			fputs(it->getname(), f);
			if (it->getname()[strlen(it->getname()) - 1] != '\n')
				fprintf(f, "\n");
			fputs(it->getot(), f);
			if (it->getot()[strlen(it->getot()) - 1] != '\n')
				fprintf(f, "\n");
			fprintf(f, "%d\n", it->getst());
			fputs(it->getsubj(), f);
			if (it->getsubj()[strlen(it->getsubj()) - 1] != '\n')
				fprintf(f, "\n");
		}
	}
	fclose(f);
}

void prepod::searchFio(list<prepod> mas)
{
	char buff[255];
	list<prepod>::iterator it;
	fio fi;
	bool flag = 0;
	cout << endl;
	cout << "Поиск преподавателя по фио" << endl;
	bool check = 1;
	while (check) {
		try {
			cout << "Введите фамилию: ";
			while (getchar() != '\n');
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	fi.fam = (char*)malloc(strlen(buff) + 1);
	strcpy(fi.fam, buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите имя: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	fi.name = (char*)malloc(strlen(buff) + 1);
	strcpy(fi.name, buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите отчество: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	fi.father = (char*)malloc(strlen(buff) + 1);
	strcpy(fi.father, buff);
	for (it = mas.begin(); it != mas.end(); it++)
	{
		if (*it==fi)
		{
			cout << endl << "Преподаватель найден! " << endl;
			flag = 1;
			prepod::printTable();
			it->Print();
			for (int i = 0; i < 140; i++) {
				cout << "-";
			}
			cout << endl;
			break;
		}
	}
	if (flag == 0)
		cout << "Такого преподавателя нет!" << endl;
	flag = 0;
}

void prepod::setfam(char* _fam)
{
	this->_fio.fam = strdup(_fam);
}
void prepod::setname(char* _name)
{
	prepod::_fio.name = strdup(_name);
}
void prepod::setot(char* _name)
{
	prepod::_fio.father = strdup(_name);
}

void prepod::setdep(int _dep)
{
	prepod::departament = _dep;
}

void prepod::setSt(int _st)
{
	prepod::status = _st;
}

void prepod::setsubj(char* _sub)
{
	prepod::subj = strdup(_sub);
}

char* prepod::getfam()
{
	return this->_fio.fam;
}
char* prepod::getname()
{
	return this->_fio.name;
}
char* prepod::getot()
{
	return this->_fio.father;
}
int prepod::getdep()
{
	return prepod::departament;
}
int prepod::getst()
{
	return this->status;
}
char* prepod::getsubj()
{
	return this->subj;
}

istream& operator>> (istream& in, prepod& t)
{
	cout << "Добаваление нового преподавателя" << endl;
	bool check = 1;
	char buff[255];
	int temp;
	while (check) {
		try {
			cout << "Введите кафедру (1-ИПОВС, 2-ВМ, 3-ВТ): ";
			cin >> temp;
			if (!cin) throw 0; //если не цифра
			if (!(temp == 1 || temp == 2 || temp == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только цифры 1-3! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	check = 1;
	t.setdep(temp);
	while (check) {
		try {
			cout << "Введите фамилию: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0;
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t._fio.setfami(strcat(buff, "\n"));
	check = 1;
	while (check) {
		try {
			cout << "Введите имя: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t.setname(strcat(buff, "\n"));
	check = 1;
	while (check) {
		try {
			cout << "Введите отчество: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t.setot(strcat(buff, "\n"));
	check = 1; int temp1;
	while (check) {
		try {
			cout << "Введите ученое звание (1- преподаватель, 2- доцент,3-доктор наук): ";
			cin >> temp1;
			if (!cin) throw 0; //если не цифра
			if (!(temp1 == 1 || temp1 == 2 || temp1 == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только цифры 1-3! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t.setSt(temp1);
	check = 1;
	while (check) {
		try {
			cout << "Введите предмет: ";
			while (getchar() != '\n');
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только английские буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t.setsubj(strcat(buff, "\n"));
}

int prepod::getcount()
{
	return prepod::count;
}

void prepod::setcount(int _count)
{
	prepod::count = _count;
}

bool prepod::operator==(fio& _fio2)
{
	if ((_fio.getfami()[strlen(_fio.getfami()) - 1] == '\n') && (_fio2.getfami()[strlen(_fio2.getfami()) - 1] != '\n'))
		strcat(_fio2.getfami(), "\n");
	if ((_fio.getnam()[strlen(_fio.getnam()) - 1] == '\n') && (_fio2.getnam()[strlen(_fio2.getnam()) - 1] != '\n'))
		strcat(_fio2.getnam(), "\n");
	if ((_fio.getot()[strlen(_fio.getot()) - 1] == '\n') && (_fio2.getot()[strlen(_fio2.getot()) - 1] != '\n'))
		strcat(_fio2.getot(), "\n");
	if (((strcmp(this->_fio.getfami(), _fio2.getfami()) == 0) && ((strcmp(this->_fio.getnam(), _fio2.getnam()) == 0))) && ((strcmp(this->_fio.getot(), _fio2.getot()) == 0))) {
		return true;
	}
	else return false;
}

void prepod::Sort(list<prepod> &mas)
{

		auto it1 = mas.begin();
		for (it1; it1 != mas.end(); it1++)
		{
			auto it2 = it1;
			it2++;
			for (it2; it2 != mas.end(); it2++)
			{
				if (strcmp((*it1).getsubj(), (*it2).getsubj()) > 0)
				{
					prepod temp = (*it2);
					(*it2) = (*it1);
					(*it1) = temp;
				}
			}
		}
		cout << endl << "Сортировка выполнена";
}

fio& prepod::getFIO()
{
	return this->_fio;
}
