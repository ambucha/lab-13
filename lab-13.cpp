// COMSC-210 | Lab 7 | Andrei Buchatskiy
// IDE used : Visual Studio Code

// Brainstorm:
/* Do same thing
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

// Set the array size as a constant
const int SIZE = 30;

// displayAll() displays all array elements
// arguments: vector
// return: nothing
void displayAll(const vector<double>&);

// displaySelect() displays selected array element
// arguments: vector
// return: nothing
void displaySelect(const vector<double>&);

// sortArray() sortsArray reverse and normal
// arguments: vector
// return: nothing
void sortArray(vector<double>&);

// searchElement() searches for selected element in array
// arguments: vector
// return: nothing
void searchElement(vector<double>&);

// minMax() finds min and max and sum values in the array, and average now
// arguments: vector
// return: nothing
void minMaxSumAvg(vector<double>&);

int main() {
    // Create your array of set elements
    vector<double> yields{};

    // Open file and check if it opened
    ifstream file("yields.txt");
    if (!file) {
        cout << "Error: File couldnt be opened";
        return 1;
    }

    // Read the file and fill the array, keep reading untill end of the fgile
    double val;
    while (file >> val){
        yields.push_back(val);
    }

    // Call functions
    displayAll(yields);
    displaySelect(yields);
    searchElement(yields);
    sortArray(yields);
    minMaxSumAvg(yields);
    

    /* Testing if the file read correct
    for (int i = 0; i < SIZE; i++) {
        cout << yields[i] << " ";
    }
    */

}

// Function uses for loop to display every element of the array
void displayAll(const vector<double>& arr){
    cout << "All Yields: ";
    for (double i : arr) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void displaySelect(const array<double, SIZE>& arr){
    // Create variable for element number
    int num;
    cout << "Select yield # (enter -1 if you would not like to select another yield): ";
    cin >> num;

    // Create a loop to keep choosing different elements until chosen to stop
    while(num != -1){
        cout << "Element #" << num << ": " << arr[num - 1] << endl;
        cout << "Select next yield (-1 to stop): ";
        cin >> num;
    }
    cout << endl;
}

void sortArray(array<double, SIZE>& arr){
    // SOrt the array and display using for loop
    sort(arr.begin(), arr.end());
    cout << "Lowest to Highest Yields: ";
    for (double i : arr) {
        cout << i << " ";
    }
    cout << endl << endl;

    // Sort the array in reverse and display in similar fashion
    sort(arr.rbegin(), arr.rend());
    cout << "Highest to Lowest Yields: ";
    for (double i : arr) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void searchElement(array<double, SIZE>& arr){
    // Create a variable for the target element
    double num;
    cout << "Enter a yield to search for: ";
    cin >> num;

    // Iterator to point to the element
    array<double, SIZE>::iterator it;

    // Search for the element
    it = find(arr.begin(), arr.end(), num);
    cout << "Target yield: " << num << endl;
    if (it != arr.end()){
        cout << "Target yield found in position " << it - arr.begin() << endl << endl;
    }
    else {
        cout << "Target yield not found" << endl << endl;
    }
}

void minMaxSumAvg(array<double, SIZE>& arr){
    // Use min max and accumulate functions to find the highest lowest and total yields, average also isnt too hard to add so 
    // CReate sum variable to use for average later
    double sum = accumulate(arr.begin(), arr.end(), 0.0);

    cout << "Max yield: " << *max_element(arr.begin(), arr.end()) <<endl;
    cout << "Min yield: " << *min_element(arr.begin(), arr.end()) <<endl;
    cout << "Total yield: " << sum << endl;
    cout << "Average yield: " << sum / SIZE << endl << endl;
}