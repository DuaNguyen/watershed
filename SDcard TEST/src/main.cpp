#include "mbed.h"
#include "rtos.h"
#include "FATFileSystem.h"
#include "SDBlockDevice.h"
#include <stdio.h>
#include <errno.h>
#include "Adafruit_SSD1306.h"
/* mbed_retarget.h is included after errno.h so symbols are mapped to
 * consistent values for all toolchains */
#include "platform/mbed_retarget.h"

class I2CPreInit : public I2C {
 public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl) {
        frequency(400000);
        start();
    }
};
I2CPreInit i2c(PB_7, PB_6);
Adafruit_SSD1306_I2c mylcd(i2c, NC);

SDBlockDevice sd(PA_7, PA_6, PA_5, PA_4);
FATFileSystem fs("sd", &sd);

void return_error(int ret_val){
  if (ret_val)
    printf("Failure. %d\n", ret_val);
  else
    printf("done.\n");
}

void errno_error(void* ret_val){
  if (ret_val == NULL)
    printf(" Failure. %d \n", errno);
  else
    printf(" done.\n");
}

int main()
{
	mylcd.clearDisplay();
	printf("TEST combined read/write SD card and LCD display.\n");
	printf("Opening a new file, testsd.txt.");
	FILE* fd = fopen("/sd/testsd.txt", "w+");
	errno_error(fd);

  mylcd.printf("write to sd card: Hey Watershed, sd card testing...\n");
  mylcd.display();
  fputs("Hey Watershed, sd card testing...\n", fd);
	printf("Closing file.");
	fclose(fd);
	printf(" done.\n");
  mylcd.printf("Re-open and read from sd card:\n");
  mylcd.display();
	printf("Re-opening file read-only.");
	fd = fopen("/sd/testsd.txt", "r");
	errno_error(fd);

	printf("Dumping file to screen.\n");
	char buff[255] = {0};
	while (!feof(fd)){
		int size = fread(&buff[0], 1, 15, fd);
		fwrite(&buff[0], 1, size, stdout);
	}
  fseek(fd, SEEK_SET, 0);
  fgets(buff, 255, fd);
  mylcd.printf("%s\n",buff);
	printf("Closing file.");
	fclose(fd);
	printf(" done.\n");

	printf("Filesystem Demo complete.\n");
	mylcd.printf("done!");
	mylcd.display();
	while (true) {}
}
