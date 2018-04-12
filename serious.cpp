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
