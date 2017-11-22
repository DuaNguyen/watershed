#include <mbed.h>
#include <MCP23008.hpp>
MCP23008 mcp(PB_7, PB_6, 0);
DigitalOut led(PB_4);
int main() {

    // put your setup code here, to run once:
    printf("hello\n");
    while(1) {
        // put your main code here, to run repeatedly:
        // Set GP0 is output pin
        try {
        mcp.set_output_pins(0x01);
        // Write high to GP0
        mcp.write_outputs(0x01);
        wait(0.5);
        // write low to GP0
        mcp.write_outputs(0x00);
        wait(0.5);
        led = !led;
      } catch (const char* msg) {
        printf("Exception detected\n");
        printf("%s\n", msg );
      }
    }
}
