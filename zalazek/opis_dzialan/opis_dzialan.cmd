#define ROTATE_SPEED 30
/*
* Przykładowy zestaw poleceń
*/
Set Ob_A 2 0 30 // Polozenie obiektu A
Set Ob_B 10 10 0 // Polozenie obiektu B
Rotate ROTATE_SPEED 40
Pause 1000
Move Ob_A 10 10
Rotate Ob_B ROTATE_SPEED 60
Move Ob_B 10 20
