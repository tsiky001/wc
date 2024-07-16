#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

void nooption(char* argv)
{
	FILE* f = NULL;
	int nombreMots = 0 ;
	int nombreLignes = 0 ;
	int nombreCar = 0 ;
	int max = 0 ;

	tailV(argv);
	f=open(argv);
	nombreMots=countwords(f);
	printf("il y a %d mots\n",nombreMots);
	nombreCar=countchar(f);
	printf("il y a %d caractères\n",nombreCar);
	nombreLignes=countlines(f);
	printf("il y a %d lignes\n",nombreLignes);
	max=maxline(f,nombreLignes);
	printf("la ligne la plus longue a %d caractères\n",max);
	close(f);
	printf("\n");
}


void option(char* argv,char* argt)
{
	FILE* f = NULL;
	int nombreMots = 0 ;
	int nombreLignes = 0 ;
	int nombreCar = 0 ;
	int max = 0 ;
	int j = 0 ;
	int length = 0 ;
	length = strlen(argv);

	tailV(argt);
	for(j=0 ; j<length ; j++)
	{
		if(argv[j] =='c')
		{
			f=open(argt);
			nombreCar=countchar(f);
			printf("il y a %d caractères\n",nombreCar);
			close(f);
		}
		
		if(argv[j] =='w')
		{
			f=open(argt);
			nombreMots=countwords(f);
			printf("il y a %d mots\n",nombreMots);
			close(f);
		}
		
		if(argv[j] =='l')
		{
			f=open(argt);
			nombreLignes=countlines(f);
			printf("il y a %d lignes\n",nombreLignes);
			close(f);
		}
		
		if(argv[j] =='L')
		{
			f=open(argt);
			nombreLignes=countlines(f);
			max=maxline(f,nombreLignes);
			printf("la ligne la plus longue a %d caractères\n",max);
			close(f);
		}
	}
	printf("\n");
}



int countchar(FILE* f)
{
	char car ;
	int nombreCar=0 ;
	rewind(f);
	while((car=fgetc(f))!=EOF)
	{
		nombreCar++;
	}

	return (nombreCar) ;
}

int maxline(FILE* f , int line)
{
	int* tab = NULL;
	int max =0;
	int i ;
	char car ;
	int nombreCar=0;
	rewind(f);

	tab=malloc(line*sizeof(int));
	rewind(f);
	
	for(i=0 ; i<line; i++)
	{
		while((car=fgetc(f))!='\n')
		{
			nombreCar++;
		}
		tab[i]=nombreCar;
		nombreCar = 0 ;
	}
	
	max = tab[0];
	
	for(i=0 ; i<line ; i++){
		if(tab[i]>max)
		{
			max=tab[i];
		}
	}

	return (max) ;
}

int countlines(FILE* f)
{
	char car ;
	int nombreLignes=0;
	rewind(f);
	while((car=fgetc(f))!=EOF)
	{
		if(car=='\n')
		nombreLignes++;
	}
	
	return (nombreLignes) ;
}

FILE* open(char* argv)
{
	FILE* f=NULL;
	f=fopen(argv,"r");
	if(f==NULL)
	{
		printf("Erreur lors de l'ouverture");
	}
	return (f);
}

void close(FILE* f)
{
	if(f!=NULL)
	{
		fclose(f);
	}
	else
	{
		printf("Le fichier n'a meme pas été ouvert");
	}
}

int countwords(FILE* f)
{
	rewind(f);
	int nombreMots = 0;
	char car ;
	
	while((car=fgetc(f))!=EOF)
	{
		if(car==' ' || car=='\t' || car=='\n')
		{
			fseek(f , -2, SEEK_CUR);
			car=fgetc(f);
			if(car!=' ' && car!='\t' && car!='\n')
			{
				nombreMots++;
			}
			fseek(f , 2 , SEEK_CUR);
		}
	}

	return (nombreMots);
}

void tailV(char* argv)
{
	printf("%s\n",argv);
}
