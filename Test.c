#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<time.h>
#include <semaphore.h>
#include <unistd.h>
#include "linkedList.c"

/* Yusuf Alptug Aydin-260201065*/
/*you may remove the comments to observe steps.*/

Node *head1;
Node *head2;
Node *head3;
int year;
char genre[20];
sem_t lock1;
sem_t lock2;
sem_t lock3;

//procedure cuts songs from playlists and adds to userlist
void* procedureForThreadTypeA(void * arg){
	sem_wait(&lock1);
	sem_wait(&lock3);


	Song *willBeAdded;
	int i,r;
	srand(time(NULL));
	r = ( rand() % 10 ) + 1;
	if(head1 != NULL ){
		if(r > getSize(head1)){
			r = getSize(head1);
		}
		if(head3 == NULL){
			willBeAdded = deleteNode(&head1);
			head3 = createNode(willBeAdded);
			r--;
		}
		for(i=0;i<r;i++){
			if(getSize(head1)==1){
				willBeAdded = deleteNode(&head1);
				head1= NULL;
			}
			else{
				willBeAdded = deleteNode(&head1);
			}
			addNode(&head3,willBeAdded);
			
		}
	}
/*
	printf("Updated Playlist 1 is after deletion: \n\n");
	printList(head1);
	printf("\n***********************************UserList:************************************ \n");
	printList(head3);
	printf("********************************************************************************\n\n");
*/
	sem_post(&lock1);
	sem_post(&lock3);

//*****************************************************************************************************************************
	sem_wait(&lock2);
	sem_wait(&lock3);


	srand(time(NULL));
	r = ( rand() % 10 ) + 1;
	if(head2 != NULL ){
		if(r > getSize(head2)){
			r = getSize(head1);
		}
		if(head3 == NULL){
			willBeAdded = deleteNode(&head2);
			head3 = createNode(willBeAdded);
			r--;
		}
		for(i=0;i<r;i++){
			if(getSize(head2)==1){
				willBeAdded = deleteNode(&head2);
				head2= NULL;
			}
			else{
				willBeAdded = deleteNode(&head2);
			}
			addNode(&head3,willBeAdded);
			
		}
	}
/*	printf("Updated Playlist 2 is after deletion: \n\n");
	printList(head2);
	printf("\n***********************************UserList:************************************ \n");
	printList(head3);
	printf("********************************************************************************\n\n");
*/
	sem_post(&lock2);
	sem_post(&lock3);

//******************************************************************************************************************************
	pthread_exit(NULL);
}

//procedure removes undesired type of songs
void* procedureForThreadTypeB(void * arg){
	sem_wait(&lock1);
//	printf("\nDeleting from playlist1 by genre..\n");
	deleteSongWithGenre(&head1,genre);
//	printf("Updated Playlist 1 is: \n");
//	printList(head1);
	sem_post(&lock1);
	
	sem_wait(&lock2);
//	printf("\nDeleting from playlist2 by genre..\n");
	deleteSongWithGenre(&head2,genre);
//	printf("Updated Playlist 2 is: \n");
//	printList(head2);
	sem_post(&lock2);
	
	sem_wait(&lock3);
//	printf("\nDeleting from UserPlaylist by genre..\n");
	deleteSongWithGenre(&head3,genre);
//	printf("Updated UserPlaylist is: \n");
//	printList(head3);
	sem_post(&lock3);

	pthread_exit(NULL);
}

//procedure removes songs older than desired year
void* procedureForThreadTypeC(void * arg){
	sem_wait(&lock1);
//	printf("\nDeleting from playlist1 by year..\n");
	deleteSongsOlderThan(&head1,year);
//	printf("Updated Playlist 1 is: \n");
//	printList(head1);
	sem_post(&lock1);
	
	sem_wait(&lock2);
//	printf("\nDeleting from playlist2 by year..\n");
	deleteSongsOlderThan(&head2,year);
//	printf("Updated Playlist 2 is: \n");
//	printList(head2);
	sem_post(&lock2);
	
	sem_wait(&lock3);
//	printf("\nDeleting from UserPlaylist by year..\n");
	deleteSongsOlderThan(&head3,year);
//	printf("Updated UserPlaylist is: \n");
//	printList(head3);
	sem_post(&lock3);

	pthread_exit(NULL);
}

