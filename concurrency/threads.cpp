#include <iostream>
#include <thread>

int Temperature = 0;

void GenerateTemperature ()
{
    int range = 50 - (-16) + 1;
    while(1)
    {
        Temperature = -16 + rand() % range;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void LCD_Display()
{
    while(1)
    {
        std::cout << Temperature << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread t1 = std::thread(GenerateTemperature);
    std::thread t2 = std::thread(LCD_Display);

    t1.join();
    t2.join();
    return 0;
}
