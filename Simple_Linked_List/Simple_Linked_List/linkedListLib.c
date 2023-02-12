#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"
listElement* newNode(char* name, char* lastname, int age) {
    listElement* temp = (listElement*)malloc(sizeof(listElement));
    strcpy(temp->firstName, name);
    strcpy(temp->lastName, lastname);
    temp->age = age;
    temp->nextElem = NULL;
    return temp;
}

void addListElem(listElement* start)
{

    listElement* new;
    new = (listElement*)malloc(sizeof(listElement));
    if (new == NULL)
    {
        printf("can't reserve storage.\n");
        return;
    }
    

   listElement* currElem = start;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = new;          // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &(new->age));
}


void printList(listElement* start)
{//
     if (start->nextElem == NULL)
        printf("List is empty.\n");
   
    
    else
    {
        int i = 0;
        listElement* currElem = start;
        printf("\ncurrent list:\n\n");
        do
        {
            currElem = currElem->nextElem;
            printf("%d", i);
            i++;
            printf("\t last name: %s\n", currElem->lastName);
            printf("\t first name: %s\n", currElem->firstName);
            printf("\t age: %d\n", currElem->age);
        } while (currElem->nextElem != NULL);
    }
}

void delListElem(listElement* start)
{

    int position;

    printList(start);
    if (start->nextElem != NULL) {
        printf("Which element should be deleted?\n");
        scanf("%d", &position);
        position++;
    }
    else if (position < 1 && position >(getLenOfList(start))) {
        printf("Position is out of bounds.\n");
        return;
    }
    else {
        printf("List is empty.\n");
        return;
    }

    listElement* temp = start;

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->nextElem;
    if (temp == NULL || temp->nextElem == NULL)
        return;

    listElement* next = temp->nextElem->nextElem;

    free(temp->nextElem);

    temp->nextElem = next;
}

void delList(listElement* start)
{
    
    listElement* currElem = start;
    
    while (currElem != NULL) {
        start = start->nextElem;
        free(currElem);
        currElem->nextElem = NULL;
        currElem = start;
        
    }
    
    start = (listElement*)malloc(sizeof(listElement));
    start->nextElem = NULL;
   
    
    
    
}

int getLenOfList(listElement* start)
{ // we use this for save list fcn

    int counter = 0;
    listElement* currElem = start;
    while (currElem->nextElem != NULL)
    { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(listElement* start)
{   
    FILE* filePointer;
    char fileName[20];
    listElement* currElem = start;
    printf("How to call the document? Type with .txt: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w");

    if (filePointer == NULL) {
        printf("Could not open file");
        return ;
    }

    else {
        do
        {
            currElem = currElem->nextElem;
            
            fprintf(filePointer, "%s\n", currElem->lastName);
            fprintf(filePointer, "%s\n", currElem->firstName);
            fprintf(filePointer, "%d\n", currElem->age);
        } while (currElem->nextElem != NULL);
    }
}

 void loadList(listElement* start)
{   
    
    
    FILE* filePointer;
    char fileName[20];
    
    
    system("dir *.txt");
    printf("\n Type a name of the file, which you would like to load: ");
    scanf("%s", fileName);
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("Could not open file\n");
        return start;
    }
    char firstName[50], lastName[50]; 
    int age;
    
    


    
    listElement* tail = start;
    while (tail != NULL && tail->nextElem != NULL) {
        tail = tail->nextElem;
    }

        while (fscanf(filePointer, "%s\n%s\n%d", lastName, firstName , &age) != EOF) {
            listElement* temp = newNode(firstName, lastName, age);
            /*strcpy(temp->firstName, firstName);
            strcpy(temp->lastName, lastName);
            temp->age = age;*/
                
            if (start == NULL) {
                start = tail = temp;
            }
            else {


                tail->nextElem = temp;
                tail = temp;
            }
        }
    
    
    fclose(filePointer);
    printf("loading data will be append to current list...\n");
    printList(start); // show loaded list
   

    
}

void exitFcn(listElement* start)
{   
    char answer[2];
    char cleanAnswer;
    printf("\nWould you like to save your list?[y/n]: ");
    scanf("%s", answer);
    cleanAnswer = answer[0];
    if (cleanAnswer == 'y') {
        saveList(start);
        
    }
    

}
void swap(listElement* a, listElement* b) {
    listElement* temp = (listElement*)malloc(sizeof(listElement));

    temp->age = a->age;
    strcpy(temp->lastName, a->lastName);
    strcpy(temp->firstName, a->firstName);

    a->age = b->age;
    strcpy(a->lastName, b->lastName);
    strcpy(a->firstName, b->firstName);

    b->age = temp->age;
    strcpy(b->lastName, temp->lastName);
    strcpy(b->firstName, temp->firstName);
}
void sortList(listElement* start)
{
    int swapped, i;

    listElement* ptr1;
    listElement* lastptr = NULL;

    if (start == NULL) {
        return;
    }
    

        do {
            swapped = 0;
            ptr1 = start;
            while (ptr1->nextElem != lastptr) {
                if (ptr1->age > ptr1->nextElem->age) {
                    swap(ptr1, ptr1->nextElem);
                    swapped = 1;
                }
                ptr1 = ptr1->nextElem;

            }
            lastptr = ptr1;
        } while (swapped);
    
    printList(start);
    //printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char* string)
{

    printf("\n>>stringToLower fcn is tbd.\n\n");
}
