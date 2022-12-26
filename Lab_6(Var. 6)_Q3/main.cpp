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
	
	// Создаем вектор элементов класса Book
	std::vector<Book*> books;
	
	// Заполняем вектор 
	books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
	books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));
	
	std::cout << "\nКниги в алфавитном порядке:\n\n";
	
	// Функтор (класс переопределяющий () ) для сортировки
	BookSorter book_sorter;

	// Вызываем метод sort, указываем начало - конец вектора и функтор
	std::sort(books.begin(), books.end(), book_sorter);
	// Создаем итератор
	std::vector<Book*>::iterator it;
	
	// Пробегаемся по всему вектору и выводим отсортированный результат 
	for (it = books.begin(); it != books.end(); ++it)
	{
		std::cout << (*it)->getAuthor() << " \""
			<< (*it)->getName() << "\"" << std::endl;
	}

	// Создаем функтор и передаем значения для диапозона
	BookFinder book_finder(2005, 2014);
	// если функтор book_finder вернет true, то мы заносим данные в вектор
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\nКниги находящиеся в диапозоне издания: 2005 < x < 2014:\n\n";
	// Пробегаемся по всему итератору
	while (finder != books.end())
	{
	cout << (*finder)->getAuthor() << " \""
		<< (*finder)->getName() << "\"" << endl;
	finder = find_if(++finder, books.end(), book_finder);
	}

	// Очищаем итератор
	for (it = books.begin(); it != books.end(); ++it)
	{
		delete (*it);
	}
}