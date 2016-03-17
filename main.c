#include <kipr/botball.h>

void drive(char direction, int speed, int time); // wait optional
void turn(char direction, int degrees); // fullturns optional
void serv(int port, int position);
double get_et(int duration);
double et_to_inchs(int et_value);
int exp(int value, int times);
void linefollow();

// int i;

// motors

int ml = 1; // motor left
int mr = 0; // motor right

// sensors

/*
note: things that we are not using should be set to -1
*/

int button = 0; // button port
int serv0 = 1; // servo #0 port
int et = 1; // et port
int er = 0; // er port

int main() {
  int speed = 1000;

  /*pathA = 1;
  turnA = 1;
  pathB = 1;
  turnB = 1;
  pathC = 1;
  turnC = 1;
  pathD = 1;
  turnD = 1;
  pathE = 1;
  turnE = 1;
  pathF = 1;
  turnF = 1;
  pathG = 1;
  turnG = 1;
  pathH = 1;
  turnH = 1;
  pathI = 1;
  turnI = 1;
  pathJ = 1;


  drive('f', speed, pathA);
  drive('r', speed, turnA);
  drive('f', speed, pathB);
  drive('r', speed, turnB);
  drive('f', speed, pathC);
  drive('r', speed, turnC);
  drive('f', speed, pathD);
  drive('r', speed, turnD);
  drive('f', speed, pathE);
  drive('r', speed, turnE);
  drive('f', speed, pathF);
  drive('r', speed, turnF);
  drive('f', speed, pathG);
  drive('r', speed, turnG);
  drive('f', speed, pathH);
  drive('r', speed, turnH);
  drive('f', speed, pathI);
  drive('r', speed, turnI);
  drive('f', speed, pathJ);*/

  

  return 0;
}

void drive(char direction, int speed, int time) {
  int spaad = -1 * speed; // opposite of speed
  // printf("direction: %d\n", direction);
  printf("speed: %d\n", speed);
  printf("time: %d\n", time);
  switch(direction) {
    case 'F':
    case 'f':
      mav(ml, speed); // left
      mav(mr, speed); // right
      break;
    case 'B':
    case 'b':
      mav(ml, spaad);
      mav(mr, spaad);
      break;
    default:
      printf("first parameter: %c is not valid", direction);
  }
  msleep(time);
  ao();
  // msleep(wait);
}

void turn(char direction, int degrees) {
  int speed = 1000;
  int spaad = -1 * speed; // opposite of speed
  // printf("direction: %d\n", direction);
  printf("speed: %d\n", speed);
  switch(direction) {
    case 'R':
    case 'r':
      mav(ml, spaad);
      mav(mr, speed);
      break;
    case 'L':
    case 'l':
      mav(ml, speed);
      mav(mr, spaad);
      break;
    default:
      printf("first parameter: %c is not valid", direction);
  }
  ao();
  // msleep(wait);
}

void serv(int port, int position) {
  enable_servos();
  set_servo_position(port, position);
  msleep(200);
  disable_servos();
}

double get_et(int duration) {
  int i;
  double inchs;
  for(i = 0; i < duration; i++) {
    printf("ET sensor reading is %d \n", analog(et));
    inchs = et_to_inchs(analog(et));
    msleep(50);
  }
  return inchs;
}

int exp(int value, int times) {
  int i;
  int result;
  for(i = 0; i < times; i++) {
    result = result * value;
  }
  return result;
}

double et_to_inchs(int et_value) {
  double et_value_db = (-0.0001 * exp(et_value, 6)) + (0.012 * exp(et_value, 5)) - (0.4889 * exp(et_value, 4)) + (9.0176 * exp(et_value, 3)) - (61.479 * exp(et_value, 2)) - (193.11 * et_value) + (4212.8);
  return et_value_db;
}

void linefollow() {
}
