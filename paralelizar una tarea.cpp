#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <iostream>

int main() {
    int sum = 0;
    tbb::parallel_for(tbb::blocked_range<int>(1, 101),
        [&sum](const tbb::blocked_range<int>& r) {
            int local_sum = 0;
            for (int i = r.begin(); i < r.end(); ++i) {
                local_sum += i;
            }
            #pragma omp critical
            sum += local_sum;
        }
    );
    std::cout << "Suma de 1 a 100 = " << sum << std::endl;
    return 0;
}
