// @author: Natalya Arsentyeva
#include "Time.h" // ����������� ������

/// ���������� ������ �����

/// ����������� �� ���������
Time::Time() {
	h = 0;
	m = 0;
	s = 0;
}

/// ����������� � �����������
Time::Time(int h1, int m1, int s1) {
	set_h(h1);
	set_m(m1);
	set_s(s1);
}

/// ������� �����
void Time::set_h(int h1) {
	if (h1 < 0 || h1 > 23) throw std::invalid_argument("��� ������ �����������");
	else h = h1;
}

/// ������� ������
void Time::set_m(int m1) {
	if (m1 < 0 || m1 > 59) throw std::invalid_argument("������ ������� �����������");
	else m = m1;
}


/// ������� �����
void Time::set_s(int s1) {
	if (s1 < 0 || s1 > 59) throw std::invalid_argument("������� ������� �����������");
	else s = s1;
}

/// ������� ����
int Time::get_h() const { return h; }

/// ������� ������
int Time::get_m() const { return m; }

/// ������� �������
int Time::get_s() const { return s; }

/// ������� �������� � ������
std::string Time::to_str() const {
	// ��������� �����, �� ������� ������� ��������� ��������� � ������: ���, �������, ������
	set<int> set1 = { 1, 21, 31, 41, 51 }; 
	set<int> set2 = { 2, 3, 4, 22, 23, 24, 32, 33, 34, 42, 43, 44, 52, 53, 54 };
	string str = ""; // ������ ������

	/// �������� ��� ����� ���
	if (set1.find(h) != set1.end()) { str = str + to_string(h) + " ��� "; }
	else if (set2.find(h) != set2.end()) { str = str + to_string(h) + " ���� "; }
	else { str = str + to_string(h) + " ����� "; }

	/// �������� ��� ����� ������
	if (set1.find(m) != set1.end()) { str = str + to_string(m) + " ������ "; }
	else if (set2.find(m) != set2.end()) { str = str + to_string(m) + " ������ "; }
	else { str = str + to_string(m) + " ����� "; }

	/// �������� ��� ����� �������
	if (set1.find(s) != set1.end()) { str = str + to_string(s) + " �������"; }
	else if (set2.find(s) != set2.end()) { str = str + to_string(s) + " �������"; }
	else { str = str + to_string(s) + " ������"; }

	return str; // ��������� ������
};

/// ����� � ��������� ����
void Time::output_txtfile(const string& filename, Time* a) const {
	ofstream f(filename);  // �������� � ������ � ����
	f << "�����: ";
	f << a->to_str(); // ����� ������ �������������� �������� ����� � ������ � ����� ���������� � ��������� ����
	f << endl; 	
	f.close();
};