/*  Functions.h header to MKweather.cpp with all functions  */

using namespace std;

/*  Struct: declaring my weather data variables to use later on in my array, two variables each for inside and outside 
    data and one variable for the mold index because this progam will only calculate mold outside. */
struct weatherData{
    string date;
    float fallDate;
    float tempAverageIn;
    float tempAverageOut;
    float humAverageIn;
    float humAverageOut;
    float moldIndex;

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
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
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
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
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
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
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
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
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
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            if (arr[j].moldIndex > arr[j + 1].moldIndex)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*  Below here are all the printing functions.    
    Prints the average inside humidity, the first for loop prints the five most humid temperatures. The second for loop print the
    five driest days. I have also added some cout lines in all printing functions to keep my switch cases in main() more clean */
void printHumidityInside(weatherData arr[]){
    cout << "Inside values:" << "\nThe 5 most humid days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (int i = 126; i < 131; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageIn  << endl;
    cout << endl;
    cout << "The 5 driest days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (int i = 1; i < 6; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageIn  << endl;
}

/*  Same function as above but with average outside humidity.   */
void printHumidityOutside(weatherData arr[]){
    cout << "Outside values:" << "\nThe 5 most humid days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (int i = 126; i < 131; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageOut  << endl;
    cout << endl;
    cout << "The 5 driest days" << endl;
    cout << "Date\t\tHumidity" << endl;
    for (int i = 1; i < 6; i++)
        cout << arr[i].date << "\t" << arr[i].humAverageOut  << endl;
}

/*  Prints average inside temperature.   */
void printTempInside(weatherData arr[], int arraySize){
    cout << "Inside values:" << "\nThe 5 warmest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (int i = arraySize - 1; i > 125; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageIn  << endl;
    cout << endl;
    cout << "The 5 coldest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (int i = 5; i > 0; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageIn << endl;
}

/*  Prints average outside temperature.   */
void printTempOutside(weatherData arr[], int arraySize){
    cout << "Outside values:" << "\nThe 5 warmest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (int i = arraySize - 1; i > 125; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageOut  << endl;
    cout << endl;
    cout << "The 5 coldest days" << endl;
    cout << "Date\t\tTemperature" << endl;
    for (int i = 5; i > 0; i--)
        cout << arr[i].date << "\t" << arr[i].tempAverageOut << endl;
}

/*  Prints mold index outside. */
void printMoldIndex(weatherData arr[], int arraySize){
    cout << "Moldindex is shown om a scale of 0-100. Here are the 5 days with most risk for mold:" << endl;
    for (int i = arraySize - 1; i > 125; i--)
        cout << "Index " << arr[i].moldIndex << "\tDate  " << arr[i].date << "\tTemperature " << arr[i].tempAverageOut << "\tHumidity " << arr[i].humAverageOut << endl;
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

/*  Function to find meterological fall, where the temperature during five consecutive days have to be lower than 10 degrees and 
    higher than 0 degrees. */
void findFall(weatherData arr[], float temp, int arraySize){
    bool fall = false;
    for (int i = 0; i < arraySize; i++)
    {
        if ((arr[i].fallDate > 0 && arr[i].fallDate < 10) && (arr[i + 1].fallDate > 0 && arr[i + 1].fallDate < 10) && (arr[i + 2].fallDate > 0 && arr[i + 2].fallDate < 10) && (arr[i + 3].fallDate > 0 && arr[i + 3].fallDate < 10) && (arr[i + 4].fallDate > 0 && arr[i + 4].fallDate < 10))
        {
            if ((arr[i + 1].fallDate < arr[i].fallDate) && (arr[i + 2].fallDate < arr[i + 1].fallDate) && (arr[i + 3].fallDate < arr[i + 2].fallDate) && arr[i + 4].fallDate < arr[i + 3].fallDate)
            {
                fall = true;
                cout << "Fall occurred on " << arr[i].date << endl;
                break;
            }
        }
    }
    if (fall == false)
    {
        cout << "All dates have now been wrongly sorted, fall date can't been shown." << endl;
    }
}

/*  Function to find meterological winter, average outside temperature have to be below 0 degress for five consecutive days. */
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
    int moldIndex;
    if (temp < 0)
    {
        moldIndex = 0;
    }
    if (temp >= 15)
    {
        moldIndex = (humidity - 78) / 0.22;
    }
    if (temp > 0 && temp < 15)
    {
        moldIndex = ((humidity - 78) * (temp / 15)) / 0.22;
    }
    return moldIndex;
}

/*  When called, this function will prints the menu.   */
void printMenu(){
    cout << "       Hello and welcome to the weather station!      " << endl;
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