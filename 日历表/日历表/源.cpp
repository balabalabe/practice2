#include<iostream>

class Date{
public:
	Date(int year = 1998, int month = 8, int day = 28){
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > checkday(year, month))
		{
			std::cout << "非法日期，已设为默认值: 1900-1-1" << std::endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	int checkday(int year,int month){
		int monthlist[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = monthlist[month - 1];//获取每个月对应的天数
		if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
			//闰年
			if (month == 2){
				//闰年且二月则多一天
				day++;
			}
		}
		return day;
	}
	Date& operator+=(int days){
		if (days < 0){
			return *this -= -days;
			//这里当输入一个负天数时调用一个-=重构,并把天数变号,即传一个-days进去
		}
		_day += days;
		//先把天数加上
		while (_day > checkday(_year, _month)){
			//当天数比当月的天数多时,减去当月天数并向月份进一位
			_month++;
			_day -= checkday(_year, _month);
			if (_month > 12){
				//当月数大于12时向年份进一位
				_month -= 12;
				_year++;
			}
		}
		return *this;
	}
	Date& operator-=(int days){
		if (days < 0){
			return *this += -days;
			//这里同理调用一个+=重构,并传-day进去(day -= -20就是+20的意思嘛,所以调+=重构)
		}
		_day -= days;
		while (_day < 0){
			_month--;
			//这里要注意month要先自减再给day借一位,因为day得到的不是当月的天数而是上个月的
			_day += checkday(_year, _month);
			if (_month < 0){
				_year--;
				_month += 12;
			}
		}
		return *this;
	}
	Date operator+(int days){
		Date returnday(*this);
		returnday += days;
		return returnday;
	}
	Date operator-(int days){
		Date returnday(*this);
		returnday -= days;
		return returnday;
	}
	int operator-(const Date& d){
		////两个日期相隔几天
		Date d1(*this);
		Date d2(d);
		int returnday = 0;
		int flag = 1;
		if (d1 < d2){
			d1 = d2;
			d2 = *this;
			flag = -1;
		}
		while (d2 < d1){
			++d2;
			++returnday;
		}
		return returnday * flag;
	}
	Date& operator++(){
		//实现前置++
		return *this += 1;
	}
	Date operator++(int){ //用int改变参数实现重构,与前置++区分开来
		//实现后置++
		Date returnday(*this);
		*this += 1;
		return returnday;
		//用returnday记录this指针+1前的值
	}
	Date& operator--(){
		return *this -= 1;
	}
	Date operator--(int){
		Date returnday(*this);
		*this -= 1;
		return returnday;
	}
	bool operator>(const Date& d)const{
		if (_year > d._year){
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}
	bool operator>=(const Date& d)const{
		return (*this > d) || (*this == d);
	}
	bool operator<(const Date& d)const{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)const{
		return !(*this > d);
	}
	bool operator==(const Date& d)const{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day)){
			return true;
		}
		return false;
	}
	bool operator!=(const Date& d)const{
		return !(*this == d);
	}
	void printfDate(Date& d)
	{
		std::cout << d._year << "-" << d._month << "-" << d._day << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	//测试
	int get = 0;
	Date d1(2018,1,5);
	Date d2(2019, 6, 7);
	std::cout << "d1(2018, 1, 5) += 60: " << std::endl;
	d1 += 60;
	d1.printfDate(d1);
	std::cout << "d1(2018, 3, 6) -= 60: " << std::endl;
	d1 -= 60;
	d1.printfDate(d1);
	std::cout << "d1(2018, 1, 5) = d2(2019, 6, 7): " << std::endl;
	d1 = d2;
	d1.printfDate(d1);


	std::cout << "d1(2019, 6, 7) > d2(2019, 6, 7): " << std::endl;
	get = d1 > d2;
	std::cout << get << std::endl;
	std::cout << "d1(2019, 6, 7) < d2(2019, 6, 7): " << std::endl;
	get = d1 < d2;
	std::cout << get << std::endl;
	std::cout << "d1(2019, 6, 7) == d2(2019, 6, 7): " << std::endl;
	get = (d1 == d2);
	std::cout << get << std::endl;
	std::cout << "d1(2019, 6, 7) <= d2(2019, 6, 7): " << std::endl;
	get = d1 <= d2;
	std::cout << get << std::endl;
	std::cout << "d1(2019, 6, 7) >= d2(2019, 6, 7): " << std::endl;
	get = d1 >= d2;
	std::cout << get << std::endl;

	d1--;
	std::cout << "d1(2019, 6, 7)--: " << std::endl;
	d1.printfDate(d1);
	--d1;
	std::cout << "--d1(2019, 6, 6): " << std::endl;
	d1.printfDate(d1);
	d1++;
	std::cout << "d1(2019, 6, 5)++: " << std::endl;
	d1.printfDate(d1);
	++d1;
	std::cout << "++d1(2019, 6, 6): " << std::endl;
	d1.printfDate(d1);

	get = d1+1 - d2;
	std::cout << "d1(2019, 6, 8) - d2(2019, 6, 7): " << std::endl;
	std::cout << get << std::endl;
	return 0;
}