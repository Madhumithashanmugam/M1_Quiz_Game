#include <stdio.h>
#include <stdlib.h>
char name[30];
int userScore=0,countQ=0;
void calculateScore()
{
    if (userScore >= 80&&userScore <= 100)
    {
        printf("\nCongrats! %s You win the quiz with 'A' grade.\n",name);
        printf("\nCongrats! %s You won 10,000 Cashprize.\n");
        printf("you got %d numbers.\n",userScore);
        printf("your %d Question is correct.\n",countQ);
    }
    else if(userScore >= 60&&userScore < 80)
    {
        printf("Congrats! %s You win the quiz with 'B' grade.\n",name);
        printf("\nCongrats! %s You won 5,000 Cashprize.\n");
        printf("you got %d numbers.\n",userScore);
        printf("your %d Question is correct.\n",countQ);
    }
    else if(userScore >= 40&&userScore < 60)
    {
        printf("Congrats! %s You win the quiz with 'C' grade.\n",name);
        printf("\nCongrats! %s You won 3,000 Cashprize.\n");
        printf("you got %d numbers.\n",userScore);
        printf("your %d Question is correct.\n",countQ);
    }
    else if(userScore >= 10&&userScore < 40)
    {
        printf("Sorry! %s You loose the quiz.\n",name);
        printf("you got %d numbers.\n",userScore);
        printf("your %d Question is correct.\n",countQ);
        printf("*******Better luck lext time*********\n");
    }    
    exit(0);
}
char result(char choose,char correct)
{
    char next;
    if (choose==correct)
    {
        countQ++;
        userScore=userScore+10;
        printf("Answer is correct!\n");
        printf("Press (Y) to continue Quiz ");
        printf("If you want to end this Quiz then press (N)\n");
        fflush(stdin);
        scanf("%c",&next);
        return(next);
    }else
    {
        printf("Sorry Answer is wrong!\n");
        printf("Press (Y) to continue Quiz ");
        printf("If you want to end this Quiz then press (N)\n");
        fflush(stdin);
        scanf("%c",&next);        
        return(next);
    }
}
void question()
{
    char choose,correct;
    printf("1.Q-which data type store characters?\n");
    printf("\t(A).Int\t(B).float\n");
    printf("\t(C).char\t(D).byte\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='c';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    } 
    printf("2.Q-How many bytes consume Int data type in 64 bit OS?\n");
    printf("\t(A).4\t(B).6\n");
    printf("\t(C).2\t(D).8\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='a';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }   
    printf("3.Q-How many bytes consume Float data type in 64 bit OS?\n");
    printf("\t(A).6\t(B).4\n");
    printf("\t(C).2\t(D).8\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='b';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }   
    printf("4.Q-How many bytes consume Double data type in 64 bit OS?\n");
    printf("\t(A).4\t(B).6\n");
    printf("\t(C).2\t(D).8\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='d';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }   
    printf("5.Q-How many bytes consume char data type in 64 bit OS?\n");
    printf("\t(A).4\t(B).6\n");
    printf("\t(C).1\t(D).8\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='c';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    printf("6.Q-Which type of values is store in Int data type?\n");
    printf("\t(A).integer\t(B).floating point\n");
    printf("\t(C).character\t(D).string\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='a';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    printf("7.Q-Which type of values is store in float data type?\n");
    printf("\t(A).integer\t(B).floating point\n");
    printf("\t(C).character\t(D).string\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose); 
    correct='b';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    printf("8.Q-Which type of values is store in double data type?\n");
    printf("\t(A).integer\t(B).floating point\n");
    printf("\t(C).character\t(D).string\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);  
    correct='b';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    printf("9.Q-What is string?\n");
    printf("\t(A).Integer values\t(B).floating values\n");
    printf("\t(C).Character array\t(D).Array\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);
    correct='c';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    printf("10.Q-What is structure?\n");
    printf("\t(A).Integer\t(B).float\n");
    printf("\t(C).Character\t(D).User defined data type\n");
    printf("Choose which option is correct:");
    fflush(stdin);
    scanf("%c",&choose);
    correct='d';  
    correct=result(choose,correct);
    if (correct=='n'||correct=='N')
    {
        return;   
    }
    calculateScore();
}
void menu()
{
    char ch;
    printf("\nHello!  %s\n",name);
    printf("Here are some rules of this Game.\n");
    printf("1. You can choose any option.\n");
    printf("2. You need to answer 10 question\n");
    printf("3. Every question is 10 number\n");
    printf("4.Total number is 100\n");
    printf("5. We decide you win the quiz or not\n");
    printf("Press (Y) for start quiz otherwise press (N)\n");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        question();
        calculateScore();
    }else
    {
        exit(0);
    }
}
void main()
{
    printf("\n*******Welcome to Quiz Game*******\n");
    printf("Enter your name:");
    gets(name);
    menu();
}
