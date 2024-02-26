//
//  main.c
//  projectfinal
//

#include <stdio.h>
#include<time.h>
#include <string.h>
#define MAX_EVENT 10
#define str_max 50
#define maximum_hallcapacity 500
typedef enum {
    B6 = 0,
    B12,
    B16
}eventclassification;  // the enumerated classsification is created...

typedef struct Date {
    int hour, minutes, day, months, year;

}Date; // structure for date is created..

 typedef struct EventRegister {
    char Name[50];
    char artist_group[50];
    eventclassification classification;
    struct Date event_Date;
    int duration;
    int capacity;
    int available_tickets;
}EventRegister;

int validClassification(eventclassification num) { //validating the classification..
    switch (num) {
    case B6:
    case B12:
    case B16:
        return 1;
    default:
        printf("Invalid option.\n");
        return 0;
    }
}

int validDate(Date eventdate) {   //validating the date
    if (eventdate.day >= 1 && eventdate.day <= 31 && eventdate.months >= 1 && eventdate.months <= 12 && eventdate.year >= 2023 && eventdate.months <= 2024) return 1;
    else {
        printf("Invalid Date\n");
        return 0;
    }
}
int validCapacity(int capacity) { // validate capacity
    if (capacity <= maximum_hallcapacity) {
        return 1;
    }
    else {
        printf("Maximum capacity reached..\n");
        return 0;
    }
}
int validDuration(int duration) { //validate duration
    if (duration >= 30) {
        return 1;
    }
    else
        printf("!Too few time for the program..\n");
    return 0;
}


int InsertEvent(EventRegister Event[], int *Numrecords) {
    if (*Numrecords >= MAX_EVENT) {
        printf("No capacity to insert new event.\n");
        return -1;
    }
    printf("Type event name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(Event[*Numrecords].Name, str_max, stdin);
    printf("Type artist name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(Event[*Numrecords].artist_group, str_max, stdin);
    printf("Choose classification:\n0)B6\n1)B12\n2)B16\nClassification: ");
    do {
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &Event[*Numrecords].classification);
    } while (!validClassification(Event[*Numrecords].classification));
    printf("Enter Date of Event[dd/mm/yyyy]\t[2023||2024]: ");
    do {
        fseek(stdin, 0, SEEK_END);
        scanf("%d/%d/%d", &Event[*Numrecords].event_Date.day, &Event[*Numrecords].event_Date.months, &Event[*Numrecords].event_Date.year);
    } while (!validDate(Event[*Numrecords].event_Date));
    printf("Type time of Event [hh:mm]: ");
    scanf("%d:%d", &Event[*Numrecords].event_Date.hour, &Event[*Numrecords].event_Date.minutes);

    printf("Enter the duration in [mm][>=30 min]:");
    do {
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &Event[*Numrecords].duration);
    } while (!validDuration(Event[*Numrecords].duration));

    printf("Enter the capacity of the hall [=<500] : ");

    do {
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &Event[*Numrecords].capacity);
    } while (!validCapacity(Event[*Numrecords].capacity));
    
    Event[*Numrecords].available_tickets=Event[*Numrecords].capacity;
    return 0;
}



void SaveEvents(EventRegister* events, int Numrecords) {
    FILE* fptr = fopen("events.dat", "wb");// opening the binary file for writting..
    if (fptr == NULL) {

        printf("Error! file is not opened..\n");
        return;
    }
    fwrite(&Numrecords, sizeof(int), 1, fptr); //writting the number of records to the file..
    fwrite(events, sizeof(EventRegister), Numrecords, fptr);//writting the events records to the file..
    fclose(fptr);
    printf("Events saved successfully...\n");

}

// to display the menu...
int menu() {
    printf("\n\t\tMENU.\n");
    printf("---------------------------------------------\n");
    printf("[1] Insert information about a new event.\n");
    printf("[2] List information about a specific event. \n");
    printf("[0] Exit and save event information to file. \n");
    printf("[3] Cancel an event.\n");
    printf("[4] Filter events by ratings.\n");
    printf("[5] Register ticket purchases.\n");
    printf("---------------------------------------------\n");
    int choice;
    printf("enter your choice:");
    scanf("%d", &choice);
    return choice;
}


int LoadEvents(EventRegister events[], char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        file = fopen(filename, "wb");
        int a = 0;
        fwrite(&a, sizeof(int), 1, file);
        fclose(file);
        file = fopen(filename, "rb");
    }
    if (file != NULL) {
        int numRecords;

        // to read the number of records from the file
        fread(&numRecords, sizeof(int), 1, file);

        // to check the number of records within boundary
        if (numRecords > MAX_EVENT) {
            printf("! Error maximum Events reached..\n");
            fclose(file);
            return 0;
        }
        fseek(file, sizeof(int), SEEK_SET);
        fread(events, sizeof(EventRegister), numRecords, file);
        fclose(file);
        printf("Events successfully loaded from %s.\n", filename);
        return numRecords;
    }

    else {
        printf("Unable to open %s for reading.\n", filename);
        return 0;

    }

}

