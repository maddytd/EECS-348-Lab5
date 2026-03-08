#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

const char *month_names[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

/* Read 12 monthly sales figures from user input */
int read_sales(double sales[MONTHS]) {
    printf("Enter monthly sales figures for each month:\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s: ", month_names[i]);
        if (scanf("%lf", &sales[i]) != 1) {
            fprintf(stderr, "Error: Invalid input for month %d\n", i + 1);
            return 0;
        }
    }
    printf("\n");
    return 1;
}

/* Report 1: Monthly Sales Report */
void print_monthly_report(double sales[MONTHS]) {
    printf("Monthly Sales Report for 2024\n");
    printf("%-15s %10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-15s %10.2f\n", month_names[i], sales[i]);
    }
    printf("\n");
}

/* Report 2: Sales Summary Report */
void print_summary_report(double sales[MONTHS]) {
    int min_idx = 0, max_idx = 0;
    double total = 0.0;

    for (int i = 0; i < MONTHS; i++) {
        total += sales[i];
        if (sales[i] < sales[min_idx]) min_idx = i;
        if (sales[i] > sales[max_idx]) max_idx = i;
    }

    printf("Sales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", sales[min_idx], month_names[min_idx]);
    printf("Maximum sales: %.2f (%s)\n", sales[max_idx], month_names[max_idx]);
    printf("Average sales: %.2f\n", total / MONTHS);
    printf("\n");
}

/* Report 3: Six-Month Moving Average */
void print_moving_average(double sales[MONTHS]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s %.2f\n", month_names[i], month_names[i + 5], sum / 6.0);
    }
    printf("\n");
}

/* Report 4: Sales Sorted Highest to Lowest */
void print_sorted_report(double sales[MONTHS]) {
    /* Copy sales and indices for sorting */
    double sorted_sales[MONTHS];
    int indices[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        indices[i] = i;
    }

    /* Bubble sort descending */
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - 1 - i; j++) {
            if (sorted_sales[j] < sorted_sales[j + 1]) {
                double tmp = sorted_sales[j];
                sorted_sales[j] = sorted_sales[j + 1];
                sorted_sales[j + 1] = tmp;

                int tmpi = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tmpi;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("%-15s %12s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-15s $%11.2f\n", month_names[indices[i]], sorted_sales[i]);
    }
    printf("\n");
}

int main(void) {
    double sales[MONTHS];
    if (!read_sales(sales)) {
        return 1;
    }

    print_monthly_report(sales);
    print_summary_report(sales);
    print_moving_average(sales);
    print_sorted_report(sales);

    return 0;
}