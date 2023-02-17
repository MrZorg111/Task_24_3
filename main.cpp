#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

int main() {
    /// Сбор данных
    std::time_t t = std::time(nullptr);
    std::tm local = *localtime(&t);
    std::tm timer_time = *localtime(&t);
    std::cout << "Enter the timer time:";
    std::cin >> std::get_time(&timer_time, "%M:%S");
    std::cout << asctime(&local) << std::endl;
    std::cout << asctime(&timer_time) << std::endl;

    ///Обработка данных
    double timer = difftime(std::mktime(&timer_time), std::mktime(&local));
    t = (int)timer;
    for (int i = t; i > 0; i--) {
        Sleep(1000);
        local = *localtime(&t);
        std::cout << std::put_time(&local, "%M:%S") << "\n";
        t--;
    }
    std::cout << "DING!!!DING!!!DING!!!";
    return 0;
}
