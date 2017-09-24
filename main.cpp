#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <cassert>

using namespace std;
template <typename T>
class Stack
{
private:
	T* array_; // массив который будем забивать ,array_-указатель на массив,который лежит в куче
	size_t count_; // номер элемента, добавляемый в кучу
	size_t array_size_; // размер стека

public:
	Stack(size_t s) : array_size_(s)
	{
		array_ = new T[array_size_]; // массив array_ размером array_size_, который будем забивать
		count_ = 0; 
	}


	// функция, показывающая существующие значения в объекте
	void showMe(size_t i)
	{
		cout << array_[i];
	}

	// функция, добавляющая значения в стек, и проверяющая номер элемента с вершиной стека на переполнение стека(push -добавляем наверх)
	void push(T const &d)
	{
		if (count_ == array_size_)
			StackDuplication();
		*(array_ + count_) = d;
		count_++;
	}
	// функция, убирающая значение из стека, и проверяющая номер элемента с вершиной стека на пустоту стека (pop-убираем сверху)
	void pop()
	{
		count_--;
		assert(count_ != -1);
		*(array_ + count_ ) = NULL;
	}
	// Данная функция вызывается при переполнении стека. В ней происходит переразпределение памяти
	void StackDuplication() // Данная функция вызывается при переполнении стека. В ней происходит переразпределение памяти
	{
		T* array_2 = new T[array_size_ * 2]; // Определеям указатель array_2 на новый массив с уввеличенным размером 
		for (int i = 0; i < array_size_; i++)// Переносим в новый массив элементы из старого
		{
			*(array_2 + i) = *(array_ + i);
		}
		array_size_ = array_size_ * 2;
		delete[] array_;// освобождаем память
		array_ = array_2;//переопределяем указатель
	}
};



void main()
{
	Stack<int> Ob(3);
	Ob.push(1);
	Ob.push(2);
	Ob.push(3);
	Ob.push(4);
	for (int i = 0; i < 4; i++)
	{
		Ob.showMe(i);// заполняем наш стек и выодим его содержимое на экран
	}
	cout <<   endl;
	Ob.pop(); // убираем верхний элемент из стека
	for (int i = 0; i < 4; i++)
	{
		Ob.showMe(i);
	}
	cout << endl;
	Ob.pop();
	Ob.pop();
	Ob.pop();
	cout << "Now Stack is empty." << endl;
	//Ob.pop(); // Вызываем аварийную остановку программы, выходя за границы стека
	system("pause");
}
