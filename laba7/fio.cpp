#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include "fio.h"
#include <iostream>
using namespace std;

fio::fio() {
}
fio:: ~fio() {
}
char* fio::getFam() {
	return fam;
}

void fio::setfami(char* _fam)
{
	this->fam = strdup(_fam);
}
void fio::setnam(char* _nam)
{
	this->name = strdup(_nam);
}
void  fio::setot(char* _ot)
{
	this->father = strdup(_ot);
}

char* fio::getfami()
{
	return this->fam;
}
char* fio::getnam()
{
	return this->name;
}
char* fio::getot()
{
	return this->father;
}