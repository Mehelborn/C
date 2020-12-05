#include <stdio.h>
#include <stdlib.h>

#define LN_SIZE 20

struct students {
	char lastname[LN_SIZE];
	int rbnum; //student record book number
	int rlang, maths, proging, phys; //Grades of 4 subjects
};
struct students student;

FILE *file_ptr;

void new_table(void);
void print_table(void);
void add_new_note(void);

int main(void) {
    int the_key;
    printf("1. Create a new table in a file;\n");
    printf("2. Print the table;\n");
    printf("3. Add a new student to the beginning;\n");
    printf("4. Exit.\n");
    scanf("%d", &the_key);
    if(the_key == 1) {
        new_table();    
    }
    else if(the_key == 2) {
        print_table();
    }
    else if(the_key == 3) {
        add_new_note();
    }
    else if(the_key == 4) {
        return 0;
    }
    else printf("ERROR: Please choose the option number.");
	return 0;
}

void new_table(void) {
    int exit_key;
    file_ptr = fopen("Students.dat", "wb");
    int i = 0;
    do {
        i++;
        printf("\nEnter information about a student");
        printf("\n%d. Lastname: ", i);
        scanf("%s", student.lastname);
        printf("\nRecord book number: ");
        scanf("%6d", &student.rbnum);
        printf("\nRussian language exam grade: ");
        scanf("%1d", &student.rlang);
        printf("\nMaths exam grade: ");
        scanf("%1d", &student.maths);
        printf("\nProgramming exam grade: ");
        scanf("%1d", &student.proging);
        printf("\nPhysics exam grade: ");
        scanf("%1d", &student.phys);

        fwrite(&student, sizeof(student), 1, file_ptr);

        printf("Enter 0 for exit or 1 to continue...\n");
        scanf("%d", &exit_key);
    }
    while(exit_key != 0);
    fclose(file_ptr);
}

void print_table(void) {
    file_ptr = fopen("Students.dat", "rb");

    fread(&student, sizeof(student), 1, file_ptr);
    
    printf("%-25s%-25s%-25s%-25s%-25s%-25s", 
            "Lastname", "RB number", "Russian language", 
            "Mathematics", "Programming", "Physics");
    int i = 1;
    while(!feof(file_ptr)) {
        printf("\n\n%d. %-25s%-25d%-25d%-25d%-25d%-25d",
        i, student.lastname, student.rbnum, student.rlang,
        student.maths, student.proging, student.phys);
        fread(&student, sizeof(student), 1, file_ptr);
        i++;
    }

    getchar();
}
void add_new_note() {
  int exit_key;
  file_ptr = fopen("Students.dat", "wb");
  do {
        printf("\nEnter information about a student");
        printf("\nLastname: ");
        scanf("%s", student.lastname);
        printf("\nRecord book number: ");
        scanf("%6d", &student.rbnum);
        printf("\nRussian language exam grade: ");
        scanf("%1d", &student.rlang);
        printf("\nMaths exam grade: ");
        scanf("%1d", &student.maths);
        printf("\nProgramming exam grade: ");
        scanf("%1d", &student.proging);
        printf("\nPhysics exam grade: ");
        scanf("%1d", &student.phys);

        fwrite(&student, sizeof(student), 1, file_ptr);

        printf("Enter 0 for exit or 1 to continue...\n");
        scanf("%d", &exit_key);
  }
  while(exit_key != 0);
  fclose(file_ptr);
}