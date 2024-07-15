#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <exception>

template <typename ANY>
class Stack {
private:
	ANY* first;      // ��������� �� ����� ������
	ANY* last;       // ��������� �� ��������� �������
	size_t size;     // ������ �����
	size_t elements; // ������� ��������� � ����� ���� �� ������ ������ ������� ��� ���������
public:
	Stack(size_t size);  // �������� �� ������ �����	//�����������
	~Stack();// ����������
	void put(ANY value); // ��������� ����� ��������
	ANY get();           // ����� ���� � ���������� �������
	ANY look();
	bool isEmpty();      // �������� ������ ���� ��� ���
	void clear();        // ���������� �������
	bool isFull();       // �������� ����
	void upgrade();      //���������� �����
};


template<typename ANY>
Stack<ANY>::Stack(size_t size) {                 //����������
	if (size == 0)
		throw std::exception("null size error"); // �������� ������ ���� ���� 0 ������� 
	first = new ANY[size]{};                     // ���� ������ �� �������
	last = nullptr;                              // 0 ��������� � �����
	this->size = size;
	elements = 0;
}

template<typename ANY>
Stack<ANY>::~Stack() {                   // ���������� ��� ������������ ������������ ������
	delete[] first; 

}

template<typename ANY>
void Stack<ANY>::put(ANY value) {        // ����� ��� ���������� ��������� � ����
	if (isFull())
		throw std::exception("stack overflow");
	first[elements++] = value;              // ���� ���� �� ������
	last = &first[elements - 1];            // ������ ���������� �������� �� ������� �� ���������� 
	// last = &(first[elements++] = value); // ��� ���� �������
}



template<typename ANY>
ANY Stack<ANY>::get() {  // ��������� � ������� �� �������
	if (isEmpty())
		throw std::exception("stack is empty"); //���� ���� ������ �� ������
	
	--elements; //�������� ���. ���������
	return *(last--);
}


template<typename ANY>
ANY Stack<ANY>::look() {               // ��������� � ������ 
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
void Stack<ANY>::clear() {               // ������� ����. ������ ����, � ��������� ���
	elements = 0;
}


#endif //_STACK_HPP_
