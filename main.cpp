#include "Erat.h"
#include "City.h"
#include <ctime>
#include <iostream>

int main()
{
    // ������ ����������

    auto start = std::time(nullptr);

    Erat test(10000);
    test.FindAllPrimes();

    auto end = std::time(nullptr);
    std::cout << "Time (seconds): " << (end - start) << std::endl;

    test.PrintFirst(10); // ���� ������ 10 ������� �����

    system("pause");

    // ����� ̳��� = { ���, ����, �����...

    BusSchedule schedule;
    schedule.AddRoute(Lviv, Kyiv);
    schedule.AddRoute(Lviv, Ivano_Frankivsk);
    schedule.AddRoute(Kyiv, Zhytomyr);
    schedule.AddRoute(Zhytomyr, Ivano_Frankivsk);
    schedule.AddRoute(Ivano_Frankivsk, Kherson);

    schedule.PrintAllRoutes();

    std::cout << "There is route from " << GetCityName(Lviv) << " to " << GetCityName(Kherson) << ": "
        << std::boolalpha << schedule.HasRouteFromTo(Lviv, Kherson) << std::endl;



    return 0;
}