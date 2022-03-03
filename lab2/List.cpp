#include "List.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

List::List() : head(NULL), tail(NULL), size(0)//список инициализации
{
}

List::List(int size_lt) : head(NULL), tail(NULL)
{
	this->size = size_lt;
}

List::List(const List& List_copy) : size(List_copy.size)//конструктор копирования
{
	int* buf = new int[List_copy.size];
	Node* el_list = List_copy.head;

	for (int i = 0; i <= List_copy.size - 1; i++)
	{
		buf[i] = el_list->data;
		el_list = el_list->next;
	}

	for (int i = 0; i < List_copy.size; i++)
	{
		this->push(buf[i]);
	}

	delete[] buf;
}

List::~List()
{
	if ((head == 0) || (size == 0) || (tail == 0))//если список пуст
	{
		delete head; //удаляем вершину
		delete tail;
		size = 0; //размер нулевой
	}
	else
	{
		while (head->next != NULL) //пока не дойдем до нулевого указателя
		{
			Node* temp = head; //временная переменная юнита, присваиваем ей значение начала
			temp = temp->next; //теперь вершина указывает на следующий за ней элемент,
			if (temp == tail)
			{
				break;
			}
			delete temp; //а временную - удаляеям
		}
		delete head; //удаляем вершину
		delete tail;
		size = 0; //размер нулевой
	}
}

void List::push(int value)
{
	Node* tmp = new Node;
	tmp->next = head;
	tmp->data = value;

	if (head != NULL)
	{
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tail = tmp;
	}
	size++;
}

void List::print()
{
	if (size == 1)
	{
		Node* temp = head;
		cout << temp->data << endl;
		return;
	}
	if (size == 0)
	{
		cout << "There's nothing to print" << endl;
		return;
	}
	else
	{
		Node* temp = head;
		while (temp)//пока temp не null
		{
			cout << temp->data << ", ";
			temp = temp->next;
			if (temp == tail)
			{
				break;
			}
		}

		cout << temp->data << endl;
	}
}

Node* List::get_head()
{
	return head;
}

Node* List::get_tail()
{
	return tail;
}

int List::get_size() const
{
	return size;
}

void List::set_size(int new_size)
{
	this->size = new_size;

}

List& List::operator++ ()//добавление элемента(префикс)
{
	system("cls");
	int value;
	cout << "Input integer value to the list: ";
	cin >> value;
	Node* tmp = new Node;//выделяем память под новый узел
	tmp->next = head;//теперь новый узел указывает на предыдущий первый элемент и становится первым
	tmp->data = value;//присваиваем значение элемента

	if (head != NULL)//"замыкание круга", т.е. хвост указывает на начало
	{
		tail->next = tmp;
		tail = tmp;
		tmp->next = head;
	}
	else
	{
		head = tmp;
		tail = tmp;
		tail->next = head;
	}
	size++;
	cout << "The value was added to the list" << endl;
	return *this;
}

void operator--(List& obj, int)//перегруженный оператор удаления элемента(постфикс)
{

	if (obj.head == NULL)//если список пуст
	{
		cout << "The list is empty!" << endl;
		return;
	}

	if (obj.head == obj.head->next)//если голова равна хвосту
	{
		Node* tmp = obj.head;
		obj.head = tmp->next;
		delete tmp;
		obj.size--;
		cout << "The value was deleted!" << endl;
	}
	else
	{
		Node* tmp = obj.head;
		obj.head = tmp->next;
		obj.tail->next = obj.head;
		delete tmp;
		obj.size--;
		cout << "The value was deleted!" << endl;
	}
}

int List::operator[](int index)
{
	if ((index >= size) || (index < 0))
	{
		cout << "Error index";
		exit(-1);
	}
	else
	{
		Node* buf = head;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		return (buf->data);
	}
}

void List::operator()()
{
	if (size < 5)
	{
		return;
	}
	int i = 0;
	Node* buf = head;
	while (i < 5)
	{
		i++;
		cout << buf->data << ", ";
		buf = buf->next;
	}
	cout << endl;
}

List& List::operator= (const List& r)//присвоение двух списков друг другу
{
	if (this == &r)
	{
		return *this;
	}

	set_size(r.get_size());
	Node* buf = head;
	Node* buf_r = r.head;
	for (int i = 0; i < get_size(); i++)
	{
		buf->data = buf_r->data;
		buf = buf->next;
		buf_r = buf_r->next;
	}
	return *this;
}

bool operator==(const List& l, const List& r)
{
	if (l.get_size() == r.get_size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const List& l, const List& r)
{
	return !(l == r);//возвращаем обратное значенение работы перегруженного оператора "=="
}

bool operator>(const List& l, const List& r)
{
	if (l.get_size() > r.get_size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const List& l, const List& r)
{
	if (l.get_size() < r.get_size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(const List& l, const List& r)
{
	return !(l < r);
}

bool operator<=(const List& l, const List& r)
{
	return !(l > r);
}

void List::operator+(const List& r)
{
	if (size != r.get_size())
	{
		cout << "Two lists are not equal for size!" << endl;
		return;
	}
	Node* buf = head;
	Node* buf_r = r.head;
	while (buf->next != head)//пока не дойдем до хвоста
	{
		buf->data += buf_r->data;
		buf = buf->next;
		buf_r = buf_r->next;
	}
	buf->data += buf_r->data;
}

void List::operator-(const List& r)
{
	Node* buf = head;
	Node* buf_r = r.head;
	if (r.get_size() > size)//если размер правого списка будет больше размера левого
	{
		size = r.get_size();
		cout << "size minus: " << size;
	}
	while (buf->next != head)
	{
		buf->data -= buf_r->data;
		buf = buf->next;
		buf_r = buf_r->next;
	}
	buf->data -= buf_r->data;
}

void List::operator*(const List& r)
{
	Node* buf = head;
	Node* buf_r = r.head;
	if (r.get_size() > size)
	{
		size = r.get_size();
	}
	while (buf->next != head)
	{
		buf->data *= buf_r->data;
		buf = buf->next;
		buf_r = buf_r->next;
	}
	buf->data *= buf_r->data;
}

void List::operator/(const List& r)
{
	Node* buf = head;
	Node* buf_r = r.head;
	if (r.get_size() > size)
	{
		size = r.get_size();
	}
	while (buf->next != head)
	{
		buf->data /= buf_r->data;
		buf = buf->next;
		buf_r = buf_r->next;
	}
	buf->data /= buf_r->data;
}

std::ostream& operator<< (std::ostream& out, const List& obj)
{
	if (obj.size == 1)
	{
		Node* temp = obj.head;
		out << temp->data << endl;
		return out;
	}
	if (obj.size == 0)
	{
		out << "There's nothing to print" << endl;
		return out;
	}
	else
	{
		Node* temp = obj.head;
		while (temp)
		{
			out << temp->data << ", ";
			temp = temp->next;
			if (temp == obj.tail)
			{
				break;
			}
		}

		out << temp->data << endl;
		return out;
	}
}

std::istream& operator>> (std::istream& in, List& obj)
{
	Node* buf = obj.head;
	for (int i = 0; i < obj.get_size(); i++)
	{
		in >> buf->data;
		buf = buf->next;
	}
	return in;
}