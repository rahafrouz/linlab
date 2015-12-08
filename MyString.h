#include <iostream>
#include <conio.h>

using namespace std;

class MyString
{
public:
	MyString();
	MyString(char*);
	~MyString();
	long Length();
	int find(char*);
	bool IsSubstr(char*);
	void Substr(int, int);//probable errors
	MyString ToLower();//has been modified ... 
	MyString ToUper();
	MyString Add(char);
	MyString operator +(MyString);
	MyString operator =(MyString);
	MyString operator +=(char);
	MyString operator +=(char*);
	char operator [] (int);//probable errors
	bool operator < (MyString);
	bool operator > (MyString);
	bool operator >= (MyString);
	bool operator <= (MyString);
	bool operator == (MyString);
	bool operator != (MyString);
	friend ostream & operator << (ostream&, MyString);
	friend istream & operator >> (istream&, MyString&);

private:
	char* txt;

};

MyString::MyString()
{
	txt = "";
}

MyString::MyString(char* txt)
{
	//int i = 0;
	this->txt = new char;
	/*while (txt[i] != '\0')
	{
	i++;
	}
	this->txt = new char[i];*/
	this->txt = txt;
}

MyString::~MyString()
{
	txt = NULL;
}

long MyString::Length()
{
	int i = 0;
	while (txt[i] != '\0')
	{
		i++;
	}
	return i;
}

