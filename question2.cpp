#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declare the structure
struct FootballPlayer
{
//Declare structure variables.
string players_name;
string players_position;
int players_touchdowns;
int players_catches;
int players_passingYards;
int players_receivingYards;
int players_rushingYards;
};

//Maximum number of players is 10.
const int Max = 10;

//Declaration of the functions.
void inputFileData(ifstream&, FootballPlayer[], int);
void printingDataToFile(ofstream&, FootballPlayer[], int);
void printingDataToConsole(FootballPlayer[], int);
int findIndexOfSpecificPlayer(FootballPlayer[], int, string);
void updateDataOfThePlayer(FootballPlayer[], int);

//Start the main method.
int main()
{
//Array to access structure variables.
FootballPlayer players[Max];

//Object of ifstream class.
ifstream infile;

//Object of ofstream class.
ofstream outfile;
int ch = 0;

// open the input file
infile.open("question2.txt");

// check whether file exists or not.
if(!infile)
{
cout << "The input file question2.txt is not found." << endl;

exit(1);
}

// open the output file
outfile.open("output.txt");

// Fetch data from input file into structure variables
inputFileData(infile, players, Max);

//Start the do while loop.
do
{
//Display the menu on the console.
cout << "----MENU---" << endl;
cout << "1. Select a player (by name)" << endl;
cout << "2. Display players information" << endl;
cout << "3. Update player information" << endl;
cout << "4. Quit" << endl;

//Prompt the user to enter the choice.
cout << "Enter your choice: ";
cin >> ch;

//Check the different cases
if(ch == 1)
{
//Declare string variable.
string name;

//Prompt the user to enter the player name.
cout << "Enter name of the player: ";
cin >> name;

//Call to the function and storing the result in string variable.
int index = findIndexOfSpecificPlayer(players, Max, name);

//Check whether index found or not.
if(index >= 0)
cout << "The Player " << name << " exists. "<< endl;
else
cout << "The player " << name << " is not found ." << endl;
}

// Check different cases.
else if(ch == 2)
{
//Declare string variable.
string name;

//Prompt the user to enter the player name.
cout << "Enter name of the player: ";
cin >> name;

//Call to the function and storing the result in string variable.
int index = findIndexOfSpecificPlayer(players, Max, name);

//Check whether index found or not.
if(index >= 0)

//Call to the function to display results
printingDataToConsole(players, index);
else
cout << "The player " << name << " is not found in the array." << endl;
}



// Check different cases.
else if(ch == 3)
{
//Call to the function to update result.
updateDataOfThePlayer(players, Max);

//Print the data in the output file.
printingDataToFile(outfile, players, Max);
}

// Check different cases.
else if(ch == 4)
cout << "Program terminated." << endl;

//else for invalid input
else
cout << "Incorrect choice!" << endl;

cout << endl;

//Terminating conditiob of do-while loop.
}while(ch != 4);

//Close the input file.
infile.close();

//CLose the output file.
outfile.close();

return 0;
}

//Definition of the function.
void inputFileData(ifstream& infile, FootballPlayer players[], int length)
{
//Initialize an Integer variable.
int i = 0;

//Extracting player name from file.
infile >> players[i].players_name;

//Start the while loop to input data.
while(infile && i < length)
{
//Extracting data from file.
infile >> players[i].players_position;
infile >> players[i].players_touchdowns;
infile >> players[i].players_catches;
infile >> players[i].players_passingYards;
infile >> players[i].players_receivingYards;
infile >> players[i].players_rushingYards;

//Update the value of i.
i++;

//EXtracting players name.
infile >> players[i].players_name;
}
}

//Definition of the function
void printingDataToFile(ofstream& outfile, FootballPlayer players[], int length)
{
//Check whether structure variable has data or not.
if(players[0].players_name == "")
{
cout << "The array is empty." << endl;
return;
}

//Writing data into the file.
outfile << "Details of all players are as follows:" << endl;

//Start the for loop
//Write the data in output file.
for(int i = 0; i < length; i++)
{
outfile << (i + 1) << ". ";
outfile << players[i].players_name << " ";
outfile << players[i].players_touchdowns << " ";
outfile << players[i].players_catches << " ";
outfile << players[i].players_passingYards << " ";
outfile << players[i].players_receivingYards << " ";
outfile << players[i].players_rushingYards << endl;
}
}