int main(){

	printf("Please enter the ""year"" to delete songs older than: ");
	scanf("%d",&year);
	printf("Please enter the undesired ""genre"": ");
	scanf("%s",genre);
	printf("\nProcessing..\n");
//------------------------creation of Playlist 1-----------------------------
	Song *newSong1 = createSong("song1","pop",1971);
	Node *newNode1 = createNode(newSong1);	
    	head1 = newNode1;
	Song *newSong2 = createSong("song2","rock",1972);
	Song *newSong3 = createSong("song3","pop",1973);
	Song *newSong4 = createSong("song4","folk",1974);
	Song *newSong5 = createSong("song5","rock",1975);
	Song *newSong6 = createSong("song6","pop",1976);
	Song *newSong7 = createSong("song7","folk",1977);
	Song *newSong8 = createSong("song8","pop",1978);
	Song *newSong9 = createSong("song9","rock",1979);
	Song *newSong10 = createSong("song10","pop",1980);
	Song *newSong11 = createSong("song11","folk",1981);
	Song *newSong12 = createSong("song12","rock",1982);
	Song *newSong13 = createSong("song13","pop",1983);
	Song *newSong14 = createSong("song14","pop",1984);
	Song *newSong15 = createSong("song15","rock",1985);
	Song *newSong16 = createSong("song16","folk",1986);
	Song *newSong17 = createSong("song17","rock",1987);
	Song *newSong18 = createSong("song18","pop",1988);
	Song *newSong19 = createSong("song19","folk",1989);
	Song *newSong20 = createSong("song20","folk",1990);
	addNode(&head1,newSong2);
	addNode(&head1,newSong3);
	addNode(&head1,newSong4);
	addNode(&head1,newSong5);
	addNode(&head1,newSong6);
	addNode(&head1,newSong7);
	addNode(&head1,newSong8);
	addNode(&head1,newSong9);
	addNode(&head1,newSong10);
	addNode(&head1,newSong11);
	addNode(&head1,newSong12);
	addNode(&head1,newSong13);
	addNode(&head1,newSong14);
	addNode(&head1,newSong15);
	addNode(&head1,newSong16);
	addNode(&head1,newSong17);
	addNode(&head1,newSong18);
	addNode(&head1,newSong19);
	addNode(&head1,newSong20);
/*
	printf("\nFirst form of Playlist 1: \n");
	printList(head1);
	printf("\n");
*/

//-----------------------creation of Playlist 2----------------------------
	Song *newSong001 = createSong("song001","rock",1971);
	Node *newNode2 = createNode(newSong001);	
    	head2 = newNode2;
	Song *newSong002 = createSong("song002","folk",1972);
	Song *newSong003 = createSong("song003","pop",1973);
	Song *newSong004 = createSong("song004","rock",1974);
	Song *newSong005 = createSong("song005","pop",1975);
	Song *newSong006 = createSong("song006","pop",1976);
	Song *newSong007 = createSong("song007","pop",1977);
	Song *newSong008 = createSong("song008","rock",1978);
	Song *newSong009 = createSong("song009","folk",1979);
	Song *newSong0010 = createSong("song0010","rock",1980);
	Song *newSong0011 = createSong("song0011","folk",1981);
	Song *newSong0012 = createSong("song0012","rock",1982);
	Song *newSong0013 = createSong("song0013","pop",1983);
	Song *newSong0014 = createSong("song0014","folk",1984);
	Song *newSong0015 = createSong("song0015","pop",1985);
	Song *newSong0016 = createSong("song0016","folk",1986);
	Song *newSong0017 = createSong("song0017","pop",1987);
	Song *newSong0018 = createSong("song0018","folk",1988);
	Song *newSong0019 = createSong("song0019","rock",1989);
	Song *newSong0020 = createSong("song0020","pop",1990);
	addNode(&head2,newSong002);
	addNode(&head2,newSong003);
	addNode(&head2,newSong004);
	addNode(&head2,newSong005);
	addNode(&head2,newSong006);
	addNode(&head2,newSong007);
	addNode(&head2,newSong008);
	addNode(&head2,newSong009);
	addNode(&head2,newSong0010);
	addNode(&head2,newSong0011);
	addNode(&head2,newSong0012);
	addNode(&head2,newSong0013);
	addNode(&head2,newSong0014);
	addNode(&head2,newSong0015);
	addNode(&head2,newSong0016);
	addNode(&head2,newSong0017);
	addNode(&head2,newSong0018);
	addNode(&head2,newSong0019);
	addNode(&head2,newSong0020);
/*
	printf("First form of Playlist 2: \n");
	printList(head2);
	printf("\n");

	printf("\nFirst form of User Playlist: \n");
	printList(head3);
	printf("\n");
*/

//-------------------------semaphores are initialized-----------------------
	sem_init(&lock1, 0, 1);
	sem_init(&lock2, 0, 1);
	sem_init(&lock3, 0, 1);
//--------------------------------------------------------------------------
	pthread_t threads[5];

	int* p1 = malloc(sizeof(int));
 	//*p1=0;
	int* p2 = malloc(sizeof(int));
	//*p2=1;
	int* p3 = malloc(sizeof(int));
	//*p3=2;
	int* p4 = malloc(sizeof(int));
	//*p4=3;
	int* p5 = malloc(sizeof(int));
	//*p5=4;

	int flag =1;
	while(flag==1){	//the loop will guarantee that the playlists will be empty at the end
		//threads are created
		pthread_create(&threads[0],NULL,procedureForThreadTypeA,p1);
		pthread_create(&threads[1],NULL,procedureForThreadTypeA,p2);
		pthread_create(&threads[2],NULL,procedureForThreadTypeA,p3);
		pthread_create(&threads[3],NULL,procedureForThreadTypeB,p4);
		pthread_create(&threads[4],NULL,procedureForThreadTypeC,p5);
	
		pthread_join(threads[0], NULL);//thread A
		pthread_join(threads[1], NULL);//thread A
		pthread_join(threads[2], NULL);//thread A
		pthread_join(threads[3], NULL); //thread B
		pthread_join(threads[4], NULL);// thread C
		if(getSize(head1) == 0 && getSize(head2) == 0)
			flag = 0;
	}	






	
	printf("\nLast Forms of Lists:\n");
	printf("Playlist 1: \n");
	printList(head1);
	printf("\n");
	printf("Playlist 2: \n");
	printList(head2);
	printf("\n");
	printf("User Playlist: \n");
	printList(head3);
	printf("\n");

	
	return 0;
}
