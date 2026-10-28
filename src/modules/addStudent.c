#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Student {
    int id;
    char name[40];
    float score;
};
int studentCount=0;
struct Student students[40];
void sortStudent() {
    struct Student temp;
    int i,j;
    for (i = 0; i < studentCount - 1; i++) {
        for (j = 0; j < studentCount - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
int findStudent(int* id) {
    int searchId;
    int low = 0, mid, high = studentCount - 1;
    bool flag = false;

    if (!(studentCount > 0)) {
        printf("There are no student in record.\n");
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

            printf("Student ID: %d\n", students[mid].id);
            printf("Student Name: %s\n", students[mid].name);
            printf("Student Score: %.2f\n", students[mid].score);

            return mid;

        } else if (students[mid].id < *id) {

            low = mid + 1;

        } else {

            high = mid - 1;

        }
    }

    if (!flag) {
        printf("Student ID %d not found.\n", *id);
    }
    
    return -1;
}

// For test & debug only.

void addStudent() {
	
int id;
char name[40];
float score;
	printf("Input Student ID: ");
	scanf("%d",&id);
	int check=findStudent(&id);
	
	if(check==-1){
	getchar();
	printf("Input Name: ");
	fgets(name,sizeof(name), stdin);
	
	printf("Input Score: ");
	scanf("%f",&score);
	
    students[studentCount].id=id;
    strcpy(students[studentCount].name,name);
    students[studentCount].score=score;
	
}
	else
	printf("Student ID Already Exist");
}
int main(){
	addStudent();
	printf("%d\n%s%.2f",students[0].id,students[0].name,students[0].score);
return 0;
}
