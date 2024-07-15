#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_


template <typename ANY, size_t max_size>
class Queue {
private:
	ANY data[max_size];
	size_t size;   // текущий размер очереди
public:
	Queue() :size(0) {}    // констр по умолчанию
	void put(ANY value);
	ANY get();
	ANY look();
	bool isEmpty();
	bool isFull();
	void clear();
};


template<typename ANY, size_t max_size>
 void Queue<ANY, max_size>::put(ANY value){
	 if (isFull())
		 throw std::exception("queue overflow");
	 data[size++] = value;        // добавили элемент
}

template<typename ANY, size_t max_size>
 ANY Queue<ANY, max_size>::get() {     // получение и удаление
	 if (isEmpty())
		 throw std::exception("queue is empty");
	 ANY tmp = data[0];                // временное хранилище первого элемента
	 for (size_t i = 1; i < size; ++i)
		 data[i - 1] = data[i];        // из текущего элемента все переходит в другую очередь
	 --size;
	return tmp;
}

template<typename ANY, size_t max_size>
 ANY Queue<ANY, max_size>::look(){
	 if (isEmpty())
		 throw std::exception("queue is empty");// очередь пустая
	return data[0];
}

template<typename ANY, size_t max_size>
 bool Queue<ANY, max_size>::isEmpty() {
	 return size == 0;
}

template<typename ANY, size_t max_size>
 bool Queue<ANY, max_size>::isFull(){
	 return size == max_size;                  // очередь заполнена
}

template<typename ANY, size_t max_size>
 void Queue<ANY, max_size>::clear(){
	 size = 0;
}



#endif // _QUEUE_HPP_