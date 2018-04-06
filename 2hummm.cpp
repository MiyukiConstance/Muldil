/*!
 \file      Example1.cpp

 \brief     Super COOL Stuff,  also Richard was fired today!
 \	    Good Drift Wood Riddance!
 \author    Marcel Bergeron   Based on some work from a french guy
 \version   0.1
 \date      05/01/2011
 */

#include <stdio.h>
#include "serialib.h"
#include <stdlib.h>



#define         DEVICE_PORT             "/dev/ttyO2"                  

// Set dev adress
char bigul1[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX adress
char bigul2[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x11, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set Overide
char bigul3[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x10, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Light Overide
char bigul4[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x04, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX Enable
char bigul5[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x0e, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};

int main()
{

// New Stuff

int input = 66;
char input2 = 28;
char line [3];
printf("Input man \n");
std::cin.get( line, 3);
std::cout << line << "\n";
input2 = input;
input = atoi (line);
printf("the value of input is %d \n" ,input);

// Now pour Modifier la valeur de ce que je desire configurer

bigul1[9]={input};
bigul2[9]={input};
//bigul5

printf(" The value of bigul1 9 is %d \n", bigul1[9]);

// End of New Stuff


    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
//    char Buffer[128];
//    char Buffer[128];
    char Buffer[256];
    int Buffed[128];

    // Open serial port

    Ret=LS.Open(DEVICE_PORT,115200);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");




    // Write the AT command on the serial port

    Ret=LS.Write (bigul1, 14);
    Ret=LS.Write (bigul2, 14);
    Ret=LS.Write (bigul3, 14);
    Ret=LS.Write (bigul4, 14);
    Ret=LS.Write (bigul5, 14);                                          // Send the command on the serial port
    if (Ret!=1) {                                                           // If the writting operation failed ...
        printf ("Error while writing data\n");                              // ... display a message ...
        return Ret;                                                         // ... quit the application.
    }
    printf ("Write operation is successful \n");




    // Read a string from the serial device
//    Ret=LS.ReadString(Buffer,'\n',128,5000);  // Read a maximum of 128 characters with a timeout of 5 seconds
//    Ret=LS.ReadString(Buffer, 0xff,128,5000);   // The final character of the string must be a line feed ('\n')
//    if (Ret>0) {
	//Buffed = atoi (Buffer);                                                              // If a string has been read from, print the string
//	printf ("Miyuki : %d \n",Buffer);
       // printf ("String read from serial port : %s",Buffer);}
//}
//    else
//        printf ("TimeOut reached. No data received !\n");                   // If not, print a message.



    // Close the connection with the device

    LS.Close();

    return 0;
}


