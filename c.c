#include <stdio.h>
#include <string.h>

int main() {
    FILE *ffptr;

            ffptr = fopen(("%s", username1), "r");

            if(ffptr == NULL)
            {
                // fprintf(fptr, "USERNAME=");
                // fputs(username1, fptr);
                // fputs("\n", fptr);
                // fprintf(fptr, "PASSWORD=");
                // fputs(password1, fptr);
                // fclose(fptr);
                // printf("ACCOUNT CREATED SUCCESSFULLY\n");
                // printf("LET'S CONTINUE WITH CALCULATOR!!\n");

                // calculation();
                printf("SOMETHING WENT WRONG PLEASE TRY AGAIN!!!");
            }
            else
            {
                // int n2;
                // printf("WE HAVE FOUND AN ACCOUNT WITH THE SAME USERNAME\n");
                // printf("WOULD YOU LIKE TO LOGIN THIS ACCOUNT OR MAKE A NEW ONE\n");
                // printf("PRESS '1' FOR LOGIN AND '2' FOR TO MAKE A NEW ACCOUNT\n");
                // scanf("%d", &n2);
                // if(n2 == 1)
                // {

                // }
                // else if(n2 == 2)
                // {

                // }
                // else
                // {
                //     printf("INVALID INPUT!!!\n");
                //     printf("PLEASE TRY AGAIN!!!\n");
                // }
                
            }
    return 0;
}
