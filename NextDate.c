#include <stdio.h>

int isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int isValidDate(int day, int month, int year) {
    if (year < 1812 || year > 2018) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || (month == 2 && ((isLeap(year) && day > 29) || (!isLeap(year) && day > 28)))) return 0;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    if (day > 31) return 0;
    return 1;
}

void getNextDay(int day, int month, int year) {
    int daysInMonth[] = {31, isLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (day < daysInMonth[month - 1]) {
        (day)++;
    } else {
        day = 1;
        if (month == 12) {
            month = 1;
            (year)++;
        } else {
            (month)++;
        }
    }
  printf("Next day is %02d/%02d/%d\n", day, month, year);
}

void main() {
    int day, month, year;
    printf("Enter date in dd mm yyyy format: ");
    scanf("%d %d %d", &day, &month, &year);

    if (!isValidDate(day, month, year)) {
        printf("Invalid date input\n");
        return 1;
    }

    getNextDay(day,month,year);
    
}
