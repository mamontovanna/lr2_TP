#pragma once
#include "List.h"
#include <iostream>
//���������� ������ "Menu",  � ���������������� ������� ������ List(2)
//����� ������� ������ ��� ������ �� ��������
class Menu
{
private:
	List list, new_list;
	int exit = 1;
	int choose;

public:
	void main_menu();//������� ����(����� ������, � ������� ��������)
	int show_options();//��������� �����
	void add_elem();//���������� ��������
	void delete_elem();//�������� �������
	void print_list();//����� ������(�������� � ���� 3 ����� �� �����)
	void math_list();//���������� �������������� �������� �� ��������
	void compare_list();//��������� �������
	void print_five();//����� ��������� ������ 5 ��������� ������
	void print_whole();//����� ����� ������
	void print_one();//����� ����������� ������� ������
	void exit_from_programm();//�����
};
