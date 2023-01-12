#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
using namespace std; 

int main(){
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient


    // PART 1: Select a primary sorting category from user input

    char category[5][6] = {"Age", "ID", "Sex", "Last", "First"};
    //making an array of strings called category which has 5 categories in it 
    
    char cat[6];

    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";
    
    cin >> cat;
    //asking the user to input a category from the categories displayed
    while(1){//beginning a while loop that is always true (since 1 is a non-zero number)

        if (strcasecmp(cat,category[0])==0){
        //comparing two strings without regards to case sensitivity starting from Age (0th category listed)
            cout << "Case 1, sorting by Age." << endl;
            break; 
            //if the user inputs the "age" category, the loop breaks/stops, if not it continues on to the next else if statement
        }
        else if (strcasecmp(cat, category[1])==0){
            cout << "Case 2, sorting by ID." << endl;
            break;
            //if the user inputs the "id" category, the loop breaks/stops, if not it continues on to the next else if statement
        }
        else if (strcasecmp(cat, category[2])==0){
            cout << "Case 3, sorting by Sex." << endl;
            break;
            //if the user inputs the "sex" category, the loop breaks/stops, if not it continues on to the next else if statement
        }
        else if (strcasecmp(cat,category[3])==0){
            cout << "Case 4, sorting by Last Name." << endl;
            break;
            //if the user inputs the "last" category, the loop breaks/stops, if not it continues on to the next else if statement
        }
        else if (strcasecmp(cat,category[4])==0){
            cout << "Case 5, sorting by First Name." << endl;
            break;
            //if the user inputs the "first" category, the loop breaks/stops, if not it continues on to the last else statement
        }
        else {
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
            cin >> cat; 
            //if the user inputs anything other than the 5 categories, the above statement will output and ask the user
            //to input one of the categories listed.
        }
    }
    
    // PART 3/4: Sorting patient records

    for (int i=0;i<NUM_PATIENTS-1;i++){ 
        
        for (int j=0;j<NUM_PATIENTS-i-1;j++){
    //the two above for loops are basically the base of how the bubble sort will work
            
            if (strcasecmp(cat,category[0])==0){//if the user inputs age, the records will be sorted by age (in ascending order)
                
                if (age[j]>age[j+1]){ 
                //if the value before the next in the age category is larger than the next, then we continue with the following instructions
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]); 
                        //when the value before the next is bigger than the next we want to switch them so we "swap" each of its 
                        //corresponding record elements as well.

                } else if (age[j]==age[j+1]){
                //otherwise if some of the values of each patient are the same, we then sort them by first name
                    
                    if (strcasecmp(firstName[j],firstName[j+1])>0){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                    //this compares the first names alphabetically and swaps them when needed
                    }
                }
        }   else if(strcasecmp(cat,category[1])==0){
            //if the user inputs to be sorted by id, the records will be sorted by patients' id numbers (in ascending order)
                    
                    if (strcasecmp(id[j],id[j+1])>0){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                    //when the value before the next is bigger than the next, we want to switch them so we "swap" each 
                    //of its corresponding record elements as well.
                }

        }   else if (strcasecmp(cat,category[2])==0){
            //if the user inputs to be sorted by sex, the records will be sorted by patients' sex (alphabetically, so f will come before m)

                if (sex[j]>sex[j+1]){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                //if the beginning patient is male then it will swap it with the next if the next is female since f comes before m 
                //alphabetically, then we swap each of its corresponsing record elements as well. 
                }
                else if (sex[j]==sex[j+1]){ 
                //otherwise if some of the patients have the same sex, we then sort those patients by first name, 
                //similar to when sorting by age
                    
                    if (strcasecmp(firstName[j],firstName[j+1])>0){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                    }
                }
    
        }   else if (strcasecmp(cat,category[3])==0){
            //if the user inputs to be sorted by last name, the records will be sorted by patients' last names, alphabetically
                
                if (strcasecmp(lastName[j],lastName[j+1])>0){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                //if the starting letter of one of the last names comes later in the alphabet than the next, then they and their 
                //corresponding record elements will be switched. (This also accounts for the second, third, fourth, etc. letter if 
                //the first letter is the same).
                }
        
        }   else if (strcasecmp(cat,category[4])==0){
            //if the user inputs to be sorted by first name, the records will be sorted by patients' first names, alphabetically.
                
                if (strcasecmp(firstName[j],firstName[j+1])>0){
                        swap(age[j],age[j+1]);
                        swap(id[j],id[j+1]);
                        swap(firstName[j],firstName[j+1]);
                        swap(lastName[j],lastName[j+1]);
                        swap(sex[j],sex[j+1]);
                //if the first letter of the first name comes later in the alphabet than the next, then they and their 
                //corresponding record elements will be switched. (This also accounts for the second, third, fourth, etc. letter if 
                //the first letter is the same).
                }
        } 
        }
    }
   
   // PART 2: Outputting patient records to terminal in tabular form

   //this code block allows the patient records to be outputted in tabular form with set width of 13 characters (spaces)
    
    cout << setw(13) << "Age:"; 
    //starting from the "Age" label, it is outputted with a set width of 13 characters
    for (int i=0; i<10; i++){
        cout << setw(13) << age[i];
    //moving onto the records for age, this is a for loop to output the age of each patient starting from the 0th patient 
    //with a set width of 13 characters
    }
    cout << endl;

    cout << setw(13)<<"ID:";
    //this outputs the "ID" label with a set width of 13 characters
    for (int i=0; i<10; i++){
        cout << setw(13) << id[i];
    //this for loop outputs the id number of each patient starting from the 0th patient with a set width of 13 characters
    }
    cout << endl;
    
    cout << setw(13)<<"First Name:";
    //this outputs the "First Name" label with a set width of 13 characters 
    for (int i=0; i<10; i++){
        cout << setw(13) << firstName[i];
    //this for loop outputs the first names of each patient starting from the 0th patient with a set width of 13 characters
    }
    cout << endl;
    
    cout << setw(13) << "Last Name:";
    //this outputs the "Last Name" label with a set width of 13 characters
    for (int i=0; i<10; i++){
        cout << setw(13) << lastName[i];
    //this for loop outputs the last names of each patient starting from the 0th patient with set a width of 13 characters
    }
    cout << endl;

    cout << setw(13) << "Sex:";
    //this outputs the "Sex" label with a set width of 13 characters
    for (int i=0; i<10; i++){
        cout << setw(13) << sex[i];
    //this for loop outputs the sex of each patient starting from the 0th patient with a set width of 13 characters
    }
    cout << endl;

return 0;
}



