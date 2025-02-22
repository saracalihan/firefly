#include <stdint.h>

#define GPIO_OUT_W1TS_REG 0x3FF44008
#define GPIO_OUT_W1TC_REG 0x3FF4400C
#define GPIO_ENABLE_REG   0x3FF44020
#define GPIO5             5

inline void delay(){
    int j=0;
    for(int i=0;i<2000000; i++){
        j+=1;
    }
}

void app_main(void)
{
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*) GPIO_OUT_W1TS_REG;
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*) GPIO_OUT_W1TC_REG;
    volatile uint32_t* gpio_enable_reg = (volatile uint32_t*) GPIO_ENABLE_REG;

    // Set the mode for GPIO5 to output
    *gpio_enable_reg = (1 << GPIO5);

    while(1) {
        // Set the level for GPIO5 to HIGH
        *gpio_out_w1ts_reg = (1 << GPIO5);

        // Delay
        delay();
        // Set the level for GPIO5 to LOW
        *gpio_out_w1tc_reg = (1 << GPIO5);
        delay();
        // Delay
    }
}

