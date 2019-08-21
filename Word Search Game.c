
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void start1(char *);
int levelslect(int level);
int newgame(int,char);
void startgame (char username[],int life,int score,int level,char**);
char **readBoard();
char **readBoard2();
char **readBoard3();
char boardstoring(int l, int o ,int level);
void position(int l , int o, int level);
void Forward(int l, int o, int level);
void Backward(int l, int o, int level);
void Downward(int l, int o, int level);
void Upward(int l, int o, int level);
void ForwardUpward(int l, int o, int level);
void BackwardUpward(int l, int o,int level);
void ForwardDownward(int l, int o, int level);

int main()
{

    int level=0;
    char start[5],option='-',board;
    printf("Please Select one of the following levels\n");
        printf("Input 1 for easy level\n");
        printf("Input 2 for normal level\n");
        printf("Input 3 for hard level\n");

    level=levelslect(level);
    while(option!='e'||option!='E')
    {
    printf("Enter n or N for new game\n");
    printf("Enter r or R to resume game\n");
    printf("Enter e or E to exit from game\n");
    scanf("%c",&option);
    system("CLS");
    do
    {
    if (option=='n'||option=='N')
    {
        newgame(level,board);
    }
    if (option=='r'||option=='R')
    {
        break;
    }
    }while(option=='r' || option=='R');
    }


}
int levelslect(int level)
{

    //system("color 80");
	//system("color e5");


            scanf("%d",&level);
        if (level==1 || level==2 || level==3)
        {
            return level;
        }

}
int newgame(int level,char board)
{

    //system("color 80");
	//system("color c7");
    char username[32];
    printf("Please enter your name:\n");
    scanf("%s",&username);
    int life=3;
    int score=0;
    startgame (username,life,score,level,&board);
    return 0;


}
void startgame (char username[],int life,int score,int level,char **board)
{
    //system("color 50");//this function is use to change the screen color
	//system("color e7");//this is also used to change the screen color along with previous one on running time

    char input[32]="";
    while(input[0]!='p' || input[1]!=NULL)
    {
    system("CLS");
    printf("Name of player is\n\t%s",username);
    printf("\n");
    printf("Your score is\n\t%d",score);
    printf("\n");
    printf("Your remaining life is\n\t%d",life);
    printf("\n");


     printf("\n\n%s your puzzle box is:\n",username);

    printf("Your Given word are\n");
        if(level==1)
        {
        int l=7,o=7;
        printf("your selected level is 1\n");
        printf("\n\t\tEasy level\n");
        readBoard();
        printf("\t\t 1-free\n\t\t 2-comsats\n\t\t 3-app\n\t\t 4-boy\n\t\t 5-car\n\t\t 6-camera\n\t\t 7-pack\n\t\t 8-gas");
        position(l,o,level);
        }
        else if(level==2)
        {int l=10,o=10;
        printf("Your selected level is 2\n");
        printf("\n\t\tmedium level\n");
        readBoard2();
        printf("\t\t1-Apple\n\t\t2-mango\n\t\t3-bnana\n\t\t4-cooler\n\t\t5-gas\n\t\t6-oppo\n\t\t7-mobile\n");
        position(l,o,level);
        }
     else if(level==3)
        { int l=12,o=7;
        printf("Your slected level is 3\n");
        printf("\n\t\tHard level\n");
        readBoard3();
        printf("\t\t1-camera\n\t\t2-apple\n\t\t3-boy\n\t\t4-mango\n\t\t5-gas\n\t\t6-oppo\n\t\t7-mobile\n\t\t8-comsata\n");
        position(l,o,level);
        }
        if (life<=0);
     {
         printf("Game over");
         getch();
         break;
     }
    }

}
char **readBoard()
{
    char ch;
    FILE *fp;
    fp = fopen("board.txt", "r");
    while(1)
    {
        ch=fgetc (fp);
        if (ch==EOF)
            break;
    printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

char **readBoard2()
{
    char ch;
    FILE *fp;
    fp = fopen("board2.txt", "r");
    while(1)
    {
        ch=fgetc (fp);
        if (ch==EOF)
            break;
    printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
char **readBoard3()
{
    char ch;
    FILE *fp;
    fp = fopen("board3.txt", "r");
    while(1)
    {
        ch=fgetc (fp);
        if (ch==EOF)
            break;
    printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

void position(int l, int o, int level)
{
    int n;
    printf("\nEnter the searching position\n");
    printf("1.Forward Search\n2.Backward Search\n3.Downward Search\n4.Upward Search\n5.Forward Upward(Diagonally) Search\n6.Backrward Upward(Diagonally) Search\n7.Forward Downward(Diagonally) Search");
    printf("\nsearching position is\n");
    scanf("%d",&n);
    if(n==1)
        Forward(l,o,level);
    else if(n==2)
        Backward(l,o,level);
    else if(n==3)
        Downward(l,o,level);
    else if(n==4)
        Upward(l,o,level);
    else if(n==5)
        ForwardUpward(l,o,level);
    else if(n==6)
        BackwardUpward(l,o,level);
    else if(n==7)
        ForwardDownward(l,o,level);
    else
        printf("You Entered Wrong Position");

}
void Forward(int l, int o, int level)
{

    char ar[l][o],c;
    int i,j,a,b,x,y,k=0,score=0;
    char ch[5]="camera",ch1[6]="comsats", ch2[3]="app",ch3[3]="boy";
    boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the coloum\n");
     scanf("%d",&b);

     for(i=a; i<=a; i++)
     {  k=0;
         for(j=x; j<=b; j++)
         {
             if(ar[i][j]==ch[k] || ch1[k] || ch2[k] || ch3[k])
                {
                    score++;
                    k++;
                }


         }
     }
              if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");
        printf("\nYou got %d Score\n",score);
}
void Backward(int l, int o, int level)
{
     char ar[l][o],c;
     int i,j,a,b,x,y,k=0,score=0;
     char ch[3]="car", ch1[4]="free";
     boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the coloum\n");
     scanf("%d",&b);

     for(i=a; i<=a; i++)
     {  k=0;
         for(j=x; j>=b; j--)
         {
             if(ar[i][j]==ch[k] || ch1[k])
                {
                    score++;
                    k++;
                }



         }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);

}
void Downward(int l, int o, int level)
{
     char ar[l][o],c;
     int i,j,a,b,x,y,k=0,score=0;
     char ch[4]="pack";
     boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the row\n");
     scanf("%d",&b);

     for(i=a; i<=b; i++)
     {
         for(j=x; j<=x; j++)
         {
             if(ar[i][j]==ch[k])
                {
                    score++;
                    k++;
                    
                }



         }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);

}
void Upward(int l, int o, int level)
{
     char ar[l][o],c;
    int i,j,a,b,x,y,k=0,score=0;
    char ch[3]="gas";
     boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the row\n");
     scanf("%d",&b);

     for(i=a; i>=b; i--)
     {
         for(j=x; j<=x; j++)
         {
             if(ar[i][j]==ch[k])
                {
                    score++;
                    k++;
                    
                }
          }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);

}
void ForwardUpward(int l, int o, int level)
{
    char ar[l][o],c;
    int i,j,a,b,x,y,k=0,score=0;
    char ch[3]="gas", ch1[6]="cooler";
    boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the row\n");
     scanf("%d",&b);
     printf("And the Coloumn\n");
     scanf("%d",&y);
k=0;
     for(i=a; i>=b; i--)
     {
         for(j=x; j<=y; j++)
         {
             if(ar[i][j]==ch[k] || ch1[k])
                {
                    score++;
                    k++;
                    break;
                }



         }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);
}
void BackwardUpward(int l, int o,int level)
{
	 char ar[l][o],c;
    int i,j,a,b,x,y,k=0,score=0;
    char ch[3]="gas", ch1[5]="apple";
    boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the row\n");
     scanf("%d",&b);
     printf("And the Coloumn\n");
     scanf("%d",&y);
k=0;
     for(i=a; i>=b; i--)
     {
         for(j=x; j>=y; j--)
         {
             if(ar[i][j]==ch[k] || ch1[k])
                {
                    score++;
                    k++;
                    break;
                    
                }



         }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);
}
void ForwardDownward(int l, int o, int level)
{
		 char ar[l][o],c;
    int i,j,a,b,x,y,k=0,score=0;
    char ch[3]="app"; 
    boardstoring(l,o,level);
     printf("Enter the starting position of your word\n");
     printf("The word starts at the row\n");
     scanf("%d",&a);
     printf("And the coloum\n");
     scanf("%d",&x);
     printf("Enter the ending position of your given word\n");
     printf("The word ends at the row\n");
     scanf("%d",&b);
     printf("And the Coloumn\n");
     scanf("%d",&y);
k=0;
     for(i=a; i<=b; i++)
     {
         for(j=x; j<=y; j++)
         {
             if(ar[i][j]==ch[k])
                {
                    score++;
                    k++;
                    break;
                    
                }



         }

     }
         if(score>0)
             printf("Congratulations word is found at given position\n");
         else
             printf("Word not found");


        printf("\nYou got %d Score\n",score);
}


char boardstoring(int l , int o, int level)
{
 char ar[l][o],c;
    int i,j;
    FILE *fp;
      if(level==1)
        {fp=fopen("B11.txt","r");}
    else if(level==2)
        {fp=fopen("B12.txt","r");}
    else if(level==3)
        {fp=fopen("B13.txt","r");}
    if(fp==NULL)
        printf("File not Found");

for(i=0; i<l; i++)
    {
        for(j=0; j<o; j++)
        {

         fscanf(fp," %c",&ar[i][j]); //The space in "..%c" consumes the newline character when using scanf() format specifiers such as %c %lf %d etc.
        }
}
}
