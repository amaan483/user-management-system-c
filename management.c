#include<stdio.h>
#include<unistd.h>
#include<conio.h>
#include<string.h>

#define MAX_USERS 10

typedef struct {
    char username[30];
    char password[30];
}user;

user users[MAX_USERS];
int user_count = 0;

void Register();
int login();

int main() {
    int option;
    int user_index;
    while(1) {
    printf("Welcome to user management.\n");
    printf("1. Register\n2. Login\n3. Exit\n");
    printf("Select an option : ");
    scanf("%d", &option);
    getchar();//consume extra enter
    switch(option) {
        case 1:
        Register();
        break;
        case 2:
        user_index = login();
        if(user_index>=0) {
            printf("Login successful!\n Welcome, %s!\n", users[user_index].username);
        }
        else {
            printf("Login failed! Incorrect username or password.\n");
        }
        break;
        case 3:
        printf("Exiting program.");
        return 0;
        break;
        default:
        printf("Inavlid option, Please try again.\n");
        break;
    }
    }
    
    return 0;
}

void fix_fgets_input(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void input_password(char *password) {
    char ch;
    int i=0;
    printf("Enter password : ");
    while(1) {
        ch = getch();
        if(ch == 13) {
            break;
        }
        else if(ch == 8) {
            if(i>0) {
                i--;
                printf("\b \b");
            }
        }
        else if(i<29) {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i]='\0';
    printf("\n");
}

void Register() {
    if(user_count == MAX_USERS) {
        printf("Maximum %d users are supported! No more registrations Allowed!!!\n", MAX_USERS);
        return;
    }
    int new_index = user_count;
    printf("Regitser a new user.\n");
    printf("Enter a new user : ");
    fgets(users[new_index].username, 30, stdin);
    fix_fgets_input(users[new_index].username);
    input_password(users[new_index].password);
    user_count++;
    printf("Registration successful.\n");
}

int login() {
    char username[30];
    char password[30];

    printf("Enter username : \n");
    fgets(username, 30, stdin);
    fix_fgets_input(username);
    input_password(password);
    for(int i=0; i<user_count; i++) {
        if(strcmp(username, users[i].username)==0 && strcmp(password, users[i].password)==0) {
            return i;
        }
    }
    return -1;
}





