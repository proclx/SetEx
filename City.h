#pragma once
#include <string>
#include <queue>
#include "set.h"
#include <iomanip>
// ����� ̳��� = { ���, ����, �����, �����, �����, ��������, �������, �����, г���, 
// ����� - ���������, �������, ����, �������, ��������, ��������, ѳ���������, �������, 
// ������������, ³�����, �������, �������, ������, �������������, �������, ������ }; 

// ̳��� = ������� ���; ����� � �������, � ��� ��� ������� ���� ������� ������� ���, 
// � ����� � ����� ��������� ����������.�������� �������, ��� �� ������� �������� �������, 
// �� ����� � �������� ���� ������� ��������� � ���� ����������� �� ��������� ������� �������, 
// ��� �� ��������� ������� � �����������, ��� �� �����, �� � �����.

const unsigned CityEnumSize = 25;

enum City
{
	Kyiv,
	Lviv,
	Kharkiv,
	Dnipro,
	Odessa,
	Ternopil,
	Uzhhorod,
	Lutsk,
	Rivne,
	Ivano_Frankivsk,
	Zhytomyr,
	Sumy,
	Donetsk,
	Luhansk,
	Zaporizhzhia,
	Simferopol,
	Chernivtsi,
	Khmelnytskyi,
	Vinnytsia,
	Cherkasy,
	Poltava,
	Chernihiv,
	Kropyvnytskyi,
	Mykolaiv,
	Kherson
};

std::string GetCityName(City code);

class BusSchedule
{
private:
	Set<City> allCities[CityEnumSize];
public:
	void AddRoute(City from, City to);
	void AddOneSideRoute(City from, City to);
	void RemoveRoute(City from, City to);
	void PrintAllRoutes() const;
	bool HasRouteFromTo(City from, City to, unsigned busTransfers = 2, unsigned level = 0) const;
};