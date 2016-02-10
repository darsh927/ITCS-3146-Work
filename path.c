#include <stdio.h>
main()
{
char array[100][100]={0};
FILE *fptr;
char c,face;
char file_name[20];
int m,n,i,j,entranceR,entranceC,currentR,currentC,tempR,tempC,exitR,exitC;
int val=0;

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

//find the entrance of the array
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
val++;

if(val==1){
exitR=tempR;
exitC=tempC;
array[exitR][exitC]='X';
}
else{
entranceR=tempR;
entranceC=tempC;
array[entranceR][entranceC]='X';
}
}
//if statements to set face
if (entranceR==0){
face='S';
}else if (entranceC!=0){
face='W';
}else if (entranceR!=0){
face='N';
}else face='E';

//print statements for
printf("\nEntrance at: %d,%d, %c\n",entranceR,entranceC,face);
printf("Exit at: %d,%d\n",exitR,exitC);

//set current coordinates to entrance, will manipulate later in the code
currentR=entranceR;
currentC=entranceC;

//loop for while statement, needs to be changed
int loop=0;

while(loop!=50){
//switch statement for the direction your faceing
switch(face){
//looking South
case 'S':
//go forward if you have a wall to your right
if(array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='0'){
array[currentR+1][currentC]=array[currentR][currentC];
currentR++;
printf("Current location: %d,%d",currentR,currentC);
}
//if there is no wall to the right of you, turn right and walk forward
if(array[currentR][currentC-1]=='0'){
   array[currentR][currentC-1]=array[currentR][currentC];
   currentC--;
   printf("Current location: %d,%d",currentR,currentC);
   face='W';
}
//if there is a wall to your right and a wall in front then turn left and walk forward
if(array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='1' && array[currentR+1][currentC]=='0'){
    array[currentR+1][currentC]=array[currentR][currentC];
    currentR++;
    face='E';
}
//if you are surrounded by walls then turn around and walk forward
if(array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='1' && array[currentR+1][currentC]=='1'){
   face='N';
}
printf("\n");
break;
//Facing North
case 'N':
//go forward if you have a wall to your right
if(array[currentR-1][currentC]=='0' && array[currentR][currentC+1]=='1'){
array[currentR-1][currentC]=array[currentR][currentC];
currentR--;
printf("Current location: %d,%d",currentR,currentC);
}
//if there is no wall to the right of you, turn right and walk forward
if(array[currentR][currentC+1]=='0'){
   array[currentR][currentC+1]=array[currentR][currentC];
   currentC++;
   printf("Current location: %d,%d",currentR,currentC);
   face='E';
}
//if there is a wall to your right and a wall in front then turn left and walk forward
if(array[currentR][currentC+1]=='1' && array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='0'){
    array[currentR][currentC-1]=array[currentR][currentC];
    currentC--;
    face='W';
}
//if you are surrounded by walls then turn around
if(array[currentR][currentC+1]=='1' && array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='1'){
   face='S';
}
printf("\n");
break;
//Facing East
case 'E':
//go forward if you have a wall to your right
if(array[currentR+1][currentC]=='1' && array[currentR][currentC+1]=='0'){
array[currentR][currentC+1]=array[currentR][currentC];
currentC++;
printf("Current location: %d,%d",currentR,currentC);
}
//if there is no wall to the right of you, turn right and walk forward
if(array[currentR+1][currentC]=='0'){
   array[currentR+1][currentC]=array[currentR][currentC];
   currentR++;
   printf("Current location: %d,%d",currentR,currentC);
   face='S';
}
//if there is a wall to your right and a wall in front then turn left and walk forward
if(array[currentR+1][currentC]=='1' && array[currentR][currentC+1]=='1' && array[currentR-1][currentC]=='0'){
    array[currentR-1][currentC]=array[currentR][currentC];
    currentR--;
    face='N';
}
//if you are surrounded by walls then turn around and walk forward
if(array[currentR+1][currentC]=='1' && array[currentR][currentC+1]=='1' && array[currentR-1][currentC]=='1'){
   face='W';
}
printf("\n");
break;
//Facing West
case 'W':
//go forward if you have a wall to your right
if(array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='0'){
array[currentR][currentC-1]=array[currentR][currentC];
currentC--;
printf("Current location: %d,%d",currentR,currentC);
}
//if there is no wall to the right of you, turn right and walk forward
if(array[currentR-1][currentC]=='0'){
   array[currentR-1][currentC]=array[currentR][currentC];
   currentR--;
   printf("Current location: %d,%d",currentR,currentC);
   face='N';
}
//if there is a wall to your right and a wall in front then turn left and walk forward
if(array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='0'){
    array[currentR+1][currentC]=array[currentR][currentC];
    currentR++;
    face='S';
}
//if you are surrounded by walls then turn around and walk forward
if(array[currentR-1][currentC]=='1' && array[currentR][currentC-1]=='1' && array[currentR+1][currentC]=='1'){
   face='E';
}
printf("\n");
break;
}
loop++;
}
for (i=0; i<m; i++)
for (j=0; j<n; j++)  {
if (j == 0) printf("\n");
printf("%c  ",array[i][j]);
}
printf("\n");
}
