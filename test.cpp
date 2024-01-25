#include<iostream>
using namespace std;

//class Stack
//{
//public:
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		_capacity = n;
//		_size = 0;
//	}
//
//	/*~Stack()
//	{
//		free(_a);
//		_size = _capacity = 0;
//		_a = nullptr;
//	}*/
//
//private :
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//
//	Stack st1(30);
//	
//	Stack st2(st1);
//
//	Stack st3(10);
//
//	st1 = st2;
//
//	return 0;
//}
//

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return MonthDay[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else cout << "ÈÕÆÚ´íÎó" << endl;
	}

	bool operator>(Date d)
	{
		if (_year > d._year) return true;
		if (_year == d._year && _month > d._month) return true;
		if (_year == d._year && _month == d._month && _day > d._day) return true;
		else return false;
	}

	bool operator==(Date d)
	{
		if (_year == d._year
			&& _month == d._month
			&& _day == d._day)
			return true;
		else return false;
	}

	bool operator!=(Date d)
	{
		return !(*this == d);
	}

	bool operator>=(Date d)
	{
		return *this > d || *this == d;
	}

	bool operator<(Date d)
	{
		return !(*this >= d);
	} 

	bool operator<=(Date d)
	{
		return !(*this > d);
	}

	Date& operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
	}

	Date operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month == 1;
			}
		}
	}

	Date& operator-(int day)
	{
		Date ret(*this);
		ret._day -= day;
		while (ret._day <= 0)
		{
			ret._day += GetMonthDay(ret._year, ret._month);
			ret._month--;
			if (ret._month <= 0)
			{
				ret._month = 12;
				ret._year--;
			}
		}
	}
private:
	int _year;
	int _month;
	int _day;
};