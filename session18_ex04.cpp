#include <stdio.h>
#include <string.h>

struct students {
    int ID;
    char name[50];
    int age;
    char phone[15];
};

int main() {
    struct students student01[5];

    for (int i = 0; i < 5; i++) {
        student01[i].ID = i + 1;

        printf("Nhap thong tin cho sinh vien %d:\n", student01[i].ID);

        printf("Nhap ten: ");
        fgets(student01[i].name, sizeof(student01[i].name), stdin);
        student01[i].name[strcspn(student01[i].name, "\n")] = 0;

        printf("Nhap tuoi: ");
        scanf("%d", &student01[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%s", student01[i].phone);
        getchar(); 
    }

    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < 5; i++) {
        printf("Sinh vien %d:\n", student01[i].ID);
        printf("Name: %s\n", student01[i].name);
        printf("Age: %d\n", student01[i].age);
        printf("Phone Number: %s\n", student01[i].phone);
    }

    return 0;
}

