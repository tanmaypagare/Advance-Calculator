#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[100];
    char stored_password[50];
    char input_password[50];

    fp = fopen("login.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, sizeof(line), fp))
    {
        // Check if line starts with PASSWORD=
        if (strncmp(line, "PASSWORD=", 9) == 0)
        {
            strcpy(stored_password, line + 9);

            // Remove newline character
            stored_password[strcspn(stored_password, "\n")] = '\0';
            break;
        }
    }

    fclose(fp);

    // Take password input from user
    printf("Enter password: ");
    scanf("%s", input_password);

    // Compare passwords
    if (strcmp(stored_password, input_password) == 0)
    {
        printf("Login Successful ✅\n");
    }
    else
    {
        printf("Wrong Password ❌\n");
    }

    return 0;
}
