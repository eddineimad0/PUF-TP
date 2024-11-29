#include<common.h>
#include<uart.h>
#include<libopencm3/stm32/rcc.h>
#include<libopencm3/stm32/gpio.h>
#include<stdio.h>

#define PUF_REGION_START 0x20000000
#define PUF_REGION_LEN 0x40

static void firmware_init(){
    rcc_clock_setup_in_hsi_out_64mhz();
    /*rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);*/
}

int main() {
    firmware_init();

    uint8_t* read = (uint8_t*) PUF_REGION_START;
    uart_setup();

    uint8_t print_buffer[256] = {0};

    int32_t size = sprintf((char *) print_buffer,
                            "=======================================================\r\n");
    uint32_t send_size = (size>0)? (uint32_t)size : 0;
    uart_write_buffer(print_buffer, send_size);
    for(uint32_t i = 0; i<PUF_REGION_LEN; i+=8){
        size = sprintf((char *) print_buffer,
                               "%p:\t0x%02X\t0x%02X\t0x%02X\t0x%02X\t0x%02X\t0x%02X\t0x%02X\t0x%02X\r\n",
                               read,read[0],read[1],read[2],read[3],read[4],read[5],read[6],read[7]);
        send_size = (size>0)? (uint32_t)size : 0;
        uart_write_buffer(print_buffer, send_size);
        read += 8;
    }

    while(true){
    }

    return 0;
}

