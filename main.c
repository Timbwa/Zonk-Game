/*
 * Author: David Timbwa Auna
 * ID: 2278026
 * date: 11/4/2018
 * */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function to roll a dice
int rollADice(){
    return 1 + rand() % 6;
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

// function to check if char entered is a dice number
void charNumError(char c){
    while(c < '1' || c > '6'){
        printf("\nPlease enter a number from 1 - 6");
        printf("\nWhich ones do you want to roll again? ");
        fflush(stdin);
        scanf("%c",&c);
    }
}

// function to add fives
int sumFives(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    int sum = 0;

    if(dice1 == 5){
        sum += 50;
    }
    if(dice2 == 5){
        sum += 50;
    }
    if(dice3 == 5){
        sum += 50;
    }
    if(dice4 == 5){
        sum += 50;
    }
    if(dice5 == 5){
        sum += 50;
    }
    if(dice6 == 5){
        sum += 50;
    }
    return sum;
}

// function to add ones
int sumOnes(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    int sum = 0;

    if(dice1 == 1){
        sum += 100;
    }
    if(dice2 == 1){
        sum += 100;
    }
    if(dice3 == 1){
        sum += 100;
    }
    if(dice4 == 1){
        sum += 100;
    }
    if(dice5 == 1){
        sum += 100;
    }
    if(dice6 == 1){
        sum += 100;
    }
    return sum;
}

// function to add three of a kind
int sumOfThrees(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    int countOnes = 0,countTwos = 0,countThrees = 0,countFours = 0,countFives = 0,countSix = 0;

    {
        if (dice1 == 1)
            countOnes += 1;
        if (dice2 == 1)
            countOnes += 1;
        if (dice3 == 1)
            countOnes += 1;
        if (dice4 == 1)
            countOnes += 1;
        if (dice5 == 1)
            countOnes += 1;
        if (dice6 == 1)
            countOnes += 1;
    }

    {
        if (dice1 == 2)
            countTwos += 1;
        if (dice2 == 2)
            countTwos += 1;
        if (dice3 == 2)
            countTwos += 1;
        if (dice4 == 2)
            countTwos += 1;
        if (dice5 == 2)
            countTwos += 1;
        if (dice6 == 2)
            countTwos += 1;
    }

    {
        if (dice1 == 3)
            countThrees += 1;
        if (dice2 == 3)
            countThrees += 1;
        if (dice3 == 3)
            countThrees += 1;
        if (dice4 == 3)
            countThrees += 1;
        if (dice5 == 3)
            countThrees += 1;
        if (dice6 == 3)
            countThrees += 1;
    }

    {
        if (dice1 == 4)
            countFours += 1;
        if (dice2 == 4)
            countFours += 1;
        if (dice3 == 4)
            countFours += 1;
        if (dice4 == 4)
            countFours += 1;
        if (dice5 == 4)
            countFours += 1;
        if (dice6 == 4)
            countFours += 1;
    }

    {
        if (dice1 == 5)
            countFives += 1;
        if (dice2 == 5)
            countFives += 1;
        if (dice3 == 5)
            countFives += 1;
        if (dice4 == 5)
            countFives += 1;
        if (dice5 == 5)
            countFives += 1;
        if (dice6 == 5)
            countFives += 1;
    }

    {
        if (dice1 == 6)
            countSix += 1;
        if (dice2 == 6)
            countSix += 1;
        if (dice3 == 6)
            countSix += 1;
        if (dice4 == 6)
            countSix += 1;
        if (dice5 == 6)
            countSix += 1;
        if (dice6 == 6)
            countSix += 1;
    }

    if(countOnes == 3){
        return 1000;
    }
    else if(countTwos == 3){
        return 2 * 100;
    }
    else if(countThrees == 3){
        return 3 * 100;
    }
    else if(countFours == 3){
        return 4 * 100;
    }
    else if(countFives == 3){
        return 5 * 100;
    }
    else if(countSix == 3){
        return 6 * 100;
    }
    else{
        return 0;
    }
}

// function to add six of a kind
int sumOfSixOfAKind(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    if(dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5 && dice5 == dice6)
        return 1000;
    return 0;
}

// function to get sum of straight
int sumOfStraight(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    if(dice1 == dice2){
        return 0;
    }
    else if(dice1 == dice3){
        return 0;
    }
    else if(dice1 == dice4){
        return 0;
    }
    else if(dice1 == dice5){
        return 0;
    }
    else if(dice1 == dice6){
        return 0;
    }
    else if(dice2 == dice3){
        return 0;
    }
    else if(dice2 == dice4){
        return 0;
    }
    else if(dice2 == dice5){
        return 0;
    }
    else if(dice2 == dice6){
        return 0;
    }
    else if(dice3 == dice4){
        return 0;
    }
    else if(dice3 == dice5){
        return 0;
    }
    else if(dice3 == dice6){
        return 0;
    }
    else if(dice4 == dice5){
        return 0;
    }
    else if(dice4 == dice6){
        return 0;
    }
    else if(dice5 == dice6){
        return 0;
    }
    else{
        return 1500;
    }

}

//function to print the dice with its value
void printDice(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    int counter = 1;

    if(dice1 > 0){
        printf("[Dice %d]: %d ",counter,dice1);
        counter++;
    }
    if(dice2 > 0){
        printf("[Dice %d]: %d ",counter,dice2);
        counter++;
    }
    if(dice3 > 0){
        printf("[Dice %d]: %d ",counter,dice3);
        counter++;
    }
    if(dice4 > 0){
        printf("[Dice %d]: %d ",counter,dice4);
        counter++;
    }
    if(dice5 > 0){
        printf("[Dice %d]: %d ",counter,dice5);
        counter++;
    }
    if(dice6 > 0){
        printf("[Dice %d]: %d ",counter,dice6);
    }
}

//function to print dice that are being re-rolled
void printRerolledDice(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){

    if(dice1 > 0){
        printf("1 ");
    }
    if(dice2 > 0){
        printf("2 ");
    }
    if(dice3 > 0){
        printf("3 ");
    }
    if(dice4 > 0){
        printf("4 ");
    }
    if(dice5 > 0){
        printf("5 ");
    }
    if(dice6 > 0){
        printf("6 ");
    }
}

// computer strategy decider
int computerStrategyDecider(int dice1,int dice2,int dice3,int dice4,int dice5,int dice6){
    int compPoints = 0;
    int loopCount = 0; // limit comps to two loops to maximize points and play safe
    int diceFlag = 0,diceVal;


    while(loopCount <= 1){

        if(sumOfStraight(dice1,dice2,dice3,dice4,dice5,dice6) == 1500){
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            compPoints += sumOfStraight(dice1,dice2,dice3,dice4,dice5,dice6);
            printf("\nI stop and kept dice 1 2 3 4 5 6");
            return compPoints;
        }
        else if(sumOfSixOfAKind(dice1,dice2,dice3,dice4,dice5,dice6) > sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) || ((sumOfSixOfAKind(dice1,dice2,dice3,dice4,dice5,dice6) == 1000) && (sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) == 1000))){
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            compPoints += sumOfSixOfAKind(dice1,dice2,dice3,dice4,dice5,dice6);
            printf("\nI stop and kept dice 1 2 3 4 5 6");
            return compPoints;
        }
        else if((sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) >= sumOnes(dice1,dice2,dice3,dice4,dice5,dice6)) && sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) != 0){
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            compPoints += sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6);
            diceVal = sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) / 100;

            if(loopCount == 1){// loop to play safe
                printf("\nI stop and keep dice 1 2 3 4 5 6");
                return compPoints;
            }

            if(sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) == 1000){
                printf("\n111--Kept dice ");
                if(dice1 == 1){
                    printf("1 ");
                    dice1 = diceFlag;
                } else{
                    dice1 = rollADice();
                }
                if(dice2 == 1){
                    printf("2 ");
                    dice2 = diceFlag;
                } else{
                    dice2 = rollADice();
                }
                if(dice3 == 1){
                    printf("3 ");
                    dice3 = diceFlag;
                } else{
                    dice3 = rollADice();
                }
                if(dice4 == 1){
                    printf("4 ");
                    dice4 = diceFlag;
                } else{
                    dice4 = rollADice();
                }
                if(dice5 == 1){
                    printf("5 ");
                    dice5 = diceFlag;
                } else{
                    dice5 = rollADice();
                }
                if(dice6 == 1){
                    printf("6 ");
                    dice6 = diceFlag;
                } else{
                    dice6 = rollADice();
                }
                printf("and rolled ");
                printRerolledDice(dice1,dice2,dice3,dice4,dice5,dice6);
            } else{
                printf("\n333--Kept dice ");
                if(dice1 == diceVal){
                    printf("1 ");
                    dice1 = diceFlag;
                } else{
                    dice1 = rollADice();
                }
                if(dice2 == diceVal){
                    printf("2 ");
                    dice2 = diceFlag;
                } else{
                    dice2 = rollADice();
                }
                if(dice3 == diceVal){
                    printf("3 ");
                    dice3 = diceFlag;
                }else{
                    dice3 = rollADice();
                }
                if(dice4 == diceVal){
                    printf("4 ");
                    dice4 = diceFlag;
                }else{
                    dice4 = rollADice();
                }
                if(dice5 == diceVal){
                    printf("5 ");
                    dice5 = diceFlag;
                }else{
                    dice5 = rollADice();
                }
                if(dice6 == diceVal){
                    printf("6 ");
                    dice6 = diceFlag;
                }
                else{
                    dice6 = rollADice();
                }
                printf("and rolled ");
                printRerolledDice(dice1,dice2,dice3,dice4,dice5,dice6);
            }
        } else if(sumOnes(dice1,dice2,dice3,dice4,dice5,dice6) > sumFives(dice1,dice2,dice3,dice4,dice5,dice6)){
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            compPoints += sumOnes(dice1,dice2,dice3,dice4,dice5,dice6);
            diceVal = 1;

            if(loopCount >= 1){// loop to play safe
                printf("\nI stop here");
                return compPoints;
            }

            printf("\n1--Kept dice ");
            if(dice1 == diceVal){
                printf("1 ");
                dice1 = diceFlag;
            } else{
                dice1 = rollADice();
            }
            if(dice2 == diceVal){
                printf("2 ");
                dice2 = diceFlag;
            } else{
                dice2 = rollADice();
            }
            if(dice3 == diceVal){
                printf("3 ");
                dice3 = diceFlag;
            }else{
                dice3 = rollADice();
            }
            if(dice4 == diceVal){
                printf("4 ");
                dice4 = diceFlag;
            }else{
                dice4 = rollADice();
            }
            if(dice5 == diceVal){
                printf("5 ");
                dice5 = diceFlag;
            }else{
                dice5 = rollADice();
            }
            if(dice6 == diceVal){
                printf("6 ");
                dice6 = diceFlag;
            }
            else{
                dice6 = rollADice();
            }
            printf("and rolled ");
            printRerolledDice(dice1,dice2,dice3,dice4,dice5,dice6);
        }else if(sumFives(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            compPoints += sumFives(dice1,dice2,dice3,dice4,dice5,dice6);
            diceVal = 5;

            if(loopCount == 1){// loop to play safe
                printf("\nI stop here");
                return compPoints;
            }

            printf("\n5--Kept dice ");
            if(dice1 == diceVal){
                printf("1 ");
                dice1 = diceFlag;
            } else{
                dice1 = rollADice();
            }
            if(dice2 == diceVal){
                printf("2 ");
                dice2 = diceFlag;
            } else{
                dice2 = rollADice();
            }
            if(dice3 == diceVal){
                printf("3 ");
                dice3 = diceFlag;
            }else{
                dice3 = rollADice();
            }
            if(dice4 == diceVal){
                printf("4 ");
                dice4 = diceFlag;
            }else{
                dice4 = rollADice();
            }
            if(dice5 == diceVal){
                printf("5 ");
                dice5 = diceFlag;
            }else{
                dice5 = rollADice();
            }
            if(dice6 == diceVal){
                printf("6 ");
                dice6 = diceFlag;
            }
            else{
                dice6 = rollADice();
            }
            printf("and rolled ");
            printRerolledDice(dice1,dice2,dice3,dice4,dice5,dice6);
        } else{
            printf("\nI got %c%c",205,62);
            printDice(dice1,dice2,dice3,dice4,dice5,dice6);
            printf("\nZonk !!!");
            return 0;
        }
        loopCount++;
    }

}

