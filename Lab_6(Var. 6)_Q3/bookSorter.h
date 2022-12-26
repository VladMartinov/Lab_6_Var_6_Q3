#pragma once
#include "book.h"

// ������� �� ������� ���������� (������ �������������� ��������� () )
// () ��������� 2 ���������� ����� � ���������� ���������.
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