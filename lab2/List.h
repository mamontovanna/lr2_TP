#pragma once
#include <iostream>

typedef struct Node
{
	int data = 0;
	Node* next;
}; //узел списка

class List
{
private:
	Node* head; //голова
	Node* tail; //хвост
	int size; //размер списка
public:
	List(); //конструктор без параметров
	explicit List(int size_lt); //конструктор с параметром без преобразования
	List(const List& List_copy); //конструктор копирования
	~List(); //деструктор

	List& operator++(); //добавление в конец списка(префикс)
	friend void operator--(List& obj, int); //удаление первого элемента(постфикс)
	int operator[] (int index); //получение элемента списка
	void operator()(); //подсписок от 1 до 5
	List& operator= (const List& r); //присвоение двух списков друг другу
	friend bool operator== (const List& l, const List& r); //левый равен правому(количество элементов)
	friend bool operator!= (const List& l, const List& r); //левый список неравен правому
	friend bool operator> (const List& l, const List& r); //левый больше правого
	friend bool operator< (const List& l, const List& r); //левый меньше правого
	friend bool operator>= (const List& l, const List& r); //левый больше или равен правому
	friend bool operator<= (const List& l, const List& r); //левый меньше или равен правому
	void operator+ (const List& r); //новый список как сумма двух списков
	void operator- (const List& r); //новый список как разность двух списков
	void operator* (const List& r); //новый список как произведение двух списков
	void operator/ (const List& r); //новый список как частное двух списков
	friend std::ostream& operator<< (std::ostream& out, const List& obj);//перегрузка оператора вывода
	friend std::istream& operator>> (std::istream& in, List& obj);//перегрузка оператора ввода

	void push(int value);
	void print(); //вывод содержимого списка

	Node* get_head();
	Node* get_tail();
	int get_size() const;
	void set_size(int new_size);
};
