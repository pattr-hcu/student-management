#include <stdio.h>
#define max 4  

struct Student {
    int id;
    char name[40];
    float score;
};


struct Student S[max] = {
    {690001, "Somchai", 91.0f},
    {690002, "Somsri",  20.0f},
    {690003, "Somsak",  59.0f},
    {690004, "Sompong", 86.0f}
};

void showStatistic(struct Student S[], int n);

int main() {
    showStatistic(S, max);
    return 0;
}


void showStatistic(struct Student S[], int n) {
    int i;
    float total = 0, avg;

    printf("\n===== Show MANU =====\n");
    for (i = 0; i < n; i++) {
        printf("%d  %-10s  %.1f\n", S[i].id, S[i].name, S[i].score);
        total += S[i].score; 
    }
    avg = total /n;

    printf("=========================\n");
    printf("Total Score : %.1f\n", total);
    printf("Averagg Score : %.2f\n",avg);
}
