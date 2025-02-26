/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
//#include <builtins.h>
#include "project.h"
#define _XTAL_FREQ 80000000UL

led_t led1 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN0, .led_status = LED_OFF };
led_t led2 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN1, .led_status = LED_OFF };
led_t led3 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN2, .led_status = LED_OFF };
led_t led4 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN3, .led_status = LED_OFF };
led_t led5 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN4, .led_status = LED_OFF };
led_t led6 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN5, .led_status = LED_OFF };
led_t led7 = { .port_name = GPIO_PORTB, .pin = GPIO_PIN6, .led_status = LED_OFF };



button_t high_btn = {
  .button_pin = {
    .Direction = GPIO_INPUT,
    .Port = GPIO_PORTC,
    .Pin = GPIO_PIN0,
    .Logic = GPIO_LOW
  },  
  .button_active = BUTTON_ACTIVE_HIGH,
  .button_status = BUTTON_RELEASED
};

button_t low_btn = {
  .button_pin = {
    .Direction = GPIO_INPUT,
    .Port = GPIO_PORTC,
    .Pin = GPIO_PIN1,
    .Logic = GPIO_HIGH
  },  
  .button_active = BUTTON_ACTIVE_HIGH,
  .button_status = BUTTON_RELEASED
};



void initialization(void);
void leftToRight(void);
void rightToLeft(void);

button_status_t high_btn_status = BUTTON_RELEASED;
button_status_t low_btn_status = BUTTON_RELEASED;


void main(void) {
    initialization();
    while(1){
        button_read_status(&high_btn,&high_btn_status);
        button_read_status(&low_btn,&low_btn_status);

        if(BUTTON_PRESSED == high_btn_status){
            leftToRight();
        }
        else if(BUTTON_RELEASED == low_btn_status){
            rightToLeft();
        }
        else{
            /*Nothing*/
        }
    }
    
    return;
}

void initialization(void){
    led_initialize(&led1);
    led_initialize(&led2);
    led_initialize(&led3);
    led_initialize(&led4);
    led_initialize(&led5);
    led_initialize(&led6);
    led_initialize(&led7);

    
    button_initialize(&high_btn);
    button_initialize(&low_btn);
}
void leftToRight(void){
    led_turn_on(&led1);
    __delay_ms(10);
    led_turn_on(&led2);
    __delay_ms(10);
    led_turn_on(&led3);
        __delay_ms(10);
    led_turn_on(&led4);
        __delay_ms(10);
    led_turn_on(&led5);
        __delay_ms(10);
    led_turn_on(&led6);
        __delay_ms(10);
    led_turn_on(&led7);
        __delay_ms(10);
        
    led_turn_off(&led7);
    __delay_ms(10);
    led_turn_off(&led6);
    __delay_ms(10);
    led_turn_off(&led5);
    __delay_ms(10);
    led_turn_off(&led4);
    __delay_ms(10);
    led_turn_off(&led3);
    __delay_ms(10);
    led_turn_off(&led2);
    __delay_ms(10);
    led_turn_off(&led1);
    __delay_ms(10);


}

void rightToLeft(void){
    led_turn_on(&led7);
    __delay_ms(10);
    led_turn_on(&led6);
    __delay_ms(10);
    led_turn_on(&led5);
        __delay_ms(10);
    led_turn_on(&led4);
        __delay_ms(10);
    led_turn_on(&led3);
        __delay_ms(10);
    led_turn_on(&led2);
        __delay_ms(10);
    led_turn_on(&led1);
        __delay_ms(10);
        
    led_turn_off(&led1);
    __delay_ms(10);
    led_turn_off(&led2);
    __delay_ms(10);
    led_turn_off(&led3);
    __delay_ms(10);
    led_turn_off(&led4);
    __delay_ms(10);
    led_turn_off(&led5);
    __delay_ms(10);
    led_turn_off(&led6);
    __delay_ms(10);
    led_turn_off(&led7);
    __delay_ms(10);
    


    

}