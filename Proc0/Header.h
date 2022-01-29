#ifndef HEADER
#define HEADER

#include <iostream>

using namespace std;

//��������
struct truck {
	int cargo;//����������������
	int engine;//�������� ���������
};

//�������
struct bus {
	short int capacity;//��������������������
	int engine;//�������� ���������
};

//���������
struct transport {

	enum key { TRUCK, BUS };
	key k;
	union {
		truck t;
		bus b;
	};
};

//���������
struct container
{
	int len;
	transport* cont;
	container* next;
	container* prev;
};

void Init(container* head, container* tail);

void Clear(container* head);

void In(container* head, container* tail, ifstream& ifst);

transport* In(ifstream& ifdt);

void In(truck& t, ifstream& ist);

void In(bus& b, ifstream& ist);

void Out(container* head, ofstream& ofst);

void Out(transport* s, ofstream& ofst);

void Out(truck& t, ofstream& ofst);

void Out(bus& b, ofstream& ofst);

void MultiMethod(container* head, ofstream& ofst);

#endif