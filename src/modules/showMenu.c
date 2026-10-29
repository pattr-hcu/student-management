#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int showMenu();

int main() {
    int choice;

    do {
        choice = showMenu();

        printf("\nYou selected option %d\n", choice);

        printf("Press any key to continue...\n");
        getch();

        system("cls");
    } while (choice != 9);

    return 0; 
}

int showMenu() {
    int ch;

    printf("--------------------------------------\n");
    printf(" Welcome to Student Management System\n");
    printf("--------------------------------------\n");
    printf("1. Add Student\n");
    printf("2. List Students\n");
    printf("3. Find Student\n");
    printf("4. Show Highest/Lowest Student by score\n");
    printf("5. Sort Students by Score\n");
    printf("6. Show Students Statistics\n");
    printf("\n9. Exit\n");
    printf("--------------------------------------\n");
    printf("Enter : ");
    scanf("%d", &ch);

    return ch;
}
