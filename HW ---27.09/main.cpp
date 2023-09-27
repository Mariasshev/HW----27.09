#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
	void InsertElement(char data, int p);
	void DelByPosition(int p);
	int FindfEl(char ch);
};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::InsertElement(char data, int p)
{
	if (Head == NULL || p == 1 || p == GetCount()) {
		Add(data);
	}
	else {
		Element* temp = Head;
		while (p - 1 > 0) {
			temp = temp->Next;		
			p--;
		}
		Element* ins = new Element;
		ins->data = data;
		ins->Next = temp->Next;
		temp->Next = ins;

	}
}

void List::DelByPosition(int p)
{
	if (Head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		Element* temp = Head;
		while (p - 1 > 0) {
			temp = temp->Next;
			p--;
		}
		Element* del = temp->Next;
		temp->Next = del->Next;
		delete del;
	}

}

int List::FindfEl(char ch)
{
	if (Head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		Element* temp = Head;
		int count = 0;
		while (temp != 0)
		{
			if (temp->data == ch) {
				return count + 1;
			}
			count++;
			temp = temp->Next;
		}
	}
	return NULL;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

void main()
{
	List lst;
	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";			// Выводим строку
	int len = strlen(s);			// Определяем длину строки
	for (int i = 0; i < len; i++)	// Загоняем строку в список
		lst.Add(s[i]);

	//Распечатываем содержимое списка
	lst.Print();
	lst.InsertElement('W', 2);
	lst.Print();
	lst.DelByPosition(2);
	lst.Print();
	//return position, not index!!
	cout << lst.FindfEl('H');
}

