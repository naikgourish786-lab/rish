#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STATES 5

int main() {
    char stateCodes[MAX_STATES][3] = {"KA", "MH", "TN", "DL", "AP"};
    char vehicleNo[15];
    char state[3];

    int i, len, stateFound = 0, valid = 1, numStart;

    printf("Enter vehicle number (e.g., KA05MH1234): ");
    scanf("%14s", vehicleNo);

    len = strlen(vehicleNo);

    if (len < 9 || len > 10) {
        printf("Invalid vehicle number - incorrect length\n");
        return 0;
    }
    state[0] = vehicleNo[0];
    state[1] = vehicleNo[1];
    state[2] = '\0';

    for (i = 0; i < MAX_STATES; i++) {
        if (strcmp(state, stateCodes[i]) == 0) {
            stateFound = 1;
            break;
        }
    }

    if (!stateFound) {
        printf("Invalid vehicle number - invalid state code\n");
        return 0;
    }

    if (!isdigit(vehicleNo[2]) || !isdigit(vehicleNo[3])) {
        printf("Invalid vehicle number - invalid RTO code\n");
        return 0;
    }

    numStart = len - 4;

    for (i = 4; i < numStart; i++) {
        if (!isalpha(vehicleNo[i])) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("Invalid vehicle number - invalid series code\n");
        return 0;
    }

    for (i = numStart; i < len; i++) {
        if (!isdigit(vehicleNo[i])) {
            valid = 0;
            break;
        }
    }

    if (valid)
        printf("Valid vehicle number\n");
    else
        printf("Invalid vehicle number - invalid number part\n");

    return 0;
}