//DEfinition of the function to display result.
void printingDataToConsole(FootballPlayer players[], int index)
{
//Check whether name is empty or not
if(players[0].players_name == "")
{
cout << "The array is empty." << endl;
return;
}

//Display the Details of the player.
cout << "\nDetails of a player:" << endl;
cout << (index + 1) << ". ";
cout << players[index].players_name << " ";
cout << players[index].players_position << " ";
cout << players[index].players_touchdowns << " ";
cout << players[index].players_catches << " ";
cout << players[index].players_passingYards << " ";
cout << players[index].players_receivingYards << " ";
cout << players[index].players_rushingYards << endl;
}

//Definition of function to calculate the index
int findIndexOfSpecificPlayer(FootballPlayer players[], int length, string name)
{
//Start the for loop to traverse the complete file.
for(int index = 0; index < length; index++)
{
//Check whether name matches with the given name.
if(players[index].players_name == name)
//Return the index value of that entry.
return index;
}
//Return -1 if name not found.
return -1;
}





//Definition of the function to update the player information.
void updateDataOfThePlayer(FootballPlayer players[], int length)
{
//Initialize the integer variable.
int choice=0;

//Start the do-while loop.
do
{
//Desplay the menu to the user.
cout << "----MENU---" << endl;
cout << "1. Update the name of the player" << endl;
cout << "2. Update the position of the player" << endl;
cout << "3. Update the number of touchdowns of the player" << endl;
cout << "4. Update the number of catches of the player" << endl;
cout << "5. Update the number of passing yards of the player" << endl;
cout << "6. Update the number of receiving yards of the player" << endl;
cout << "7. Update the number of rushing yards of the player" << endl;
cout << "8. Quit" << endl;

//Declare the string variable.
string name;
// Prompt the user to enter the name of player.
cout << "Enter name of the player to whom you want to update details: ";
cin >> name;

//Check whether player is present in the list or not.
int index = findIndexOfSpecificPlayer(players, Max, name);

if(index < 0)
cout << "The player does not exists." << endl;
else
{

//Prompt the user to enter the choice.
cout << "Enter your choice: ";
cin >> choice;

//condition of case 1.
if(choice==1)
{
//Declare String Variable.
string nam;

//Prompt the user to enter the updated name.
cout<<"Enter the name by which you want to update previous name";
cin>> nam;

//Update the value of name.
players[index].players_name = nam;
cout << "The detail is updated." << endl;
}

//condition of case 2.
else if(choice==2)
{
//Prompt the user to enter the position of player.
cout << "Enter the position of the player: ";
cin >> players[index].players_position;
cout << "The detail is updated." << endl;
}

//condition of case 3.
else if(choice==3)
{
//Prompt the user to enter the number of touchdowns.
cout << "Enter the the number of touchdowns: ";
cin >> players[index].players_touchdowns;
cout << "The detail is updated." << endl;
}

//Condition for case 4.
else if(choice==4)
{
//Prompt the user to enter the number of catches.
cout << "Enter the number of catches: ";
cin >> players[index].players_catches;
cout << "The detail is updated." << endl;
}

//Condition for case 5.
else if(choice==5)
{
//Prompt the user to enter the number of passing yards.
cout << "Enter the number of passing yards: ";
cin >> players[index].players_passingYards;
cout << "The detail is updated." << endl;
}

//Condition of case 6.
else if(choice==6)
{

//Prompt the user to enter the number of receiving yards.
cout << "Enter the number of receiving yards: ";
cin >> players[index].players_receivingYards;
cout << "The detail is updated." << endl;
}

//Condition of case 7.
else if(choice==7)
{

//Prompt the user to enter the number of rushing yards.
cout << "Enter the number of rushing yards: ";
cin >> players[index].players_rushingYards;
cout << "The detail is updated." << endl;
}

//Condition of case 8.
else if(choice == 8)
{
cout << "Updation complete" << endl;
}

//Condition of case 9.
else
cout << "Incorrect choice!" << endl;
}

//Termination condition of while loop.
}while(choice != 8);

}
