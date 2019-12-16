/* MKweather.cpp */

#include <iostream>
#include <string>
#include <fstream> //included lib for read from file function

using namespace std;

/*  Struct: declaring my weather data variables to use later on in my array, two variables each for inside and outside 
    data and one variable for the mold index because this progam will only calculate mold outside. */
struct weatherData{
    string date;
    float fallDate;
    float tempAverageIn;
    float tempAverageOut;
    int humAverageIn;
    int humAverageOut;
    int moldIndex;

    weatherData() : date(""), fallDate(0), tempAverageIn(0), tempAverageOut(0), humAverageIn(0), humAverageOut(0), moldIndex(0) {}
};

/*  Below are all the sorting functions, I have used bubblesort for this.
    In swap function two variables swaps places, this function will be called in all bubblesorting functions. */
void swap(weatherData *xp, weatherData *yp){
    weatherData temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*  Sorts humidity inside. */
void sortHumidityInside(weatherData arr[], int arraySize){
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].humAverageIn > arr[j + 1].humAverageIn)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Sorts humidity outside. */
void sortHumidityOutside(weatherData arr[], int arraySize){
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].humAverageOut > arr[j + 1].humAverageOut)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Sorts temperature inside. */
void sortTempInside(weatherData arr[], int arraySize){
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].tempAverageIn > arr[j + 1].tempAverageIn)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Sorts temperature outside. */
void sortTempOutside(weatherData arr[], int arraySize){
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].tempAverageOut > arr[j + 1].tempAverageOut)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Sorts mold index on outside data (since we don't do any calculations on mold inside). */
void sortMoldIndex(weatherData arr[], int arraySize){
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].moldIndex > arr[j + 1].moldIndex)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Below here are all the printing functions.    
    Prints the average inside humidity, the first for loop prints the 5 most humid temperatures. The second for loop print the
    5 driest days. I have also added some cout lines in all printing functions to keep my switch cases in main() function more clean */
void printHumidityInside(weatherData arr[]){
    int i;
    cout << "Inside values:" << endl;
    cout << "The 5 most humid days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (i = 126; i < 131; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageIn  << endl;

    cout << endl;
    cout << "The 5 driest days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (i = 1; i < 6; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageIn  << endl;
        cout << endl;
}

/*  Same function as above but with average outside humidity.   */
void printHumidityOutside(weatherData arr[]){
    int i;
    cout << "Outside values:" << endl;
    cout << "The 5 most humid days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (i = 126; i < 131; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageOut  << endl;

    cout << endl;
    cout << "The 5 driest days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (i = 1; i < 6; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageOut  << endl;
        cout << endl;
}

/*  Prints average inside temperature.   */
void printTempInside(weatherData arr[], int arraySize){
    int i;
    cout << "Inside values:" << endl;
    cout << "The 5 warmest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (i = arraySize - 1; i > 125; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageIn  << endl;
    
    cout << endl;
    cout << "The 5 coldest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (i = 5; i > 0; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageIn << endl;
}

/*  Prints average outside temperature.   */
void printTempOutside(weatherData arr[], int arraySize){
    int i;
    cout << "Outside values:" << endl;
    cout << "The 5 warmest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (i = arraySize - 1; i > 125; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageOut  << endl;
    
    cout << endl;
    cout << "The 5 coldest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (i = 5; i > 0; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageOut << endl;
}

/*  Prints mold index outside. */
void printMoldIndex(weatherData arr[], int arraySize){
    int i;
    for (i = arraySize - 1; i > 125; i--)
        cout << "Moldindex: " << arr[i].moldIndex << "\tDate: " << arr[i].date << "\tTemperature: " << arr[i].tempAverageOut << "\tHumidity: " << arr[i].humAverageOut << endl;
}

/*  Search function using linear search.    */
void searchAll(weatherData arr[], string userSearch, int arraySize){
    bool search = false;
    for (int i = 0; i <= arraySize; i++)
    {
        if (arr[i].date == userSearch)
        {
            search = true;
            cout << "Here are the results for " << userSearch << "\n" << endl;
            cout << "Average outside temperature: " << arr[i].tempAverageOut << "\tAverage outside humidity: " << arr[i].humAverageOut << endl;
            cout << "Average inside temperature: " << arr[i].tempAverageIn << "\tAverage inside humidity: " << arr[i].humAverageIn << endl;
        }
    }
        if (search == false)
        {
            cout << userSearch << " is not found in text file. Try again?" << endl;
        }  
}

