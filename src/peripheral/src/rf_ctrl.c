#include <gd32f4xx.h>

const static uint32_t channel1_att_pin_config[6][2] = {
    {GPIOC, GPIO_PIN_6},  {GPIOC, GPIO_PIN_9},  {GPIOA, GPIO_PIN_9},
    {GPIOA, GPIO_PIN_10}, {GPIOA, GPIO_PIN_11}, {GPIOA, GPIO_PIN_12}};

void channel1_att_set(uint8_t value) {
    for (uint32_t i = 0; i < 6; i++) {
        gpio_bit_write(channel1_att_pin_config[i][0],
                       channel1_att_pin_config[i][1], value % 2 > 0 ? 1 : 0);
        value = value / 2;
    }
}

void rf_ctrl_init(void) {
    // enable all gpio clock
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);

    // config channel1 gpios
    for (uint32_t i = 0; i < 6; i++) {
        gpio_mode_set(channel1_att_pin_config[i][0], GPIO_MODE_OUTPUT,
                      GPIO_PUPD_NONE, channel1_att_pin_config[i][1]);
    }

    channel1_att_set(0xaa);
}
