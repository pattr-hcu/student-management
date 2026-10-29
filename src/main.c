#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[40];
    float score;
};

struct Student students[MAX_STUDENTS];
unsigned int studentCount = 0;

int showMenu();
void addStudent();
void removeStudent();
void showStudent();
int findStudent(int* id);
void sortStudent();
void sortByScore(struct Student S[], int n, int t);	
void showStatistic(struct Student S[], int n);
float calculateAverage(struct Student s[], int n);
char calculateGrade(float score);

int main() {
    int choice;

    do {
        system("cls");
        choice = showMenu();
        system("cls");

        switch (choice) {
            case 1:
                printf("Add Student\n");
                addStudent();
                break;
            case 2:
                printf("Remove Student\n");
                removeStudent();
                break;
            case 3:
                printf("List Students\n");
                showStudent();
                break;
            case 4:
                printf("Find Student\n");
                {
                    int id, idx;
                    
                    printf("Enter Student ID to find: ");
                    scanf("%d", &id);
                    idx = findStudent(&id);

                    if (idx != -1) {
                        printf("Student found:\n");
                        printf("ID: %d\n", students[idx].id);
                        printf("Name: %s", students[idx].name);
                        printf("Score: %.2f\n", students[idx].score);
                    } else {
                        printf("\nStudent ID %d not found.\n", id);
                    }
                }
                break;
            case 5:
                printf("Show sorted Student by score\n");
                {
                    int t;
                    printf("\nEnter 0 for Highest or 1 for Lowest (0/1): ");
                    scanf("%d", &t);
                    sortByScore(students, studentCount, t);
                    showStudent();
                }
                break;
            case 6:
                printf("Show Students Statistics\n");
                showStatistic(students, studentCount);
                break;
            case 9:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress any key to continue...\n");
        getch();
    } while (choice != 9);

    printf("Exiting the program...\n");

    return 0; 
}

int showMenu() {
    int ch;

    printf("--------------------------------------\n");
    printf(" Welcome to Student Management System\n");
    printf("--------------------------------------\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. List Students\n");
    printf("4. Find Student\n");
    printf("5. Show sorted Student by score\n");
    printf("6. Show Students Statistics\n");
    printf("\n9. Exit\n");
    printf("--------------------------------------\n");
    printf("Enter : ");
    scanf("%d", &ch);

    return ch;
}

// Assigned to Man
void addStudent() {
    int id;
    char name[40];
    float score;

	printf("Input Student ID: ");
	scanf("%d",&id);

	int check = findStudent(&id);
	
	if(check==-1){
        getchar();

        printf("Input Name: ");
        fgets(name,sizeof(name), stdin);
        
        printf("Input Score: ");
        scanf("%f",&score);
        
        students[studentCount].id=id;
        strcpy(students[studentCount].name, name);
        students[studentCount].score=score;

        studentCount++;
    }
	else printf("\nStudent ID Already Exist");
}

// Assigned to Ponl
void removeStudent() {
    int id, idx;

    printf("Enter Student ID to remove: ");
    scanf("%d", &id);
    idx = findStudent(&id);

    if (idx != -1) {
        for (int i = idx; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("\nStudent ID %d removed successfully.\n", id);
    } else {
        printf("\nStudent ID %d not found.\n", id);
    }
}

// Assigned to Pub
void showStudent() {
    if (studentCount == 0) {
        printf("There are no student in record.\n");
        return;
    }

    printf("Student List:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Score", "Grade");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-30s %-10.2f %-10c\n", students[i].id, students[i].name, students[i].score, calculateGrade(students[i].score));
    }
}

// Assigned to Pub
void sortByScore(struct Student S[], int n, int t) {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            
            if (t == 0 && S[j].score <S[j + 1].score){
			
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
                
            }else
                 if (t == 1 && S[j].score >S[j + 1].score){
				 
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
                 
            }
        }
    }
}

// Assigned to Ponl
void sortStudent() {
    struct Student temp;
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Assigned to Ponl
int findStudent(int* id) {
    int searchId;
    int low = 0, mid, high = studentCount - 1;
    bool flag = false;

    if (!(studentCount > 0)) {
        return -1;
    }

    if (id == NULL) {
        printf("Find student ID: ");
        scanf("%d", &searchId);
        id = &searchId;
    }

    sortStudent();

    while (low <= high && !flag) {
        mid = (low + high) / 2;

        if (students[mid].id == *id) {
            flag = true;

            return mid;

        } else if (students[mid].id < *id) {

            low = mid + 1;

        } else {

            high = mid - 1;

        }
    }
    
    return -1;
}

// Assigned to Pub
void showStatistic(struct Student S[], int n) {
    int i;
    float total = 0, avg;

    printf("\n===== Show Statistics =====\n");
    for (i = 0; i < n; i++) {
        printf("%d  %-10s  %.1f  %c\n", S[i].id, S[i].name, S[i].score, calculateGrade(S[i].score));
        total += S[i].score; 
    }
    avg = total /n;

    printf("=========================\n");
    printf("Total Score : %.1f\n", total);
    printf("Average Score : %.2f\n",avg);
}

// Assigned to Diw
float calculateAverage(struct Student s[],int n){

    float sum = 0;
    
    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        sum += s[i].score;
    }

    return sum / n;
}

// Assigned to Diw
char calculateGrade(float score) {
    if (score >= 80)
        return 'A';
    else if (score >= 70)
        return 'B';
    else if (score >= 60)
        return 'C';
    else if (score >= 50)
        return 'D';
    else
        return 'F';
}
