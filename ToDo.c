#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char todo[100];

void menu();
void viewToDoS();
void addToDoS();
void deleteToDoS();
void resetToDoS();

void menu()
{
    system("color 0F");
    int choice;
start:
    system("cls");
    printf("\t\t<<-- ToDo LIST -->>\n\n");
    system("color 0F");
    printf("Instructions\n");
    printf("----------\n");
    printf("1. Add ToDoS\n");
    printf("2. View ToDoS\n");
    printf("3. Delete ToDos\n");
    printf("4. Reset ToDoS\n");
    printf("5. EXIT\n");
    system("color 0F");
    printf("\nChoose : ");
    fflush(stdin);
    scanf("%d", &choice);

    while (1)
    {
        switch (choice)
        {
        case 1:
            addToDoS();
            break;
        case 2:
            viewToDoS();
            break;
        case 3:
            deleteToDoS();
            break;
        case 4:
            resetToDoS();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Command\n");
            printf("Press any key to retry ");
            fflush(stdin);
            getch();
            goto start;
        }
    }
}

void viewToDoS()
{
    system("color 0F");
    FILE *file;
    system("cls");
    printf("\t\tYour ToDoS\n");
    printf("\t\t---------\n\n");
    file = fopen("todo.txt", "rb+");

    if (file == NULL)
    {
        printf("You don't have any ToDoS yet\n");
        printf("\nPress any key to continue ");
        fflush(stdin);
        getch();
        menu();
    }

    int i = 1;
    while (fread(&todo, sizeof(todo), 1, file))
    {
        printf("%d. %s", i, todo);
        i++;
    }

    fclose(file);
    printf("\nPress any key to continue ");
    fflush(stdin);
    getch();
    menu();
}

void addToDoS()
{
    system("color 0A");
    FILE *file;
    system("cls");
    char add = 'y';
    printf("\t\tAdd ToDoS\n");
    printf("\t\t---------\n\n");

    file = fopen("todo.txt", "ab+");

    while (add == 'y' || add == 'Y')
    {
        printf("Add a todo\n");
        fflush(stdin);
        fgets(todo, 100, stdin);

        fwrite(&todo, sizeof(todo), 1, file);

        printf("\nWant to add another?(y/n)");
        add = getch();
        printf("\n\n");
    }

    fclose(file);
    menu();
}

void deleteToDoS()
{
    system("color FC");
    FILE *file, *fite;
    system("cls");
    char del[100];
    printf("\t\tDelete ToDoS\n");
    printf("\t\t-----------\n\n");
    printf("Enter the ToDo you want to delete\n");
    fflush(stdin);
    fgets(del, 100, stdin);
    file = fopen("todo.txt", "rb+");
    fite = fopen("temp.txt", "wb+");
    int j = 0;
    while (fread(&todo, sizeof(todo), 1, file) == 1)
    {
        if (strcmp(todo, del) != 0)
        {
            fwrite(&todo, sizeof(todo), 1, fite);
        }
        if (strcmp(todo, del) == 0)
        {
            printf("\nYour ToDo was deleted successfully\n");
            j++;
        }
    }
    if (j > 0)
    {
        fclose(file);
        fclose(fite);
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        fflush(stdin);
        printf("\nPress any key to continue");
        getch();
        menu();
        menu();
    }
    fclose(file);
    fclose(fite);
    printf("\nThe ToDo you entered doesn't exist\n");
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
    fflush(stdin);
    printf("\nPress any key to continue");
    getch();
    menu();
}

void resetToDoS()
{
    system("color CF");
    FILE *file, *fite1;
    system("cls");
    printf("\t\tReset ToDoS\n");
    printf("\t\t-----------\n\n");
    printf("Do you want to reset your ToDoS list ?(y/n)");
    fflush(stdin);
    char a = getch();
    if (a == 'y' || a == 'Y')
    {
    }
    else
    {
        printf("\n\nPress any key to continue ");
        fflush(stdin);
        getch();
        menu();
    }

    file = fopen("todo.txt", "rb+");
    fite1 = fopen("temp1.txt", "wb+");

    while (fread(&todo, sizeof(todo), 1, file))
    {
        fwrite(&todo, sizeof(fite1), 1, fite1);
    }

    printf("\n\nYour ToDoS list has been reset\n");
    fclose(file);
    fclose(fite1);
    remove("todo.txt");
    rename("temp1.txt", "todo.txt");
    fflush(stdin);
    printf("\nPress any key to continue");
    getch();
    menu();
}

int main()
{
    //To Do list in C
    menu();
    return 0;
}
