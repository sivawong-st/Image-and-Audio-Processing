#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int N ,M;

    // รับค่า N และ M
    printf("Please enter size of N(ROW) : ");
    scanf("%d",&N);
    printf("Please enter size of M(COLUM) : ");
    scanf("%d",&M);

    // ตรวจสอบว่าค่าเป็นบวก
    if (N <= 0 || M <= 0) {
        printf("Error The entered value is negative or zero.\n");
        return 1;
    }

    printf("N = %d and M = %d\n", N, M);

     // จองหน่วยความจำ
    int **NM = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        NM[i] = (int *)malloc(M * sizeof(int));
    }

    // รับค่าจากผู้ใช้เพื่อเก็บในอาเรย์
    printf("Please enter value in array :\n");
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        do {
            printf("NM[%d][%d] = ", i, j);
            scanf("%d", &NM[i][j]);
            if (NM[i][j] > 255) {
                    printf("Error: Value must not exceed 255. Please enter again.\n");
                }
            } while (NM[i][j] > 255); // ตรวจสอบซ้ำจนกว่าจะใส่ค่าที่ถูกต้อง
        }
    }

    // แสดงผลค่าภายในอาเรย์
    printf("Value in array :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", NM[i][j]); // ใช้ %4d เพื่อให้ความกว้างตัวเลขเท่ากัน
        }
        printf("\n");
    }

    //หาผลรวมของค่าทั้งหมด
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            total += NM[i][j];
        }
    }
    printf("Total : %d\n",total);

    // คำนวณ Brightness
    double brightness = (double)total / (N * M);
    printf("Brightness (B): %.2f\n", brightness);

    // คำนวณ Contrast
    double contrast_sum = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            contrast_sum += pow((NM[i][j] - brightness), 2);
        }
    }
    double contrast = sqrt(contrast_sum / (N * M));
    printf("Contrast (C): %.2f\n", contrast);

    // คืนหน่วยความจำ
    for (int i = 0; i < N; i++) {
        free(NM[i]);
    }
    free(NM);

    return 0;
}