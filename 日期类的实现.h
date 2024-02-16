#pragma once
#include<iostream>
using namespace std;
class Date

{

public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month)
	{
		int flag = 0;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			flag = 1;
		}
		int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		arr[2] += flag;
		return arr[month];
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 || month < 1 || month>12
			|| day>GetMonthDay(year,month)
			|| day<0)
		{
			cout << "非法日期" << endl;
			return;
		}
		_year = year;
		_month = month;
		_day = day;
	}


	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}


	// 析构函数

	~Date()
	{
		_year =-1;
		_month =-1;
		_day = -1;
	}



	// 日期+=天数

	Date& operator+=(int day)
	{
		int n = GetMonthDay(_year, _month);
		_day += day;
		while(_day > n)
		{
			_month += 1;
			_day= _day - n;
			if (_month == 13)
			{
				_month = 1;
				_year += 1;
			}
			n = GetMonthDay(_year, _month);
		}
		return *this;
	}



	// 日期+天数

	Date operator+(int day)
	{
		Date a(*this);
		a += day;//调用：日期+=天数
		return a;
	}


	// 日期-天数

	Date operator-(int day)
	{
		Date a(*this);
		a -= day;//调用：日期-=天数
		return a;
	}


	// 日期-=天数

	Date& operator-=(int day)
	{
		if(day<0)
		{
			return *this += -day;//调用日期+=天数
		}

		if (_day > day)
		{
			_day -= day;
			return *this;
		}
		int n = GetMonthDay(_year, _month);
		_day -= day;//已减去当前日期天数，即 |_day|代表距离上个月1号 差几天(没有距离0天)
		while (_day <= 0)
		{
			_month -= 1;
			//当前月天数 - | _day|,表示日期
			_day += n;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			n = GetMonthDay(_year, _month);
		}
		return *this;
	}


	//没有深拷贝，因此前置++和--没必要创建类
	// 前置++
	// ++d -> d.operator++(&d)
	Date& operator++()
	{
		*this += 1;//+=运算符重载
		//*this++;
		return *this;
	}



	// 后置++
	// d++ -> d.operator++(&d, 0)
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}


	// 后置--

	Date operator--(int)
	{
		Date ret(*this);
		*this-=1;
		return ret;
	}



	// 前置--

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}


	// d1 > d2
	// >运算符重载

	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return 1;
		if(_year == d._year && _month > d._month)
			return 1;
		if (_year == d._year && _month == d._month && _day>d._day)
			return 1;
		return 0;
	}



	// ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}


	// 下面复用上面两个的实现
	// >=运算符重载

	bool operator >= (const Date& d)
	{

		return operator>(d) || operator==(d);
	}


	// <运算符重载

	bool operator < (const Date& d)
	{
		if (operator >=(d))
			return 0;
		return 1;
	}



	// <=运算符重载

	bool operator <= (const Date& d)
	{
		if (_year > d._year)
			return 0;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return 0;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return 0;
			}
		}
		return true;
	}


	// !=运算符重载

	bool operator != (const Date& d)
	{
		return _year != d._year
			|| _month != d._month
			|| _day != d._day;
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max(*this);
		Date min(d);
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int day = 0;
		while (min < max)
		{
			++min;
			day++;
		}
		//if (flag != 1)
		//	day = -day;
		return day*flag;
	}



private:

	int _year;

	int _month;

	int _day;

};
