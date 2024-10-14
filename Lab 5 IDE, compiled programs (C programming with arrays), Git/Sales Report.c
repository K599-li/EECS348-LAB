#include <stdio.h>
#include <string.h>


double monthly_sales[12] = {
    23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
    72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
};

const char *months[12] = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

// 1. Monthly Sales Report
void monthly_sales_report() {
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], monthly_sales[i]);
    }
}

// 2. Sales Summary Report
void sales_summary_report() {
    double min_sales = monthly_sales[0];
    double max_sales = monthly_sales[0]; 
    double total_sales = 0.0;
    int min_month_index = 0;
    int max_month_index = 0;

    for (int i = 0; i < 12; i++) {
        if (monthly_sales[i] < min_sales) {
            min_sales = monthly_sales[i];
            min_month_index = i;
        }
        if (monthly_sales[i] > max_sales) {
            max_sales = monthly_sales[i];
            max_month_index = i;
        }
        total_sales += monthly_sales[i];
    }

    double avg_sales = total_sales / 12;

    printf("\nSales summary report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[min_month_index]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[max_month_index]);
    printf("Average sales: $%.2f\n", avg_sales);
}

// 3. Six-Month Moving Average Report
void six_month_moving_average_report() {
    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 7; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += monthly_sales[j];
        }
        double avg = sum / 6;
        printf("%s-%s %.2f\n", months[i], months[i + 5], avg);
    }
}

// 4. Sales Report (Highest to Lowest)
void sales_report_highest_to_lowest() {
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month       Sales\n");


    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i;
    }


    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (monthly_sales[indices[i]] < monthly_sales[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

  
    for (int i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[indices[i]], monthly_sales[indices[i]]);
    }
}

int main() {
    monthly_sales_report();
    sales_summary_report();
    six_month_moving_average_report();
    sales_report_highest_to_lowest();
    return 0;
}