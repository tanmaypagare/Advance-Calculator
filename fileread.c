#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;

    char name[100];
    
    char user_password[100];
    fptr = fopen("data.txt", "r");

    if (fptr == NULL)
    {
        printf("FAILED TO OPEN");
    }
    else
    {
        printf("FILE OPENED SUCCESSFULLY\n");
        // sbc = fgets(name , sizeof(name) , fptr)
        while(fgets(name , sizeof(name) , fptr) != NULL)
        {
            char *abc;
            char file_password[100];
            abc = strchr(file_password, '=');
            if (abc != NULL)
            {
                fgets(file_password , sizeof(file_password) , fptr);
                // abc = strchr(file_password, '=');/
                abc++;
                printf("%s", name);
            }
            // if(strcmp(name , "PASSWORD=*") == 0)
            // {
            //     strcpy(file_password , name + 9);

            //     file_password[strcspn(file_password , "\n")] = '\0';
            // }
            // else
            // {
            //     printf("HERE IS THE ISSUE\n");
            // }

            

            // printf("%s", name);
            // printf("--------------------------");
        }
        fclose(fptr);
    }

    // printf("ENTER THE PASSWORD :- ");
    // scanf("%s", user_password);

    // if (strcmp(file_password , user_password) == 0)
    // {
    //     printf("VALID PASSWORD!!\n");
    // }
    // else
    // {
    //     printf("INVALID PASSWORD!!\n");
    // }
    return 0;
}