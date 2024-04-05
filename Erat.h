#pragma once
#include "set.h"
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
        for (unsigned i = from + 1; i <= to; i += 2)
        {
            this->Add(i);
        }
        /*for (unsigned i = from; i <= to; ++i)
        {
            this->Add(i);
        }*/
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
                if (this->Contains(i))
                {
                    this->Remove(i);
                }
                else
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
};