/*  Function to find meterological fall, where the temperature during consecutive days have to be lower than 10 degrees and 
higher than 0 degrees 5 days in a row. */
void findFall(weatherData arr[], float temp, int arraySize){
    for (int i = 0; i < arraySize; i++)
    {
        if ((arr[i].fallDate > 0 && arr[i].fallDate < 10) && (arr[i + 1].fallDate > 0 && arr[i + 1].fallDate < 10) && (arr[i + 2].fallDate > 0 && arr[i + 2].fallDate < 10) && (arr[i + 3].fallDate > 0 && arr[i + 3].fallDate < 10) && (arr[i + 4].fallDate > 0 && arr[i + 4].fallDate < 10))
        {
            if ((arr[i + 1].fallDate < arr[i].fallDate) && (arr[i + 2].fallDate < arr[i + 1].fallDate) && (arr[i + 3].fallDate < arr[i + 2].fallDate) && arr[i + 4].fallDate < arr[i + 3].fallDate)
            {
                cout << "Fall occurred on " << arr[i].date << endl;
                break;
            }
        }
    }
}

/*  Function to find meterological winter, average outside temperature have to be below 0 degress for 5 consecutive days. */
void findWinter(weatherData arr[], float temp, int arraySize){
    bool findWinter = false;
    for (int i = 0; i < arraySize; i++)
    {
        if ((arr[i].tempAverageOut < 0) && (arr[i + 1].tempAverageOut < 0) && (arr[i + 2].tempAverageOut < 0) && (arr[i + 3].tempAverageOut < 0) && (arr[i + 4].tempAverageOut < 0))
        {
            findWinter = true;
            cout << "Winter is coming " << arr[i].date << endl;
            break;
        }
    }
    if (findWinter == false)
    {
        cout << "Sadly no winter came" << endl;
    }
}

/*  Calculation for the mold index. */
int moldIndex(float temp, int humidity){
    //int moldLimit = 78;
    int moldIndex = 0;

    if (temp < 0)
    {
        moldIndex = 0;
    }
    if (temp > 15)
    {
        moldIndex = (humidity - 78) / 0.22;
    }
    if (temp > 0 && temp < 15)
    {
        moldIndex = ((humidity - 78) * (temp / 15)) * 0.22;
    }
    return moldIndex;
}

/*  When called, this function will prints the menu.   */
void printMenu(){
    cout << "       Hello and welcome to the weather station!       " << endl;
    cout << "******************************************************" << endl;
    cout << "1  Search for any of the many dates available" << endl;
    cout << "" << endl;
    cout << "****** METEROLOGICAL WEATHER *************************" << endl;
    cout << "2 Show me when fall of 2016 occured" << endl;
    cout << "3 Show me when winter of 2016 occured" << endl;
    cout << "" << endl;
    cout << "****** INSIDE ****************************************" << endl;
    cout << "4  Show the 5 warmest and coldest days" << endl;
    cout << "5  Show the 5 most humid and driest days" << endl;
    cout << "" << endl;
    cout << "****** OUTSIDE ***************************************" << endl;
    cout << "6  Show the 5 warmest and coldest days" << endl;
    cout << "7  Show the 5 most humid and driest days" << endl;
    cout << "8  Show all days with high mold index" << endl;
    cout << "" << endl;

}
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
                    data.humAverageIn += stoi(humidity);
                    inCount++;
                }
                if (inOut == "Ute") 
                {
                    //Same here: save temperatures and humidity data from "ute" as floats and ints to calculate later with the outCounter
                    data.tempAverageOut += stof(temperature);
                    data.humAverageOut += stoi(humidity);
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

        case 2: //To find fall date we have to select this case before case 4 - 8 because all dates are sorted when we read from text file, the other cases sort their data
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
            cout << "Here is the mold index" << endl;
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