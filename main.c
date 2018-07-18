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

// function to choose between Y or N
int contGame(char c){
    if(c == 'y' || c == 'Y'){
        return 1;
    }
    else if(c == 'n' || c == 'N'){
        return 0;
    }
    else{
        return -1; // returns -1 if neither Y or N is entered
    }
}

// function to check for wrong input in yes or no
void charError(char c){
    while(contGame(c) < 0){
        printf("Please enter a (Y/N): \n");
        fflush(stdin);
        scanf("%c",&c);
    }
}


// function to decide who starts
void start(User *user, Comp *comp){
    (*comp).dieInit = roll();
    printf("I have rolled the dice and got %d!\n",(*comp).dieInit);
    printf("Are you ready to Zonk! Shall I roll the dice for you (Y/N)? ");
    fflush(stdin);
    scanf("%c",&(*user).choice);
    charError((*user).choice);
    //contGame((*user).choice);
    if(!contGame((*user).choice)){
        printf("Ok byee ...");
        exit(1);
    }else{
        (*user).dieInit = roll();
        printf("I have rolled the dice for you and you get %d\n",(*user).dieInit);
    }


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