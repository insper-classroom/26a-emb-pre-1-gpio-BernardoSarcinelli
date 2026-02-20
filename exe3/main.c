#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R_PIN=28;
const int BTN_G_PIN=26;
const int LED_PIN_R=4;
const int LED_PIN_G=6;

int main() {
  int G=0;
  int R=0;
  stdio_init_all();
  //incia os botoes
  gpio_init(BTN_R_PIN);
  gpio_set_dir(BTN_R_PIN, GPIO_IN);
  gpio_pull_up(BTN_R_PIN);

  gpio_init(BTN_G_PIN);
  gpio_set_dir(BTN_G_PIN, GPIO_IN);
  gpio_pull_up(BTN_G_PIN);

  //inicia os LEDs

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {

    if (!gpio_get(BTN_R_PIN)){
      if (R==0){
        R=1;
        gpio_put(LED_PIN_R,R);
      }else{
        R=0;
        gpio_put(LED_PIN_R,R);
      }
      while(!gpio_get(BTN_R_PIN)){
      }
    }

    if (!gpio_get(BTN_G_PIN)){
      if (G==0){
        G=1;
        gpio_put(LED_PIN_G,G);
      }else{
        G=0;
        gpio_put(LED_PIN_G,G);
      }
      while(!gpio_get(BTN_G_PIN)){
      }
    }
  }
}
