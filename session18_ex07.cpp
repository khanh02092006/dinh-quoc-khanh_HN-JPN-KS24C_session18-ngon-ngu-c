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

    
    char tencan_xoa[50];
    printf("\nNhap ten sinh vien can xoa: ");
    getchar(); 
    fgets(tencan_xoa, sizeof(tencan_xoa), stdin);
    tencan_xoa[strcspn(tencan_xoa, "\n")] = 0; 

    int thay = 0;
    for (int i = 0; i < soluongsinhvienhientai; i++) {
        if (strcmp(sinhvien[i].name, tencan_xoa) == 0) {
            thay = 1;
           
            for (int j = i; j < soluongsinhvienhientai - 1; j++) {
                sinhvien[j] = sinhvien[j + 1];
            }
            soluongsinhvienhientai--; 
            break; 
        }
    }

    
    if (!thay) {
        printf("Sinh vien '%s' khong ton tai.\n", tencan_xoa);
    } else {
        printf("Da xoa sinh vien '%s'.\n", tencan_xoa);
    }

    
    printf("\nThong tin cac sinh vien sau khi xoa:\n");
    for (int i = 0; i < soluongsinhvienhientai; i++) {
        printf("ID: %d\n", sinhvien[i].ID);
        printf("Name: %s\n", sinhvien[i].name);
        printf("Age: %d\n", sinhvien[i].age);
        printf("Phone: %s\n", sinhvien[i].phone);
    }

    return 0;
}

	  		
	   
