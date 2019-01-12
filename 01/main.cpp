#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	printf("+-----------------------------------------------------");
	printf("|         MOBILE PHONE STORE MANAGEMENT PROGRAM      |");
	printf("|1.Input|2.Sort|3.Analyze|4.Find|5.Save|6.Open|7.Exit|");
	printf("+-----------------------------------------------------\n");
	int choice;
	printf("Enter your choice: ");
   	scanf("%d", &choice);
	switch(choice) {
      case 1 :
         printf("1. Input\n" );
         break;
      case 2 :
         printf("2. Sort\n" );
         break;
      default :
         printf("Invalid choice, choose 1-7\n" );
   	}
   	printf("Do you want to continue?");
   	char choice2;
   	scanf(" %c", &choice2);
   	if( choice2 == 'y' || choice2 == 'Y'){

   	} else if ( choice2 == 'n' || choice2 == 'N'){

   	} else if ( choice2 == 'c' || choice2 == 'C'){
   		system("cls");
   	} else {
   		exit(1);
   	}
	return 0;
}

