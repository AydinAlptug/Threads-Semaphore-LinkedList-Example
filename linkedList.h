#include<stdio.h>
#include<stdlib.h>
#include "Song.c"
struct node{
    struct song *Song;
    struct node *link;
};


typedef struct node Node;

Node* createNode(Song* song); //Create and return a node with the given song
int isEmpty(Node *head); //checks if the list is empty or not
void addNode(Node **head,Song* song);//adds given song to the list
void addNodeAt(Node **head, int index, Song* song); //Add given song to the given index
Song* deleteNode(Node **head); //deletes the last node
void deleteSongsOlderThan(Node **head, int year); //delete songs older than given year
void deleteSongWithGenre(Node **head, char* genre); //delete songs with given genre 
int getSize(Node *head); //Return size of the list
void printList(Node *head); //print the songs in the list
int getFrequency(Node *head, Song* song); //Return number of occurrences of a song
