/*  LAB 1
 *
 * Filename:    Intro_To_Data_Structures.cpp
 * Purpose:     Create a Menu of functions/activities
 * Author:      Colton Wilson
 * Student ID:  106-65-4060
 *
 *
 * Created on Jan. 28th, 2021
*/
//Directives
#include<iostream>
#include<cstdlib>
#include <iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>
#include <ctype.h>

//Constatnts
const int ARRAY_MAX_SIZE = 5, ROWS = 3, COLS = 3;


using namespace std;

//Function Prototypes
int findMin(int a[], int size);
//PreCondition: size is declared size or array a
//PostCondition: Minimum value found
//Purpose: Find the minimum value of user inputted array

double computeAvg(int a[ROWS][COLS]);
//PreCondition: ROWS and COLS are declared sizes for array a.
//PostCondition: Average is computed from given array
//Purpose: Get the Average of the random integers in array

bool isLeapYear(int year);
//PreCondition: year is declared by user input
//PostCondition: True or False if year is a leap year
//Purpose: Get user inputted year and return in leap year or not

int calcuate(string exp);
//PreCondition: exp is declared by user input math expression
//PostCondition: integer solution printed to screen
//Purpose: Take the string exp from user and convert to integer solution. 

void getFileContent(string filename, vector<string>& words);
//PreCondition:filename has been connected to an input file. 
//PostCondition: words from file and moved into vector and printed to screen
//Purpose: Print words from file to screen for user

void frequencyCount (vector <string>& word_freq, string searchword);
//PreCondition: searchword is declared by user and vector string is declared by sentence to use. 
//PostCondition: searchword is found # times in vector. 
//Purpose: Find out how many times a word is found in vector. 

void stopWordRemoval(vector <string>& words);
//PreCondition: User declared vector with stop words in it. 
//PostCondition: vector updated with no stop words
//Purpose: Remove stop words from user inputted sentence

void newline();
//PreCondition: N/A
//PostCondition: N/A
//Purpose: Clears the input field from User

//Call Main
int main(void)
{
    //Declare Variables
    int choice, minarray, year;
    double avg_Array_Total, answer;
    bool leapYear;
    string exp, filename, searchword, input, temp_word, test;
    vector<string> words, word_freq, stop_word, stopWordsCheck;
    char repeat, clear_screen;
    //Set up Arrays
    int user_Min_Array[ARRAY_MAX_SIZE];
    int avg_Array[ROWS][COLS];

    //Menu-Prompt User for selection and don't stop until -1(quit)
    do {
        cout << "**********Menu**********\n";
        cout << endl;
        cout << endl;
        cout << "1) Find Minimum\n";
        cout << "2) Compute Average\n";
        cout << "3) Is Leap Year\n";
        cout << "4) Calculate\n";
        cout << "5) Read File\n";
        cout << "6) Word Frequency\n";
        cout << "7) Remove Stop Words\n";
        cout << "-1) Quit\n";
        cout << endl;
        cout << "Please make a selection by Inputting the number and pressing Enter\n";

        cin >> choice;

        cout << endl;


        //If-Else to select which function to call
        if (choice == 1)
        {
            //Call findMin
            minarray = findMin(user_Min_Array, ARRAY_MAX_SIZE);
            //Print to screen Minimum value
            cout << endl;
            cout << "The Minimum Value in the Array is : " << minarray << "\n";

        }
        else if (choice == 2)
        {
            //Activate Random number generator
            srand(time(NULL));
            //Call computeAvg
            avg_Array_Total = computeAvg(avg_Array);
            //Print Avg to screen
            cout << endl;
            cout << endl;
            cout << "The Average of this Array is: " << avg_Array_Total << "\n";

        }
        else if (choice == 3)
        {
            //Prompt User to enter a Year to test
            cout << "Enter a year you would like to see if it is a Leap Year(YYYY): ";
            cin >> year;
            //Call isLeapYear 
            leapYear = isLeapYear(year);

            //Print to screen if it is leap year or not
            if (leapYear == true)
            {
                cout << endl;
                cout << year << " is a Leap Year\n";
            }
            else
            {
                cout << endl;
                cout << year << " is not a Leap Year\n";
            }

        }
        else if (choice == 4)
        {
            //Prompt user to input a math expression
            cout << "Enter a Mathematical Expression (i.e. 1+1): ";
            cin >> exp;

            //Call calculate
            answer = calcuate(exp);

            //Print anser to screen
            cout << "The answer is: " << answer;
            cout << endl;
            cout << endl;

        }
        else if (choice == 5)
        {
            //Prompt User to input what file you want to open
            cout << "What file would you like to open? (Only File: text.txt): ";
            cin >> filename;
           //Call getFileContent
          getFileContent(filename, words);
       }
        else if (choice == 6)
        {

            //Prompt user to see what word they would like to find in given sentence
            {
             cout << "What word would you like to find the frequency of from: \"Dhanyu is a handsome professor Dhanyu is professor\": ";
            cin >> searchword;
            word_freq = { "Dhanyu", "is", "a", "handsome", "professor", "Dhanyu", "is", "professor" };

            //Call frequencyCount
            frequencyCount(word_freq, searchword);


            }
        }
        else if (choice == 7)
        {
            //Call newline
            newline();
            //Prompt user to input the sentence they would like to take stop words out of
            cout << "Please input a sentence to take out the Stop Words(Stop words are: a, an, the, i, we, they): ";
            //getline function to convert user input to string
            getline(cin, temp_word);

            //Make instream to convert to vector
            istringstream stream(temp_word);

            //While loop to convert each word into the vector
            while (stream >> test)
            {

                stop_word.push_back(test);
            }
            

            //Call stopWordRemoval function
            stopWordRemoval(stop_word);
        }

        //If statement to clear screen if user has not quit menu
        if (choice != -1)
        {
            cout << endl;
            cout << "Press any key and Enter to clear the screen: ";
            cin >> clear_screen;

            system("CLS");
        }


    } while (choice != -1);



    exit(EXIT_SUCCESS);
}