int MyString::find(char* sub)
{
	int txtlen = Length();
	int sublen = 0;

	while (sub[sublen] != '\0')
	{
		sublen++;
	}

	int i = 0, j = 0, index = 0;

	while (i < txtlen && j < sublen)
	{
		if (txt[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			index++;
			i = index;
		}
	}

	if (j == sublen)
	{
		return index + 1;
	}
	else
	{
		cout << "\n Not Found ! \n ";
		return -1;
	}
}

bool MyString::IsSubstr(char* sub)
{
	int txtlen = Length();
	int sublen = 0;

	while (sub[sublen] != '\0')
	{
		sublen++;
	}

	int i = 0, j = 0, index = 0;

	while (i < txtlen && j < sublen)
	{
		if (txt[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			index++;
			i = index;
		}
	}

	if (j == sublen)
	{
		cout << "\n Yes ' " << sub << " ' is a sub string of the main string ' " << txt << " ' " << endl;
		return true;
	}
	else
	{
		cout << "\n Oops ' " << sub << " ' is not a sub string of the main string ' " << txt << " ' " << endl;
		return false;
	}
}

void MyString::Substr(int a, int b)
{
	int len = Length();
	a--;
	if (a >= 0 && b >= 0 && a < len && b < len)
	{
		for (int i = a; i < b; i++)
		{
			cout << txt[i];
		}
	}
	cout << endl;
	return;
}

MyString MyString::ToLower()
{
	MyString copy;
	char ch;
	copy.txt = new char;
	for (int i = 0; i <= Length(); i++)
	{
		int ascii = 0;
		ascii = (int)txt[i];

		if (ascii >= 65 && ascii <= 90)
		{
			ascii += 32;
			ch = (char)ascii;
			copy.txt[i] = ch;
		}
		else
		{
			ch = (char)ascii;
			copy.txt[i] = ch;
		}
	}
	txt = copy.txt;
	return txt;
}

MyString MyString::ToUper()
{
	MyString copy;
	char ch;
	copy.txt = new char;
	for (int i = 0; i <= Length(); i++)
	{
		int ascii = 0;
		ascii = (int)txt[i];

		if (ascii >= 97 && ascii <= 122)
		{
			ascii -= 32;
			ch = (char)ascii;
			copy.txt[i] = ch;
		}
		else
		{
			ch = (char)ascii;
			copy.txt[i] = ch;
		}
	}
	txt = copy.txt;
	return txt;
}

MyString MyString::Add(char c)
{
	MyString copy;
	copy.txt = new char;
	copy.txt = txt;
	int len = Length();
	//len++;
	copy.txt[len] = c;
	copy.txt[++len] = NULL;
	txt = copy.txt;
	return txt;
}

MyString MyString::operator +(MyString sub)
{
	MyString copy;
	copy.txt = new char;
	int len = Length();
	int sublen = 0;

	while (sub[sublen] != '\0')
	{
		sublen++;
	}

	for (int i = 0; i < len; i++)
	{
		//len++;
		copy.txt[i] = txt[i];
	}
	for (int i = 0; i < sublen; i++)
	{
		copy.txt[len] = sub[i];
		len++;
	}
	txt = copy.txt;
	return txt;
}

MyString MyString::operator=(MyString str)
{
	int txtlen = Length();
	int strlen = 0;

	while (str[strlen] != '\0')
	{
		strlen++;
	}

	if (strlen <= txtlen)
	{
		int i;
		for (i = 0; i < strlen; i++)
		{
			txt[i] = str[i];
		}
		txt[i] = '\0';
		cout << " \n\t Equalization successful ! \n " << endl;
	}
	else
	{
		cout << "\a\n\t An error has been occured in equalization ! \n";
	}
	return txt;
}

MyString MyString::operator +=(char c)
{
	MyString copy;
	copy.txt = new char;
	copy.txt = txt;
	int len = Length();
	//len++;
	copy.txt[len] = c;
	copy.txt[++len] = NULL;
	txt = copy.txt;
	return txt;
}

MyString MyString::operator += (char* sub)
{
	MyString copy;
	copy.txt = new char;
	int len = Length();
	int sublen = 0;

	while (sub[sublen] != '\0')
	{
		sublen++;
	}

	for (int i = 0; txt[i] != '\0'; i++)
	{
		//len++;
		copy.txt[i] = txt[i];
	}
	for (int i = 0; sub[i] != '\0'; i++)
	{
		copy.txt[len] = sub[i];
		len++;
	}
	copy.txt[len] = NULL;
	txt = copy.txt;
	return txt;
}

char MyString::operator[](int a)
{
	int len = Length();

	if (a < len && a >= 0)
	{
		char word = txt[a];
		return word;
	}
	return false;
}

bool MyString::operator < (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen > strlen)
	{
		cout << "\n second sentence " << " < " << " first sentence \n" << endl;
		cout << " \n\t and it is : " << string.txt << "\n" << endl;
		return false;
	}
	else if (txtlen < strlen)
	{
		cout << "\n first sentence " << " < " << " second sentence \n" << endl;
		cout << " \n\t and it is : " << txt << "\n" << endl;
		return true;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen == strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 > sum2)
		{
			cout << "\n second sentence " << " < " << " first sentence \n" << endl;
			cout << " \n\t and it is : " << string.txt << "\n" << endl;
			return false;
		}
		else if (sum2 > sum1)
		{
			cout << "\n first sentence " << " < " << " second sentence \n" << endl;
			cout << " \n\t and it is : " << txt << "\n" << endl;
			return true;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 == sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] >(int) string.txt[i])
				{
					cout << "\n second sentence " << " < " << " first sentence \n" << endl;
					cout << " \n\t and it is : " << string.txt << "\n" << endl;
					return false;
				}
				else if ((int)string.txt[i] > (int)txt[i])
				{
					cout << "\n first sentence " << " < " << " second sentence \n" << endl;
					cout << " \n\t and it is : " << txt << "\n" << endl;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool MyString::operator > (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen > strlen)
	{
		cout << "\n first sentence " << " > " << " second sentence \n" << endl;
		cout << " \n\t and it is : " << txt << "\n" << endl;
		return true;
	}
	else if (txtlen < strlen)
	{
		cout << "\n second sentence " << " > " << " first sentence \n" << endl;
		cout << " \n\t and it is : " << string.txt << "\n" << endl;
		return false;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen == strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 > sum2)
		{
			cout << "\n first sentence " << " > " << " second sentence \n" << endl;
			cout << " \n\t and it is : " << txt << "\n" << endl;
			return true;
		}
		else if (sum2 > sum1)
		{
			cout << "\n second sentence " << " > " << " first sentence \n" << endl;
			cout << " \n\t and it is : " << string.txt << "\n" << endl;
			return false;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 == sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] >(int) string.txt[i])
				{
					cout << "\n first sentence " << " > " << " second sentence \n" << endl;
					cout << " \n\t and it is : " << txt << "\n" << endl;
					return true;
				}
				else if ((int)string.txt[i] > (int)txt[i])
				{
					cout << "\n second sentence " << " > " << " first sentence \n" << endl;
					cout << " \n\t and it is : " << string.txt << "\n" << endl;
					return false;
				}
			}
		}
		return false;
	}
	return false;
}

