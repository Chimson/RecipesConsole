#ifndef _RECIPES_H_
#define _RECIPES_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
 using namespace std;

/*
     Recipes_List:
          vector of Recipe
               each Recipe:
                    title
                    ingredients list
                         vector of strings: "quantity name"
                    directions
                    found
*/

class Ingredients_List { 
private:
     vector<string> list;
public:
     Ingredients_List();
     void add_ingred(string &);
     void write_ingredients(ofstream &);
     void read_ingredients(ifstream &in_file);
     void display();
     bool find(string &);
};

class Recipe {
private:
     Ingredients_List ingred_list;
     string title;
     string directions;
     int found;
public:
     Recipe(int = 0);    // found defaulted at 0
     string get_title() {return title;}
     string get_directions() {return directions;}
     int get_found() {return found;}
     void set_found(int num) {found = num;}                        
     void enter_users_title();
     void enter_users_ingredients();
     void enter_users_directions();
     void write_ingredients(ofstream &out_file);
     void read_recipe(ifstream &in_file);
     bool check_valid_entry();
     void display();
     bool search_by_ingred(string &user);
     void display_search_results(int &num);
}; 

class Recipes_List { 
private:
     vector<Recipe> recipes;
public:
     Recipes_List();
     void add_recipe(Recipe &user_recipe);
     void write_to_file(ofstream &out_file);
     void display_stored_recipes();
     void search_by_ingred(string &user);
     void display_ordered_results(int &num);
};

// non-member function prototypes and global constants:
void menu();
void file_check(ifstream &in_file);
bool find_substring(string &user, string &ingred);


#endif // _RECIPES_H_
