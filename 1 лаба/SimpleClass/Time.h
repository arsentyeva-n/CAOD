// @author: Natalya Arsentyeva
#pragma once			// Защита от повторного подключения
#include <iostream>		// Стандартная библиотека
#include <stdexcept>	// Подключение библиотеки для вызова исключения
#include <string>		// Подключение строк
#include <fstream>		// Библиотека для файлов
#include <set>			// Подключение множеств 
using namespace std;

/// Класс Время
class Time
{
	// Закрытые поля часов, минут, секунд
private: 
	int h, m, s;
	// Методы
public:
	Time(); // Конструктор по умолчанию
	Time(int h1, int m1,  int s1); // Конструктор с параметрами


	/// Сеттеры принимающие значения полей
	void set_h(int h1);
	void set_m(int m1);
	void set_s(int s1);

	/// Геттеры возращающие значения полей
	int get_h() const;
	int get_m() const;
	int get_s() const;

	/// Перевод значений в строку
	std::string to_str() const;

	/// Вывод в текстовый файл
	void output_txtfile(const string& filename, Time* a) const;
};