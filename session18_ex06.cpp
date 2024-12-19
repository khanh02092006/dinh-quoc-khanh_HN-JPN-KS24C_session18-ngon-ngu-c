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
    int soluongsinhvienhientai = 5;

    if (soluongsinhvienhientai < 50) {
        struct student sinhvienmoi;
        sinhvienmoi.ID = soluongsinhvienhientai + 1;

        printf("Nhap thong tin sinh vien moi:\n");

       
        printf("Nhap ten: ");
        
        fgets(sinhvienmoi.name, sizeof(sinhvienmoi.name), stdin);
        sinhvienmoi.name[strcspn(sinhvienmoi.name, "\n")] = 0;

        
        printf("Nhap tuoi: ");
        scanf("%d", &sinhvienmoi.age);

        
        printf("Nhap so dien thoai: ");
        scanf("%s", sinhvienmoi.phone);

        
        students[soluongsinhvienhientai] = sinhvienmoi;
        soluongsinhvienhientai++;
    } else {
        printf("Khong the them sinh vien, mang da day.\n");
    }

    
    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < soluongsinhvienhientai; i++) {
        printf("ID: %d\n", students[i].ID);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Phone Number: %s\n", students[i].phone);
    }

    return 0;
}

		
