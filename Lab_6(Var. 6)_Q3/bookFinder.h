#pragma once
#include "book.h"

// ������� ������� ����������� ����������� �������� ���������
// �������������� () � ���������� ������� �������� ����� ���������
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