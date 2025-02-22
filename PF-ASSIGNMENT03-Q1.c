#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining[3]; //FORMAT = Day, Month, Year
};

void inputEmployeeDetails(struct Employee *emp) {
    printf("Enter employee code (ONLY INTEGER): ");
    scanf("%d", &emp->employeeCode);
        
    printf("Enter employee name: ");
    scanf("%s", emp->employeeName);

    printf("Enter date of joining (DD MM YYYY): ");
    scanf("%d %d %d", &emp->dateOfJoining[0], &emp->dateOfJoining[1], &emp->dateOfJoining[2]);
        
    
}

int main() {
    struct Employee employees[4];

    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        inputEmployeeDetails(&employees[i]);
    }

    int currentDay, currentMonth, currentYear;
    printf("\nEnter current date (DD MM YYYY): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    int count = 0;
    for (int i = 0; i < 4; i++) {
        int tenure = currentYear - employees[i].dateOfJoining[2];
        if (currentMonth < employees[i].dateOfJoining[1]) {
            tenure--;
        } else if (currentMonth == employees[i].dateOfJoining[1] && currentDay < employees[i].dateOfJoining[0]) {
            tenure--;
        }

        if (tenure > 3) {
            printf("\nEmployee %d Details:\n", i + 1);
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %d/%d/%d\n", employees[i].dateOfJoining[0], employees[i].dateOfJoining[1], employees[i].dateOfJoining[2]);
            printf("Tenure: %d years\n", tenure);
            count++;
        }
    }

    printf("\nTotal employees with more than 3 years of tenure: %d\n", count);

    return 0;
}