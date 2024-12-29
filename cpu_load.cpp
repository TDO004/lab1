#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void benchmark(long long* counters, long long num_counters) {
    for (long long i = 0; i < num_counters; i++) {
        for (long long j = 0; j < 1000000000; j++) {
            counters[i]++;
        }
    }
}

int main() {
    for (long long num_counters = 1; num_counters <= 4; num_counters += 1) {
        // Выделяем память под счётчики
        long long* counters = (long long*)malloc(num_counters * sizeof(long long));
        for (long long i = 0; i < num_counters; i++) counters[i] = 0;

        // Измерение времени работы
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        benchmark(counters, num_counters);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Расчёт объёма памяти
        long long memory_used = num_counters * sizeof(long long);

        printf("Counters: %lld, Memory: %lld bytes, Time: %f seconds\n",
            num_counters, memory_used, cpu_time_used);

        free(counters); // Освобождение памяти
    }
    return 0;
}
