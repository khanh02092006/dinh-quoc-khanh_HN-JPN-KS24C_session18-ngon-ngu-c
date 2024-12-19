#include <stdio.h>
#include <string.h>
struct student{
	char name[50];
	int age;
	char phone[15];
};
int main(){
	struct student student1;
	strcpy(student1.name," dinh quoc khanh");
	student1.age=20;
	strcpy(student1.phone,"0388932784");
	printf(" name:%s\n",student1.name);
	printf("age:%d\n",student1.age);
	printf("phone:%s\n",student1.phone);
	return 0;
	}
