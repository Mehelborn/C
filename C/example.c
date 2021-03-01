#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

const char filename[] = "session_results.dat";

struct session {
    char lastname[15];
    short cs, mt, en, ru, al;
    session* prev;
    session* next;
};

session* head = NULL;
session* tail = NULL;

void menu();
void createFile();
void printFile();
void search();
void csStudents();

void main() {    
    char c;
    while (1) {
        menu();
        puts("Choose the option number: ");
        c = _getch();
        switch (c) {
            case '1':
                createFile();
                puts("File 'session_results.dat' was created and saved");
                break;
            case '2':
                puts("The file:");
                printFile();
                break;
            case '3':
                search();
                break;
            case '4':
                puts("The best computer scientists:");
                csStudents();
                break;
            case '5':
                return;
        }
    }
}

void menu() {
    puts("\n1 - Create a new file");
    puts("2 - Print the file");
    puts("3 - Search");
    puts("4 - Print the best students in computer science");
    puts("5 - Exit\n");
}

void createFile() {
    session* p = head;
    while (p != NULL) {
        session* q = p;
        p = p->next;
        free(q); // Удаляем элемент списка из динамической памяти
    }
    head = NULL;
    tail = NULL;
    

    char selector;
    while (1) {
        puts("Enter '0' to return to menu or '1' to add a note");
        selector = _getch();
        if (selector == '1') {
            session* p = (session*)malloc(sizeof(session)); // Выделяем динамическую память
            printf("Student`s lastname: "); // Вводим все поля элемента списка
            scanf("%s", p->lastname);
            printf("Computer Science: ");
            scanf("%d", &p->cs);
            printf("Mathematics: ");
            scanf("%d", &p->mt);
            printf("English: ");
            scanf("%d", &p->en);
            printf("Russian: ");
            scanf("%d", &p->ru);
            printf("Linear Algebra: ");
            scanf("%d", &p->al);
            p->prev = NULL;
            p->next = NULL;
            if (head == NULL) // Если список пустой
                head = tail = p;
            else if (head->next == NULL) { // Если одна запись в списке
                p->next = head;
                head->prev = p;
                head = p;
            }
            else {
                p->prev = tail->prev;
                p->next = tail;
                p->prev->next = p;
                tail->prev = p;
            }
        }
        else if (selector == '0') break;
    }

    FILE* f; // файл
    f = fopen(filename, "w"); // открываем файл для записи
    session* p = head;
    while (p != NULL) { // Цикл по всем элементам списка
        fprintf(f, "%s %d %d %d %d %d\n", p->lastname, p->cs, p->mt, p->en, p->ru, p->al);
        p = p->next;
    }
    fclose(f);
    printf("The list saved in %s\n", filename);
    
}

void printFile() {
    session* p = head;
    printf("%-15s%-25s%-20s%-20s%-20s%-20s", "lastname", "Computer Science", "Mathematics", "English", "Russian", "Linear Algebra");
    while (p != NULL) { 
        printf("%-15s", p->lastname);
        printf("%-25d", p->cs);
        printf("%-20d", p->mt);
        printf("%-20d", p->en);
        printf("%-20d", p->ru);
        printf("%-20d\n", p->al);
        p = p->next;
    }
}

void search() {
    char lastname[50];
    printf("Student`s lastname: ");
    scanf("%s", lastname);
    session* p = head;
    int found = 0;
    printf("%-15s%-25s%-20s%-20s%-20s%-20s", "lastname", "Computer Science", "Mathematics", "English", "Russian", "Linear Algebra");
    while (p != NULL) {
        if (!strcmp(p->lastname, lastname)) {
            printf("%-15s", p->lastname);
            printf("%-25d", p->cs);
            printf("%-20d", p->mt);
            printf("%-20d", p->en);
            printf("%-20d", p->ru);
            printf("%-20d\n", p->al);
            found = 1;
            break;
        }
        p = p->next;
    }
    if (found == 0)
        puts("Can`t find such student");
}

void csStudents() {
    session* p = head;
}