//
//  Movie.h
//  MovieUSingLinkedList
//
//  Created by Kemal Abdulrahman on 7/13/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//

#ifndef Movie_h
#define Movie_h
#include<string>

using namespace std;
typedef struct node{
   string name;
   int rating;
   int year;
   struct node *next;
}node;

class Movie{
private:
   int numberOfNodes; // number of nodes in the linked list.
   node *root;  //head of the linked list
public:
   Movie(); // constructor
   void add(string name,int year,int rating);
   void update();
   void removeMovie();
   void arrangeByTitle();
   void arrangeByYearViewed();
   void arrangeByRating();
   void listAllMovies();
   void menu();
   node *newnode(string name,int rating,int year);
   ~Movie(); //destructor
};

#endif /* Movie_h */