int playComputer(){
    int dice1 = rollADice(),
            dice2 = rollADice(),
            dice3 = rollADice(),
            dice4 = rollADice(),
            dice5 = rollADice(),
            dice6 = rollADice();
    int i;
    printf("\nMy Turn: \n");
    for (i = 0; i < 100; ++i) {// prints multiple '='
        printf("%c",205);
    }
    return computerStrategyDecider(dice1,dice2,dice3,dice4,dice5,dice6);
}

int playUser(){
    int i,userPoints = 0;
    char contGameChar;// yes(y) or no(n)
    char diceChar;
    int dice1 = rollADice(),
            dice2 = rollADice(),
            dice3 = rollADice(),
            dice4 = rollADice(),
            dice5 = rollADice(),
            dice6 = rollADice();

    printf("\nYour Turn: \n");
    for (i = 0; i < 100; ++i) {
        printf("%c",205);
    }

    printf("\nAre you ready to Zonk! Shall I roll them for you?(Y/N) ");
    scanf("%c",&contGameChar);

    charError(contGameChar);

    while(contGame(contGameChar)){
        fflush(stdin);
        printf("\nYou got %c%c ",205,62);
        printDice(dice1,dice2,dice3,dice4,dice5,dice6);
        int temp1 = 0,temp2 = 0,temp3 = 0,temp4 = 0,temp5 = 0,temp6 = 0;

        printf("\nDo you want to continue (Y/N)? ");
        scanf("%c",&contGameChar);

        charError(contGameChar); // error check

        if(contGame(contGameChar)){
            fflush(stdin);
            printf("\nWhich ones do you want to roll again? ");
            scanf("%c",&diceChar);

            charNumError(diceChar); // checks if number entered is between 1 - 6

            while(diceChar != 10){
                if(diceChar == '1' && dice1 != 0){
                    dice1 = rollADice();
                    temp1 = 1;
                }
                if(diceChar == '2' && dice2 != 0){
                    dice2 = rollADice();
                    temp2 = 1;
                }
                if(diceChar == '3' && dice3 != 0){
                    dice3 = rollADice();
                    temp3 = 1;
                }
                if(diceChar == '4' && dice4 != 0){
                    dice4 = rollADice();
                    temp4 = 1;
                }
                if(diceChar == '5' && dice5 != 0){
                    dice5 = rollADice();
                    temp5 = 1;
                }
                if(diceChar == '6' && dice6 != 0){
                    dice6 = rollADice();
                    temp6 = 1;
                }
                scanf("%c",&diceChar);
            }

            if(!temp1){
                dice1 = 0;
            }
            if(!temp2){
                dice2 = 0;
            }
            if(!temp3){
                dice3 = 0;
            }
            if(!temp4){
                dice4 = 0;
            }
            if(!temp5){
                dice5 = 0;
            }
            if(!temp6){
                dice6 = 0;
            }

        }else{
            if(sumOfStraight(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
                userPoints += sumOfStraight(dice1,dice2,dice3,dice4,dice5,dice6);
            }
            else if(sumOfSixOfAKind(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
                userPoints += sumOfSixOfAKind(dice1,dice2,dice3,dice4,dice5,dice6);
            }
            else if(sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
                userPoints += sumOfThrees(dice1,dice2,dice3,dice4,dice5,dice6);
            }
            else if(sumOnes(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
                userPoints += sumOnes(dice1,dice2,dice3,dice4,dice5,dice6);
            }
            else if(sumFives(dice1,dice2,dice3,dice4,dice5,dice6) > 0){
                userPoints += sumFives(dice1,dice2,dice3,dice4,dice5,dice6);
            }
            else{
                return userPoints;
            }
        }
    }

    return userPoints;
}

//prints scoresheet
void scoreSheet(int compScore,int playerScore){
    printf("\nOur Scoresheet");
    printf("\n=============================");
    printf("\nMy score\tYour score");
    printf("\n%d\t\t%d",compScore,playerScore);

}

int main() {
    srand(time(NULL));

    int  diceDeciderP1 = 0,// dice rolled to see who's going to start
            diceDeciderP2 = 0;
    int rounds,count = 1;// rounds and count to keep track of rounds
    char contGameChar; // Y or N
    int sumComps = 0,sumPlayer = 0,tempCompSum,tempPlayerSum;// sums to keep track of points

    printf("Welcome to the Zonk game.\n"
                   "How many rounds would you like to play? ");
    scanf("%d",&rounds);
    printf("OK, lets get started!\n");

    for(count;count <= rounds;count++){
        fflush(stdin);
        diceDeciderP1 = rollADice();
        printf("\nI have rolled the dice and got %d!\n"
                       "Are you ready to Zonk! Shall I roll the dice for you (Y/N)?",diceDeciderP1);
        scanf("%c",&contGameChar);

        charError(contGameChar);// check input error

        if(contGame(contGameChar)){
            diceDeciderP2 = rollADice();
            printf("I have rolled the dice for you and you got %d",diceDeciderP2);
            fflush(stdin);
        }
        else{
            printf("\nHope to see you next time ! Byee !\n");
            break;
        }

        if(diceDeciderP1 >= diceDeciderP2){//computer starts if dice is greater or equal to player's
            tempCompSum = playComputer();
            if(tempCompSum == 0){
                printf("\nMy score: Z");
            }else{
                printf("\nMy score: %d",tempCompSum);
            }
            sumComps += tempCompSum;
            tempPlayerSum = playUser();

            if(tempPlayerSum == 0){
                printf("\nYour score: Z");
            } else{
                printf("\nYour score: %d",tempPlayerSum);
            }
            sumPlayer += tempPlayerSum;
        }
        else{
            printf("\nYour score: %d",sumPlayer += playUser());
            printf("\nMy score: %d",sumComps += playComputer());
        }
        scoreSheet(sumComps,sumPlayer);
    }

    if(sumPlayer > sumComps){
        printf("\nYOU ARE THE WINNER!");
    } else if(sumPlayer == sumComps){
        printf("\nWE'VE TIED!");
    } else{
        printf("\nI AM THE WINNER!");
    }

    return 0;
}