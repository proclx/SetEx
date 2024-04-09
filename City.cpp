#include "City.h"

std::string GetCityName(City code)
{
    switch (code)
    {
    case City::Kyiv:
        return "Kyiv";
        break;
    case City::Lviv:
        return "Lviv";
        break;
    case City::Kharkiv:
        return "Kharkiv";
        break;
    case City::Dnipro:
        return "Dnipro";
        break;
    case City::Odessa:
        return "Odessa";
        break;
    case City::Ternopil:
        return "Ternopil";
        break;
    case City::Uzhhorod:
        return "Uzhhorod";
        break;
    case City::Lutsk:
        return "Lutsk";
        break;
    case City::Rivne:
        return "Rivne";
        break;
    case City::Ivano_Frankivsk:
        return "Ivano-Frankivsk";
        break;
    case City::Zhytomyr:
        return "Zhytomyr";
        break;
    case City::Sumy:
        return "Sumy";
        break;
    case City::Donetsk:
        return "Donetsk";
        break;
    case City::Luhansk:
        return "Luhansk";
        break;
    case City::Zaporizhzhia:
        return "Zaporizhzhia";
        break;
    case City::Simferopol:
        return "Simferopol";
        break;
    case City::Chernivtsi:
        return "Chernivtsi";
        break;
    case City::Khmelnytskyi:
        return "Khmelnytskyi";
        break;
    case City::Vinnytsia:
        return "Vinnytsia";
        break;
    case City::Cherkasy:
        return "Cherkasy";
        break;
    case City::Poltava:
        return "Poltava";
        break;
    case City::Chernihiv:
        return "Chernihiv";
        break;
    case City::Kropyvnytskyi:
        return "Kropyvnytskyi";
        break;
    case City::Mykolaiv:
        return "Mykolaiv";
        break;
    case City::Kherson:
        return "Kherson";
        break;
    default:
        return "Unknown";
        break;
    }
}

void BusSchedule::AddRoute(City from, City to)
{
    if (from != to)
    {
        allCities[from].Add(to);
        allCities[to].Add(from);
    }
}

void BusSchedule::AddOneSideRoute(City from, City to)
{
    if (from != to)
    {
        allCities[from].Add(to);
    }
}

void BusSchedule::RemoveRoute(City from, City to)
{
    try
    {
        allCities[from].Remove(to);
    }
    catch (const std::exception&)
    {

    }
}

void BusSchedule::PrintAllRoutes() const
{
    for (unsigned i = 0; i < CityEnumSize; ++i)
    {
        if (!allCities[i].IsEmpty())
        {
            for (unsigned j = 0; j < CityEnumSize; ++j)
            {
                if (allCities[i].Contains((City)j))
                {
                    std::cout << std::setw(20) << GetCityName((City)i) << std::setw(20) << GetCityName((City)j) << '\n';
                }
            }
        }
    }
}

// функція знаходила маршрут, але не знаходила той, який має найменшу к-ть пересадок

//std::queue<City> BusSchedule::FindFirstRoute(City from, City to, unsigned busTransfers, std::queue<City> route, unsigned level) const
//{
//    if (from == to)
//    {
//        route.push(from);
//        return route;
//    }
//    if (level > busTransfers)
//    {
//        return std::queue<City>();
//    }
//    route.push(from);
//    for (unsigned i = 0; i < CityEnumSize; ++i)
//    {
//        if (allCities[from].Contains((City)i))
//        {
//            std::queue<City> result = FindFirstRoute((City)i, to, busTransfers, route, ++level);
//            if (!result.empty())
//            {
//                return result;
//            }
//        }
//    }
//    return std::queue<City>();
//}

bool BusSchedule::HasRouteFromTo(City from, City to, unsigned busTransfers, unsigned level) const
{
    if (from == to)
    {
        return true;
    }
    if (level > busTransfers + 1)
    {
        return false;
    }
    for (unsigned i = 0; i < CityEnumSize; ++i)
    {
        if (allCities[from].Contains((City)i))
        {
            bool result = HasRouteFromTo((City)i, to, busTransfers, ++level);
            if (result)
            {
                return result;
            }
        }
    }
    return false;
}