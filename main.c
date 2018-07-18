#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// define computer, user and game structures
struct Comp{
    int score;
    int dice[6];
    int dieInit;
};

struct User{
    int score;
    int dice[6];
    int dieInit;
    char choice;
};

struct Game{
    int rounds;
};

typedef struct Comp Comp;
typedef struct User User;
typedef struct Game Game;

// function to roll a die
int roll(){
    int die = 1 + (int)rand() % 6;
    return die;
}

// function to check correct char input
void errorCheck(char choice){
    while ((choice != 'y' && choice != 'Y') && (choice != 'n' && choice != 'N')){
        printf("Please enter (Y/N): ");
        fflush(stdin);
        scanf("%c",&choice);
    }
}

// function to contiue game
void contGame(char choice){
    if(choice != 'y' && choice != 'Y'){
        printf("\n Ok byee ...");
        exit(1);
    }
}

// function to decide who starts
void start(User *user, Comp *comp){
    (*comp).dieInit = roll();
    printf("I have rolled the dice and got %d!\n",(*comp).dieInit);
    printf("Are you ready to Zonk! Shall I roll the dice for you (Y/N)? ");
    fflush(stdin);
    scanf("%c",&(*user).choice);
    //errorCheck(user.choice);
    //contGame(user.choice);
    (*user).dieInit = roll();
    printf("I have rolled the dice for you and you get %d\n",(*user).dieInit);
}

void playComputer(){
    printf("comps...\n");
}

void playUser(){
    printf("user...\n");
}
int main(){
    srand(time(NULL));
    Game game;
    Comp comp,*compAddr;
    User user,*userAddr;
    compAddr = &comp;
    userAddr = &user;
    int i;
    printf("Welcome to the Zonk Game.\n"
                   "How many rounds would you like to play?");
    fflush(stdin);
    scanf("%d",&game.rounds);
    printf("OK, lets get started!\n");

    start(userAddr,compAddr);

    printf("comp init: %d\n",comp.dieInit);
    printf("user init: %d\n",user.dieInit);
    for(i = 0;i < game.rounds;++i){
        if(comp.dieInit >= user.dieInit){ // comps start if dice is >= user.dieInit
            playComputer();
            playUser();
        }
        else if(user.dieInit > comp.dieInit){
            playUser();
            playComputer();
        }
    }

}