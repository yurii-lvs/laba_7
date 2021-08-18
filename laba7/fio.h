#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class fio
{
	friend class prepod;
public:
	fio();
	~fio();
	char* getFam();
	void setfami(char* _fam);
	void setnam(char* _nam);
	void setot(char* _ot);
	char* getfami();
	char* getnam();
	char* getot();
protected:
	char* fam;
	char* name;
	char* father;
};
