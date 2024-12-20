#include <stdio.h>
#include <string.h>

struct Dish {
    int ID;
    char name[50];
    int gia;
};

struct Dish monan[100] = {
    {1, "Pho", 50000},
    {2, "Banh mi", 20000},
    {3, "Goi cuon", 30000},
    {4, "Com tam", 40000},
    {5, "Mi Quang", 45000}
};
int sizemax = 5;

void displaymenu() {
    printf("Menu mon an:\n");
    for (int i = 0; i < sizemax; i++) {
        printf("ID: %d, Ten: %s, Gia: %d\n", monan[i].ID, monan[i].name, monan[i].gia);
    }
}

void themphan_mon(int index, int ID, char name[], int gia) {
    if (sizemax < 100) {
        for (int i = sizemax; i > index; i--) {
            monan[i] = monan[i - 1];
        }
        monan[index].ID = ID;
        strcpy(monan[index].name, name);
        monan[index].gia = gia;
        sizemax++;
    } else {
        printf("Mang day\n");
    }
}

void sua_phantu(int index, int ID, char name[], int gia) {
    if (index >= 0 && index < sizemax) {
        monan[index].ID = ID;
        strcpy(monan[index].name, name);
        monan[index].gia = gia;
    } else {
        printf("Khong hop le\n");
    }
}

void xoa_phantu(int index) {
    if (index >= 0 && index < sizemax) {
        for (int i = index; i < sizemax - 1; i++) {
            monan[i] = monan[i + 1];
        }
        sizemax--;
    } else {
        printf("Khong hop le\n");
    }
}

void sap_xep_theogia(int check) {
    for (int i = 0; i < sizemax - 1; i++) {
        for (int j = i + 1; j < sizemax; j++) {
            if ((check == 1 && monan[i].gia > monan[j].gia) || (check == 0 && monan[i].gia < monan[j].gia)) {
                struct Dish temp = monan[i];
                monan[i] = monan[j];
                monan[j] = temp;
            }
        }
    }
}

void sap_xep_theoten() {
    for (int i = 0; i < sizemax - 1; i++) {
        for (int j = i + 1; j < sizemax; j++) {
            if (strcmp(monan[i].name, monan[j].name) > 0) {
                struct Dish temp = monan[i];
                monan[i] = monan[j];
                monan[j] = temp;
            }
        }
    }
}

void tim_kiem_tuyen_tinh(char name[]) {
    int found = 0;
    for (int i = 0; i < sizemax; i++) {
        if (strcmp(monan[i].name, name) == 0) {
            printf("Tim thay: ID: %d, Ten: %s, Gia: %d\n", monan[i].ID, monan[i].name, monan[i].gia);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an trong menu.\n");
    }
}

void tim_kiem_nhi_phan(char name[]) {
    sap_xep_theoten();
    int left = 0, right = sizemax - 1;
    int found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(monan[mid].name, name);
        if (cmp == 0) {
            printf("Tim thay: ID: %d, Ten: %s, Gia: %d\n", monan[mid].ID, monan[mid].name, monan[mid].gia);
            found = 1;
            break;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an trong menu.\n");
    }
}

int main() {
    int lua_chon;
    do {
        printf("\nMenu\n");
        printf("1. In ra gia tri cac phan tu trong menu mon an\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                displaymenu();
                break;
            case 2: {
                int index, gia, ID;
                char name[50];
                printf("Nhap vi tri muon them: ");
                scanf("%d", &index);
                printf("Nhap ID: ");
                scanf("%d", &ID);
                printf("Nhap ten mon an: ");
                scanf("%s", name);
                printf("Nhap gia mon an: ");
                scanf("%d", &gia);
                themphan_mon(index, ID, name, gia);
                break;
            }
            case 3: {
                int index, gia, ID;
                char name[50];
                printf("Nhap vi tri muon sua: ");
                scanf("%d", &index);
                printf("Nhap ID moi: ");
                scanf("%d", &ID);
                printf("Nhap ten mon an moi: ");
                scanf("%s", name);
                printf("Nhap gia moi: ");
                scanf("%d", &gia);
                sua_phantu(index, ID, name, gia);
                break;
            }
            case 4: {
                int index;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &index);
                xoa_phantu(index);
                break;
            }
            case 5: {
                char option;
                printf("Chon kieu sap xep (a: Giam dan, b: Tang dan): ");
                scanf(" %c", &option);
                if (option == 'a') {
                    sap_xep_theogia(1);
                } else if (option == 'b') {
                    sap_xep_theogia(0);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            }
            case 6: {
                char option, name[50];
                printf("Chon kieu tim kiem (a: Tuyen tinh, b: Nhi phan): ");
                scanf(" %c", &option);
                printf("Nhap ten mon an can tim: ");
                scanf("%s", name);
                if (option == 'a') {
                    tim_kiem_tuyen_tinh(name);
                } else if (option == 'b') {
                    tim_kiem_nhi_phan(name);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 7);

    return 0;
}

			
			
