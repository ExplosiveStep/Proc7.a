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
	container* head = new container;//"Голова"
	container* tail = new container;//"Хвост"
	Init(head, tail);//Инициализация контейнера
	In(head, tail, ifst);//Ввод содержимого контейнера из указанного потока
	int len = head->len;//Количество элементов в контейнере
	ofst << "Filled container. " << endl;
	Out(head, ofst);//Вывод параметров транспорта в файл
	ofst << "\n\nMULTIMETHOD. " << endl;
	MultiMethod(head, ofst);
	Clear(head);//Очистка контейнера
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