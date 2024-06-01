#include <stdio.h>
#include <time.h>

void fillTime24(char *buffer, size_t size) {
  time_t rawTime;
  struct tm *currentTime;

  time(&rawTime);
  currentTime = localtime(&rawTime);

  strftime(buffer, size, "%H:%M:%S", currentTime);
}

void fillTime12(char *buffer, size_t size) {
  time_t rawTime;
  struct tm *currentTime;

  time(&rawTime);
  currentTime = localtime(&rawTime);

  strftime(buffer, size, "%I:%M:%S", currentTime);
}

int main() {
  char time[50];

  fillTime24(time, sizeof(time));
  printf("\nCurrent Time: %s\n", time);

  fillTime12(time, sizeof(time));
  printf("\nCurrent Time: %s\n", time);

  return 0;
}

