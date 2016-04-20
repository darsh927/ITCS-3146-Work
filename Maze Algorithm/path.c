#include <stdio.h>
main(){
    char array[100][100]={0}; // create a default array, sized at 100x100
    FILE *fptr;
    char file_name[20],c,face;
    int m,n,i,j,entranceR,entranceC,currentR,currentC,tempR,tempC,exitR,exitC,val=0;

    //declaring function to return where the object is facing.
    char facingDirection(int entranceR, int entranceC);

    printf("Enter the size of the array: ");
        scanf("%d%d", &m,&n);

    printf("Type in the name of the file containing the Field\n");
        scanf("%s",file_name);

    fptr=fopen(file_name,"r");
        for (i=0; i<m; i++)
            for (j=0; j<n; j++){
                c=fgetc(fptr);
                while ( !((c == '1')||(c =='0')) ) c=fgetc(fptr);
                array[i][j]=c;
            }
    fclose(fptr);

    //loop to find and declare entry and exit locations
    while(val!=2){
        //top
        for(j=0;j<n;j++){
            if(array[0][j]=='0'){
                tempR=0;
                tempC=j;
            }
        }
        //right
        for(i=0;i<m;i++){
            if(array[i][n-1]=='0'){
                tempR=i;
                tempC=n-1;
            }
        }
        //down
        for(j=n; j>=0; j--){
            if(array[m-1][j]=='0'){
                tempR=m-1;
                tempC=j;
            }
        }
        //left
        for(i=m; i >= 0; i--){
            if (array[i][0] == '0'){
            tempR=i;
            tempC=0;
            }
        }
        //increment val.
        val++;
        //on the second loop define the exit location
        if(val==1){
            exitR=tempR;
            exitC=tempC;
            array[exitR][exitC]='X';
        }
        //on the first loop define the entrance location
        else{
            entranceR=tempR;
            entranceC=tempC;
            array[entranceR][entranceC]='X';
        }
    }

    //call the function to return the face
    face = facingDirection(entranceR,entranceC);

    //print entance of the maze and what direction you are facing at that locations
    printf("\nEntrance at: %d,%d\n",entranceR,entranceC);

    //print exit location
    printf("Exit at: %d,%d\n",exitR,exitC);

    //set current coordinates to entrance, will manipulate later in the code
    currentR=entranceR;
    currentC=entranceC;

    while(currentR!=exitR || currentC!=exitC){
        //switch statement for the direction your faceing
        switch(face){
            //Facing South
            case 'S':
                //if there is no wall to the right of you, turn right and walk forward
                if(array[currentR][currentC-1]=='0'|| array[currentR][currentC-1]=='X'){
                    array[currentR][currentC-1]=array[currentR][currentC];
                    currentC--;
                    face='W';
                }
                //go forward if you have a wall to your right and a 0 in front of you
                else if(array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='0'|| array[currentR+1][currentC]=='X'){
                    array[currentR+1][currentC]=array[currentR][currentC];
                    currentR++;
                }
                else{face ='E';}
            break;

            //Facing North
            case 'N':
                //if there is no wall to the right of you, turn right and walk forward
                if(array[currentR][currentC+1]=='0'|| array[currentR][currentC+1]=='X'){
                    array[currentR][currentC+1]=array[currentR][currentC];
                    currentC++;
                    face='E';
                }
                //go forward if you have a wall to your right and a 0 in front of you
                else if(array[currentR][currentC+1]=='1' && array[currentR-1][currentC]=='0'|| array[currentR-1][currentC]=='X'){
                    array[currentR-1][currentC]=array[currentR][currentC];
                    currentR--;
                }
                else{face ='W';}
            break;

            //Facing East
            case 'E':
                //if there is no wall to the right of you, turn right and walk forward
                if(array[currentR+1][currentC]=='0'|| array[currentR+1][currentC]=='X'){
                    array[currentR+1][currentC]=array[currentR][currentC];
                    currentR++ ;
                    face='S';
                }
                //go forward if you have a wall to your right and a 0 in front of you
                else if(array[currentR+1][currentC]=='1' && array[currentR][currentC+1]=='0'|| array[currentR][currentC+1]=='X'){
                    array[currentR][currentC+1]=array[currentR][currentC];
                    currentC++;
                }
                else{face ='N';}
            break;

            //Facing West
            case 'W':
                //if there is no wall to the right of you, turn right and walk forward
                if(array[currentR-1][currentC]=='0'|| array[currentR-1][currentC]=='X'){
                    array[currentR-1][currentC]=array[currentR][currentC];
                    currentR--;
                    face='N';
                }
                //go forward if you have a wall to your right and a 0 in front of you
                else if(array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='0'|| array[currentR][currentC-1]=='X'){
                    array[currentR][currentC-1]=array[currentR][currentC];
                    currentC--;
                }
                else{face ='S';}
            break;
            }
            if (currentR==entranceR && currentC==entranceC){
                printf("No path found.\n");
                break;
            }
            if (currentR==exitR && currentC==exitC){
                printf("Path found!!!!\n");
                break;
            }
    }

    //for loop to print array after manipulation/going through it.
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)  {
            if (j == 0) printf("\n");
            printf("%c  ",array[i][j]);
        }
    printf("\n");
}

//function to return the face at entrance of the maze.
char facingDirection(int entranceR, int entranceC){
    char f;
    //if statements to set face
    if (entranceR==0){
        f='S';
    }else if (entranceC!=0){
        f='W';
    }else if (entranceR!=0){
        f='N';
    }else f='E';
        return f;
}
