#pragma once
#include <iostream>

typedef struct Node
{
	int data = 0;
	Node* next;
}; //���� ������

class List
{
private:
	Node* head; //������
	Node* tail; //�����
	int size; //������ ������
public:
	List(); //����������� ��� ����������
	explicit List(int size_lt); //����������� � ���������� ��� ��������������
	List(const List& List_copy); //����������� �����������
	~List(); //����������

	List& operator++(); //���������� � ����� ������(�������)
	friend void operator--(List& obj, int); //�������� ������� ��������(��������)
	int operator[] (int index); //��������� �������� ������
	void operator()(); //��������� �� 1 �� 5
	List& operator= (const List& r); //���������� ���� ������� ���� �����
	friend bool operator== (const List& l, const List& r); //����� ����� �������(���������� ���������)
	friend bool operator!= (const List& l, const List& r); //����� ������ ������� �������
	friend bool operator> (const List& l, const List& r); //����� ������ �������
	friend bool operator< (const List& l, const List& r); //����� ������ �������
	friend bool operator>= (const List& l, const List& r); //����� ������ ��� ����� �������
	friend bool operator<= (const List& l, const List& r); //����� ������ ��� ����� �������
	void operator+ (const List& r); //����� ������ ��� ����� ���� �������
	void operator- (const List& r); //����� ������ ��� �������� ���� �������
	void operator* (const List& r); //����� ������ ��� ������������ ���� �������
	void operator/ (const List& r); //����� ������ ��� ������� ���� �������
	friend std::ostream& operator<< (std::ostream& out, const List& obj);//���������� ��������� ������
	friend std::istream& operator>> (std::istream& in, List& obj);//���������� ��������� �����

	void push(int value);
	void print(); //����� ����������� ������

	Node* get_head();
	Node* get_tail();
	int get_size() const;
	void set_size(int new_size);
};
