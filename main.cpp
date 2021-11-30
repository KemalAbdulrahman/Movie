//
//  main.cpp
//  MovieUSingLinkedList
//
//  Created by Kemal Abdulrahman on 7/27/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//

#include <iostream>
#include "Movie.h"
int main(int argc, const char * argv[]) {
   char choice = 'y';
   Movie obj;
   while (choice != 'Q') {
      obj.menu();   // creating the menu
                    //asking the user to input the choice.
      cout<<"\nEnter your choice ";
      cin>>choice;  // give the user input.

      switch (choice) {
         case 'A': {
            // string name;
            int year;
            int rating;
            string name;
            cout<<"Add a movie name ";
            cin.ignore();  // this line will ignore the '\n' character if it is there. it is used when cin is used before it.
            getline(cin,name);
            cout<<"Enter the year you saw "<<name << " [like 2016 ] ";
            cin>>year;
            cout<<"Enter the rating for "<< name << " [1 ,2 ,3, 4, 5] ";
            cin>>rating;
            obj.add(name,rating,year);
            break;
         }
         case 'U':
            obj.update();  // this is perform the update in the linked list.
            break;
         case 'E':
            obj.removeMovie(); // this will perform the removal of the movie from the linked list.
            break;
         case 'L':
            obj.listAllMovies(); // this will perform the listing of all the movies in the linked list
            break;
         case 'T':
            obj.arrangeByTitle();  // this will sort the linked list according to the names of the movie.
            break;

         case 'V':
            obj.arrangeByYearViewed(); // this will arrange the linked list based on the year saw.
            break;
         case 'R':
            obj.arrangeByRating(); // this will sort the linked list based on the rating.
            break;
         case 'Q':
            exit(0);  // this will quit the system.
            break;
      }
   }

}

