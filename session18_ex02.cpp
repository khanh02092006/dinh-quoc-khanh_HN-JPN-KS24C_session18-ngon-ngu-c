#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc sinh viên
struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    
    struct Student student1;

    
    printf("Nhap ten sinh vien: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    
    student1.name[strcspn(student1.name, "\n")] = 0;

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &student1.age);
    
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", student1.phoneNumber);

   
    printf("\nThong tin sinh vien:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Phone Number: %s\n", student1.phoneNumber);

    return 0;
}

