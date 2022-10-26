#include <gd32f4xx.h>

void rf_ctrl_init(void);
int main(void) {

    rf_ctrl_init();
    while (1)
        ;
}