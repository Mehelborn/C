#include <stdio.h>
#include <stdlib.h>

#define LN_SIZE 20

struct students {
	char lastname[LN_SIZE];
	short rbnum; //student record book number
	short rlang, maths, proging, phys; //Grades of 4 subjects
};
struct students student;

FILE *file_ptr;

void new_table(void);
void print_table(void);
void add_new_note(void);

int main(void) {
    char the_key;
    printf("1. Create a new table in a file;\n");
    printf("2. Print the table;\n");
    printf("3. Add a new student to the beginning;\n");
    printf("4. Exit.\n");
    while(1) {
        switch(the_key) {
        case 1:
            new_table();
            break;
        case 2:
            print_table();
            break;
        case 3:
            add_new_note();
            break;
        case 4: 
            return 0;
        default:
            printf("ERROR: Please choose the option number.");
        }
    }
	return 0;
}

void new_table(void) {
    char exit_key;
    file_ptr = fopen("Students.dat", "wb");
    int i = 1;
    do {
        i++;
        clrscr();
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

        printf("Enter 'e' for exit\n");
        exit_key = getch();
    }
    while(exit_key != 'e');
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
        printf("\n\n%d. %-25s%-25h%-25h%-25h%-25h%-25h",
        i, student.lastname, &student.rbnum, &student.rlang,
        &student.maths, &student.proging, &student.phys);
        fread(&student, sizeof(student), 1, file_ptr);
        i++;
    }

    getch();
}
void add_new_note() {
  char exit_key;
  file_ptr = fopen("Students.dat", "wb");
  do {
        clrscr();
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

        printf("Enter 'e' for exit\n");
        exit_key = getch();
  }
  while(exit_key != 'e');
  fclose(file_ptr);
}


