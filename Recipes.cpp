#include "Recipes.h"

// class functions defns:
Ingredients_List::Ingredients_List() {
}

void Ingredients_List::write_ingredients(ofstream &out_file) {
  out_file << list.size() << endl;
  for (auto ingred : list)
    out_file << ingred << endl;
}  

void Ingredients_List::add_ingred(string & str) {
  list.push_back(str);
}

void Ingredients_List::read_ingredients(ifstream &in_file){
  int size{};
  in_file >> size;
  in_file.ignore();     
  string first_ingred;
  for(int i{0}; i < size; ++i) {
    getline(in_file, first_ingred);
    list.push_back(first_ingred);
  }
}

void Ingredients_List::display() {
  for(auto &ingred : list) 
    cout << ingred << endl;
}

bool Ingredients_List::find(string &user) {
  bool check{false};
  for(auto &ingred : list) {
    if ( find_substring(user, ingred) == true)
      check = true;
  }
  return check;         
}

Recipe::Recipe(int found_val) 
  : found{found_val} {
}

void Recipe::enter_users_title() {
  cout << "Enter the name of your recipe: ";
  getline(cin, title);     // skips whitespace, stops storing until enter is pressed
  cout << endl;  
}

void Recipe::enter_users_directions() {
  cout << "Enter \"" << title << "'s\" directions: ";
  getline(cin, directions);
  cout << endl;
}      

void Recipe::enter_users_ingredients() {
  string user_string;
  bool quit{false};
  do {
    cout << "Enter quantity and ingredient or 'q' to  quit\n  (for example, 2 cups of tomatoes): ";
    getline(cin, user_string);    // use obj instead of user_string, write a method?
    if (user_string == "q" | user_string == "Q") {
      quit = true;     
    } else {
      ingred_list.add_ingred(user_string);  
    }
    cout << endl;
  } 
  while(quit == false);
}    

void Recipe::write_ingredients(ofstream &out_file) {
  ingred_list.write_ingredients(out_file);
}

void Recipe::read_recipe(ifstream &in_file) {
  getline(in_file, title);      
  ingred_list.read_ingredients(in_file);
  getline(in_file, directions);      
}

bool Recipe::check_valid_entry() {
  bool check{true};
  if( title.empty() | directions.empty() ) {
    cout << "Recipe contains an empty section - add another recipe" << endl;
    check = false;
  }
  return check;
}

void Recipe::display() {
  string stars(30,'*');
  cout << stars << endl;
  cout << title << endl;
  ingred_list.display();
  cout << directions << endl;
  cout << stars << endl;
  cout << endl;
}

void Recipe::display_search_results(int &num) {
  string stars(36, '*'); 
	cout << setfill('*');
  cout << left << setw(5) << "*"  << " " << num  << " ingredients found " << setw(10) << '*' << endl;
  cout << setfill(' ');
  cout << title << endl;
  ingred_list.display();
  cout << directions << endl;
  cout << stars << endl;
  cout << endl;
}

bool Recipe::search_by_ingred(string &user) {
  bool check{false};
  if (ingred_list.find(user) == true) {
    ++found;   
    check = true;
  }
  return check;
}


Recipes_List::Recipes_List() {
}

void Recipes_List::add_recipe(Recipe &user_recipe) {
  recipes.push_back(user_recipe);
}

void Recipes_List::write_to_file(ofstream &out_file) {
  for (auto &recipe : recipes) {
    out_file << recipe.get_title() << endl;
    recipe.write_ingredients(out_file);   
    out_file << recipe.get_directions() << endl;   
  }
}

void Recipes_List::display_stored_recipes() {
	string stars(30, '*');
  cout << stars << endl;
  cout << endl;
  for (auto &recipe: recipes) {
    recipe.display();
  }
}

void Recipes_List::search_by_ingred(string &user) {
  for(auto &recipe : recipes) {
    if ( recipe.search_by_ingred(user) == true ) {
    }
  }       
}

void Recipes_List::display_ordered_results(int &num) {      // does it need need &num or just num?
  cout << endl;
  int start{1};
  while (start <= num) { 
    for(auto &recipe: recipes) {
      if( recipe.get_found() == start ) {
          recipe.display_search_results(start);
      }
    }
    ++start;
  }
  for( auto &recipe: recipes)   
    recipe.set_found(0);     // sets founds back to 0               
}

// non-class function defns:
void menu() {  
  cout << endl;   
  cout << "Please select an option:" << endl;
  int m_wdth{5};
  cout << setw(m_wdth) << left << " " << "(1)  Enter a Recipe\n"; 
  cout << setw(m_wdth) << left << " " << "(2)  Display Current Stored Recipes\n";
  cout << setw(m_wdth) << left << " " << "(3)  Search by Ingredient\n";     
  cout << setw(m_wdth) << left << " " << "(e)  Exit Program\n";
}    

void file_check(ifstream &in_file) {
  if (!in_file.is_open()) {
    cout << "Error opening file to read" << endl;
    exit(EXIT_FAILURE);
  }
}     

bool find_substring(string &user, string &ingred) {
  size_t fnd = ingred.find(user);	
  if (fnd == std::string::npos)			// returns false if nopos, true otherwise (found)
    return false;								
  else
    return true;
}

 





