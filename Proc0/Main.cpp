#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container* head = new container;//"������"
	container* tail = new container;//"�����"
	Init(head, tail);//������������� ����������
	In(head, tail, ifst);//���� ����������� ���������� �� ���������� ������
	int len = head->len;//���������� ��������� � ����������
	ofst << "Filled container. " << endl;
	Out(head, ofst);//����� ���������� ���������� � ����
	ofst << "\n\nMULTIMETHOD. " << endl;
	MultiMethod(head, ofst);
	Clear(head);//������� ����������
	ofst << "Empty container. " << endl;
	cout << "Stop" << endl;
	if (len == 1) delete tail;
	if (len == 0)
	{
		delete head;
		delete tail;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}