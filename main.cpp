#include "Recipes.h"

int main () {

     cout << left << setw(28) << " " << "WELCOME TO RECIPES" << endl;
     cout << left << setw(26) << " " << "(written by Ben Harki)" << endl;
         
     Recipes_List *roster{nullptr};
     roster = new Recipes_List; 
     
     //***** Initialize roster program storage ******
     // read file open check
     ifstream in_file{"Recipe_Storage.txt"};
     file_check(in_file);

     // read recipes file and add it to roster    // if file is empty, first recipe in roster is empty
     Recipe getter_recipe;    
      while(!in_file.eof()) {
          getter_recipe.read_recipe(in_file);
          if( getter_recipe.get_title().empty() == 0  ) {        // if title is not empty
               roster->add_recipe(getter_recipe);                    // avoids adding anything to roster that does not have a title in file
          }     
          getter_recipe = {};
      }
     in_file.close();
     //*******************************************

     char selection{};
     do {
         
          menu();
          cout << ">> ";
          cin >> selection;      
          cin.ignore();  // ignores >>'s automatic \n in buffer
          cout << endl;
          switch (selection) {
               case '1': {
                    // Ask user to enter recipe and store in user_recipe
                    Recipe user_recipe;
                    user_recipe.enter_users_title();        
                    user_recipe.enter_users_ingredients();
                    user_recipe.enter_users_directions();

                    if ( user_recipe.check_valid_entry() == true ) {
                         roster->add_recipe(user_recipe);   // does not add in recipes that do not have a title or directions
                    }     

                    // creates a new file and writes all of roster every time
                    ofstream out_file{"Recipe_Storage.txt"};	
                    roster->write_to_file(out_file);
                    out_file.close();
               }
               break;
               case '2': {
                    roster->display_stored_recipes();
               }
               break;
               case '3': {
				string user;
                    int num_searches{0};
                    do {
                         cout << "Enter an ingredient to search for or \"d\" to display current results: ";
                         getline(cin, user);
                         if (user != "d") {      // so that "d" is not searched
                              ++num_searches;
                              roster->search_by_ingred(user);    // case sensitive, want to make it case insensitive
                         }
                    } while(user != "d");
                    roster->display_ordered_results(num_searches);    // displays in ascending order
               }
               break;
               case 'e': {
                    cout << "EXITING PROGRAM - goodbye . . ." << endl;
                    cout << endl;
               }   
               break;  
               default:
                    cout << "INVALID ENTRY -  try again" << endl;
          }
     } while(selection != 'e'); 

     delete roster;      // deallocates pointer

     return 0;
}

 





