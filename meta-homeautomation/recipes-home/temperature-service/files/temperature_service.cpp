#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <systemd/sd-journal.h>

int main()
{
    sd_journal_print(LOG_INFO, "Temperature service started");

    while(true)
    {
        int temp = rand() % 10 + 20;

        std::cout << "Temperature: " << temp << std::endl;

        sd_journal_print(LOG_INFO, "Temperature value %d", temp);

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
