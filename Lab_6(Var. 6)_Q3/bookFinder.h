#pragma once
#include "book.h"

// Функтор имеющий конструктор принимающий значения диапозона
// Переопределяет () и возварщает булевое значение после сравнений
class BookFinder {
public:

	BookFinder(int yearGreater, int yearSmaller) { _yearGreater = yearGreater; _yearSmaller = yearSmaller; }

	bool operator()(Book* a) {
		if (a->getYear() > 2005) {
			if (a->getYear() < 2014)
				return true;
			else
				return false;
		}
		else
			return false;
	}

private:
	int _yearGreater;
	int _yearSmaller;
};