#include <iostream>
#include <vector>
#include <chrono>

void benchmark(std::vector<long long>& counters) {
    for (auto& counter : counters) {
        for (long long j = 0; j < 1000000000; j++) {
            counter++;
        }
    }
}

int main() {
    for (long long num_counters = 1; num_counters <= 4; num_counters++) {
        // Создаём вектор для счётчиков
        std::vector<long long> counters(num_counters, 0);

        // Измерение времени работы
        auto start = std::chrono::high_resolution_clock::now();
        benchmark(counters);
        auto end = std::chrono::high_resolution_clock::now();

        // Вычисление времени выполнения
        std::chrono::duration<double> elapsed = end - start;

        // Расчёт объёма памяти
        long long memory_used = num_counters * sizeof(long long);

        // Вывод результатов
        std::cout << "Counters: " << num_counters
            << ", Memory: " << memory_used << " bytes"
            << ", Time: " << elapsed.count() << " seconds" << std::endl;
    }

    return 0;
}