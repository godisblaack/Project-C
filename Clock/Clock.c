#include <stdio.h>
#include <time.h>

void fillTime24(char *buffer, size_t size) {
  time_t rawTime;
  struct tm *currentTime;

  time(&rawTime);
  currentTime = localtime(&rawTime);

  sprintf(buffer, "%02d:%02d:%02d", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
}

void fillTime12(char *buffer, size_t size) {
  time_t rawTime;
  struct tm *currentTime;

  time(&rawTime);
  currentTime = localtime(&rawTime);

  strftime(buffer, size, "%I:%M:%S %p", currentTime);
}

void fillDate(char *buffer, size_t size) {
  time_t rawTime;
  struct tm *currentTime;

  time(&rawTime);
  currentTime = localtime(&rawTime);

  strftime(buffer, 100, "%A %B %d %Y", currentTime);
}

int main() {
  char time[50], date[50];

  fillTime24(time, sizeof(time));
  printf("\nCurrent Time: %s\n", time);

  fillTime12(time, sizeof(time));
  printf("\nCurrent Time: %s\n", time);

  fillDate(date, sizeof(date));
  printf("\nDate: %s\n\n", date);

  return 0;
}

