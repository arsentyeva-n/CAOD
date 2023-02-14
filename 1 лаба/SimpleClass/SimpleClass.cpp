// @author: Natalya Arsentyeva

#include "Time.h" // Подключение класса 


int main()
{
	setlocale(LC_ALL, "ru"); // Подключение русского языка

	/// protected code
	try
	{	const string filename = "time"; // Название текстового файла
		
		// Создание 1 объекта
		Time *object1 = new Time(); 
		// Задание значений
		object1->set_h(21);
		object1->set_m(59);
		object1->set_s(33);
		// Вывод в консоль значений этого объекта
		cout << object1->to_str() << endl;
		object1->output_txtfile(filename, object1);
		delete object1; // Очистка памяти

		// Создание 2 объекта
		Time* object2 = new Time();
		object2->set_h(12);
		object2->set_m(43);
		object2->set_s(21);
		cout << object2->to_str() << endl;
		delete object2;

		// Создание 3 объекта
		Time* object3 = new Time();
		object3->set_h(0);
		object3->set_m(0);
		object3->set_s(0);
		cout << object3->to_str() << endl;
		delete object3;
	}
	catch (std::invalid_argument &e) // Ловит исключения и выводит их на экран
	{
		std::cout << e.what();
	}
}