//Function Definition of findMin
int findMin(int a[], int size)
{
    //Variables with findMin as scope
    int min;
    //Prompt User to enter integers
    cout << "Please enter " << ARRAY_MAX_SIZE << " Integer Values then press Enter: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    //Set minimum to first value
    min = a[0];
    //Work through array and update minimum if needed
    for (int i = 0; i < size; i++)
    {
        if (a[i] <= min)
        {
            min = a[i];
        }
    }
    //Return minimum
    return (min);
}
//Function Definition of computeAvg
double computeAvg(int a[ROWS][COLS])
{
    //Variables with computeAvg
    int randNum, index1, index2, sum = 0;
    double avg;
    //Filling in Array with random numbers
    for (index1 = 0; index1 < ROWS; index1++)
    {
        for (index2 = 0; index2 < COLS; index2++)
        {
            a[index1][index2] = (rand() % 100 + 1);
        }
    }
    //Print Array to screen so User can see
    cout << "Here is your Random Array: ";

    for (index1 = 0; index1 < ROWS; index1++)
    {
        for (index2 = 0; index2 < COLS; index2++)
        {
            cout << setw(5) << a[index1][index2];
        }
    }
    //Add all numbers in array together
    for (index1 = 0; index1 < ROWS; index1++)
    {
        for (index2 = 0; index2 < COLS; index2++)
        {
           sum = sum + a[index1][index2];
        }
    }
    //Calculate the average
    avg = sum / (ROWS + COLS);


    //Return average
    return(avg);
}
//Function Definition of isLeapYear
bool isLeapYear(int year)
{
    //Compute to see if year inputted is a Leap Year
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 > 0))
    {
        //return true or false
        return true;
    }
    return false;

}
//Function Definition of calculate
int calcuate(string exp)
{
    //Variables with function as scope
    int num1 = 0, num2 = 0, answer = 0;
    char symbol, test_char;
    bool symbol_flag = false;

    //For loop to work through each char in expression
   for(int i = 0; i < exp.size(); i++)
   {
       //if statement to see if char is a digit
       if (isdigit(exp[i]))
       {
           //if statement to see if the symbol char as been passed
           if (symbol_flag == false)
           {
               num1 = (num1 * 10) + (exp[i] - 48);
           }
           else
           {
              num2 = (num2 * 10) + (exp[i] - 48);
           }
       }
       //If not digit, it must be symbol so change symbol flag to true
       else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
       {
           symbol = exp[i];
           symbol_flag = true;
       }
   }
   //If statement to do the actual calculation based on user inputted symbol
   if (symbol == '+')
   {
       answer = num1 + num2;
   }
   else if(symbol == '-')
   {
       answer = num1 - num2;
   }
   else if (symbol == '*')
   {
       answer = num1 * num2;
   }
   else if (symbol == '/')
   {
       answer = num1 / num2;
   }
   

   //return answer
    return (answer);
}
//Function Definition of getFileContent
void getFileContent(string filename, vector<string>& words)

{
    //Variable with function as scope
    int count = 0;
    string line;
    //Declare streams
    ifstream infile;
    //Open streams
    infile.open(filename);

    //Check for Error
    if (infile.fail())
    {
        cerr << "Error Opening File" << endl;
        exit(1);
    }

    //Read File until the end
    while (getline(infile, line))
    {
        words.push_back(line);
    }
    cout << "Contents of file: \n";
    cout << endl;
    //Print words to screen
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
        cout << endl;
    }
    
    //Close file
    infile.close();

}
//Function Definition of frequencyCount
void frequencyCount(vector <string>& word_freq, string searchword)
{
    //variable with function as scope
    int freq;
    //count for searchword from begin to end
    freq = count(word_freq.begin(), word_freq.end(), searchword);
    //Print to screen
    cout << "Word \"" << searchword << "\" appears " << freq << " times." << endl;




}
//Function Definition of stopWprdRemoval
void stopWordRemoval(vector <string>& words)
{
    //Variable with function as scope
    vector<string>  stopWordsCheck;
    int i, j;
    //Words we are checking for in vector
    stopWordsCheck = { "a", "A","an","An","the","The", "i","I","we","We", "they","They"};
    //For loop to work through given sentence
    for (int i = 0; i < words.size(); i++)
    {
        //For loop to work through the words to check for
        for (int j = 0; j < stopWordsCheck.size(); j++)
        {
            //If a stop word is found-erase it
            if (words[i] == stopWordsCheck[j])
            {
                words.erase(words.begin() + i);
            }
        }
    }
    //Print new sentence to screen
    cout << endl;
    cout << "Your new sentence is: ";

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }

    cout << endl;
    //Clear the vectors to restore memory
    words.clear();
    stopWordsCheck.clear();

    return;
}
//Function Definition of newline
void newline()
{
    //Variable for function
    char symbol;
    //Go through user input and clear pending inputs until hit enter character
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}
