#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int choice;
    printf("Choose an option:\n");
    printf("1. Manual input of book sizes\n");
    printf("2. Randomly generate book sizes\n");
    scanf("%d", &choice);

    int totalBooks;
    int books[10];

    if (choice == 1) {
        // Manual input
        printf("Insert the amount of books you want: ");
        scanf("%d", &totalBooks);

        printf("Now for the number of pages for each book. For simplicity and ease of use, you will need to input just one or more numbers which will then be multiplied by 100.\n");
        for (int i = 0; i < totalBooks; i++) {
            printf("Book[%d]: ", i + 1);
            int bookPages;
            scanf("%d", &bookPages);
            books[i] = bookPages * 100;
        }
    } else if (choice == 2) {
        // Randomly generate book sizes
        totalBooks = rand() % 20; // Random amount of books maximum 19
        for (int i = 0; i < totalBooks; i++) {
            books[i] = rand() % 1000 + 100; // Random sizes between 100 and 1099
        }
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
        return 1; // Exit program if choice is invalid
    }

    int num_books = totalBooks;
    int total_pages = 0;
    for (int i = 0; i < num_books; i++) {
        total_pages += books[i];
    }

    int num_employees;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    int avg_pages = total_pages / num_employees;

    int current_sum = 0;
    int sections = 1;

    printf("Employee 1: ");

    for (int i = 0; i < num_books; i++) {
        current_sum += books[i];
        if (current_sum > avg_pages * sections) {
            printf("\nEmployee %d: ", sections + 1);
            sections++;
        }
        printf("%d ", books[i]);
    }
    printf("\nNumber of books: %d\n",books);
    printf("\nAverage pages per employee: %d\n", avg_pages);

    return 0;
}
