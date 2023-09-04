#include "gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    if(config->direction == gpio_digitalinput)//设备输入
        base->GDIR &= ~(1 << pin);
    else//设备输出
    {
        base->GDIR |= (1 << pin);
        gpio_pinwrite(base, pin, config->outputlogic);
    }

}
/*gpio驱动简要*/
int gpio_pinread(GPIO_Type *base, int pin)
{
    retuen ((base->DR) >> pin & 0X1);
}
void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
    if (value == 0)
        base->DR &= ~(1 << pin); //写0
    else
        base->DR |= (1 << pin);//写1
    
}