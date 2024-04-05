#include <iostream>
#include <string>

using namespace std;

struct bad_length
{
	int forbidden_length;
	bad_length(int length) :forbidden_length(length) {}

};

int function(std::string str, int forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		throw bad_length(forbidden_length);
	}

	return str.length();
}


int main()
{
	int forbidden_length;

	cout << "Введите запретную длину строки: ";
	cin >> forbidden_length;

	string str;
	while (true)
	{
		cout << "Введите слово: ";
		cin >> str;

		try
		{
			int length = function(str, forbidden_length);
			cout << "Длина слова " << '"' << str << '"' << " равна " << length << endl;

		}
		catch (bad_length& bl)
		{
			cout << "Вы ввели слово с запретной длины! До свидания ";
			return 0;
		}
	}
	return 0;
}

