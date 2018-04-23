#pragma once
#include<iostream>

using namespace std;

class date
{
private:
	int day;
	int mouth;
	int year;

public:
	date() = default;
	date(int day, int mouth, int year)
	{
		if(day>0&&day<32)
			this->day = day;
		else cout << "Вы не правильно указали день\n";
		if(mouth>0&&mouth<13)
			this->mouth = mouth;
		else cout << "Вы не правильно указали месяц\n";
		if(year<2019)
		this->year = year;
	}
	int &getDay() { return this->day; }
	int &getMouth() { return this->mouth; }
	int &getYear() { return this->year; }

	bool comparisonDate(int day, int mouth, int year)
	{
		if (this->day == day&&this->mouth == mouth&&this->year == year) return true;
		else false;
	}

	date changeDate(int day)
	{
		if (this->mouth == 1 || this->mouth == 3 || this->mouth == 5 || this->mouth == 7 || this->mouth == 8 || this->mouth == 10 || this->mouth == 12)
		{
			this->day += day;
			if (this->day > 31)
			{
				this->day = this->day%31;
				for(int i=0;i<day/30;i++)
				this->mouth += 1;
				if (this->mouth > 12)
				{
					this->mouth = this->mouth%12;
					if(IsLeap(this->year))
						this->year += this->day%366;
					else 
						this->year += this->day % 365;
				}
			}
		}
		else if (this->mouth == 2)
		{
			if (IsLeap(this->year))
			{
				this->day += day;
				if (this->day > 29)
				{
					this->day = this->day % 29;
					this->mouth += day / 30;
					if (this->mouth > 12)
					{
						this->mouth = this->mouth % 12;
					}
					this->year += day % 366;
				}
			}
			else
			{
				this->day += day;
				if (this->day > 28)
				{
					this->day = this->day % 28;
					this->mouth += day / 30;
					if (this->mouth > 12)
					{
						this->mouth = this->mouth % 12;
					}
					this->year += day % 366;
				}
			}

		}
			
		
	}
};

bool IsLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0) 
		if(year % 400 == 0) return true;
}