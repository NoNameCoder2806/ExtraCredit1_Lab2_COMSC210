Part 1 of the assignment:
A program that reads .txt files containing normal text content and allows user to decrypt or encrypt the files. Here's a detailed description of the operations that the user can perform:

1. File encryption
            - This option will ask the user to enter the name of the input and output file. If the user enter blank names or the files cannot be opened, an error message will be displayed. Otherwise, the content of
            the file will be encryted.
            - Encryption format: each character is shifted by a repeating sequence of values: +10, +20, +30, +10, +20, +30, ... and the pattern restarts at the beginning of each new line.

2. File decryption
            - This option will also ask the user to enter the name of the input and output file. If the user enter blank names or the files cannot be opened, an error message will be displayed. Otherwise, the content of 
            the file will be decryted.
            - Decryption format: each character is shifted by the reverse order of the encryption sequence: -10, -20, -30, -10, -20, -30, ... It also restarts at the beginning of each new line.

3. Display file content
            - This option will ask the user to enter the name of the file whose content they want to display. If the user enter a blank name or the file cannot be opened, an error message will be displayed. Otherwise
            the content of the file will be displayed.

4. Display the encrypted content
            - This option will display the content of the file that is most recently encrypted. If none of the file has been encrypted (meaning option 1 has never been selected), it will not display anything. If
            the file cannot be opened, an error message will be displayed. Otherwise, the content of most recently encrypted file will be displayed.

5. Display the decrypted content
            - This option will display the content of the file that is most recently decrypted. If none of the file has been decrypted (meaning option 2 has never been selected), it will not display anything. If
            the file cannot be opened, an error message will be displayed. Otherwise, the content of most recently decrypted file will be displayed.

6. Exit
            - This option ends the program. 


Part 2 of the assignment:
a program that reads .txt files containing information on items 
            such as their name, quantity on hand, wholesale cost, and retail 
            cost. The program will only store new items and check whether the
            item has existed based on the item name. Here's a detailed 
            description of the operations:

1. Input
            - The program allows user to input via console or file. If the user choose to input the item's information via the console input option, they will be required to enter the item name, quantity on hand, 
            wholesale cost, and retail cost one by one. If the user wishes to use a file to add the data, they will be required to enter the file's name.

2. Search and display the items
            - The user will be asked to enter the name of the item to search for the matching item name(s) inside the inventory. The function will display all the matching item names starting from the first letter.

3. Change record
            - This option will prompt the user to enter the item name whose information the user wishes to change. The user will be required to enter the new quantity on hand, wholesale cost, and the retail cost.

 4. Display all records
            - The user can select this option to display all the current items in the inventory. 

5. Display inventory report
            - This option will display a report on the total number of items, the total wholesale cost, and the total retail cost of the inventory.

6. Reset inventory
            - If selected, this option will allow the user to reset the whole inventory. Upon selecting, the user will be asked to confirm the choice once more time before the inventory is reset. This option
            cannot be undone once completed.

8. Exit
            - This option ends the program. 
