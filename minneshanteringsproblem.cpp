#include <iostream>
using namespace std;

void createMemoryLeak()
{
    int *ptr = new int(5); // Dynamiskt allokerat minne
    // Ingen delete-anrop, så minnet frigörs inte
}

int main()
{
    createMemoryLeak(); // Varje gång funktionen anropas, skapas en ny minnesläcka

    /* '''''''''''' Dubbel frigöring av minne ''''''''''' */
    int *ptr = new int(10); // Dynamiskt allokerat minne
    delete ptr;             // Frigör minnet
    delete ptr;             // Dubbel frigöring av minnet

    /* *************** Dangling pointers ******************* */
    int *dangling_ptr = new int(20); // Dynamiskt allokerat minne
    delete dangling_ptr;             // Frigör minnet
    cout << *dangling_ptr << endl;   // Dangling pointer - försöker läsa från frigjort minne

    return 0;
}
