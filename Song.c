#include<string.h>

struct song {
	char name [25];
	char genre [15];
	int year;//(1992)
	struct song *link;
};

typedef struct song Song;


Song* createSong(char* name,char* genre,int year){
   	Song *newSong = malloc(sizeof(Song));
   	strcpy(newSong->name,name); 
	strcpy(newSong->genre,genre);  
	newSong->year = year;       
   	newSong->link = NULL;
   	return newSong;
} 


