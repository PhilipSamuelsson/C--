#include <iostream> // Include the iostream library for input and output operations
#include <cstring>  // Include the cstring library for string manipulation functions

using namespace std; // Use the standard namespace to avoid repeating 'std::'

// Define the struct for a TV program
struct Program
{
    char name[31];    // Program name (up to 30 characters + null terminator)
    char channel[21]; // Channel name (up to 20 characters + null terminator)
    int startHour;    // Start time hour
    int startMinute;  // Start time minute
    int endHour;      // End time hour
    int endMinute;    // End time minute
};

int main()
{
    // Example of how to use the struct
    Program exampleProgram;

    // Assign values to the struct fields
    strncpy(exampleProgram.name, "Cops", sizeof(exampleProgram.name) - 1); // Copy program name to struct
    exampleProgram.name[sizeof(exampleProgram.name) - 1] = '\0';           // Ensure the string is null-terminated

    strncpy(exampleProgram.channel, "Discovery", sizeof(exampleProgram.channel) - 1); // Copy channel name to struct
    exampleProgram.channel[sizeof(exampleProgram.channel) - 1] = '\0';                // Ensure the string is null-terminated

    exampleProgram.startHour = 20;   // Set start hour
    exampleProgram.startMinute = 30; // Set start minute
    exampleProgram.endHour = 21;     // Set end hour
    exampleProgram.endMinute = 30;   // Set end minute

    // Print the program details
    cout << "Program Name: " << exampleProgram.name << endl;                                                                                         // Print program name
    cout << "Channel: " << exampleProgram.channel << endl;                                                                                           // Print channel name
    cout << "Start Time: " << exampleProgram.startHour << ":" << (exampleProgram.startMinute < 10 ? "0" : "") << exampleProgram.startMinute << endl; // Print start time
    cout << "End Time: " << exampleProgram.endHour << ":" << (exampleProgram.endMinute < 10 ? "0" : "") << exampleProgram.endMinute << endl;         // Print end time

    return 0;
}
You need to define a data structure(struct) in a programming language to store information about TV programs.This structure should include :

    Program name : Up to 30 characters.Channel name : Up to 20 characters.Start time : Expressed as hour and minute.End time : Expressed as hour and minute.