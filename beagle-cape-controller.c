/*
  ============================================================================
  Name        : bacon-cape-controller.c
  Author      : Ryan Johnson
  Version     :
  Copyright   : Your copyright notice
  Description : Task 2,
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
//open file
#include <fcntl.h>
//Read file
#include <unistd.h>

 /*
  * Marcos for hardware compoents
  */
 #define SILDER "/sys/devices/ocp.3/bacon_adc_helper.15/AIN5"
 #define SWITCH "/sys/class/gpio/gpio22"

//Functions
char * getBaconHardwareValue(char * hardware);

int main(void) {

  //Set value on LED Display 0..9 + turn on/off the dot with GET

  //Output current value of slider as integer

  //Output status of push switch in eihter "up" or "down"
  char * sliderV = getBaconHardwareValue("/sys/devices/ocp.3/bacon_adc_helper.15/AIN5");
  // char switchV = getHardwareValue(SWITCH);

  puts("sliderV");
  puts(sliderV);

  return EXIT_SUCCESS;
}

 /*
  * Playground
  */

 // int getSliderValue() {
 //
 //   //Open slider value file with write only permission
 //   int result = open(SILDER "/value", O_RDONLY);
 //
 //   if (result == -1) {
 //     //Error
 //     perror("Failed to Read Slider value");
 //     exit(EXIT_FAILURE);
 //   }
 //
 //   //Return value
 //   return result;
 // }
 //
 // char getSwitchValue() {
 //
 //   //Open slider value file with write only permission
 //   int fd = open(SWITCH "/value", O_RDONLY);
 //
 //   if (fd == -1) {
 //     //Error
 //     perror("Failed to Read Switch value");
 //     exit(EXIT_FAILURE);
 //   }
 //
 //   char result[1];
 //
 //   //Read 1 byte from start of the file
 //   int byteRead = read(fd, result, 1);
 //
 //   //Loop for puting read value to result
 //   int i;
 //   for (i=0; i<byteRead; i++) {
 //     putchar(result[i]);
 //   }
 //
 //   //Close file
 //   close(fd);
 //
 //   //Return value
 //   return result;
 // }
 //

 //Macro to string might cause error, watch out
 char * getBaconHardwareValue(char * hardware) {

   //Open Hardware value file with write only permission
   int fd = open(SILDER "/value", O_RDONLY);

   //Error
   if (fd == -1) {
     perror("Failed to Read value of " SILDER);
     exit(EXIT_FAILURE);
   }

   //Return value
   char * results;

   //Read 1 byte from start of the file
   int byteRead = read(fd, results, 5);

   //Loop for puting read value to result
   int i;
   char test[5];

  //  itoa(byteRead, test, 10);
   for (i=0; i<byteRead; i++) {
    puts(SILDER[0] "/value");
     putchar(results[i]);
   }

   //Close file
   close(fd);

   //Return value
   return results;
}
