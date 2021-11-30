//
//  Movie.cpp
//  MovieUSingLinkedList
//
//  Created by Kemal Abdulrahman on 7/27/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//



#include <stdio.h>
#include "Movie.h"
#include<string>
using namespace std;
// this is the constructor
Movie:: Movie(){
   numberOfNodes = 0;
   root = NULL;
}


// it will create a new node to the list
node * Movie::newnode(string name,int year,int rating){  // WILL ALLOCATE THE MEMORY TO THE NODE
   node *temp = new node;
   temp->name = name;
   temp->rating = rating;
   temp->year = year;
   temp->next = NULL;
   return temp;
}

// this function will add the node to the linked list
void Movie:: add(string name,int year,int rating){
   //insert in the list.
   if(root == NULL){  // if the root is null ,then  assign the new node to the linked list
      root = newnode(name, rating, year);
      return;
   }else{ // otherwise loop through the linked list until it reaches the end.
      struct node *ptr = root;

      //looping till the end of the linked list


      while(ptr->next != NULL){
         ptr = ptr->next;
      }
      ptr->next = newnode(name, rating, year);
   }
   numberOfNodes ++;
   return;

}
// this function will update the value for the desired node.
void Movie:: update(){
   string name;
   int rating;
   int year;
   int sequenceNumber;
   cout<<"Enter the squence number to update" << " [1- " << numberOfNodes + 1<<" ]";
   //update
   cin>>sequenceNumber ;
   cout<<"Enter the movie name to update ";
   cin.ignore();
   getline(cin,name);
   cout<<"Enter the year to update ";
   cin>> year;
   cout<<"Enter the rating to update ";
   cin>> rating;
   int i = 1;
   struct node *temp = root;
   while(temp != NULL && i<sequenceNumber){  // go into the direction of looking node .
      temp = temp->next;
      i++;
   }
   temp->name = name;
   temp->rating = rating; // it is updating all the values corresponding to the desired input values.
   temp->year = year;
   return;
}

// it will list all the movies.
void Movie::listAllMovies(){
   node *ptr = root;

   cout<<"# Title                         Viewed Rating\n";
   cout<<"---------------------------------------------\n";
   int i =1;
   // it will traverse all nodes one by one and print the information.
   while(ptr!= NULL){
      cout<<i<<"  "<<ptr->name << "                           "<<ptr->year << "    "<<ptr->rating<<"\n";
      ptr = ptr->next;
      i++;
   }
}

//this function is remove the node from the linked list.
void Movie::removeMovie(){
   if(numberOfNodes <0){
      cout<<"List is empty\n";
      return;
   }
   int sequenceNumber;
   cout<<"Enter the sequence number to be deleted" << "[1- " << numberOfNodes + 1 <<" ]";
   cin>>sequenceNumber;
   struct node *ptr = root;
   int i=1;
   while (ptr!=NULL && i<sequenceNumber-1) {  // go until the matching sequencenumber matches .
      ptr = ptr->next;
      i++;
   }
   if(ptr == root){  // if it is root then change the root.
      node *temp = root;
      root = root->next;
      delete temp;
   }else{  // if the desired node is not root, then remove the node from the node .
      node *temp = ptr->next;
      if(temp->next){
         ptr->next = temp->next;
      }else{
         ptr->next = NULL;
      }
      delete temp;
   }
   numberOfNodes--;  // decrement the number of nodes in the linked list,
}
//this function is sorting the linked list on the basis of title/name of the movie.
void Movie::arrangeByTitle(){
   //sorting the linked list.
   for (node *p = root; p; p = p->next)
      for (node* q = p->next; q; q = q->next)
         if (q->name < p->name)
         {
            // swap entire content
            swap(*p, *q);

            // swap ptr to original value
            swap(p->next, q->next);
         }
}
//this function is sorting the linked lists on the year saw.
void Movie::arrangeByYearViewed(){
   //sorting the linked list.
   for (node *p = root; p; p = p->next)
      for (node* q = p->next; q; q = q->next)
         if (q->year < p->year)
         {
            // swap entire content
            swap(*p, *q);

            // swap ptr to original value
            swap(p->next, q->next);
         }
}
// this function is sorting the list by rating.
void Movie::arrangeByRating(){
   //sorting the linked list.
   for (node *p = root; p; p = p->next)  // two loops //first one
      for (node* q = p->next; q; q = q->next) //second one
         if (q->rating < p->rating)
         {
            // swap entire content
            swap(*p, *q);   // this is swaping the content of the two nodes.

            // swap ptr to original value
            swap(p->next, q->next);  // this is adjusting the links of the nodes.
         }
}
//removing the all nodes  memory.
Movie:: ~Movie(){
   //deallocate the memory.
   node *ptr = root;
   while(ptr!=NULL){
      node *temp = ptr;
      delete temp;
      ptr = ptr->next;
   }

}

//this is the menu function we need to display.
void Movie::menu(){
   cout<<"A Add a Movie"<<"\n";
   cout<<"U update the moview\n";
   cout<<"E remove the movie\n";
   cout<<"L List all movies \n";
   cout<<"T Arrange by title\n";
   cout<<"V Arrange by year saw\n";
   cout<<"R arrange by rating\n";
   cout<<"Q Quit\n";
}