bool MyString::operator >= (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen >= strlen)
	{
		cout << "\n first sentence " << " >= " << " second sentence \n" << endl;
		cout << " \n\t and it is : " << txt << "\n" << endl;
		return true;
	}
	else if (txtlen <= strlen)
	{
		cout << "\n second sentence " << " >= " << " first sentence \n" << endl;
		cout << " \n\t and it is : " << string.txt << "\n" << endl;
		return false;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen == strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 >= sum2)
		{
			cout << "\n first sentence " << " >= " << " second sentence \n" << endl;
			cout << " \n\t and it is : " << txt << "\n" << endl;
			return true;
		}
		else if (sum2 >= sum1)
		{
			cout << "\n second sentence " << " >= " << " first sentence \n" << endl;
			cout << " \n\t and it is : " << string.txt << "\n" << endl;
			return false;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 == sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] >= (int)string.txt[i])
				{
					cout << "\n first sentence " << " >= " << " second sentence \n" << endl;
					cout << " \n\t and it is : " << txt << "\n" << endl;
					return true;
				}
				else if ((int)string.txt[i] >= (int)txt[i])
				{
					cout << "\n second sentence " << " >= " << " first sentence \n" << endl;
					cout << " \n\t and it is : " << string.txt << "\n" << endl;
					return false;
				}
			}
		}
		return false;
	}
	return false;
}

bool MyString::operator <= (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen >= strlen)
	{
		cout << "\n second sentence " << " <= " << " first sentence \n" << endl;
		cout << " \n\t and it is : " << string.txt << "\n" << endl;
		return false;
	}
	else if (txtlen <= strlen)
	{
		cout << "\n first sentence " << " <= " << " second sentence \n" << endl;
		cout << " \n\t and it is : " << txt << "\n" << endl;
		return true;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen == strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 >= sum2)
		{
			cout << "\n second sentence " << " <= " << " first sentence \n" << endl;
			cout << " \n\t and it is : " << string.txt << "\n" << endl;
			return false;
		}
		else if (sum2 >= sum1)
		{
			cout << "\n first sentence " << " <= " << " second sentence \n" << endl;
			cout << " \n\t and it is : " << txt << "\n" << endl;
			return true;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 == sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] >= (int)string.txt[i])
				{
					cout << "\n second sentence " << " <= " << " first sentence \n" << endl;
					cout << " \n\t and it is : " << string.txt << "\n" << endl;
					return false;
				}
				else if ((int)string.txt[i] >= (int)txt[i])
				{
					cout << "\n first sentence " << " <= " << " second sentence \n" << endl;
					cout << " \n\t and it is : " << txt << "\n" << endl;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool MyString::operator == (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen == strlen)
	{
		cout << "\n second sentence " << " = " << " first sentence \n" << endl;
		cout << " \n\t and they are : " << txt << endl;
		return true;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen != strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 == sum2)
		{
			cout << "\n second sentence " << " = " << " first sentence \n" << endl;
			cout << " \n\t and they are : " << txt << endl;
			return true;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 != sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] == (int)string.txt[i])
				{
					cout << "\n second sentence " << " = " << " first sentence \n" << endl;
					cout << " \n\t and they are : " << txt << endl;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool MyString::operator != (MyString string)
{
	int txtlen = Length();
	int strlen = 0;

	while (string[strlen] != '\0')
	{
		strlen++;
	}

	// Part1 : comparing with length .

	if (txtlen != strlen)
	{
		cout << "\n second sentence " << " != " << " first sentence \n" << endl;
		cout << " \n\t and they are : " << string.txt << "\n\t and ;" << txt << endl;
		return true;
	}

	// Part 2 : comparing with ASCII codes . 

	else if (txtlen == strlen)
	{
		int i = 0, sum1 = 0, sum2 = 0, j = 0;
		while (i <= txtlen)
		{
			sum1 += (int)txt[i];
			i++;
		}
		while (j <= strlen)
		{
			sum2 += (int)string.txt[j];
			j++;
		}
		if (sum1 != sum2)
		{
			cout << "\n second sentence " << " != " << " first sentence \n" << endl;
			cout << " \n\t and they are : " << string.txt << "\n\t and ;" << txt << endl;
			return true;
		}

		// Part 3 : comparing with ASCII codes of characters in same places .

		else if (sum1 == sum2)
		{
			for (int i = 0; i < txtlen; i++)
			{
				if ((int)txt[i] != (int)string.txt[i])
				{
					cout << "\n second sentence " << " != " << " first sentence \n" << endl;
					cout << " \n\t and they are : " << string.txt << "\n\t and ;" << txt << endl;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

ostream & operator << (ostream& output, MyString str)
{
	int len = str.Length();
	for (int i = 0; i < len; i++)
	{
		output << str[i];
	}
	cout << endl;
	return output;
}

/*istream & operator >> (istream& input, MyString& str)
{
	int len, i;
	cout << " \n Please enter the length of your string " << endl;
	cin >> len;
	str.txt = new char;// [len];
	for (i = 0; str.txt[i] = '.'; i++)
	{
		cin.get(str.txt[i]);
	}
	str.txt[i] = NULL;
	return input;
}*/