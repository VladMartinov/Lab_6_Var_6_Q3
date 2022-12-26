#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // sort
#include "book.h"
#include "bookSorter.h"
#include "bookFinder.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "RUSSIAN");
	
	// ������� ������ ��������� ������ Book
	std::vector<Book*> books;
	
	// ��������� ������ 
	books.push_back(new Book("����� � ���", "������� �.�.", 2010));
	books.push_back(new Book("���������", "����������� �.�.", 2004));
	books.push_back(new Book("�����", "�������� �.�.", 2010));
	books.push_back(new Book("���� ��������", "������� �.�.", 1999));
	books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
	books.push_back(new Book("���������� �������", "������� �.", 2009));
	books.push_back(new Book("������ �����", "������� �.", 2001));
	books.push_back(new Book("�����", "ø�� �.�.", 2010));
	books.push_back(new Book("����� ������", "������� �.", 1998));
	
	std::cout << "\n����� � ���������� �������:\n\n";
	
	// ������� (����� ���������������� () ) ��� ����������
	BookSorter book_sorter;

	// �������� ����� sort, ��������� ������ - ����� ������� � �������
	std::sort(books.begin(), books.end(), book_sorter);
	// ������� ��������
	std::vector<Book*>::iterator it;
	
	// ����������� �� ����� ������� � ������� ��������������� ��������� 
	for (it = books.begin(); it != books.end(); ++it)
	{
		std::cout << (*it)->getAuthor() << " \""
			<< (*it)->getName() << "\"" << std::endl;
	}

	// ������� ������� � �������� �������� ��� ���������
	BookFinder book_finder(2005, 2014);
	// ���� ������� book_finder ������ true, �� �� ������� ������ � ������
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\n����� ����������� � ��������� �������: 2005 < x < 2014:\n\n";
	// ����������� �� ����� ���������
	while (finder != books.end())
	{
	cout << (*finder)->getAuthor() << " \""
		<< (*finder)->getName() << "\"" << endl;
	finder = find_if(++finder, books.end(), book_finder);
	}

	// ������� ��������
	for (it = books.begin(); it != books.end(); ++it)
	{
		delete (*it);
	}
}