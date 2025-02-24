#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char name[20];
    int day, month, year;
    printf("Enter your name: ");
    scanf("%20s", &name);
    printf("Enter your day of birth: ");
    scanf("%d", &day);
    printf("Enter your month of birth: ");
    scanf("%d", &month);
    printf("Enter your year of birth: ");
    scanf("%d", &year);

    int age = 0, cont = 0;
    time_t current_time = time(NULL);
    char date_string[20];
    strftime(date_string, 20, "%Y-%m-%d-", localtime(&current_time));
    char* cuv = strtok(date_string, "-");
    while (cuv != NULL) {
        cont++;
        int date = atoi(cuv);
        printf("%d\n", date);
        if (cont == 1){
            int diff = date - year;
            age = diff;
        }
        else if (cont == 2) {
            if (date < month) {
                age--;
                break;
            }
        }
        else {
            if (date < day)
                age--;
        }
        cuv = strtok(NULL, "-");
    }
    printf("Hello, %s, you are %d!\n old!", name, age);
    return 0;
}
