#include <iostream>
#include <unistd.h>
#include <systemd/sd-journal.h>

int main()
{
    int temperature = 25;

    while (true)
    {
        temperature++;

        sd_journal_print(LOG_INFO, "Controller reading temperature: %d", temperature);

        if (temperature > 28)
        {
            sd_journal_print(LOG_WARNING, "Temperature high -> Turning ON cooling system");
            std::cout << "Cooling ON" << std::endl;
        }
        else
        {
            sd_journal_print(LOG_INFO, "Temperature normal");
        }

        sleep(6);
    }

    return 0;
}
