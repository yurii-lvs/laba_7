#pragma once
#pragma warning(disable : 4996)
#include"fio.h"
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

class prepod
{
private:
	fio _fio;
	int departament;
	int status;
	char* subj;
	static int count;
public:
	friend class fio;
	friend std::istream& operator>> (istream& is, prepod& temp);
	friend int operator==(fio& a, prepod& b);
	prepod();
	prepod(int departament, fio fi, int status);
	void Addprepod();
	~prepod();
	friend int loadTeacher(const char* fileName, list<prepod>& t);
	friend void saveTeacher(const char* fileName, list<prepod>& t);
	static void printTable();
	static void sortPrepod(prepod* t, int n);
	void searchFio(list<prepod> mas);
	void setfam(char* _fam);
	void setname(char* _name);
	void setot(char* _name);
	void setdep(int _dep);
	void setSt(int _st);
	void setsubj(char* _sub);
	char* getfam();
	char* getname();
	char* getot();
	int getdep();
	int getst();
	char* getsubj();
	void PrintAll(list<prepod> mas);
	void Print();
	int getcount();
	bool operator==(fio& fio2);
	void setcount(int _count);
	void Sort(list<prepod> &mas);
	fio& getFIO();
};



