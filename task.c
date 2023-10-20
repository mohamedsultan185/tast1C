// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

union ActivityFlag {
    int activeFlag;
    char flagChar[4];
};

void registerUser(struct User users[], union ActivityFlag *flag, int *userCount) {
    printf("Enter username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter password: ");
    scanf("%s", users[*userCount].password);
    
    printf("Enter activity flag (true/1 or false/0): ");
    scanf("%d", &flag->activeFlag);

    (*userCount)++;
    printf("Registration successful!\n");
}

int loginUser(struct User users[], union ActivityFlag flag, int userCount, char username[], char password[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (flag.activeFlag == 1) {
                return 1; // Active user, login successful
            } else {
                printf("User is not active. Please contact the administrator.\n");
                return 0; // Inactive user, login failed
            }
        }
    }
    return -1; // Invalid username or password, login failed
}

int main() {
    struct User users[100];
    union ActivityFlag flag;
    int userCount = 0;
    int choice;
    char username[50];
    char password[50];

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &flag, &userCount);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int loginStatus = loginUser(users, flag, userCount, username, password);
                if (loginStatus == 1) {
                    printf("Login successful!\n");
                } else if (loginStatus == 0) {
                    printf("Login failed. User is not active.\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
