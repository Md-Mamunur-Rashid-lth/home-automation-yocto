#include <iostream>
#include <unistd.h>
#include <systemd/sd-journal.h>

int main()
{
    bool lightOn = false;

    while (true)
    {
        lightOn = !lightOn;

        if (lightOn)
        {
            sd_journal_print(LOG_INFO, "Light turned ON");
            std::cout << "Light ON" << std::endl;
        }
        else
        {
            sd_journal_print(LOG_INFO, "Light turned OFF");
            std::cout << "Light OFF" << std::endl;
        }

        sleep(5);
    }

    return 0;
}
