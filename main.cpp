#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Required for the sleep() function

int main() {
    int hour, minute, second;

    // 1. Ask the user to set the initial time
    printf("Set the starting time (HH MM SS): ");
    scanf("%d %d %d", &hour, &minute, &second);

    // Validate the user input
    if (hour > 23 || minute > 59 || second > 59 || hour < 0 || minute < 0 || second < 0) {
        printf("Error: Invalid time format entered!\n");
        return 1;
    }

    // 2. Start an infinite loop to run the clock
    while (1) {
        // Clear the terminal screen to refresh the clock face
        // Note: Use system("cls") if you are on Windows
        system("clear");

        // 3. Print the time in HH:MM:SS format
        // %02d ensures single digits print with a leading zero (e.g., "05")
        printf("=====================\n");
        printf("    DIGITAL CLOCK    \n");
        printf("=====================\n");
        printf("      %02d:%02d:%02d\n", hour, minute, second);
        printf("=====================\n");

        // Flush the output buffer to make sure it prints instantly
        fflush(stdout);

        // 4. Update the time components
        second++; // Add 1 second

        if (second == 60) {
            minute++;
            second = 0; // Reset seconds
        }
        if (minute == 60) {
            hour++;
            minute = 0; // Reset minutes
        }
        if (hour == 24) {
            hour = 0;   // Reset hours for a 24-hour clock
        }

        // 5. Pause the program for 1 second before looping again
        sleep(1);
    }

    return 0;
}
