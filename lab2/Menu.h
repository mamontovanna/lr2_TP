#pragma once
#include "List.h"
#include <iostream>
//объ€вление класса "Menu",  в которомсоздаютс€ объекты класса List(2)
//также описаны методы дл€ работы со списками
class Menu
{
private:
	List list, new_list;
	int exit = 1;
	int choose;

public:
	void main_menu();//главное меню(выбор списка, с которым работаем)
	int show_options();//доступные опции
	void add_elem();//добавление элемента
	void delete_elem();//удаление элмента
	void print_list();//вывод списка(содержит в себе 3 опции на выбор)
	void math_list();//выполнение арифметических операций со списками
	void compare_list();//сравнение списков
	void print_five();//вывод подсписка первых 5 элементов списка
	void print_whole();//вывод всего списка
	void print_one();//вывод конкретного элмента списка
	void exit_from_programm();//выход
};
