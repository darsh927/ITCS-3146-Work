//Darshesh Patel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this is where the nodes are created
struct node{
    char *word;
    struct node *next;
};

//variable declaration for pointers
struct node *list = NULL;
struct node *end = NULL;
struct node *begin = NULL;
struct node *aPtr = NULL;
struct node *tempPtr = NULL;

//linked list structure
void LinkedList(
    struct node *j,
    struct node **last
    );

//read file function
void read_file(int numchar);
void print_list(int numchar);
void free_mem();

int main(){
    //number of characters per line
    int cPerLine = 0;
    printf("Enter how many characters you want per line between 40 and 100.\n");
    scanf("%d", &cPerLine);
    //function call to read in the FILE
    read_file(cPerLine);
    //function call to print out the contents of the linked list aligned
    print_list(cPerLine);
    free_mem();
    return 0;
}
//funtion to read from FILE
void read_file(int numchar){
    FILE *fptr = NULL;
    char *String = malloc(30*sizeof(char));
    char file_name[20];

    printf("Enter the name of the file containing your txt.\n");
    scanf("%s", file_name);
    //open file_name
    fptr = fopen(file_name, "r");
    //scan in from file, ignore whitespace
    fscanf(fptr, "%s", String);
    //add from file to linked list
    list = (struct node *)malloc(sizeof(struct node));
    list->word = String;
    list->next = NULL;
    end = list;

    while(!feof(fptr)){
        String = malloc(30*sizeof(char));
        fscanf(fptr, "%s", String);
        end->next = (struct node *)malloc(sizeof(struct node));
        end = end->next;
        end->word = String;
        end->next = NULL;
    }
    //close file_name
    fclose(fptr);
    printf("\nThe Text is:  \n\n");
}
//this function prints text from the linked list with the proper justification
void print_list(int numchar){
    end = list;
    aPtr = list;
    begin = list;
    tempPtr = begin;

    while(begin->next != NULL){
        int spaces[50] = {};
        // spaces within a line
        int whiteSpace = 0, charLine = 0;
        //determine leftover space so that it can be filled with spaces
        int leftOverSpace = 0, count = 0, finalLine = 0, i = 0, j = 0;

        charLine = strlen(end->word)+1;
        count = 1;
        end = end->next;

        while(charLine+strlen(end->word)+1 < numchar){
            charLine = charLine + strlen(end->word) + 1;
            count = count + 1;

            if(end->next != NULL)
                end = end->next;
            else{
                finalLine = 1;
            }
        }
        //calculate space needed based on leftover space on the line
        leftOverSpace = numchar - (charLine-1);

        while(leftOverSpace > 0){

            if(whiteSpace < (count - 1)){
                spaces[whiteSpace] = spaces[whiteSpace] + 1;
                leftOverSpace = leftOverSpace - 1;
                whiteSpace = whiteSpace + 1;
            }
            else
                whiteSpace = 0;
        }
        //print out the words for the line
        for( i = 1; i <= count; i++){
            if(i , count){
                printf("%s ", aPtr->word);
                for(j = 1; j <= spaces[i-1]; j++){
                    printf(" ");
                }
            }
            else if(i = count){
                printf("%s\n", aPtr->word);
            }
        if(aPtr->next != NULL)
            aPtr = aPtr->next;
        }
        if(aPtr->next != NULL)
            end = aPtr;
        if(end->next == NULL)
            begin = end;
            printf("\n");
    }
}
//this function free's the dynamic memory at the end
void free_mem(){
    end = list;
    while(end->next != NULL){
        end = end->next;
    }
    while(list != NULL){
        if(end == list){
            free(list->word);
            free(list);
            list = NULL;
            end = NULL;
            aPtr = NULL;
        }
        else{
            aPtr = list;
            while(aPtr->next != end)
                aPtr = aPtr->next;
                free(end->word);
                free(end);
                end = aPtr;
        }
    }
}