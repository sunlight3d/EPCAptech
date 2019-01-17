#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
	char name[50];
	char manufacturer[25];
	int release_year;
	float price;
} Mobile;

void inputMobile(Mobile *mobile, int n){
	int i;
	for(i=0; i<n; i++){
		printf("\nPlease input Mobile[%d]:",i+1);
		printf("Name: ");
		gets(mobile[i].name);
		
		printf("\nManufacturer: ");
		gets(mobile[i].manufacturer);
		
		INPUT1: printf("\nRelease Year: ");
		scanf("%d",&mobile[i].release_year);
		if(mobile[i].release_year < 1999){
			printf("\nMobile release year must be greater than or equal to 1999");
			goto INPUT1;
		}
		
		INPUT2: printf("\nPrice: ");
		scanf("%f",&mobile[i].price);
		if(mobile[i].price < 500 || mobile[i].price > 6000){
			printf("\nMobile price must be between 500($) and 6000($)");
			goto INPUT2;
		}
		fflush(stdin);
	}
}
void listMobiles(Mobile *mobiles, int n){
	int j = 0;
	printf("+-----------------------------------------------------\n");
	printf("|Smartphone		|Manufacture 	|Release Year	|Price($)");
	for (int i = 0; i < n; i++)         //Loop for ascending ordering
	{
		for (int j = 0; j < n; j++)     //Loop for comparing other values
		{
			if (strcmp(mobiles[j].name, mobiles[i].name) > 0)  //Comparing other array elements
			{
				Mobile tmp = mobiles[i];         //Using temporary variable for storing last value
				mobiles[i] = mobiles[j];            //replacing value
				mobiles[j] = tmp;             //storing last value
			}  
		}
	}
	
	while(j<n){
		printf("\n%s	%s		%d		%f",mobiles[j].name,mobiles[j].manufacturer,mobiles[j].release_year,mobiles[j].price);
		j++;
	}
}

void saveToFile(FILE *fptr, Mobile *mobiles, int n){
	int j = 0;			
	fwrite(mobiles, sizeof(Mobile), n, fptr);		
	fclose(fptr); 	
}
/*
void readFromFile(FILE *file, Mobile *mobiles, int n){
	int j = 0;			
	fwrite(&mobiles, sizeof(struct Mobi), 1, fptr);		
	file.close();	
}
*/
void analyzeMobiles(Mobile *mobiles, int n){
	int j = 0;
	printf("+-----------------------------------------------------\n");
	printf("Statistics Result:");
}
void findMobiles(Mobile *mobiles, char manufacturer[25], float min, float max, int n){
	Mobile *filteredMobiles = (Mobile *)malloc(n*sizeof(Mobile));
	int j = 0;
	int i = 0;
	printf("+-----------------------------------------------------\n");
	for (i = 0; i < n; i++) {
		if((mobiles[i].name == manufacturer) && (mobiles[i].price >= min) && (mobiles[i].price <= max)){
			filteredMobiles[j] = mobiles[i];
			j++;
		}
	}
	listMobiles(filteredMobiles, j+1);
}
int main(int argc, char** argv) {
	Mobile *mobiles;
	int n;
	START: printf("+-----------------------------------------------------\n");
	printf("|         MOBILE PHONE STORE MANAGEMENT PROGRAM      |\n");
	printf("|1.Input|2.Sort|3.Analyze|4.Find|5.Save|6.Open|7.Exit|\n");
	printf("+-----------------------------------------------------\n");
	int choice;
	printf("\nEnter your choice: ");
   	scanf("%d", &choice);
	switch(choice) {
      case 1 :
        printf("Input number of mobiles: ");
		scanf("%d",&n);
		fflush(stdin);
		mobiles = (Mobile *)malloc(n*sizeof(Mobile));
		inputMobile(mobiles,n);
        break;
      case 2 :
        listMobiles(mobiles, n);
        break;
      case 4 :
      	printf("\nSearch mobiles:");	
      	char manufacturer[25];
      	float min;
      	float max;
		printf("\nManufacture: "); 
		gets(manufacturer);
		printf("\nMin price($): "); 
		scanf("%f",&min);
		printf("\nMax price($): "); 
		scanf("%f",&max);
        findMobiles(mobiles, manufacturer, min, max, n);
        break;
      case 5 :
      	char fileName[50];
        printf("Save the list into file: ");
		scanf("%s",fileName);
		FILE *fptr;
		fptr = fopen(fileName,"wb");
		if(fptr == NULL) {
			printf("Error reading file");
			exit(1);
			break;
		}
		saveToFile(fptr, mobiles, n);
        break;
    
      default :
         printf("\nInvalid choice, choose 1-7\n" );
   	}
   	printf("\nDo you want to continue?");
   	char choice2;
   	scanf(" %c", &choice2);
   	if( choice2 == 'y' || choice2 == 'Y'){
		goto START;
   	} else if ( choice2 == 'n' || choice2 == 'N'){
		goto START;
   	} else if ( choice2 == 'c' || choice2 == 'C'){
   		system("cls");
   		goto START;
   	} else {
   		exit(1);
   	}
	return 0;
}

