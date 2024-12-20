#include <stdio.h>
#include <string.h>

struct student {
    int ID;
    char name[50];
    int age;
    char phone[15];
};

int main() {
    struct student sinhvien[50] = {
        {1, "Dinh Quoc Khanh", 18, "0388932784"},
        {2, "Pham Thanh Dat", 18, "0388932784"},
        {3, "Le Van C", 22, "0112233445"},
        {4, "Pham Thi D", 23, "0223344556"},
        {5, "Hoang Van E", 24, "0334455667"}
    };
    int soluongsinhvienhientai = 5;

    
    printf("Thong tin cac sinh vien:\n");
    for (int i = 0; i < soluongsinhvienhientai; i++) {
        printf("ID: %d\n", sinhvien[i].ID);
        printf("Name: %s\n", sinhvien[i].name);
        printf("Age: %d\n", sinhvien[i].age);
        printf("Phone: %s\n", sinhvien[i].phone);
    }

    
    if (soluongsinhvienhientai < 50) {
        struct student sinhvienmoi;
        printf("\nNhap thong tin sinh vien moi:\n");
        
        printf("ID: ");
        scanf("%d", &sinhvienmoi.ID);
        getchar(); 
        printf("Name: ");
        fgets(sinhvienmoi.name, sizeof(sinhvienmoi.name), stdin);
        sinhvienmoi.name[strcspn(sinhvienmoi.name, "\n")] = 0; 

        printf("Phone: ");
        scanf("%s", sinhvienmoi.phone);

        int vitri_chen;
        printf("Nhap vi tri chen (0-%d): ", soluongsinhvienhientai);
        scanf("%d", &vitri_chen);

        if (vitri_chen < 0 || vitri_chen > soluongsinhvienhientai) {
            printf("Vi tri chen khong hop le.\n");
        } else {
           
            for (int i = soluongsinhvienhientai; i > vitri_chen; i--) {
                sinhvien[i] = sinhvien[i - 1];
            }
            sinhvien[vitri_chen] = sinhvienmoi; 
            soluongsinhvienhientai++; 
        }
    } else {
        printf("Danh sach sinh vien da day, khong the them moi.\n");
    }

    
    printf("\nThong tin cac sinh vien sau khi chen:\n");
    for (int i = 0; i < soluongsinhvienhientai; i++) {
    	sinhvien[i].ID = i + 1;
        printf("ID: %d\n", sinhvien[i].ID);
        printf("Name: %s\n", sinhvien[i].name);
        printf("Age: %d\n", sinhvien[i].age);
        printf("Phone: %s\n", sinhvien[i].phone);
    }

    return 0;
}

