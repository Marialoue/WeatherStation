/* MKweather.cpp, this is the executable main file  */

#include <iostream>
#include <string>
#include <fstream> //included lib for read from file function
#include "Functions.h" //include all weather functions

using namespace std;

/*  Driver program.     */
int main(){
    weatherData weatherDataArray[131]; //Creating an array with an index of 131, this is where the data will be saved later on
    int arraySize = sizeof(weatherDataArray) / sizeof(weatherDataArray[0]); //calculating size of array, useful when calculating mean values

    int i = 0; //This int is used locally in main() for case 7 & 8 in switch later on

    string date; //Creating variables to save the data from when we read text file "tempdata4.txt"
    string time;
    string inOut;
    string temperature;
    string humidity;

    float count = 0; //Counters used to calculate mean value
    float inCount = 0;
    float outCount = 0;
    string currentDate = ""; //Date variables to check date in if conditions
    string checkDate = "";
    weatherData data; //From weatherData data we can access our struct variables

    int userInput; //To navigate the menu and search for dates we need user input
    string userSearch;

    ifstream text("tempdata4.txt"); //This is the text file we want to read from
    if (text.is_open()) 
    {
        while (!text.eof()) 
        {
            getline(text, date, ' '); //getline() reads from file
            getline(text, time, ',');
            getline(text, inOut, ',');
            getline(text, temperature, ',');
            getline(text, humidity);

            if (date == checkDate) //If the date from "tempdata4.txt" is equal to the checkdate we start to separate the data into inside and outside data. This will not happen the first date we read.
            {
                if (inOut == "Inne") //With this if condition we want to seperate the outside and inside data to be able to calculate mean values
                {
                    //Save temperatures and humidity data from "inne" as floats and ints to calculate later with the inCounter
                    data.tempAverageIn += stof(temperature);
                    data.humAverageIn += stof(humidity);
                    inCount++;
                }
                if (inOut == "Ute") 
                {
                    //Same here: save temperatures and humidity data from "ute" as floats and ints to calculate later with the outCounter
                    data.tempAverageOut += stof(temperature);
                    data.humAverageOut += stof(humidity);
                    data.fallDate += stof(temperature);
                    outCount++;
                }
                currentDate = date;
                count++;
            }
            else
            {
                checkDate = date;
                if (count != 0)
                {                    
                    data.date = currentDate; //Calculate all mean values and fall date
                    data.tempAverageIn = data.tempAverageIn / inCount;
                    data.humAverageIn = data.humAverageIn / inCount;
                    data.fallDate = data.fallDate / outCount;
                    data.tempAverageOut = data.tempAverageOut / outCount;
                    data.humAverageOut = data.humAverageOut / outCount;
                    data.moldIndex = moldIndex(data.tempAverageOut, data.humAverageOut); //saves moldIndex() function in moldIndex variable
                    
                    weatherDataArray[i] = data; //This saves our data in the weatherDataArray

                    inCount = 0; //Reset all values to 0 before entering next getline()
                    outCount = 0;
                    data.tempAverageIn = 0;
                    data.humAverageIn = 0;
                    data.tempAverageOut = 0;
                    data.humAverageOut = 0;
                    i++;
                }
            }
        }
    }
    
    do
    {
        printMenu(); //Prints menu
        cin >> userInput; //Takes in user input to be used on the switch cases 
        cout << endl;

        switch (userInput)
        {
        case 1:
            cout << "When searching use this format to access date -> yyyy-mm-dd: ";
            cin >> userSearch;
            cout << endl;
            searchAll(weatherDataArray, userSearch, arraySize);
            cout << endl;
            break;

        case 2: //To find fall date we have to select this case before case 4 - 8 because all dates are sorted when we first read from text file, the other cases sort their data
            cout << endl;
            findFall(weatherDataArray, weatherDataArray[i].fallDate, arraySize);
            cout << endl;
            break;

        case 3:
            cout << endl;
            findWinter(weatherDataArray, weatherDataArray[i].tempAverageOut, arraySize);
            cout << endl;
            break;

        case 4:
            cout << endl;
            sortTempInside(weatherDataArray, arraySize);
            printTempInside(weatherDataArray, arraySize);
            cout << endl;
            break;

        case 5:
           cout << endl;
            sortHumidityInside(weatherDataArray, arraySize);
            printHumidityInside(weatherDataArray);
            cout << endl;
            break;

        case 6:
            cout << endl;
            sortTempOutside(weatherDataArray, arraySize);
            printTempOutside(weatherDataArray, arraySize);
            cout << endl;
            break;

        case 7: 
            cout << endl;
            sortHumidityOutside(weatherDataArray, arraySize);
            printHumidityOutside(weatherDataArray);
            cout << endl;
            break;

        case 8:
            cout << endl;
            sortMoldIndex(weatherDataArray, arraySize);
            printMoldIndex(weatherDataArray, arraySize);
            cout << endl;
            break;

        default:
            cout << "OOOPS " << userInput << " is not a valid input you can use in this menu. Do try again." << endl;
            cout << endl; 
            break;
        }
    } while (userInput != 0);
            cout << "Good bye" << endl; 
}