#include <stdio.h>
#include <string.h>
struct student{
	char name[50];
	int age;
	char phone;

};
int main(){
	struct student student[5];
	for(int i=0;i<5;i++){
		printf( " nhap thong tin cho sinh vien %d\n",i+1);
		printf(" nhap ten :");
		fgets(student[i].name,sizeof(student[i].name),stdin);
		student[i].name[strcspn(student[i].name, "\n")] = 0;
		printf("Nhap tuoi: ");
        scanf("%d", &student[i].age);
        
        printf("Nhap so dien thoai: ");
        scanf("%s", student[i].phone);
        getchar();
        }
    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < 5; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("Name: %s\n", student[i].name);
        printf("Age: %d\n", student[i].age);
        printf("Phone Number: %s\n",student[i].phone);
        }
        return 0;
		}   
