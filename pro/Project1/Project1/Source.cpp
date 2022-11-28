#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool is_digits(const string& str) {
	return str.find_first_not_of("0123456789") == string::npos;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	ifstream fin;//������ ������ �� �����
	fin.open("vvod.txt");
	string input_str;
	while (!fin.eof()) fin >> input_str;
	fin.close();

	int input_str_length = input_str.length();

	if (input_str_length >= 3 && input_str_length <= 1000 && is_digits(input_str)) { //�������� �� �������
		ofstream fout("vyvod.txt");//�������� ����� ������
		string Astr = ""; string Bstr = ""; string Cstr = "";
		bool check = false; //��� ��������� �����

		int cycle = 0;

		while (cycle < input_str_length + 1 && !check) { //������� ������

			for (int j = 0; j < input_str_length - 2 && !check; j++) {
				Astr = ""; Bstr = ""; Cstr = "";


				list<char> A(1, input_str[0]);
				list<char> B(1, input_str[j + 1]);
				list<char> C;

				//���������� ������� ������
				for (int i = 1; i <= j; i++) {
					A.push_back(input_str[i]);
				}

				//���������� �������� ������ ����������� �������
				for (int i = j + 2; i < input_str_length; i++) {
					C.push_back(input_str[i]);
				}
				for_each(A.cbegin(), A.cend(), [&](char n) { Astr += n; }); // ���������� [&] ������ [] �.�. ��� ���������� ���������� � ������� ����������
				for_each(B.cbegin(), B.cend(), [&](char n) { Bstr += n; });
				for_each(C.cbegin(), C.cend(), [&](char n) { Cstr += n; });

				while (C.size() > 1 && !check) {
					Astr = ""; Bstr = ""; Cstr = "";
					B.push_back(C.front()); C.pop_front();

					for_each(A.cbegin(), A.cend(), [&](char n) { Astr += n; });
					for_each(B.cbegin(), B.cend(), [&](char n) { Bstr += n; });
					for_each(C.cbegin(), C.cend(), [&](char n) { Cstr += n; });

					//�������� �������
					if (atoi(Astr.c_str()) + atoi(Bstr.c_str()) == atoi(Cstr.c_str()) && Astr.front() != '0' && Bstr.front() != '0' && Cstr.front() != '0')
						check = true; //������������� �ukl
				}

				ofstream fout;//������� ����� � ����
				fout.open("vyvod.txt");
				fout << Astr << "+" << Bstr << "=" << Cstr;
				fout.close();

			}
			//�������� �������� ������ �� ������
			input_str += input_str[0];
			input_str.erase(0, 1);
			cycle++;
		}
		if (!check) {
			ofstream fout("vyvod.txt");//������� � ���� ������������� �����
			fout << "No";
			fout.close();
		}
	}
	else {
		ofstream fout("vyvod.txt");//������� � ���� ������������� �����
		fout << "No";
		fout.close();
	}
}





