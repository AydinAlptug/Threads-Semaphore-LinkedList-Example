#include"linkedList.h"
#include <string.h>
//Create and return a node with the given song
Node* createNode(Song *song){
    Node *newNode = malloc(sizeof(Node));
    newNode->Song = song;            
    newNode->link = NULL;
    
    return newNode;
} 

//checks if the list is empty or not
int isEmpty(Node *head){
	if(head==NULL)
		return 1;
	else
		return 0;	
} 

//adds given song to the list
void addNode(Node **head,Song* song){

	Node* current=*head;
	Node* newNode;
	newNode=malloc(sizeof(Node));
	newNode->Song = song;
	newNode->link = NULL;
	
	while(current->link != NULL){
		current = current->link;
	}
	current->link=newNode;
}

//Add given song to the given index 
void addNodeAt(Node **head, int index, Song* song){
	Node* current=*head;	
	Node* newNode;
	newNode=malloc(sizeof(Node));
	newNode->Song=song;
	newNode->link=NULL;

	int i=0;
	int size=getSize(*head);

	if (index < 1 || index > size + 1){
		printf("invalid index\n");
		return;
	}
	else{
		if(index==1){
			newNode->link=*head;
			*head=newNode;
			return;
			
		}
		for (i=1;i<index-1;i++){
			current = current->link;
		}
		newNode->link=current->link;
		current->link=newNode;
	}
}

//deletes the last node
Song* deleteNode(Node **head) {
	Node* current=*head;
	Node* prev=*head;
	Song* result;
		
	while (current->link != NULL) 
    	{
    		prev = current; 
       		current = current->link;	
    	}
	result = current->Song;
	prev->link = NULL;
	return result;
}
//delete songs with given genre 
void deleteSongWithGenre(Node **head, char* genre) {
     Node* temp = *head;
     Node* prev = *head;	
  
    while (temp != NULL && strcmp(temp->Song->genre,genre) == 0) 
    { 
        *head = temp->link;   
        free(temp);           
        temp = *head;         
    } 
  
    // Delete occurrences other than head 
    while (temp != NULL) 
    { 
        while (temp != NULL && strcmp(temp->Song->genre,genre) != 0) 
        { 
            prev = temp; 
            temp = temp->link; 
        }     
        if (temp == NULL) return; // If song with given genre was not present in linked list
        prev->link = temp->link; 
        free(temp); 
        temp = prev->link; 
    } 
}

//delete songs older than given year
void deleteSongsOlderThan(Node **head, int year) {
	Node* current=*head;
	Node* prev=*head;
	while (current != NULL) 
    	{
    		if(current->Song->year < year){
			if(current == *head)
				*head =	current->link; 
    			current = current->link;
    			prev->link = current;
    		}
    		else{
    			prev = current; 
       			current = current->link;	
    		}
    	}
}

//Return size of the list
int getSize(Node *head){
	int size=0;
	Node *current=head;
	while(current!=NULL){
		size++;
		current=current->link;	
	}
	return size;
}

//print the songs in the list
void printList(Node *head){
	Node *current = head;
   	 while (current != NULL) {
         	printf("Name: %s Genre: %s Year: %d\n", current->Song->name, current->Song->genre, current->Song->year);
         	current = current->link;
   	 }
} 

//Return number of occurrences of a song
int getFrequency(Node *head, Song* song){
	int freq=0;
	Node *current=head;
	while(current!=NULL){
		if(strcmp(current->Song->name,song->name))
			freq++;
		current=current->link;	
	}
	return freq;
}

