#include <kipr/botball.h>

void drive(int speed, int time, int wait);

int main() {
	drive();
}

void drive(int speed, int time, int wait) {
  mav(0, speed); // left
  mav(1, speed); // right
  msleep(time);
  ao();
  msleep(wait);
}
