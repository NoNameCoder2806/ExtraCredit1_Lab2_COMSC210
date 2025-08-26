/*
Student: Dat Hoang Vien
Subject: COMSC-165: Advanced Programming With C & C++
Assignment: 8
Part: 1
Date: 07/05/2025
Description: a program that reads .txt files containing normal text content and 
            allows user to decrypt or encrypt the files. Here's a detailed 
            description of the operations that the user can perform:

            1. File encryption
            - This option will ask the user to enter the name of the input and 
            output file. If the user enter blank names or the files cannot be 
            opened, an error message will be displayed. Otherwise, the content of
            the file will be encryted.
            - Encryption format: each character is shifted by a repeating 
            sequence of values: +10, +20, +30, +10, +20, +30, ... and the pattern
            restarts at the beginning of each new line.

            2. File decryption
            - This option will also ask the user to enter the name of the input 
            and output file. If the user enter blank names or the files cannot be 
            opened, an error message will be displayed. Otherwise, the content of 
            the file will be decryted.
            - Decryption format: each character is shifted by the reverse order
            of the encryption sequence: -10, -20, -30, -10, -20, -30, ... It also 
            restarts at the beginning of each new line.

            3. Display file content
            - This option will ask the user to enter the name of the file whose
            content they want to display. If the user enter a blank name or the 
            file cannot be opened, an error message will be displayed. Otherwise
            the content of the file will be displayed.
            
            4. Display the encrypted content
            - This option will display the content of the file that is most 
            recently encrypted. If none of the file has been encrypted (meaning  
            option 1 has never been selected), it will not display anything. If
            the file cannot be opened, an error message will be displayed.
            Otherwise, the content of most recently encrypted file will be 
            displayed.

            5. Display the decrypted content
            - This option will display the content of the file that is most 
            recently decrypted. If none of the file has been decrypted (meaning  
            option 2 has never been selected), it will not display anything. If
            the file cannot be opened, an error message will be displayed.
            Otherwise, the content of most recently decrypted file will be 
            displayed.

            6. Exit
            - This option ends the program. 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function Prototype
bool fileEncryption(const string fileInput, const string fileOutput, string& errorMessage);

void stringEncryption(string&);

bool fileDecryption(const string fileInput, const string fileOutput, string& errorMessage);

void stringDecryption(string&);

bool displayContent(const string fileName, string& errorMessage);

int main()
{
    // Declare variables
    int choice = 0;                    // User's choice
    bool loop = true;                  // Loop the program
    string fileToEncrypt = "";         // Name of the encryption file
    string fileToDecrypt = "";         // Name of the decryption file
    string currentEncryptedFile = "";  // Name of the encrypted file
    string currentDecryptedFile = "";  // Name of the decrypted file
    string errorMessage = "";          // Error message

    // Ask user to enter choice
    while (loop)
    {
        // Ask the user to pick an option
        cout << "Choose from these options: " << endl;
        cout << "1. File encryption" << endl;
        cout << "2. File decryption" << endl;
        cout << "3. Display file content" << endl;
        cout << "4. Display the encrypted content" << endl;
        cout << "5. Display the decrypted content" << endl;
        cout << "6. Exit!" << endl;
        cout << "Your option: ";
        cin >> choice;
        cin.ignore(1000, 10);

        // Check whether the option is valid
        while (choice < 1 || choice > 6)
        {
            // Ask the user to enter a valid option
            cout << "Invalid! Please enter an option from 1 - 5: ";
            cin >> choice;
            cin.ignore(1000, 10);
        }

        // Switch-cases
        switch (choice)
        {
            // 1. File encryption
            case 1: 
            {
                // Let user enter the name of the file to encrypt
                cout << " - Enter the name of the file you want to encrypt: ";
                getline(cin, fileToEncrypt);

                // Let user enter the name of the output file, 
                // whose content needs decryption
                cout << " - Enter the name of the output file: ";
                getline(cin, fileToDecrypt);

                // Print a blank line
                cout << endl;

                // Encrypt the file and check whether it was successful
                if (fileEncryption(fileToEncrypt, fileToDecrypt, errorMessage))
                {
                    cout << " --- File encryption successful! --- \n" << endl;
                    currentEncryptedFile = fileToDecrypt;
                }
                else
                {
                    cout << "Error: " << errorMessage << "\n" << endl;
                }

                // Reset the variables
                errorMessage = "";
                fileToEncrypt = "";
                fileToDecrypt = "";

                // Break out of the switch-case
                break;
            }

            // 2. File decryption
            case 2:
            {
                // Let user enter the name of the file to decrypt
                cout << " - Enter the name of the file you want to decrypt: ";
                getline(cin, fileToDecrypt);

                // Let user enter the name of the output file,
                // whose content needs encryption
                cout << " - Enter the name of the output file: ";
                getline(cin, fileToEncrypt);

                // Print a blank line
                cout << endl;

                // Decrypt the file and check whether it was successful
                if (fileDecryption(fileToDecrypt, fileToEncrypt, errorMessage))
                {
                    cout << " --- File decryption successful! --- \n" << endl;
                    currentDecryptedFile = fileToEncrypt;
                }
                else
                {
                    cout << "Error: " << errorMessage << "\n" << endl;
                }

                // Reset the variables
                errorMessage = "";
                fileToEncrypt = "";
                fileToDecrypt = "";

                // Break out of the switch-case
                break;
            }

            // Display the file's content
            case 3:
            {
                // Store file's name
                string fileName = "";

                // Let user enter the name of the file to display
                cout << " - Enter the name of the file you want to display: ";
                getline(cin, fileName);

                // Print a header to console
                cout << " --- File content --- " << endl;
                cout << endl;

                // Display the encrypted content
                if(!displayContent(fileName, errorMessage))
                {
                    cout << "Error: " << errorMessage << endl;
                }

                // Print a footer to console
                cout << endl;
                cout << " --- File content --- " << endl;
                cout << endl;

                // Reset the variables
                errorMessage = "";

                // Break out of the switch-case 
                break;
            }

            // 4. Display the encrypted content
            case 4:
            {
                // Print a header to console
                cout << " --- Encrypted content --- " << endl;
                cout << endl;

                // Display the encrypted content
                if(!displayContent(currentEncryptedFile, errorMessage))
                {
                    cout << "Error: " << errorMessage << endl;
                }

                // Print a footer to console
                cout << endl;
                cout << " --- Encrypted content --- " << endl;
                cout << endl;

                // Reset the variables
                errorMessage = "";

                // Break out of the switch-case 
                break;
            }

            // 5. Display the decrypted content
            case 5:
            {
                // Print a header to console
                cout << " --- Decrypted content --- " << endl;
                cout << endl;

                // Display the decrypted content
                if(!displayContent(currentDecryptedFile, errorMessage))
                {
                    cout << "Error: " << errorMessage << endl;
                }

                // Print a footer to console 
                cout << endl;
                cout << " --- Decrypted content --- " << endl;
                cout << endl;

                // Reset the variables
                errorMessage = "";

                // Break out of the switch-case 
                break;
            }

            // 6. Exit
            case 6:
            {
                // Print an exit message and set the looping boolean to false
                cout << "Thank you for using this program!" << endl;
                loop = false;
                break;
            }
        }
    }
    
    return 0;
}

// Define function
void stringEncryption(string& str)
{
    // Variables
    int shifts[] = {10, 20, 30};  // The format to encrypt the characters

    // Loop and encrypt the string
    for(int i = 0; i < str.length(); i++)
    {
        str.at(i) = str.at(i) + shifts[i % 3];
    }
}

bool fileEncryption(const string fileInput, const string fileOutput, string& errorMessage)
{
    // Check whether the input file name is empty
    if (fileInput.empty())
    {
        errorMessage = "Input file name is empty!";
        return false;
    }

    // Check whether the output file name is empty
    if (fileOutput.empty())
    {
        errorMessage = "Output file name is empty!";
    }

    // Create 2 file stream objects and open the files
    ifstream fin;
    fin.open(fileInput, ios::in);
    ofstream fout;
    fout.open(fileOutput, ios::out);

    // Check whether we can open the input file
    if (!fin)
    {
        errorMessage = "Could not open " + fileInput + "!";
        return false;
    }

    // Check whether we can open the output file
    if (!fout)
    {
        errorMessage = "Could not open " + fileOutput + "!";
        return false;
    }

    // Variables
    string line = "";  // Store the lines of the file

    // Read the content of the file
    while (getline(fin, line))
    {
        // Encrypt the string and paste it into the output file
        stringEncryption(line);
        fout << line << endl;
    }

    // Close and clear the fie stream objects
    fin.close();
    fin.clear();
    fout.close();
    fout.clear();
    
    return true;
}

void stringDecryption(string& str)
{
    // Variables
    int shifts[] = {-10, -20, -30};  // The format to decrypt the characters

    // Loop and encrypt the string
    for(int i = 0; i < str.length(); i++)
    {
        str.at(i) = str.at(i) + shifts[i % 3];
    }
}

bool fileDecryption(const string fileInput, const string fileOutput, string& errorMessage)
{
    // Check whether the input file name is empty
    if (fileInput.empty())
    {
        errorMessage = "Input file name is empty!";
        return false;
    }
    
    // Check whether the output file name is empty
    if (fileOutput.empty())
    {
        errorMessage = "Output file name is empty!";
        return false;
    }

    // Create 2 file stream objects and open the files
    ifstream fin;
    fin.open(fileInput, ios::in);
    ofstream fout;
    fout.open(fileOutput, ios::out);

    // Check whether we can open the input file
    if (!fin)
    {
        errorMessage = "Could not open " + fileInput + "!";
        return false;
    }

    // Check whether we can open the output file
    if (!fout)
    {
        errorMessage = "Could not open " + fileOutput + "!";
        return false;
    }

    // Variables
    string line = "";  // Store the lines of the file

    // Read the content of the file
    while (getline(fin, line))
    {
        // Encrypt the string and paste it into the output file
        stringDecryption(line);
        fout << line << endl;
    }

    // Close and clear the fie stream objects
    fin.close();
    fin.clear();
    fout.close();
    fout.clear();

    return true;
}

bool displayContent(const string fileName, string& errorMessage)
{
    // Check whether file name is empty
    if (fileName.empty())
    {
        errorMessage = "No content to display!";
        return false;
    }

    // Create a file stream object to read the files
    ifstream fin;
    fin.open(fileName, ios::in);

    // Check whether we can open the file
    if (!fin)
    {
        errorMessage = "Could not open " + fileName + "!";
        return false;
    }

    // Variables
    string line = "";  // Store the lines of the file

    // Print all the lines to the console
    while (getline(fin, line))
    {
        // Paste the data to the console
        cout << line << endl;
    }

    // Close and clear the fie stream object
    fin.close();
    fin.clear();

    return true;
}