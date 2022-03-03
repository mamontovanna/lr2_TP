#include <iostream>
#include "List.h"
#include "Menu.h"

using namespace std;

void Menu::main_menu()
{
	while (exit == 1)
	{
		cout << "There's two lists: list_one and list_two" << endl;
		cout << "Which one you choose?" << endl;
		cout << "1 - list_one" << endl;
		cout << "2 - list_two" << endl;
		cout << "->  ";
		cin >> choose;
		switch (show_options())
		{
		case 1:
			add_elem();
			break;
		case 2:
			delete_elem();
			break;
		case 3:
			print_list();
			break;
		case 4:
			math_list();
			break;
		case 5:
			compare_list();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}

int Menu::show_options()
{
	int c1;
	cout << "\nWhat do you want to do?" << endl;
	cout << "1 - Add new element to the list (++)" << endl;
	cout << "2 - Delete an element from the list (--)" << endl;
	cout << "3 - Print list (optionally)" << endl;
	cout << "4 - Math with lists" << endl;
	cout << "5 - Compare two lists" << endl;
	cout << "0 - Exit" << endl;
	cout << ">>  ";
	cin >> c1;
	return c1;
}

void Menu::add_elem()
{
	if (choose == 1)
	{
		++list;
	}
	else
	{
		++new_list;
	}
}

void Menu::delete_elem()
{
	if (choose == 1)
	{
		list--;
	}
	else
	{
		new_list--;
	}
}

void Menu::print_list()
{
	cout << "Do you want print whole list or the first five elements?" << endl;
	int c;
	cout << "1 - Whole list" << endl;
	cout << "2 - The first five" << endl;
	cout << "3 - Print one element" << endl;
	cin >> c;

	switch (c)
	{
	case 1:
		print_whole();
		break;
	case 2:
		print_five();
		break;
	case 3:
		print_one();
		break;
	default:
		break;
	}
}

void Menu::print_five()
{
	if (choose == 1)
	{
		if (list.get_size() < 5)
		{
			cout << "Error: There's less than five elements at the list" << endl;
			return;
		}
		else
		{
			cout << "The first five elements: ";
			list();
		}
	}
	else
	{
		if (new_list.get_size() < 5)
		{
			cout << "Error: There's less than five elements at the list" << endl;
			return;
		}
		else
		{
			cout << "The first five elements: ";
			new_list();
		}
	}
}

void Menu::print_whole()
{
	if (choose == 1)
	{
		list.print();
	}
	else
	{
		new_list.print();
	}
}

void Menu::print_one()
{
	if (choose == 1)
	{
		cout << "Which one do you want to print?" << endl;
		cout << "Input number from 1 to " << list.get_size() << ":" << endl;
		int c;
		cin >> c;
		cout << list[c - 1] << endl;
	}
	else
	{
		cout << "Which one do you want to print?" << endl;
		cout << "Input number from 1 to " << new_list.get_size() << ":" << endl;
		int c;
		cin >> c;
		cout << new_list[c - 1] << endl;
	}
}



void Menu::math_list()
{
	int c;
	cout << "\nWhat do you want to do?" << endl;
	cout << "1 - Plus (+)" << endl;
	cout << "2 - Minus (-)" << endl;
	cout << "3 - Miltiply (*)" << endl;
	cout << "4 - Divide (/)" << endl;
	cout << "->  ";
	cin >> c;
	switch (c)
	{
	case 1:
		list + new_list;
		break;
	case 2:
		list - new_list;
		break;
	case 3:
		list * new_list;
		break;
	case 4:
		list / new_list;
		break;
	default:
		break;
	}
}

void Menu::compare_list()
{
	int c;
	cout << "\nWhat do you want to do?" << endl;
	cout << "1 - Equal (==)" << endl;
	cout << "2 - Not equal (!=)" << endl;
	cout << "3 - More (>)" << endl;
	cout << "4 - Less (<)" << endl;
	cout << "5 - More or equal (>=)" << endl;
	cout << "6 - Less or equal (<=)" << endl;
	cout << "->  ";
	cin >> c;
	switch (c)
	{
	case 1:
		if (list == new_list)
		{
			cout << "List is equal to new_list" << endl;
		}
		else
		{
			cout << "List is not equal to new_list" << endl;
		}
		break;
	case 2:
		if (list != new_list)
		{
			cout << "List is not equal to new_list" << endl;
		}
		else
		{
			cout << "List is equal to new_list" << endl;
		}
		break;
	case 3:
		if (list > new_list)
		{
			cout << "List is more than new_list" << endl;
		}
		else
		{
			cout << "List is not more than new_list" << endl;
		}
		break;
	case 4:
		if (list < new_list)
		{
			cout << "List is less than new_list" << endl;
		}
		else
		{
			cout << "List is not less than new_list" << endl;
		}
		break;
	case 5:
		if (list >= new_list)
		{
			cout << "List is more or equal than new_list" << endl;
		}
		else
		{
			cout << "List is not more or equal than new_list" << endl;
		}
		break;
	case 6:
		if (list <= new_list)
		{
			cout << "List is less or equal than new_list" << endl;
		}
		else
		{
			cout << "List is not less or equal than new_list" << endl;
		}
		break;
	default:
		break;
	}
}

void Menu::exit_from_programm()
{
	exit = 0;
}