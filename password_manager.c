#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

// type definition for saved password
typedef struct pass{
    char service_name[100];
    char username[100];
    char password[100];
} saved;

// function to save a new password
void saveNew(){
    saved newpass, temp;
    
    printf("Enter service name: ");
    gets(newpass.service_name);
    printf("Username: ");
    gets(newpass.username);
    printf("Password: ");
    gets(newpass.password);

    FILE *f;
    f = fopen("passwords", "rb");
    if(f){
        fflush(stdin);
        while(fread(&temp, sizeof(saved), 1, f) == 1){
            if(!strcmp(temp.service_name, newpass.service_name) &&
               !strcmp(temp.username, newpass.username)){
                    printf("Username already exists...\n");
                    printf("Enter any key to continue...");
                    _getch();
                    return;
               }
        }
        fclose(f);
        
    }
    
    FILE *f1;
    f1 = fopen("passwords", "ab+");
    if(!f1){
        printf("Failed to retrieve passwords file!");
        sleep(3);
        return;
    }
    fwrite(&newpass, sizeof(saved), 1, f1);
    fflush(stdin);

    printf("Password saved!\n");
    
    fclose(f1);

    printf("Enter any key to continue...");
    _getch();
}

// function to delete a saved password
void deletePassword(){
    saved temp;

    FILE *f;
    f = fopen("passwords", "rb");
    if(!f){
        printf("Failed to retrieve passwords file!");
        sleep(3);
        return;
    }

    FILE *f2;
    f2 = fopen("temp", "wb+");
    if(!f2){
        printf("File Error...");
        sleep(3);
        return;
    }
    char service_name[100];
    int flag = 0;

    printf("Enter the service name: ");
    gets(service_name);
    
    char username[100];
    printf("Username: ");
    gets(username);
    
    fflush(stdin);
    while(fread(&temp, sizeof(saved), 1, f) == 1){
        if(strcmp(temp.service_name, service_name) != 0){
            fwrite(&temp, sizeof(saved), 1, f2);
        }
        if(strcmp(temp.service_name, service_name) == 0){
            if(strcmp(temp.username, username) == 0){
                flag = 1;
                break;
            }
            else
                fwrite(&temp, sizeof(saved), 1, f2);
        }
    }
    fclose(f);
    fclose(f2);
    if(flag){
        remove("passwords");
        rename("temp", "passwords");
        printf("Password deleted successfully!\n");
    }
    else{
        remove("temp");
        printf("Password not found!\n");
    }
    printf("Enter any key to continue...");
    _getch();
}
// function to modify a saved password
void modifyPassword(){
    FILE *f;
    f = fopen("passwords", "rb+");
    if(!f){
        printf("Failed to retrieve passwords file!");
        sleep(3);
        return;
    }
    saved temp, newpass;
    char service_name[100];
    int flag = 0;

    printf("Enter the service name: ");
    gets(service_name);

    char username[100];
    printf("Username: ");
    gets(username);

    fflush(stdin);
    while(fread(&temp, sizeof(saved), 1, f) == 1){
        if(strcmp(temp.service_name, service_name) == 0){
            if(strcmp(temp.username, username) == 0){
                strcpy(newpass.service_name, temp.service_name);
                strcpy(newpass.username, temp.username);
                printf("New Password: ");
                gets(newpass.password);
                fseek(f, -sizeof(saved), SEEK_CUR);
                fwrite(&newpass, sizeof(saved), 1, f);
                flag = 1;
                break;
            }
        }
        fflush(stdin);
    }
    if(flag)
        printf("Password updated successfully!\n");
    else
        printf("Password not found!\n");
    fclose(f);

    printf("Enter any key to continue...");
    _getch();
}

// function to find a saved password
void findPassword(){
    saved temp;
    
    FILE *f;
    f = fopen("passwords", "rb");
    if(!f){
        printf("Failed to retrieve passwords file!");
        sleep(3);
        return;
    }

    char service_name[100];
    printf("Enter the service name: ");
    gets(service_name);

    int flag = 0;

    char username[100];
    printf("Username: ");
    gets(username);

    fflush(stdin);
    while(fread(&temp, sizeof(saved), 1, f) == 1){
        if(strcmp(temp.service_name, service_name) == 0){
            if(strcmp(temp.username, username) == 0){
                system("cls");
                printf("Service name: %s\n", temp.service_name);
                printf("Username: %s\n", temp.username);
                printf("Password: %s\n", temp.password);
                flag = 1;
                break;
            }
        }
    }
    fclose(f);
    if(!flag)
        printf("Record not found!\n");
    printf("Enter any key to continue...");
    _getch();
}

// function to list all saved usernames
void display(){
    saved temp;

    FILE *f;
    f = fopen("passwords", "rb");
    if(!f){
        printf("Failed to retrieve passwords file!");
        sleep(3);
        return;
    }
    while(fread(&temp, sizeof(saved), 1, f) == 1){
        printf("Service: %s\n", temp.service_name);
        printf("Username: %s\n\n", temp.username);
    }
    fclose(f);
    printf("Enter any key to continue...");
    _getch();
}

// driver code

char * display_msg = "[1] to save new password"
"[2] to modify a password"
"[3] to delete a password"
"[4] to find a password"
"[5] to display all passwords"
"[6] to exit."

int main(){

    while(1){

        fflush(stdin);
        char x;
        printf(display_msg);
	char c;
	scanf("%d", &c);


	switch(x){
            case '1':
                saveNew();
                break;
            case '2':
                modifyPassword();
                break;
            case '3':
                deletePassword();
                break;
            case '4':
                findPassword();
                break;
            case '5':
                display();
                break;
            case '6':
                printf("Adios...");
                return 0;
            default:
                printf("Invalid choice.");
                sleep(3);
                break;
        }
    }
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
