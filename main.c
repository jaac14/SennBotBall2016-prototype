#include <kipr/botball.h>

void drive(char direction, int speed, int time); // wait optional
void turn(int degrees, int fullturns); // fullturns optional
void serv(int port, int position);
int get_et(int duration);
int et_to_mm(int et_value);
void linefollow();

// int i;

// motors

int ml = 1; // motor left
int mr = 0; // motor right

// sensors

int button = 0;
int serv0 = 1;
int et = 1;
int er = 0;

int main() {
	int speed = 1000;
	
  pathA = 1;
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
  drive('f', speed, pathJ);
  
 
  
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
  msleep(time);
  ao();
  // msleep(wait);
}

void turn(int degrees, int fullturns) {
}

void serv(int port, int position) {
  enable_servos();
  set_servo_position(port, position);
  msleep(200);
  disable_servos();
}

int get_et(int duration) {
  int i;
  for(i = 0; i < duration; i++) {
    printf("ET sensor reading is %d \n", analog(et));
    // code to return distance from et value
    msleep(50);
  }
  return 0;
}

int et_to_mm(int et_value) {
  return 0;
}

void linefollow() {
}
