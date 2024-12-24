#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    while (true) {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - start);
        if (duration.count() >= 10) {  // Время выполнения — 10 секунд
            std::cout << "Program executed for " << duration.count() << " seconds.\n";
            break;
        }
    }
    return 0;
}
