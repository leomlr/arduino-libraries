#include <Grove_LED_Bar.h>

Grove_LED_Bar bar_2(2, 3, 0);

int j;

void setup() {
  bar_2.begin();
}

void loop() {
  for (j = 1; j <= 10; j++) {
    bar_2.setLevel(j);
    delay(1000*1);
  }
}
