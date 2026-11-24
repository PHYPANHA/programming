#include <stdio.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_ONE_SECOND() Sleep(1000)
#else
    #include <unistd.h>
    #define SLEEP_ONE_SECOND() sleep(1)
#endif

int main(void) {
    char time_str[16];

    printf("Digital Clock (Press Ctrl+C to stop)\n\n");

    while (1) {
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        if (local == NULL) {
            fprintf(stderr, "Error retrieving local time.\n");
            return 1;
        }

        /* Format time as HH:MM:SS (24-hour format) */
        strftime(time_str, sizeof(time_str), "%H:%M:%S", local);

        /* '\r' returns the cursor to the start of the current line */
        printf("\r  %s  ", time_str);
        fflush(stdout);

        SLEEP_ONE_SECOND();
    }

    return 0;
}