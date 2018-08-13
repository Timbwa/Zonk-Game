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

// function to print multiple '='
void equalSign(){
    printf("\n");
    for (int j = 0; j < 100; ++j) {// prints multiple '='
        printf("%c",205);
    }
}

// function to print dice

void printDice(int dice[6]){
    for (int i = 0; i < 6; ++i) {
        printf("[Dice %d]: %d ", i + 1,dice[i]);
    }
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

// function to sum fives
int sumFives(int dice[6]){
    int i, sum = 0;
    for (i = 0; i < 6; ++i) {
        if(dice[i] == 5){
            sum += 50;
        }
    }
    return sum;
}
// function to sum ones
int sumOnes(int dice[6]){
    int i, sum = 0;
    for(i = 0; i < 6 ; ++i){
        if(dice[i] == 1){
            sum += 100;
        }
    }
    return sum;
}

// function to sum three-of-a-kind
int sumOfThrees(int dice[6]){
    int countSums[6] = {0,0,0,0,0,0};
    for (int i = 0; i < 6; ++i) {
        if(dice[i] == 1){
            countSums[0] += 1;
        }
        if(dice[i] == 2){
            countSums[1] += 1;
        }
        if(dice[i] == 3){
            countSums[2] += 1;
        }
        if(dice[i] == 4){
            countSums[3] += 1;
        }
        if(dice[i] == 5){
            countSums[4] += 1;
        }
        if(dice[i] == 6){
            countSums[5] += 1;
        }
    }

    if(countSums[0] == 3){
        return 1000;
    }

    int points = 0;
    int temp;

    for (int j = 1; j < 6; ++j) {
        if(countSums[j] == 3){
            temp = (j + 1) * 100;
            if(temp > points){
                points = temp;
            }
        }
    }
    return points;
}

// function to add six of a kind
int sumOfAKind(int dice[6]){
    if(dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4] && dice[4] == dice[5]){
        return 1000;
    }
    return 0;
}

// function to get sum of a straight
int sumOfStraight(int dice[6]){
    int sum = 1500;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0;(i != j) && (j < 6); ++j){
            if (dice[i] == dice[j]){
                sum = 0;
            }
        }
    }
    return sum;
}

int computerStrategyDecider(Comp *comp){

}

void playComputer(Comp *comp){
    for (int i = 0; i < 6; ++i) {
        (*comp).dice[i] = roll();
    }
    printf("\nMy Turn: \n");
    printf("I got:\n");
    printDice((*comp).dice);
    equalSign();
}

void playUser(User *user){
    for (int i = 0; i < 6; ++i) {
        (*user).dice[i] = roll();
    }
    printf("\nYour Turn: \n");
    printf("You got:\n");
    printDice((*user).dice);
    equalSign();

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
            playComputer(compAddr);
            playUser(userAddr);
        }
        else if(user.dieInit > comp.dieInit){
            playUser(userAddr);
            playComputer(compAddr);
        }
    }

}