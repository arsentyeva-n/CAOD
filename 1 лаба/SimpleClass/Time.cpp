// @author: Natalya Arsentyeva
#include "Time.h" // Подключение класса

/// Реализация класса Время

/// Конструктор по умолчанию
Time::Time() {
	h = 0;
	m = 0;
	s = 0;
}

/// Конструктор с параметрами
Time::Time(int h1, int m1, int s1) {
	set_h(h1);
	set_m(m1);
	set_s(s1);
}

/// Задание часов
void Time::set_h(int h1) {
	if (h1 < 0 || h1 > 23) throw std::invalid_argument("Час введен некорректно");
	else h = h1;
}

/// Задание секунд
void Time::set_m(int m1) {
	if (m1 < 0 || m1 > 59) throw std::invalid_argument("Минуты введены некорректно");
	else m = m1;
}


/// Задание минут
void Time::set_s(int s1) {
	if (s1 < 0 || s1 > 59) throw std::invalid_argument("Секунды введены некорректно");
	else s = s1;
}

/// Вернуть часы
int Time::get_h() const { return h; }

/// Вернуть минуты
int Time::get_m() const { return m; }

/// Вернуть секунды
int Time::get_s() const { return s; }

/// Перевод значений в строку
std::string Time::to_str() const {
	// Множества чисел, от которых зависит написание окончания в словах: час, секунда, минута
	set<int> set1 = { 1, 21, 31, 41, 51 }; 
	set<int> set2 = { 2, 3, 4, 22, 23, 24, 32, 33, 34, 42, 43, 44, 52, 53, 54 };
	string str = ""; // Пустая строка

	/// Проверка для слова час
	if (set1.find(h) != set1.end()) { str = str + to_string(h) + " час "; }
	else if (set2.find(h) != set2.end()) { str = str + to_string(h) + " часа "; }
	else { str = str + to_string(h) + " часов "; }

	/// Проверка для слова минута
	if (set1.find(m) != set1.end()) { str = str + to_string(m) + " минута "; }
	else if (set2.find(m) != set2.end()) { str = str + to_string(m) + " минуты "; }
	else { str = str + to_string(m) + " минут "; }

	/// Проверка для слова секунда
	if (set1.find(s) != set1.end()) { str = str + to_string(s) + " секунда"; }
	else if (set2.find(s) != set2.end()) { str = str + to_string(s) + " секунды"; }
	else { str = str + to_string(s) + " секунд"; }

	return str; // Результат строки
};

/// Вывод в текстовый файл
void Time::output_txtfile(const string& filename, Time* a) const {
	ofstream f(filename);  // Создание и запись в файл
	f << "Время: ";
	f << a->to_str(); // Вызов метода преобразования значений полей в строку и вывод результата в текстовый файл
	f << endl; 	
	f.close();
};