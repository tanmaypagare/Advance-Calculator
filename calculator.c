#include <stdio.h>
#include <string.h>

int calculation()
{
    for (int i = 1;; i++)
    {
        int n1, n2, n3, n4;
        printf("WHEN YOU WANT TO EXIT PRESS 'CTRL + C'\n");
        printf("ENTER THE FIRST NUMBER :- ");
        scanf("%d", &n1);
        printf("ENTER THE SECOND NUMBER :- ");
        scanf("%d", &n2);
        printf("NOW LET ME KNOW THE OPERATION YOU WANT TO DO\n");
        printf("ENTER '1' FOR ADDITION \n");
        printf("ENTER '2' FOR SUBSTRACTION \n");
        printf("ENTER '3' FOR MULTIPLICATION \n");
        printf("ENTER '4' FOR DIVISION \n");
        scanf("%d", &n3);
        if (n3 == 1)
        {
            n4 = n1 + n2;
            printf("THE SUM OF THESE TWO NUMBER IS :- %d\n", n4);
        }
        else if (n3 == 2)
        {
            n4 = n1 - n4;
            printf("THE SUBSTRACTION OF THESE TWO NUMBER IS :- %d\n", n4);
        }
        else if (n3 == 3)
        {
            n4 = n1 * n2;
            printf("THE MULTIPLICATOIN OF THESE TWO NUMBER IS :- %d\n", n4);
        }
        else if (n3 == 4)
        {
            n4 = n1 / n2;
            printf("the division for two number is %d\n", n4);
        }
        else
        {
            printf("error in input\n");
        }
    }
    return 0;
}

