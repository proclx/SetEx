#pragma once
#include "set.h"

// Задано натуральне п.Знайти всі прості числа з проміжку[2; n] за допомогою решета Ератосфена.Суть методу :
// Записати всі числа від 2 до п;
// Залишити в записі перше просте число, тобто 2, і викреслити з запису всі кратні йому(4, 6, 8, …)
// Залишити в записі перше просте число, тобто 3, і викреслити з запису всі кратні йому(6, 9, 12, …)
// Залишити в записі перше просте число, тобто 5, і викреслити з запису всі кратні йому … Повторювати до кінця послідовності.

class Erat :
    public Set<unsigned>
{
private:
    unsigned to;
    static const unsigned from = 2;
public:
    Erat(unsigned f)
        : to(f)
    {
        List curr = new Node<unsigned>(0);
        List newHead = curr;
        unsigned i = 3;

        // додавання елементів можна і потрібно оптимізувати, адже ми наперед знаємо, що послідовність впорядкована

        while (i <= to)
        {
            curr->next = new Node<unsigned>(i);
            curr = curr->next;
            i += 2;
        }

        head = newHead->next;
        delete newHead;
    }
    ~Erat()
    {
    }
    void FindAllPrimes()
    {
        unsigned unsuccesfulAttempt = 0;
        unsigned numberOfPrimes = 0;
        unsigned totalAttempts = 0;
        List curr = this->head;
        while (curr != nullptr)
        {
            for (unsigned i = curr->value * curr->value; i <= to; i += curr->value * 2)
            {
                try
                {
                    this->Remove(i);
                }
                catch (...)
                {
                    ++unsuccesfulAttempt;
                }
                ++totalAttempts;
            }
            curr = curr->next;
            ++numberOfPrimes;
        }
        std::cout << "Unsuccessful attempts: " << unsuccesfulAttempt << '\n';
        this->Add(2);
        std::cout << "Number of primes: " << ++numberOfPrimes << '\n';
        std::cout << "Total attempts: " << totalAttempts << '\n';
    }
    void PrintFirst(unsigned n = 1)
    {
        List curr = head;
        unsigned i = 0;
        while (i < n)
        {
            std::cout << curr->value << ' ';
            curr = curr->next;
            ++i;
        }
    }
};

