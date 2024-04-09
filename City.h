#pragma once
#include <string>
#include <queue>
#include "set.h"
#include <iomanip>
// Нехай Місто = { Київ, Львів, Харків, Дніпро, Одеса, Тернопіль, Ужгород, Луцьк, Рівне, 
// Івано - Франківськ, Житомир, Суми, Донецьк, Луганськ, Запоріжжя, Сімферополь, Чернівці, 
// Хмельницький, Вінниця, Черкаси, Полтава, Чернігів, Кропивницький, Миколаїв, Херсон }; 

// Міста = множина міст; Рейси – таблиця, у якій для кожного міста вказано множину міст, 
// з якими є пряме автобусне сполучення.Напишіть функцію, яка за заданою таблицею визначає, 
// чи можна з заданого міста Початок потрапити в місто Призначення за допомогою прямого переїзду, 
// або за допомогою переїзду з пересадка­ми, але не більше, ніж з двома.

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