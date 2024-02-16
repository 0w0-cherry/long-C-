#define _CRT_SECURE_NO_WARNINGS 1
#include"日期类.h"



int main()
{
	Date d1(2024,1,28);
	Date d2(2024, 2, 27);
	Date d3(d1);
	d3 = d2;
	Date d4;
	d4 +=365;
	//Date d5= (d4 + 5);//意义在于建立一个新的日期
	Date d5 = d4 - 5;
	d5 -= 5;
	d5++;
	d5--;
	++d5;
	--d5;
	cout << (d4 > d5) << endl;
	cout << (d4 >= d5) << endl;
	cout << (d4 == d5) << endl;
	cout << (d4 < d5) << endl;
	cout << (d4 <= d5) << endl;
	cout << (d4 != d5) << endl;
	cout << (d4 - d5) << endl;

	//d1.Print();
	//d2.Print();
	//d3.Print();
	d4.Print();
	d5.Print();
	return 0;
}
