#include <chrono>
#include <ostream>
#include <math.h>
#include <random>
#include <fstream>

#include "comptage.h"

int main()
{
    int taille=pow(10,5);
    std::ofstream file;
    file.open("ComptageData.csv", std::ios_base::app);
    std::random_device seed;
    std::default_random_engine gen{seed()};
    std::uniform_int_distribution<> distrib{1,10000};

    for (int n=1; n<taille;++n)
    {
        int tab[n];
        for (int j=0; j<n;j++)
        {
            tab[j]=distrib(seed);
        }
        auto BeforeExecution = std::chrono::steady_clock::now();
        TrieInsertion(tab, n);
        auto AfterExecution = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds=AfterExecution-BeforeExecution;
        file << n << "," << elapsed_seconds.count() << std::endl;
    }
    file.close();
    return 0;
}