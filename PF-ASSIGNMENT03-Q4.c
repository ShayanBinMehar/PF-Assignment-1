#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};

void inputEmployeeRatings(struct Employee *employees, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        employees[i].totalScore = 0;
        32
        3
        2
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d: ", j + 1);
                scanf("%d", &employees[i].ratings[j]);
            } while (employees[i].ratings[j] < 1 || employees[i].ratings[j] > 10);
            employees[i].totalScore += employees[i].ratings[j];
        }
    }
}

void displayPerformance(struct Employee *employees, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Period %d: %d\n", j + 1, employees[i].ratings[j]);
        }
        printf("Total Score: %d\n\n", employees[i].totalScore);
    }
}

int findEmployeeOfTheYear(struct Employee *employees, int numEmployees) {
    int highestScoreIndex = 0;
    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].totalScore > employees[highestScoreIndex].totalScore) {
            highestScoreIndex = i;
        }
    }
    return highestScoreIndex;
}

int findHighestRatedPeriod(struct Employee *employees, int numEmployees, int numPeriods) {
    int highestPeriodScore = 0, highestPeriod = 0;
    for (int j = 0; j < numPeriods; j++) {
        int periodScore = 0;
        for (int i = 0; i < numEmployees; i++) {
            periodScore += employees[i].ratings[j];
        }
        if (periodScore > highestPeriodScore) {
            highestPeriodScore = periodScore;
            highestPeriod = j;
        }
    }
    return highestPeriod;
}

int findWorstPerformingEmployee(struct Employee *employees, int numEmployees) {
    int lowestScoreIndex = 0;
    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].totalScore < employees[lowestScoreIndex].totalScore) {
            lowestScoreIndex = i;
        }
    }
    return lowestScoreIndex;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));
    for (int i = 0; i < numEmployees; i++) {
        employees[i].ratings = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployeeRatings(employees, numEmployees, numPeriods);
    displayPerformance(employees, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(employees, numEmployees);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(employees, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(employees, numEmployees);
    printf("Worst Performing Employee: Employee %d\n", worstPerformingEmployee + 1);

    // Free the dynamically allocated memory
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].ratings);
    }
    free(employees);

    return 0;
}