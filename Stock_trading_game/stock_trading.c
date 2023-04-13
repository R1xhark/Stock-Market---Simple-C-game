#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int starting_balance = 10000;
    int balance = starting_balance;
    int price = 100;
    int shares = 0;
    int choice;
    srand(time(NULL));

    // Open data file for writing
    FILE *data_file = fopen("stock_data.dat", "w");

    // Open gnuplot for plotting
    FILE *gnuplot_pipe = popen("gnuplot", "w");
    fprintf(gnuplot_pipe, "set terminal x11\n");
    fprintf(gnuplot_pipe, "set title 'Stock Market Game'\n");
    fprintf(gnuplot_pipe, "set boxwidth 0.5\n");
    fprintf(gnuplot_pipe, "set style fill solid\n");
    fprintf(gnuplot_pipe, "set xtics rotate\n");
    fprintf(gnuplot_pipe, "set yrange [0:]\n");
    fprintf(gnuplot_pipe, "set xlabel 'Time'\n");
    fprintf(gnuplot_pipe, "set ylabel 'Price'\n");
    fprintf(gnuplot_pipe, "plot '-' using 1:2:3:4 with candlesticks title 'Stock Price'\n");

    // Game loop
    int i = 1;
    while (1) {
        // Update stock price
        int change = rand() % 21 - 10;
        price += change;
        if (price < 0) {
            price = 0;
        }

        // Print menu and current balance/shares
        printf("Current balance: %d\n", balance);
        printf("Current shares: %d\n", shares);
        printf("\n");
        printf("1. Buy shares\n");
        printf("2. Sell shares\n");
        printf("3. Quit\n");
        printf("\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        if (choice == 1) {
            // Buy shares
            int amount;
            printf("Enter the amount of money to invest: ");
            scanf("%d", &amount);
            if (amount > balance) {
                printf("Insufficient funds!\n");
            } else {
                int num_shares = amount / price;
                shares += num_shares;
                balance -= num_shares * price;
                printf("Bought %d shares at %d each.\n", num_shares, price);
            }
        } else if (choice == 2) {
            // Sell shares
            int amount;
            printf("Enter the number of shares to sell: ");
            scanf("%d", &amount);
            if (amount > shares) {
                printf("Insufficient shares!\n");
            } else {
                shares -= amount;
                balance += amount * price;
                printf("Sold %d shares at %d each.\n", amount, price);
            }
        } else if (choice == 3) {
            // Quit game
            printf("Final balance: %d\n", balance);
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }

        // Add data to file
        fprintf(data_file, "%d %d %d %d\n", i, price, price - 10, price + 10);
        i++;

        // Print updated stock price
        printf("\n");
// Print updated stock price
printf("Current stock price: %d\n", price);

// Generate new random stock price
srand(time(NULL));
int new_price = price + (rand() % 21) - 10; // random value between -10 and 10
if (new_price <= 0) {
    new_price = 1; // set a minimum price of 1
}

// Determine if the price went up or down
if (new_price > price) {
    printf("The stock price went up by %d.\n", new_price - price);
} else if (new_price < price) {
    printf("The stock price went down by %d.\n", price - new_price);
} else {
    printf("The stock price stayed the same.\n");
}
// Update the price and go to the top of the loop
price = new_price;
continue;