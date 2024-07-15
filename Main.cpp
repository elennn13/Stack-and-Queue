#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	
	//  СТЕК
	/*
	Stack<int> stack(3);

	std::cout << stack.isEmpty() << std::endl;
	stack.put(7);
	stack.put(50);
	stack.put(150);
	std::cout << stack.isEmpty() << std::endl;
	std::cout << stack.get()     << std::endl;
	std::cout << stack.isEmpty() << std::endl;

	if (!stack.isEmpty())
	std::cout << stack.get() << std::endl;
*/
	// ОЧЕРЕДЬ

	Queue<int, 3> queue;
	queue.put(10);
	queue.put(20);
	std::cout << queue.get() << std::endl; // 10
	queue.put(30);
	std::cout << queue.get() << std::endl; // 20
	queue.clear();
	std::cout << queue.isEmpty() << std::endl;



	return 0;
}