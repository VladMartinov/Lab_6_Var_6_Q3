#pragma once
#include "book.h"

// Функтор не имеющий параметров (просто переопределние оператора () )
// () принимает 2 экземпляра книги и производит сравнения.
class BookSorter {
public:

	bool operator()(Book* a, Book* b) {
		if (a->getAuthor() > b->getAuthor()) {
			return false;
		}
		else if (a->getAuthor() == b->getAuthor()) {
			if (a->getName() > b->getName())
				return false;
			else
				return true;
		}
		else return true;

	}
};