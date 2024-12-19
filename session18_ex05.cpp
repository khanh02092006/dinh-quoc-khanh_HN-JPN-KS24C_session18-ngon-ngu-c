#include <stdio.h>
#include <string.h>

struct student {
    int ID;
    char name[50];
    int age;
    char phone[15];
};

int main() {
    struct student students[50] = {
        {1, "Dinh Quoc Khanh", 18, "0388932784"},
        {2, "Pham Thanh Dat", 18, "0388932784"},
        {3, "Le Van C", 22, "0112233445"},
        {4, "Pham Thi D", 23, "0223344556"},
        {5, "Hoang Van E", 24, "0334455667"}
    };

    int tim_id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &tim_id);

    int thay = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].ID == tim_id) {
            thay = 1;
            printf("Sinh vien tim thay:\n");
            printf("ID: %d\n", students[i].ID);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Phone Number: %s\n", students[i].phone);

            printf("Nhap ten moi: ");
            getchar(); // Làm s?ch b? d?m
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;

            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            break;
        }
    }

    if (!thay) {
        printf("Khong tim thay sinh vien voi ID %d.\n", tim_id);
    }

    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d\n", students[i].ID);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Phone Number: %s\n", students[i].phone);
    }

    return 0;
}	   
		
