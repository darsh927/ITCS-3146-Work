#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

main(){
    //function declarations
    void date(), cal(), fileContents();
    int choice;
    //printf for current process ID and its Parent.
    printf("\nParent process ID: %ld, Parent's parent ID: %ld ",(long)getpid(),(long)getppid());
    //loop to execute the display menu and switch statement.
    do{
    printf("\nCurrent process PID %ld",(long)getpid());
    //print menu
    printf("\nChoose the function to be performed by the child:\n\t"
    "(1)Display current date and time\n\t"
    "(2) Display the calendar of the current month\n\t"
    "(3) List the files in the current directory\n\t"
    "(4) Exit from the program\n"
    "Enter your choice: ");    
    
    scanf("%d",&choice);
        //switch for choice made
        switch (choice){
            case 1:
                date(); //function call
                break;
            case 2:
                cal(); //function call
                break;
            case 3:
                fileContents(); //function call
                break;
        }
    }while(choice!=4);
    system("exit");
}
//display date function
void date(){
    if(fork()==0){ //create child process
    printf("\nChild process ID %ld, Parent ID %ld\n",(long)getpid(),(long)getppid());
    system("date\n");
    _exit(1); //kill the child
    }
    else{
        wait();
    }
}
//display calendar function
void cal(){
    if(fork()==0){ //create child process
    printf("\nChild process ID %ld, Parent ID %ld\n",(long)getpid(),(long)getppid());
    system("cal\n");
    _exit(1); //kill the child
    }
    else{
        wait();
    }
}
//display file contents function
void fileContents(){
if(fork()==0){ //create child process
    printf("\nChild process ID %ld, Parent ID %ld\n",(long)getpid(),(long)getppid());
    system("ls -l\n");
    _exit(1); //kill the child
    }
    else{
        wait();
    }
}