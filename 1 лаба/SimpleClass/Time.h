// @author: Natalya Arsentyeva
#pragma once			// ������ �� ���������� �����������
#include <iostream>		// ����������� ����������
#include <stdexcept>	// ����������� ���������� ��� ������ ����������
#include <string>		// ����������� �����
#include <fstream>		// ���������� ��� ������
#include <set>			// ����������� �������� 
using namespace std;

/// ����� �����
class Time
{
	// �������� ���� �����, �����, ������
private: 
	int h, m, s;
	// ������
public:
	Time(); // ����������� �� ���������
	Time(int h1, int m1,  int s1); // ����������� � �����������


	/// ������� ����������� �������� �����
	void set_h(int h1);
	void set_m(int m1);
	void set_s(int s1);

	/// ������� ����������� �������� �����
	int get_h() const;
	int get_m() const;
	int get_s() const;

	/// ������� �������� � ������
	std::string to_str() const;

	/// ����� � ��������� ����
	void output_txtfile(const string& filename, Time* a) const;
};