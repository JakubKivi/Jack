#include <Stepper.h>  //Stepper library


int StepNum=2050;   //Number of your motor steps check the datasheet of your motor the replace it if necessary


Stepper SurtrStepper(StepNum,9,11,10,6); //Defining the stepper, you should wire IN1-2-3-4 from the driver in (respectivly) d6 d9 d10 d11 from arduino

                                         //Or change the pins correctly

                     

void setup() {

  SurtrStepper.setSpeed(5); //Speed of the motor 9 is most used

}


void loop() {

  SurtrStepper.step(2000);  //Positive and negative changes the direction  
  delay(1000);
  SurtrStepper.step(-2000);
  delay(1000);  

}
