# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <conio.h>
# include <math.h>

char *name;
int money = 0;
int betMoney = 0;
int betLine = 0;

int random(int n1, int n2){
	rand();
	return floor(((float)(rand())/(float)(RAND_MAX)) * (n2-n1)) +n1;
}
char* getName(){
	printf("Enter your name :");
	char x[30];
	fgets(x,30,stdin);
	static char userName[30];
	int lingth = strlen(x);
	for(int i =0; i < lingth-1;i++){
		userName[i] = x[i];
	}

	return userName;
}
int getMoney(){
	int themoney;
	char input[20];
	printf("hello %s, ",name);
	int cheack = 0;
	while (cheack == 0){
		printf("plase enter your money :");
		fgets(input,20,stdin);
		int i=0 ;
		int ifInt = 1;
		int lingth = strlen(input);
		while( i < lingth-1 ){
			if (! (input[i]>='0' && input[i]<='9')){
				printf("Invalide number! ");
				ifInt = 0;
				break;
			}
			i++;
		}
		if(ifInt == 1){
			themoney = atoi(input);
			break;
		}
	}
	return themoney;
}
int getBetLine(){
	int betline;
	char enterBetLine[20];
	int x = 0;
	while (x==0){
		printf("Enter your line bitwing (1/3) to bet on :");
		fgets(enterBetLine,20,stdin);
		int cheack = 1;
		int i =0;
		int lingth = strlen(enterBetLine);
		while(i<lingth-1){
			if(!(enterBetLine[i]>='0'&&enterBetLine[i]<='9')){
				printf("Invalide number! ");
				cheack = 0;
				break;
			}
			i++;
		}
		if (cheack == 1){
			betline = atoi(enterBetLine);
			break;
		}
	}
	if (betline > 0 && betline <4){
		printf("\n");
		return betline-1;
	}else{
		printf("place make sure your bet line is betwing 1 and 3 !!\n");
		getBetLine();
	}
}
int getBetMoney(){
	int betmoney;
	printf("your balance is %d$, ",money);
	char enterMoney[20];
	int x =0; 
	while(x ==0){
		printf("how much you wanna bet on :");
		fflush(stdin);
		fgets(enterMoney,20,stdin);
		int i= 0 ; 
		int cheack = 1;
		int lingth = strlen(enterMoney);
		while(i < lingth-1){
			if (!(enterMoney[i]>='0' && enterMoney[i]<='9')){
				printf("Invalide number! ");
				cheack = 0;
				break;
			}
			i++;
		}
		if(cheack == 1){
			betmoney = atoi(enterMoney);
			break;
		}
	}

	if ( betmoney <= money){
		money -= betmoney;
		return betmoney;
	}else{
		printf("you enter more than what you have!\n");
		getBetMoney();
	}
}
void startGame(){
	char characters[]={ 'A', 'B', 'C', 'D', 'E', 'F'};
	char chars[3][3]={{'A', 'A', 'A'}, {'A', 'A', 'A'}, {'A', 'A', 'A'}};
	for (int i = 0; i<3; i++){
		int lingth = 6;
		char mychars[lingth];
		for (int a = 0; a<lingth; a++){
			mychars[a] = characters[a];
		}
		for(int j=0; j<3; j++){
			int rand = random(0,5) ;
			chars[i][j] = mychars[rand];
			for (int e=rand; e<lingth-1; e++ ){
				mychars[e]=mychars[e+1];
			}
			lingth--;
		}
	}
	printf(
		"\t%c | %c | %c\n\t%c | %c | %c\n\t%c | %c | %c \n\n",
		chars[0][0], chars[1][0], chars[2][0], 
		chars[0][1], chars[1][1], chars[2][1], 
		chars[0][2], chars[1][2], chars[2][2]
	);
	if(chars[0][betLine] == chars[1][betLine] && chars[1][betLine] == chars[2][betLine]){
		int win = betMoney * 10;
		money += win;
		printf("\t\tYou win, you earn %d$\n\t\tYour balance now is %d$\n\n", win, money);
	}else{
		printf("\t\tYou lose -%d\n\t\tYour balance now is %d$\n\n", betMoney, money);
	}
}
int main(){
	srand(time(0));
	name = getName();
	money = getMoney();
	int i = 0;
	while(i == 0){
		if(money>0){
			betMoney = getBetMoney();
			betLine = getBetLine();
			startGame();
			printf("you wanna play again? (y/n) :");
			char answor;
			scanf("%s",&answor);
			if (answor == 'y'){
				printf("\n");
			}else{
				printf("Your money is %d$\n\tGood bye %s ",money, name);
				break;
			}
		}else{
			printf("Your balance is 0$, you can't play. \n\t\t Have a good day %s :)",name);
			break;
		}
		
	}
	
	getch();
}