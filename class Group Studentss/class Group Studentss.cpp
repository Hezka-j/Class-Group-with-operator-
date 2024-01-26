#include <iostream>
#include <ctime>
using namespace std;

#include "Date.h"
#include "Student.h"
#include "Group.h"
int operator - (Date& right,Date& left)
{
	bool ok = false;
	int result_day;
	int result_month;
	int result_year;
	if (right.GetDay() >= left.GetDay() && right.GetMonth() >= left.GetMonth() && right.GetYear() >= left.GetYear())
	{
		result_day = right.GetDay() - left.GetDay();
		result_month = right.GetMonth() - left.GetMonth();
		result_year = right.GetYear() - left.GetYear();
	}
	else
	{
		result_day = left.GetDay() - right.GetDay();
		result_month = left.GetMonth() - right.GetMonth();
		result_year = left.GetYear() - right.GetYear();
	}
	if (left.GetYear() > right.GetYear() || left.GetYear() < right.GetYear())
	{		
		for (int i = 0; i < result_year; i++)
		{
			if (left.GetYear() > right.GetYear())
			{
				if (right.GetYear() + i / 400 == 0 && right.GetYear() + i / 100 == 0)
				{
					result_day += 366;
				}
				else
				{
					result_day += 365;
				}
			}
			else
			{
				if (left.GetYear() + i / 400 == 0 && left.GetYear() + i / 100 == 0)
				{
					result_day += 366;
				}
				else
				{
					result_day += 365;
				}
			}
			if (!ok)
			{
					for (int j = 0; j < result_month; j++)
					{
						if (j % 2 == 0)
						{
							result_day += 30;
						}
						else
						{
							result_day += 31;
						}
						ok = true;
					}
			}
		}
	}
	else
	{
		for (int j = 0; j < result_month; j++)
		{
			if (j % 2 == 0)
			{
				result_day += 30;
			}
			else
			{
				result_day += 31;
			}
		}
	}
	return result_day;
}
int main()
{
	srand(time(0));
	Student s;
	Student g(s);
	/*Group a("P26", "Programmer", 2);
	a.AddStudent(s);
	Group b;
	b.AddStudent(g);
	Group c = a + b;
	cout << c.GetName() << "\n";
	cout << c.GetCountStudents() << "\n";*/
	Date d;
	d.SetDates(1, 2, 2000);
	Date c; 
	c.SetDates(14, 5, 2025);
	int result = d - c;
	cout << result;
}