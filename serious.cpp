#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "serialib.h"
#include <ctype.h>
#include <limits>  //   //?
#include <stdio_ext.h>

#define         DEVICE_PORT             "/dev/ttyO2"  

char buffer[256];
char bar_value;

int scan_keyascii()
{
 int fd;
 struct input_event remote_event;
 unsigned char i,k=0;
 
 memset(buffer,' ',sizeof(buffer));

  unsigned char kbdus[128] =
 {
  0,  27, '1', '2', '3', '4', '5', '6', '7', '8', /* 9 */
   '9', '0', '-', '=', '\b', /* Backspace */
   '\t',   /* Tab */
   'Q', 'W', 'E', 'R', /* 19 */
   'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\n', /* Enter key */
  0,   /* 29   - Control */
   'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', /* 39 */
  '\'', '`',   0,  /* Left shift */
  '\\', 'Z', 'X', 'C', 'V', 'B', 'N',   /* 49 */
   'M', ',', '.', '/',   0,    /* Right shift */
   '*',
  0, /* Alt */
   ' ', /* Space bar */
  0, /* Caps lock */
  0, /* 59 - F1 key ... > */
  0,   0,   0,   0,   0,   0,   0,   0,
  0, /* < ... F10 */
  0, /* 69 - Num lock*/
  0, /* Scroll Lock */
  0, /* Home key */
  0, /* Up Arrow */
  0, /* Page Up */
   '-',
  0, /* Left Arrow */
  0,
  0, /* Right Arrow */
   '+',
  0, /* 79 - End key*/
  0, /* Down Arrow */
  0, /* Page Down */
  0, /* Insert Key */
  0, /* Delete Key */
  0,   0,   0,
  0, /* F11 Key */
  0, /* F12 Key */
  0, /* All other keys are undefined */
 };  
  fd = open("/dev/input/event1", O_RDONLY); /* Open the event file */

   if(fd == -1) 
  {
   printf("Can not open the input device!\n");
   return 1;
  }
  else
  { 
   while (1) 
   {
    read(fd, &remote_event, sizeof(struct input_event)); /* read the last event */
    if(remote_event.type == EV_KEY && remote_event.value == 1)
    { /* Check if a key was pressed */
    
      if(remote_event.code==103) 
      { /* Compare with key up code */
       printf("Key up was pressed\n");
      }
      else if(remote_event.code==108) 
      { /* Compare with key down code */
       printf("Key down was pressed\n");
      }
      /* ... */
      else
      { 
       if((remote_event.code <= 128) && (remote_event.code != 42))
       {
        i = kbdus[remote_event.code];
       
        if((i == '\n')||(i == '\r'))
        {
         buffer[k] = 0;
         bar_value = k;
         break;
        }
        else
        {
        
         putchar(i);
         buffer[k] = i;
         k++;
        }
       }
        }
      
    }
   }
  }

   return 0;
}

int main()
{  
    char *buf;
    char buf1[2],LCD_print[16],LCD_print1[16];
    
    int loc = 0;
    int bytesread = 0;
    int lcd_print;    
    bzero(buffer,256);
    printf("reading barcode:");
    scan_keyascii();

    return 0;
}

   
   /// new stuff
   
   
   
   /*!
 \file      Example1.cpp

 \brief     Super COOL Stuff,  also Richard was fired today!
 \	    Good Drift Wood Riddance!
 \author    Marcel Bergeron   Based on some work from a french guy
 \version   0.1
 \date      05/01/2011
 */

                

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

char name[14];
char supname[14];



int kbin() //keyboard Input

{

std::cin.get( name, 14);
std::cin.clear();
__fpurge(stdin);
//std::cin.ignore(8, '\n') ; du stuff qui marche pas
//fflush(stdin);     entoucas dans mon cas
//__fpurge(stdin); original works

return 1;
}
int main()
{

// New New Stuff

printf("Welcome to the Linear Serie Automated Test \n \n");
printf("Enter your Lid Name: \n");
kbin();
printf("Welcome %s \n Make your Supervivsor approve these settings \n", name);
// insert stuff here

printf("POULET! \n");
printf("supervisor name:");
kbin();
printf("sup name = %s \n", name);
supname = (name[14]);


// /old  stuff  New Stuff
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


  0, /* Alt */
   ' ', /* Space bar */
  0, /* Caps lock */
  0, /* 59 - F1 key ... > */
  0,   0,   0,   0,   0,   0,   0,   0,
  0, /* < ... F10 */
  0, /* 69 - Num lock*/
  0, /* Scroll Lock */
  0, /* Home key */
  0, /* Up Arrow */
  0, /* Page Up */
   '-',
  0, /* Left Arrow */
  0,
  0, /* Right Arrow */
   '+',
  0, /* 79 - End key*/
  0, /* Down Arrow */
  0, /* Page Down */
  0, /* Insert Key */
  0, /* Delete Key */
  0,   0,   0,
  0, /* F11 Key */
  0, /* F12 Key */
  0, /* All other keys are undefined */
 };  
  fd = open("/dev/input/event1", O_RDONLY); /* Open the event file */

   if(fd == -1) 
  {
   printf("Can not open the input device!\n");
   return 1;
  }
  else
  { 
   while (1) 
   {
    read(fd, &remote_event, sizeof(struct input_event)); /* read the last event */
    if(remote_event.type == EV_KEY && remote_event.value == 1)
    { /* Check if a key was pressed */
    
      if(remote_event.code==103) 
      { /* Compare with key up code */
       printf("Key up was pressed\n");
      }
      else if(remote_event.code==108) 
      { /* Compare with key down code */
       printf("Key down was pressed\n");
      }
      /* ... */
      else
      { 
       if((remote_event.code <= 128) && (remote_event.code != 42))
       {
        i = kbdus[remote_event.code];
       
        if((i == '\n')||(i == '\r'))
        {
         buffer[k] = 0;
         bar_value = k;
         break;
        }
        else
        {
        
         putchar(i);
         buffer[k] = i;
         k++;
        }
       }
        }
      
    }
   }
  }

   return 0;
}

int main()
{  
    char *buf;
    char buf1[2],LCD_print[16],LCD_print1[16];
    
    int loc = 0;
    int bytesread = 0;
    int lcd_print;    
    bzero(buffer,256);
    printf("reading barcode:");
    scan_keyascii();

    return 0;
}
