#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define WEB 0
#define UK_LANG 1
#define PR_IS 2

typedef struct Student {
  char surname[12];
  int groupNumber;
  int marks[3];
} Student;

int enterNumber(int min, int max);
Student* createStud(char* name, int group, int marks[]);
void printAll(Student **students, int size);
void func1(Student **students, int size);
void func2(Student **students, int size);
void func3(Student **students, int size);
void func4(Student **students, int size);
void printMenu();
void printError();

int main() {
	int size = 30, count = 0, choice;
	Student **students = (Student**) malloc (size * sizeof(Student));
	char surName[12];
	int gNumber;
	int marks[3];
	
	while(1) {
		printMenu();
		choice = enterNumber(0, 5);
		switch (choice) {
			case 1:
				if (count < size) {
					printf("\nEnter student's surname: ");
					fflush(stdin);
					scanf("%s", surName);
					
					printf("\nEnter group number: ");
					gNumber = enterNumber(1, 4);
					
					printf("\nEnter Web-technology mark: ");
					scanf("%d",&marks[0]);
					
					printf("\nEnter Ukrainian mark: ");
					scanf("%d",&marks[1]);
					
					printf("\nEnter Project-mark: ");
					scanf("%d",&marks[2]);
					
					students[count] = createStud(surName, gNumber, marks);
					count++;
				}
			break;
			case 2:
				func1(students, count);
			break;
			case 3:
				func2(students, count);
			break;
			case 4:
				func3(students, count);
			break;
			case 5:
				func4(students, count);
			break;
			case 0:
				return 0;
			default: printError();
		}
	}
	return 0;
}

int enterNumber(int min, int max) {
	int res, num;
	
	do {
		res = scanf("%d", &num);
		if (res != 1 || num < min || num > max) printf("\nIncorrect number!\n->");
	} while (res != 1 || num < min || num > max);
	
	return num;
}

void printError() {
	printf("\nYou got an error");
}

void printMenu() {
	printf("\n 1 - Add student\n 2 - Debtors\n 3 - Percent of excellent students\n 4 - The best-passed subject\n 5 - The worst group\n 0 - Exit\n");
}

Student* createStud(char *name, int group, int marks[]) {
	int i;
	Student* student = NULL;
	if (!(student = (Student*)malloc(sizeof(Student)))) {
		exit(0);
	}
  
	strcpy(student->surname, name);
	student->groupNumber = group;
  
	for (i = 0; i < 3; i++) {
		student->marks[i] = marks[i];
	}

	return student;
}

void printAll(Student **students, int size) {
	int i;
	if (students) {
		for (int i = 0; i < size; i++) {
			printf("\n %s\t%d\t%d\t%d\t%d", students[i]->surname, students[i]->groupNumber, students[i]->marks[0], students[i]->marks[1], students[i]->marks[2]);
		}
	} else printError();
}

void func1(Student **students, int size) {
	int i;
	if (!students) {
		printError();
		return;
	}
	
	for (i = 0; i < size; i++) {
		if (students[i]->marks[0] < 50 || students[i]->marks[1] < 50 || students[i]->marks[2] < 50) {
		printf("\n %s", students[i]->surname);
		}
	}
}

void func2(Student **students, int size) {
	int i, n = 0;
	
	if (students) {
		for (int i = 0; i < size; i++) {
			if (students[i]->marks[0] >= 70 && students[i]->marks[1] >= 70 && students[i]->marks[2] >= 70) {
				n++;
			}
		}
		printf("\n Percent of best students: %f", (double)((n * 100) / size));
	} else printError();
}

void func3(Student **students, int size) {
	int i;
	double web = 0, uk = 0, pis = 0;

	if (!students) {
		printError();
		return;
	}

	for (int i = 0; i < size; i++) {
		web += students[i]->marks[WEB];
		uk += students[i]->marks[UK_LANG];
		pis += students[i]->marks[PR_IS];
	}

	web /= size;
	uk /= size;
	pis /= size;

	printf("\n Web-technology: %f\n Ukrainian: %f\n Project: %f",web, uk, pis);

	if (web == uk && web == pis) {
		printf("\nThe same");
	}
	else if (web >= uk && web >= pis) {
		printf("\nWeb-technology");
	}
	else if (uk >= web && uk >= pis) {
		printf("\nUkrainiane");
	}
	else if (pis >= uk && pis >= web) {
		printf("\nProject");
	}
}

void func4(Student **students, int size) {
	int i, group_1 = 0, group_2 = 0, group_3 = 0, group_4 = 0;
	double marks_1 = 0, marks_2 = 0, marks_3 = 0, marks_4 = 0;

	for (i = 0; i < size; i++) {
		switch (students[i]->groupNumber) {
			case 1:
			group_1++;
			marks_1 += students[i]->marks[0] + students[i]->marks[1] + students[i]->marks[2];
		break;
		case 2:
			group_2++;
			marks_2 += students[i]->marks[0] + students[i]->marks[1] + students[i]->marks[2];
			break;
		case 3:
			group_3++;
			marks_3 += students[i]->marks[0] + students[i]->marks[1] + students[i]->marks[2];
		break;
		case 4:
			group_4++;
			marks_4 += students[i]->marks[0] + students[i]->marks[1] + students[i]->marks[2];
		break;
		}
	}

	marks_1 /= group_1 * 3;
	marks_2 /= group_2 * 3;
	marks_3 /= group_3 * 3;
	marks_4 /= group_4 * 3;

	printf("\n Group 1: %f\n Group 2: %f\n Group 3: %f\n Group 4: %f", marks_1, marks_2, marks_3, marks_4);

	if (marks_1 <= marks_2 && marks_1 <= marks_3 && marks_1 <= marks_4) {
		printf("\n Group 1");
	}
	else if (marks_2 <= marks_1 && marks_2 <= marks_3 && marks_2 <= marks_4) {
		printf("\n Group 2");
	}
	else if (marks_3 <= marks_1 && marks_3 <= marks_2 && marks_3 <= marks_4) {
		printf("\n Group 3");
	}
	else if (marks_4 <= marks_1 && marks_4 <= marks_2 && marks_4 <= marks_3) {
		printf("\n Group 4");
	}
}
