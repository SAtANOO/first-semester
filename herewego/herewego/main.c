

   #include <stdio.h>
#define MAX 100
typedef enum{
    sun=1,mon,tues,wed,thu,fri,sat
    
}weekdays;
typedef struct{
    char name[50];
    char weekname[50];
    int days;
    weekdays week;
    short yes;
}class;
int menu(){
    printf("\t MENU.");
    printf("1:type the string..\n");
    printf("2:show the current string to the user..\n");
    printf("0:Save the string in the file.\n");
    printf("3:Read the saved string.\n");
    int choice;
    printf("Enter the choice:");
    scanf("%d",&choice);
    return choice;
}

void insert(class *Name, int *num){
    if (*num<=7) {
        
        printf("Enter the day:");
        scanf("%s",Name[*num].weekname);
    }
    
    printf("Enter the name:");
    scanf("%s",Name->name);
    
    
}
int save_string(char *name){
    FILE *fp=fopen("Name.txt","wb");
    if (fp==NULL) {
        printf("Error!");
        return -1;
    }
    fseek(fp, -2, SEEK_END);
    fwrite(name, sizeof(char), MAX, fp);
    printf("File saved successfully..\n");
    fclose(fp);
    return 0;
}
int load_name(char *name){
    FILE *ptr;
    ptr = fopen("Name.txt", "rb");
    if (ptr==NULL) {
        printf("Error opening file..\n");
        return -1;
        ptr=fopen("Name.txt", "wb");
        int a=0;
        fwrite(&a, sizeof(int), 1, ptr);
        ptr=fopen("Name.txt", "rb");
    }
    fseek(ptr,sizeof(int),SEEK_SET);
    fread(name,sizeof(char),MAX,ptr);
    fclose(ptr);
    printf("Events successfully loaded from %s.\n", name);
    return 0;
}
int main(int argc , char *argv[]){
    if (argc!=2) {
        printf("Error");
        return -1;
    }
    char name[MAX];
    int choice;
    do {
        choice=menu();
        switch (choice) {
            case 1:
                insert(name,&argc);
                break;
            case 0:
                save_string(name);
                break;
            case 3:
                load_name(name);
            default:
                break;
        }
    } while (1);
    
    
}



