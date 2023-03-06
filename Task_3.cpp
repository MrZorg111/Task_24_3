#include <iostream>
#include <ctime>
#include <iomanip>


int main() {
    /// Сбор данных
    std::tm inter_time = {};
    std::cout << "Set the timer time in mm:ss format:";
    std::cin >> std::get_time(&inter_time, "%M:%S");
    std::cout << std::endl;
    std::time_t future_time = std::time(nullptr) + 60 * inter_time.tm_min + inter_time.tm_sec;
    std::tm local_future = *localtime(&future_time);
    std::time_t end = std::time(nullptr);
    ///Обработка данных
    while (std::difftime(future_time, end) > 0) {
        if(std::time(nullptr) > end) {
            std::time_t diff = (std::time_t)std::difftime(future_time, end);
            std::tm diff_local = *localtime(&diff);
            std::cout << std::put_time(&diff_local, "%M:%S") << "\n";
            end = time(nullptr);
        }
    }
    ///Вывод
    std::cout << "DING!!!DING!!!DING!!!";
    return 0;
}
