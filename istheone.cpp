/*!
 \file      istheone.cpp

 \brief     Example code source for class serialib.
            This example open the device on ttyACM0.
            (USB to RS232 converter under linux).
            If the opening is successful, it sends the AT command
            and waits for a string being received from the device.
            After 5 seconds, if no valid data are received from the
            device, reception is giving up.
	    ca c'est logiginal, bon quand on defini char bigul[] si on met de.
	    quoi dans les bracket c'est le nombre d'entry, [] laisse ouver no max.
	    je vais mettre les // plus pres des parties concernees.
	    aussi c,est pas cpp, cest g++ filename.cpp seriallib.cpp -o filenemae output.


 \author    Philippe Lucidarme (University of Angers) <serialib@googlegroups.com>
 \version   1.2
 \date      05/01/2011
 */

#include <stdio.h>
#include "serialib.h"


#if defined (_WIN32) || defined( _WIN64)
#define         DEVICE_PORT             "COM1"                               // COM1 for windows
#endif

#ifdef __linux__
#define         DEVICE_PORT             "/dev/ttyO4"                         // ttyS0 for linux
#endif

	//[] bracket vide indefini [x] lenght of the array, star 1 ou 0?

char bigul[]={0x55, 0x00, 0x07, 0x07, 0x01, 0x7a, 0xf6, 0x00, 0x00, 0x2c, 0x9b, 0x1a, 0xa0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x47};

int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
//    char Buffer[128];
    char Buffer[128];



    // Open serial port

    Ret=LS.Open(DEVICE_PORT,57600);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");




    // Write the AT command on the serial port
    // (bigul,23 ); le nom de la array a sender, nombre de bytes
    // essayer juste bigul... semble pas marcher, mais,2 2 bytes..  

    Ret=LS.Write (bigul,21);                                             // Send the command on the serial port
    if (Ret!=1) {                                                           // If the writting operation failed ...
        printf ("Error while writing data\n");                              // ... display a message ...
        return Ret;                                                         // ... quit the application.
    }
    printf ("Write operation is successful \n");




    // Read a string from the serial device
    Ret=LS.ReadString(Buffer,'\n',128,5000);                                // Read a maximum of 128 characters with a timeout of 5 seconds
                                                                            // The final character of the string must be a line feed ('\n')
    if (Ret>0)                                                              // If a string has been read from, print the string
        printf ("String read from serial port : %s",Buffer);
    else
        printf ("TimeOut reached. No data received !\n");                   // If not, print a message.



    // Close the connection with the device

    LS.Close();

    return 0;
}


