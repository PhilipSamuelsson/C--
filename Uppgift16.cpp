#include <iostream>
using namespace std;

int main()
{
    int arr[100]; // Array to store integers up to 100 elements
    int n = 0;    // Number of elements in the array
    int num;

    cout << "Enter integers (end with -1):\n";

    // Read integers and insert them sorted into the array
    while (true)
    {
        cin >> num;
        if (num == -1) // Break input loop if -1 is entered
            break;

        // Insert the number into the correct position in the sorted array
        int i;
        for (i = n - 1; (i >= 0 && arr[i] > num); i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = num;
        n++;
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    // Linear search in the sorted array
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            pos = i;
            break; // Number found, exit loop
        }
        else if (arr[i] > target)
        {
            break; // Stop search early since array is sorted
        }
    }

    if (pos != -1)
        cout << "Number found at position: " << pos << endl;
    else
        cout << "Number not found!" << endl;

    return 0;
}
