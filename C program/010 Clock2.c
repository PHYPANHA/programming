#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_ONE_SECOND() Sleep(1000)
#else
    #include <unistd.h>
    #define SLEEP_ONE_SECOND() sleep(1)
#endif

int main(void) {
    int hours = 0, minutes = 0, seconds = 0;

    printf("Enter starting time (HH MM SS): ");
    if (scanf("%d %d %d", &hours, &minutes, &seconds) != 3 ||
        hours < 0 || hours > 23 ||
        minutes < 0 || minutes > 59 ||
        seconds < 0 || seconds > 59) {
        printf("Invalid time input.\n");
        return 1;
    }

    printf("\nDigital Clock (Press Ctrl+C to stop)\n\n");

    while (1) {
        /* %02d pads single-digit numbers with a leading zero */
        printf("\r  %02d:%02d:%02d  ", hours, minutes, seconds);
        fflush(stdout);

        SLEEP_ONE_SECOND();

        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        if (hours == 24) {
            hours = 0;
        }
    }

    return 0;
}