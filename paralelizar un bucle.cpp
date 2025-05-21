#include <omp.h>
#include <iostream>

int main() {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }
    std::cout << "Suma de 1 a 100 = " << sum << std::endl;
    return 0;
}
