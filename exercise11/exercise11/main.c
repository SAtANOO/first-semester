//
//  main.c
//  exercise11
//
//  Created by Ashish Acharya on 08/01/2024.
//

#include <string.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

typedef struct {
    int day, month, year;
} TDate;

typedef struct {
    int key;
    char name[50];
    TDate birthdate;
} TBirthday;

void save_array(TBirthday* p, int n) {
    FILE* fp = fopen("datas.bin", "wb");
    if (fp == NULL) {
        printf("Error\n");
        return;
    }
    fwrite(p, sizeof(TBirthday), n, fp);
    fclose(fp);
}

int read_array(TBirthday* p) {
    FILE* fp = fopen("datas.bin", "rb");
    if (fp == NULL) {
        printf("Error\n");
        return 0;
    }
    int count = 0;
    while (fread(p, sizeof(TBirthday), 1, fp) == 1) {
        p++;
        count++;
    }
    fclose(fp);
    return count;
}

int age(TDate a) {
    time_t rt;
    time(&rt);
    struct tm* actual = localtime(&rt);
    int year = actual->tm_year + 1900;
    int month = actual->tm_mon + 1;
    int day = actual->tm_mday;

    int age = year - a.year - 1;
    if (month > a.month || (month == a.month && day >= a.day))
        age += 1;
    return age;
}

TBirthday ask_birthday(int key) {
    TBirthday b;
    printf("Name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(b.name, sizeof(b.name), stdin);
    printf("Birth date [dd/mm/yyyy] ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d/%d/%d", &b.birthdate.day, &b.birthdate.month, &b.birthdate.year);
    b.key = key;
    return b;
}

void print_birthday(TBirthday b) {
    printf("{%d} %s was born in %d/%d/%d (%d years old)\n", b.key, b.name, b.birthdate.day, b.birthdate.month, b.birthdate.year, age(b.birthdate));
}

void search(TBirthday* p) {
    char name[20];
    printf("Name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(name, sizeof(name), stdin);
    for (; p->key != 0; p++) {
        if (strcmp(name, p->name) == 0) {
            print_birthday(*p);
            return;
        }
    }
    printf("Name not found\n");
}


void change_birthdate(TBirthday* birthdate, TBirthday* Last) {
    if (Last == birthdate) {
        printf("#This birthdate doesn't exist in this list.\n");
        return;
    }

    int key;
    printf("Birthdate keys to change: ");
    scanf("%d", &key);
    TBirthday* ptr;
    for (ptr = birthdate; ptr < Last; ptr++) {
        if (ptr->key == key) {  // is equall to (*ptr).key==key
            printf("# Birthdate keys to change - [%4d] %s\n", ptr->key, ptr->name);
            TBirthday new = ask_birthday(key);
            *ptr = new;
            return;
        }
    }
    printf("The Birthdate with the key %d doesn't exist.\n", key);
}

TBirthday* remove_birthday(TBirthday* birthdate, TBirthday* actual) {
    int key;
        printf("Birthdate keys to remove: ");
        scanf("%d", &key);

        for (int i = 0; i < actual; i++) {
            if (birthdate[i].key == key) {
                for (int j = i; j < actual - 1; j++) {
                    birthdate[j] = birthdate[j + 1];
                }
                actual--;
                printf("Birthdate with key %d removed successfully.\n", key);
                return actual;
            }
        }

        printf("The Birthdate with the key %d doesn't exist.\n", key);
        return actual;
    }

int menu() {
    printf("0) Exit\n");
    printf("1) Add - add a birthday\n");
    printf("2) Search -search by name\n");
    printf("3) List - list all birthdays\n");
    printf("4) Change - change a birthday\n");
    printf("5) Remove - remove a birthday\n");
    int op;
    printf("Option: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &op);
    return op;
}

int main() {
    TBirthday bs[MAX];
    int actual = read_array(bs);
    while (1) {
        int op = menu();
        switch (op) {
        case 0:
            save_array(bs, actual);
            return 0;
        case 1:
            bs[actual] = ask_birthday(actual + 1);
            actual++;
            break;
        case 2:
            search(bs);
            break;
        case 3:
            for (int i = 0; i < actual; i++)
                print_birthday(bs[i]);
            break;

        case 4:
            change_birthdate(bs, actual);
            break;

        case 5:
            actual = remove_birthday(bs, actual);
            break;
        default:
            printf("Invalid option\n");
        }
    }
}
