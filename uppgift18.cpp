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
        if (num == -1) // End input with -1
            break;
        arr[n] = num; // Add the number to the array
        n++;
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap if arr[j] is greater than arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}