char* class(eventclassification a) {
    switch (a) {
    case B6:
        return "B6";
    case B12:
        return "B12";
    case B16:
        return "B16";
    default:
        return "Invalid!";
    }
}

int PrintEvent(EventRegister events[], int* Numrecords, char* name) {
    for (int i = 0; i < * Numrecords; i++) {
        if (strcmp(events[i].Name, name) == 0) {
            // To Print event details
            printf("Name: %s\n", events[i].Name);
            printf("Artist: %s\n", events[i].artist_group);
            printf("Classification: %s\n", class(events[i].classification));
            printf("Date: %02d:%02d %02d/%02d/%d\n", events[i].event_Date.hour, events[i].event_Date.minutes,
                events[i].event_Date.day, events[i].event_Date.months, events[i].event_Date.year);
            printf("Duration: %d minutes\n", events[i].duration);
            printf("Capacity: %d\n", events[i].capacity);
            printf("Tickets Available: %d\n", events[i].available_tickets);
            return 0;
        }
    }
    printf("Event not found.\n");
    return 0;
}

EventRegister* remove_events(EventRegister* Events, char* Last, char *Name) {
    int key;
    printf("Events classification to remove: ");
    scanf("%d", &key);

    EventRegister* ptr;
    for (ptr = Events; ptr < Last; ptr++) {
        if (ptr->classification == key) {
            printf("Removing events - [%4d] %s\n", ptr->classification, ptr->Name);

            for (EventRegister* next = ptr + 1; next < Last; ptr++, next++) {
                *ptr = *next;
            }

            return Last - 1;
        }
    }

    printf("Events with the key %d not found\n", key);
    return Last;
}
void BuyTicket(EventRegister events[], int numEvents, char* eventName, int numTickets) {
    for (int i = 0; i < numEvents; i++) {
        if (strcmp(events[i].Name, eventName)==0) {
            if (events[i].event_Date.year >= 2024) {
                if (numTickets <= events[i].available_tickets) {
                    events[i].available_tickets -= numTickets;
                    printf("%d ticket(s) bought for event %s.\n", numTickets, eventName);
                } else {
                    printf("Not enough tickets available for event %s.\n", eventName);
                }
            } else {
                printf("Event %s has already occurred.\n", eventName);
            }
            return;
        }
    }
    printf("Event %s not found.\n", eventName);
}


void FilterEvents(EventRegister* events, int num_records, eventclassification event_classification) {
    printf("Filtered Events (Classification %d):\n", event_classification);

    for (int i = 0; i < num_records; i++) {
        if (events[i].classification == event_classification && events[i].event_Date.year >= 2024 && events[i].event_Date.day > 0 && events[i].available_tickets > 0) {
             
            PrintEvent(events, &num_records, events[i].Name);
        }
    }
}
int main() {
    EventRegister Events[MAX_EVENT];
    int numRecords = LoadEvents(Events, "events.dat");
    char Eventname[50];
    int choice;
    do {
        choice = menu();
        switch (choice) {
        case 1:
            InsertEvent(Events, &numRecords);
            numRecords++;
            break;
        case 2:
            printf("Enter the name of the event you want to print:");
            fseek(stdin, 0, SEEK_END);
            fgets(Eventname,str_max,stdin);
            PrintEvent(Events, &numRecords, Eventname);
            break;
                
            case 3: {
                char name[50];
                printf("Enter the name of the event to remove: ");
                fseek(stdin, 0, SEEK_END);
                fgets(name, 50, stdin);
                EventRegister* last = remove_events(Events, Events + numRecords , name);
                if (last != Events + numRecords) {
                    numRecords--;
                }
                break;
            }

            case 4: {
                int classification_choice;
                printf("Enter the event classification (0 for B6, 1 for B12, 2 for B16): ");
                scanf("%d", &classification_choice);
                eventclassification event_classification;

                switch (classification_choice) {
                case 0:
                    event_classification = B6;
                    break;
                case 1:
                    event_classification = B12;
                    break;
                case 2:
                    event_classification = B16;
                    break;
                default:
                    printf("Invalid classification.\n");
                    continue;
                }

                FilterEvents(Events, numRecords, event_classification);
                break;
            }

            case 5:{
                printf("Enter the name of the event to buy tickets for: ");
                fseek(stdin, 0, SEEK_END);
                fgets(Eventname,str_max-1, stdin);
                
                int numTickets;
                printf("Enter the number of tickets to buy: ");
                scanf("%d", &numTickets);
                
                BuyTicket(Events, numRecords, Eventname, numTickets);
                break;
            }
            

        case 0:
            SaveEvents(Events, numRecords);
            printf(" number of saved event in the files %d ", numRecords);
            return 1;

        default:
            printf("!Invalid.. try again\n");
            break;
        }
    } while (1);
    return 0;
}
