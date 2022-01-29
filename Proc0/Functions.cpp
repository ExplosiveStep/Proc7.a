#include "Header.h"
#include <fstream>

// Инициализация контейнера
void Init(container* head, container* tail) {
    head->len = tail->len = 0;
    head->cont = tail->cont = NULL;
    head->next = tail->next = NULL;
    head->prev = tail->prev = NULL;
}

//Очистка контейнера от элементов
void Clear(container* head) {

    int len = head->len;
    container* temp = head;
    for (int i = 0; i < len; i++) {//Очистка транспорта
        delete temp->cont;
        temp->len = 0;
        temp = temp->next;
    }
    for (int i = 0; i < len; i++) {//Очистка контейнеров

        temp = head->next;
        delete head;
        head = temp;
    }
}

// Ввод содержимого контейнера из указанного потока
void In(container* head, container* tail, ifstream& ifst) {
    container* temp;
    int Len = 0;
    while (!ifst.eof()) {
        switch (Len)
        {
        case 0://Для 1-го элемента
            if ((head->cont = In(ifst))) {
                Len++;
            }
            break;

        case 1://Для 2-ух элементов
            if ((tail->cont = In(ifst))) {
                head->next = tail;
                head->prev = tail;
                tail->next = head;
                tail->prev = head;
                Len++;
            }
            break;

        default://Для более 2-ух элементов
            temp = new container;
            temp->next = NULL;
            temp->prev = NULL;
            if ((temp->cont = In(ifst))) {
                tail->next = temp;
                head->prev = temp;
                temp->next = head;
                temp->prev = tail;
                tail = temp;
                Len++;
            }
            break;
        }
        temp = head;
        for (int i = 0; i < Len; i++) {//Обновление значения "len" в каждом контейнере
            temp->len = Len;
            temp = temp->next;
        }
    }
}

// Ввод параметров из файла
transport* In(ifstream& ifst)
{
    transport* sp;
    int k;
    ifst >> k;
    switch (k) {
    case 1:
        sp = new transport;
        sp->k = transport::key::TRUCK;
        In(sp->t, ifst);
        return sp;
    case 2:
        sp = new transport;
        sp->k = transport::key::BUS;
        In(sp->b, ifst);
        return sp;
    default:
        return 0;
    }
}

// Ввод параметров грузовика из файла
void In(truck& t, ifstream& ifst)
{
    ifst >> t.cargo >> t.engine;
}

// Ввод параметров автобуса из файла
void In(bus& b, ifstream& ifst) {

    ifst >> b.capacity >> b.engine;
}

// Вывод параметров в файл
void Out(container* head, ofstream& ofst) {

    container* temp = head;
    int len = temp->len;
    ofst << "Container contains " << head->len
        << " elements." << endl;
    for (int i = 0; i < len; i++) {
        ofst << i << ": ";
        Out((temp->cont), ofst);
        temp = temp->next;
    }
}

// Вывод параметров текущего транспорта в поток
void Out(transport* s, ofstream& ofst) {

    switch (s->k) {
    case transport::key::BUS:
        Out(s->b, ofst);
        break;
    case transport::key::TRUCK:
        Out(s->t, ofst);
        break;
    default:
        ofst << "Incorrect transport!" << endl;
    }
}

// Вывод параметров грузовикав файл
void Out(truck& t, ofstream& ofst)
{
    ofst << "It is Truck: cargo = " << t.cargo << ", engine = " << t.engine << endl;
}

// Вывод параметров автобуса файл
void Out(bus& b, ofstream& ofst) {
    ofst << "It is bus: capacity = " << b.capacity << ", engine = " << b.engine << endl;
}

// Мультиметод
void MultiMethod(container* head, ofstream& ofst) {
    int len = head->len;
    container* First = head;
    container* Second = head->next;
    for (int i = 0; i < len - 1; i++) {

        for (int j = i + 1; j < len; j++) {
            switch (First->cont->k)
            {
            case transport::TRUCK:
                switch (Second->cont->k)
                {
                case transport::TRUCK:
                    ofst << "Truck and Truck." << endl;
                    break;
                case transport::BUS:
                    ofst << "Bus and Truck." << endl;
                    break;
                default:
                    ofst << "Unknown type" << endl;
                }
                break;
            case transport::BUS:
                switch (Second->cont->k)
                {
                case transport::TRUCK:
                    ofst << "Bus and Truck." << endl;
                    break;
                case transport::BUS:
                    ofst << "Bus and Bus." << endl;
                    break;
                default:
                    ofst << "Unknown type" << endl;
                }
                break;
            default:
                ofst << "Unknown type" << endl;
            }
            Out(First->cont, ofst);
            Out(Second->cont, ofst);
            Second = Second->next;
        }
        First = First->next;
        Second = First->next;
    }
}