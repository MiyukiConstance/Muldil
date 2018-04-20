#include <prussdrv.h>
#include <pruss_intc_mapping.h>
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
#include <iostream>
#include <fstream>
#include <string>
// faire menage dans les includes a la fin
#include <prussdrv.h>
#include <pruss_intc_mapping.h>
#define PRU_NUM 0 	// Using PRU 0

#define         DEVICE_PORT             "/dev/ttyO2"  

// Experimental Stuff ///




//  ca ca onne une erreuree par ce que pas dasn foncr Printf("POULET MOTHERFUCKER");

// Experimental Stuff End ///
std::string testOut[10];  //testOut est array que je veut sortir en csv
int god = 0;
int readfile()
{
std::string line;
std::ifstream myfile ("configuration.txt");
if (myfile.is_open())
{int i = 2;  // 2 par ce que 1 c'est usrName
while ( getline (myfile,line) )
{

std::cout << line << '\n';

testOut[i] = line;
i++;
}
std::cout << "sale cave" << '\n' << testOut[4] << '\n' << testOut[1];
// 1 est operator name 2 est jadore donc 
std::cout << '\n';
myfile.close();
}
else {
std::cout << "Unable to open File \n";
exit (EXIT_FAILURE);
}
return 0;
}


int writeCsv(){

std::ofstream myfile;
myfile.open ("results.csv", std::ios::app);
if (myfile.is_open()){
printf("jesus bolt \n");
myfile << testOut[1] << ',' << testOut[4] << '\n';
myfile.close();
}
else std::cout << "unable to open file";
}

char usrPass[14];
int passAuth(){ 
std::string root = "root";
std::string password = "password";
if (usrPass == root){
// vas remplacer par case NON PEUT PAS single expression multiple  cases
god =1;
//usrPass = root;
printf("je suis une huiter man!");
}
// marcheras pas switch(1){
if (usrPass == password){
printf("Good!");
}

else {
printf("You are not qualified to run this station Motherfucker\n");
exit(EXIT_FAILURE);
}
}

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
char usrName[14];
char supName[14];
char supPass[14];
//char usrPass[14];

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

char string;

int main()
{

if(getuid()!=0){
printf("You must run this program as root. EXITING.\n");
exit(EXIT_FAILURE);
}

// Initialize structure used by the prussdrv_pruintc_intc ca a lair
//tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

printf("\n\n\n\n\n");
printf("Welcome to the LIDLUM Linear Serie Automated Test \n \n");
printf("Enter your Operator Name: \n\n");
kbin();
int stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
usrName[i] = name[i];
testOut[1] = usrName;  // teporaire log genre ostie de chien sale
printf("Operator name = %s \n", usrName);
}
printf("stringLength = %d \n", stringLength);
printf("Welcomme %s \nInput Operator Password:", usrName);
kbin();
// passer a une variable
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
usrPass[i] = name[i];
}

passAuth();

if (god == 0){// le return de kbin c'est toujours name
printf("\n\nMake your Supervivsor approve these settings: \n\n");
}
// faut rajouter les includes
readfile();


//printf("The Program will read from a file and display the content \n");
//printf("The file will have all the information about the unit \n\n");
// non ca je lai mis apres la logique.


if(god == 0){
printf("Enter Supervisor Name:\a");
kbin();
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++){
supName[i] = name[i];
}
printf("stringLength = %d \n", stringLength);
printf("sup name = %s \n", name);
printf("Enter Supervisor Password:\a");
// metre la le usr root pass
//if(god = 0) {
kbin();
//}
//else printf("fuck");
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
supPass[i] = name[i];
} // end of god 0
//}
//else printf("Fuck");
//}
}

//if (god = 0){
printf("supPass = %s \n", supPass);



// /old  stuff  New Stuff
int input = 66;
char input2 = 28;
char line [3];
printf("Enter Primary(starting) Adress: \n");
std::cin.get( line, 3);
std::cout << line << "\n";
input2 = input;
input = atoi (line);
printf("the value of input is %d \n" ,input);
printf("Scan DUT (Device Under Test) Bar Code to Beiging Test \n");
	
//    bzero(buffer,256);
//    printf("reading barcode:");

writeCsv();

    scan_keyascii();
printf("\n\n\nThe Test is Executing\n");
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
    // Write Lidlum command on the serial port

    Ret=LS.Write (bigul1, 14);
    Ret=LS.Write (bigul2, 14);
    Ret=LS.Write (bigul3, 14);
    Ret=LS.Write (bigul4, 14);
    Ret=LS.Write (bigul5, 14);                                          // Send the command on the serial port
    if (Ret!=1) {                                                           // If the writting operation failed ...
        printf ("Error while writing data\n");                              // ... display a message ...
        return Ret;                                                         // ... quit the application.
    }
    printf ("POulet Write operation is successful \n");
    printf ("Why Stall \n ca a lair quil faut le backslas n abs \n");




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

printf("This is where we mess with the pruss \n");

// Second part of the test, Pruss Stuff for the DMX


// Initialize structure used by prussdrv_pruintc_intc
// PRUSS_INTC_INITDATA is found in the pruss_intc_mapping.h
tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
// Allocate and initialyze Memory
prussdrv_init ();
prussdrv_open (PRU_EVTOUT_0);
// Maps PRU Interrupts
prussdrv_pruintc_init(&pruss_intc_initdata); 

// Maintenant ecrire une valeur dans la memoire du PRUSS
// Motherfucker
// safe pour le debut mais modify
unsigned int percent = 50;
prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 0, &percent, 4);
unsigned int sample = 10;
prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 1, &sample, 4);
// quand devmem2 ces adresse 0x4a300000
// ca donne 0x32 qui est 50 dec et 0x4a300004 donne BB

// up to this point it fucking works!!!!!
//but I should realy split the program ?  francois?


// Load and Execute the PRU Programm on the PRU
prussdrv_exec_program (PRU_NUM, "./toBeDmx.bin");
// Wwait for the event Completion from PRU, returns PRU_EVTOUT_0 number
int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
printf("PRU program completed, event number %d. \n", n);
// Disable PRU and close memory mappings

prussdrv_pru_disable(PRU_NUM);
prussdrv_exit ();


    return 0;
}


