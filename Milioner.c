#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define HLIN	'-'
#define VLIN	'|'
#define UGAO	'+'
#define PRAZNO	' '
#define SIRINA	60
#define DUZINA	30
#define MAX	22
#define UNOS	4

/*Protocna struktura*/
struct pit_i_odg{
	char pitanje[SIRINA-2+1]; 
	char odg1[MAX+1], odg2[MAX+1], odg3[MAX+1], odg4[MAX+1];
	}pio;

/*pocetni ekran*/
void hokvir(int l, int i, int number, int k);
void sokvir(int l, int i, int number, char p, int k);
void znakovi(int n, char c, int number, int k);

/*Glavni ekran*/
void hokvir1(int l);
void znakovi1(int n, char c);
void okvir1(int l);

FILE *glavni;


main()
{	int i, j, number, k=0, l, m, pozicija, tacan, pare, kraj, polapola, prvo, drugo, trece, cetvrto, dvanema, dvaiskorisceno;
	char p[]="Sacekajte...", d, abcd;
	
	const char pitanja[UNOS][SIRINA-2+1]=
	{	"Koji je zid izgradjen 1961 godine?",
		"Cija je valuta forinta?",
		"Kada neko u fudbalu sam sebi da gol, to je?",
		"Pesmu Good Vibration pevala je grupa?",
	};

const char odgovori[UNOS*4][MAX+1]=
	{	"Berlinski zid",
		"Zid placa",
		"Kineski zid",
		"Zid srama",
		"Poljska",
		"Madjarska",
		"Bugarska",
		"Austrijska",
		"Samostrel",
		"Harakiri",
		"Autogol",
		"Zaledje",
		"The beach boys",
		"The monkeys",
		"The Queen",
		"The four tops"
	};
	
	
	/*Pocetni ekran*/
	while(k<20)
	{	system("CLS");
		for(i=0;i<20;i++)
			{	number = rand() % 10 + 1;
				hokvir(SIRINA, i, number, k);
			}
	
		for(j=0;j<10;j++)
			if(j==4 && k!=19)
			{	znakovi(i,VLIN, number, k);
				printf(" Igra se ucitava... ");
				znakovi(i,VLIN, number,k);
				putchar('\n');
			}
			else if(j==4 && k==19)
			{	znakovi(i,VLIN, number, k);
				printf("  Igra je ucitana   ");
				znakovi(i,VLIN, number,k);
				putchar('\n');
			}
			else if(j==6 && k==19)
			{	znakovi(i,VLIN, number, k);
				printf("  Pritisnite enter  ");
				znakovi(i,VLIN, number,k);
				putchar('\n');
			}
			else if(j==7 && k==19)
			{	znakovi(i,VLIN, number, k);
				printf("     za nastavak    ");
				znakovi(i,VLIN, number,k);
				putchar('\n');
			}
			else
				sokvir(i-1, i, 3, PRAZNO, k);
		

		for(i=20;i>0;i--)
			{	number = rand() % 10 + 1;
				hokvir(SIRINA, i-1, number, k);
			}
		k++;
	}
	
	/*Popunjavanje baze*/
	glavni=fopen("baza.bin","wb"); /*Sa proverom mi izlazi iz aplikacije, iako napravi fajl*/
	/*if((glavni=fopen("baza.bin","rb"))==NULL)
		{	printf("Greska");
			exit(1);
		}*/
	j=0;
	for(i=0;i<UNOS;i++)
		{	strcpy(pio.pitanje,pitanja[i]);
				l=strlen(pio.pitanje);
				for(m=0;m<(SIRINA-2-l);m++)
					strcat(pio.pitanje," ");

			strcpy(pio.odg1,odgovori[j++]);
			l=strlen(pio.odg1);
				for(m=0;m<(MAX+1-l-4);m++)
					strcat(pio.odg1," ");
			strcpy(pio.odg2,odgovori[j++]);
			l=strlen(pio.odg2);
				for(m=0;m<(MAX+1-l-4);m++)
					strcat(pio.odg2," ");
			strcpy(pio.odg3,odgovori[j++]);
			l=strlen(pio.odg3);
				for(m=0;m<(MAX+1-l-4);m++)
					strcat(pio.odg3," ");
			strcpy(pio.odg4,odgovori[j++]);
			l=strlen(pio.odg4);
				for(m=0;m<(MAX+1-l-4);m++)
					strcat(pio.odg4," ");
			fwrite(&pio, sizeof(pio), 1, glavni);
		}


	fclose(glavni);
	
	d=getchar();
	/*if(d>='NUL' && d<='z')*/
		system("CLS");


	start:
	pare=0;
	tacan=2;
	kraj=0;
	polapola=0;
	dvanema=0;
	dvaiskorisceno=0;

	/*Otvaranje fajla u slucaju svakog cistog starta*/
	glavni=fopen("baza.bin","rb");
	/*if((glavni=fopen("baza.bin","rb"))==NULL)
		{	printf("Greska");
			exit(1);
		}*/
	fread(&pio, sizeof(pio), 1, glavni);

	lok1:
	if(tacan==1)
		fread(&pio, sizeof(pio), 1, glavni);
		tacan=2;
		prvo=drugo=trece=cetvrto=0;

	lok0:
	/*Glavni ekran*/
	hokvir1(SIRINA-2);
	okvir1(SIRINA-2);
	puts("|     __   __  __  __     __  ________  __   __            |");
	puts("|    |  \\ /  ||  ||  |   |  ||   __   ||  \\ |  |           |");
	puts("|    |  | |  ||  ||  |__ |  ||  |__|  ||   \\|  |           |");
	puts("|    |__| |__||__||_____||__||________||__|\\ __|           |");
	puts("|                                     _____  _______       |");
	puts("|                                    |   __||   __  |      |");
	puts("|                                    |  |__ |  |__| |      |");
	puts("|                                    |   __||      _|      |");
	puts("|                                    |  |__ |  |\\  \\       |");
	puts("|                                    |_____||__| \\__|      |");
	okvir1(SIRINA-2);
	hokvir1(SIRINA-2);

	/*Pomoc*/
	hokvir1(MAX);
	putchar(VLIN);
	printf("1. Pomoc prijatelja   ");
	putchar(VLIN);
	putchar('\n');
	hokvir1(MAX);

	hokvir1(MAX);
	putchar(VLIN);
	printf("2. Pola-pola          ");
	putchar(VLIN);
	putchar('\n');
	hokvir1(MAX);

	hokvir1(MAX);
	putchar(VLIN);
	printf("3. Pomoc publike      ");
	putchar(VLIN);
	putchar('\n');
	hokvir1(MAX);
	
	putchar('\n');
	puts("PONUDJENO PITANJE:");

	/*Pitanje*/
	hokvir1(SIRINA-2);
	putchar(VLIN);
	printf(pio.pitanje);
	putchar(VLIN);
	putchar('\n');
	hokvir1(SIRINA-2);

	putchar('\n');
	putchar('\n');
	puts("PONUDJENI ODGOVORI:");

	/*Odgovor1*/
	if(drugo==1 || trece==1)
	{	putchar('\n');
		putchar('\n');
		putchar('\n');
	}
	else
	{	hokvir1(MAX);
		putchar(VLIN);
		printf("A. ");
		printf(pio.odg1);
		putchar(VLIN);
		putchar('\n');
		hokvir1(MAX);
	}
	
	/*Odgovor2*/
	if(prvo==1 || trece==1 || cetvrto==1)
	{	putchar('\n');
		putchar('\n');
		putchar('\n');
	}
	else
	{	hokvir1(MAX);
		putchar(VLIN);
		printf("B. ");
		printf(pio.odg2);
		putchar(VLIN);
		putchar('\n');
		hokvir1(MAX);
	}

	/*Odgovor3*/
	hokvir1(MAX);
	putchar(VLIN);
	printf("C. ");
	printf(pio.odg3);
	putchar(VLIN);
	putchar('\n');
	hokvir1(MAX);

	/*Odgovor4*/
	if(prvo==1 || drugo==1 || cetvrto==1)
	{	putchar('\n');
		putchar('\n');
		putchar('\n');
	}
	else
	{
		hokvir1(MAX);
		putchar(VLIN);
		printf("D. ");
		printf(pio.odg4);
		putchar(VLIN);
		putchar('\n');
		hokvir1(MAX);
	}

	puts("\nUnesite slovo za tacan odgovor ili broj za pomoc,\n");
	puts("                                   pritisnite enter\n");
	
	/*Uslovne radnje, a nize su glavne kombinacije*/
	if(tacan==1)
		{	printf("\nODGOVOR JE TACAN!!!\n");
			pare+=1000;
			if(kraj==1)
				{	printf("Cestitamo, pobedili ste!!!\n");
					printf("Osvojili ste %d dinara\n", pare);
					tacan=0;
					goto lok0;
				}
			else
			{	printf("\nDa li zelite da idete dalje?\n");
				do{
				scanf("%c", &abcd);
				getchar();
				}while(abcd!='d' && abcd!='D' && abcd!='N' && abcd!='n');
		
				if(abcd=='d' || abcd=='D')
				{	tacan=1;
					system("CLS");
					goto lok1;
				}
				else
					printf("Cestitamo, osvojili ste %d dinara!\n", pare);
			}
		}
	else if(tacan==0)
		{	printf("\nODGOVOR NIJE TACAN!!!\n");
			printf("\nDa li zelite da krenete iz pocetka?\n");
		
			do{
			scanf("%c", &abcd);
			getchar();
			}while(abcd!='d' && abcd!='D' && abcd!='N' && abcd!='n');
		
			if(abcd=='d' || abcd=='D')
			{	fclose(glavni);
				system("CLS");
				goto start;
			}
			else
				fclose(glavni);
				exit(1);
		}
	else if(dvaiskorisceno)
		{	printf("Vec ste iskoristili pomoc pola-pola\n");
			printf("Pritisnite enter");
			dvaiskorisceno=0;
			d=getchar();
			goto lok0;
		}
	/*glavne kombinacije*/
	else
		{	pozicija=ftell(glavni);
			/*printf("%d", pozicija);*/
	
			scanf("%c", &abcd);
			getchar();
			if(abcd=='2' && pozicija==151 && dvanema==0)
				{	prvo=1;
					dvanema=1;
					goto lok0;
				}
			else if(abcd=='2' && pozicija==302 && dvanema==0)
				{	drugo=1;
					dvanema=1;
					goto lok0;
				}
			else if(abcd=='2' && pozicija==453 && dvanema==0)
				{	trece=1;
					dvanema=1;
					goto lok0;
				}
			else if(abcd=='2' && pozicija==604 && dvanema==0)
				{	cetvrto=1;
					dvanema=1;
					goto lok0;
				}
			else if(pozicija=151 && (abcd=='A' || abcd=='a'))
			{	tacan=1;
				system("CLS");
				goto lok0;
		
			}
			else if(pozicija=302 && (abcd=='B' || abcd=='b'))
			{	tacan=1;
				system("CLS");
				goto lok0;
		
			}
			else if(pozicija=453 && (abcd=='C' || abcd=='c'))
			{	tacan=1;
				system("CLS");
				goto lok0;
		
			}
			else if(pozicija=604 && (abcd=='A' || abcd=='a'))
			{	tacan=1;
				system("CLS");
				kraj=1;
				goto lok0;		
			}
			else if(abcd=='2' && dvanema==1)
			{	dvaiskorisceno=1;
				goto lok0;
			}
			else
			{	tacan=0;
				system("CLS");
				goto lok0;
			}
		}

	return 0;
	
}
/*Pocetni ekran*/
void hokvir(int l, int i, int number, int k)
{	znakovi(i,VLIN, number, k);
	putchar(UGAO);
	znakovi(l-2*i-2,HLIN, number, k);
	putchar(UGAO);
	znakovi(i,VLIN, number, k);
	putchar('\n');

}
void znakovi(int n, char c, int number, int k)
{	while(n>0)
	{	n--;
		if(number!=2 || (number==2 && k==19))
			putchar(c);
		else
			putchar(' ');
	}

}
void sokvir(int l, int i, int number, char p, int k)
{	znakovi(i,VLIN, number, k);
	znakovi(i,p, number, k);
	znakovi(i,VLIN, number, k);
	putchar('\n');

}
/*Glavni ekran*/
void hokvir1(int l)
{	putchar(UGAO);
	znakovi1(l,HLIN);
	putchar(UGAO);
	putchar('\n');
}
void znakovi1(int n, char c)
{	while(n>0)
	{	n--;
		putchar(c);
	}
}
void okvir1(int l)
{	putchar(VLIN);
	znakovi1(l, ' ');
	putchar(VLIN);
	putchar('\n');
}