int main()
{

    char n, login_signup;
    char username[50]; // used in line no 38
    char password[50]; // used in line no 40
    // char password_input[50];
    char userinput_username[50];
    char userinput_password[50];
    printf("-----------------------------------------------------------WELCOME TO CALCULATOR-----------------------------------------------------------\n");

    printf("PRESS ENTER TO CONTINUE");
    scanf("%c", &n);

    printf("PRESS '1' FOR LOGIN AND '2' FOR SIGNUP\n");
    scanf("%d", &login_signup);

    if (login_signup == 1)
    {
        printf("ENTER USERNAME :- ");
        scanf("%s", userinput_username);

        FILE *fp;

        fp = fopen(("%s.txt", userinput_username), "r");

        if (fp == NULL)
        {
            int n1;
            printf("LOOKS LIKE YOU DON'T HAVE ANY ACCOUNT, WANT TO MAKE A NEW ONE?\n");
            printf("PRESS '1' FOR YES AND '2' FOR NO\n");
            scanf("%d", &n1);
            if (n1 == 1)
            {
                printf("ENTER USERNAME :- ");
                scanf("%s", username);
                printf("ENTER PASSWORD :- ");
                scanf("%s", password);
                FILE *ftr;

                ftr = fopen(("%s.txt", username), "w");

                if (ftr == NULL)
                {
                    printf("SOME ERROR OCCURED PLEASE TRY AGAIN!!\n");
                }
                else
                {
                    fputs("USERNAME=", ftr);
                    fputs(("%s", username), ftr);
                    fputs("\n", ftr);
                    fputs("PASSWORD=", ftr);
                    fputs(("%s", password), ftr);
                    fputs("\n", ftr);
                    fclose(ftr);
                    printf("ACCOUNT CREATED SUCCESSFULLY!!\n");
                    printf("LET'S CONTINUE WITH CALCULATOR!!\n");
                    calculation();
                }
            }
            else if (n1 == 2)
            {
                printf("THANK YOU FOR VISITING!!!");
            }
            else
            {
                printf("INVALID INPUT!!\n");
                printf("PLEASE TRY AGAIN!!\n");
            }
        }
        else
        {
            FILE *ptr;

            char line[50];
            char userpassword[50];
            char file_password[50];

            ptr = fopen(("%s.txt", userinput_username), "r");

            if (ptr == NULL)
            {
                printf("ERROR OCCURED!!\n");
                printf("PLEASE TRY AGAIN!!\n");
            }
            else
            {
                while (fgets(line, sizeof(line), ptr))
                {
                    if (strncmp(line, "PASSWORD=", 9) == 0)
                    {
                        strcpy(file_password, line + 9);
                        file_password[strcspn(file_password, "\n")] = '\0';
                        break;
                    }
                }
                fclose(ptr);
                printf("ENTER PASSWORD :- ");
                scanf("%s", userpassword);
                if (strcmp(file_password, userpassword) == 0)
                {
                    printf("LOGIN SUCCESSFULL!!\n");
                    printf("LET'S BEGIN WITH OUR CALCULATOR!!\n");
                    calculation();
                }
                else
                {
                    printf("INCORRECT PASSWORD!!\n");
                    printf("PLEASE TRY AGAIN!!\n");
                }
            }
            fclose(fp);
        }
    }
    else if (login_signup == 2)
    {

        FILE *fptr;

        char username1[50];
        char password1[50];

        printf("ENTER USERNAME :- ");
        scanf("%s", username1);

        fptr = fopen(("%s.txt", username1), "r");

        if (fptr == NULL)
        {
            // printf("ERROR 101\n");
            // printf("PLEASE TRY AGAIN!!");
            FILE *ffptr;

            ffptr = fopen(("%s", username1), "w");
            printf("ENTER PASSWORD :- ");
            scanf("%s", password1);

            if (ffptr == NULL)
            {
                printf("SOMETHING WENT WRONG PLEASE TRY AGAIN!!!");
            }
            else
            {
                fprintf(ffptr, "USERNAME=");
                fputs(username1, ffptr);
                fputs("\n", ffptr);
                fprintf(ffptr, "PASSWORD=");
                fputs(password1, ffptr);
                fclose(ffptr);
                printf("ACCOUNT CREATED SUCCESSFULLY\n");
                printf("LET'S CONTINUE WITH CALCULATOR!!\n");

                calculation();
            }
        }
        else
        {
            // "FILE OPENED SUCCESSFULLY\n"
            FILE *fpptr;

            char line2[50];
            char file_username[50];

            fpptr = fopen(("%s", username1), "r");

            if (fpptr == NULL)
            {
                printf("ERROR OCCURED!!\n");
                printf("PLEASE TRY AGAIN");
            }
            else
            {
                while (fgets(line2, sizeof(line2), fpptr))
                {
                    if (strncmp(line2, "USERNAME=", 9) == 0)
                    {
                        strcpy(file_username, line2 + 9);
                        file_username[strcspn(file_username, "\n")] = '\0';
                        break;
                    }
                }
                while (strcmp(file_username, username1) == 0)
                {
                    printf("EXISTING USERNAME ENTER NEW ONE!!\n");
                    printf("ENTER USERNAME :- ");
                    scanf("%s", username1);
                    if (strcmp(file_username, username1) == 0)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                FILE *fpttr;
                fpttr = fopen(("%s", username1), "w");
                printf("ENTER PASSWORD :- ");
                scanf("%s", password1);

                if(fpttr == NULL)
                {
                    printf("ERROR OCCURED!!\n");
                    printf("PLEASE TRY AGAIN!!");
                }
                else
                {
                    fprintf(fpttr, "USERNAME=");
                    fputs(username1, fpttr);
                    fputs("\n", fpttr);
                    fprintf(fpttr, "PASSWORD=");
                    fputs(password1, fpttr);
                    fclose(fpttr);
                    printf("ACCOUNT CREATED SUCCESSFULLY\n");
                    printf("LET'S CONTINUE WITH CALCULATOR!!\n");

                    calculation();
                }
                fclose(fpptr);
            }

            // printf("gadbad hogaya");

            fclose(fptr);
        }
    }
    else
    {
        printf("INVALID INPUT!!\n");
        printf("PLEASE TRY AGAIN!!");
    }
    return 0;
}
