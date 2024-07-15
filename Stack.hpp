#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <exception>

template <typename ANY>
class Stack {
private:
	ANY* first;      // указатель на динам массив
	ANY* last;       // указатель на последний элемент
	size_t size;     // размер стека
	size_t elements; // сколько элементов в стеке есть на данный момент текущее кол элементов
public:
	Stack(size_t size);  // отвечает за размер стека	//конструктор
	~Stack();// диструктор
	void put(ANY value); // принимает любое значение
	ANY get();           // метод дает и возвращает элемент
	ANY look();
	bool isEmpty();      // проверка стакан пуст или нет
	void clear();        // реализация пустоты
	bool isFull();       // заполнен стек
	void upgrade();      //увеличение стека
};


template<typename ANY>
Stack<ANY>::Stack(size_t size) {                 //реализация
	if (size == 0)
		throw std::exception("null size error"); // вызываем ошибку если стек 0 размера 
	first = new ANY[size]{};                     // если размер не нулевой
	last = nullptr;                              // 0 элементов в стеке
	this->size = size;
	elements = 0;
}

template<typename ANY>
Stack<ANY>::~Stack() {                   // диструктор для освобождения динамической памяти
	delete[] first; 

}

template<typename ANY>
void Stack<ANY>::put(ANY value) {        // метод для добавления элементов в стек
	if (isFull())
		throw std::exception("stack overflow");
	first[elements++] = value;              // если стек не полный
	last = &first[elements - 1];            // индекс помледнего элемента на который мы направляем 
	// last = &(first[elements++] = value); // или этот вариант
}



template<typename ANY>
ANY Stack<ANY>::get() {  // посмтреть и удалить из стакана
	if (isEmpty())
		throw std::exception("stack is empty"); //если стке пустой то ошибка
	
	--elements; //уменьшим кол. элементов
	return *(last--);
}


template<typename ANY>
ANY Stack<ANY>::look() {               // посмтреть в стакан 
	if (isEmpty())
		throw std::exception("stack is empty");
	return *last;
}


template<typename ANY>
bool Stack<ANY>::isEmpty() {
	return elements == 0;
}


template<typename ANY>
bool Stack<ANY>::isFull() {
	return elements == size;
}

template<typename ANY>
void Stack<ANY>::clear() {               // очищает стек. стакан есть, а элементов нет
	elements = 0;
}


#endif //_STACK_HPP_
