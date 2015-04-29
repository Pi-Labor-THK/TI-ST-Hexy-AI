//Emmilein die kleine Spinne krackselt in die Regenrinne...
//Hier läuft alles zusammen.

#include "Servotor32.h" // call the servotor32 Library
Servotor32 hexy;

//Global Variables
//Do not touch...
unsigned long millisekunden = 0; //replace of millis() for calculate sine.
unsigned long previousMillis = 0; //Used for virtual Timer

//***************************************************SET UP RUNNING-PARAMETER HERE**************************************************************

long interval = 20; //How often the Servos should be updated... Here 1000/20 = 50 times per Second ^= 50Hz. This is the normal update speed for normal servos.

//Change only for finetuning speed and/or if legs hit each other.
const int schrittweiteMin = 1300;
const int schrittweiteMax = 1900;

//Change for finetuning and/or for moving over higher objects.
const int beinHoeheMin = 2000; //Kleiner -> Höher
const int beinHoeheMax = 2350; //Größer -> Tiefer

//Change if the foot isn't high enough to move over objects.
const int fussHoeheMin = 900;
const int fussHoeheMax = 1400;

int frequenz = 2; //Frequency of the sine. Change for more or less speed. If you change this value while running it's cogging. So spd is used for changing speed. Negative frequency causes reversal.

boolean keepRunning = false;

//****************************************************Programmvariablen**************************************************************************

int richtung = 0; //0 Geradeaus, 90 ^= 90Grad rechts, -90 ^= -90Grad links
int spd = 0;//This is the running speed of hexy. It's used for counting up milliseconds, so higher spd causes faster running but to high causes cogging.

void setup() {
  hexy.begin();
  delay(10000);
  standUp();
}

void loop() {
  update(); //Check if Servos have to be updated
  //parseSerial(); //Look for new commands
  if (keepRunning) {//Für asymetrisches Laufen
    runUntil(0); //Wird nur zur Initialisierung mit der richtigen Zahl aufgerufen (Siehe Communication)
}

delay(20);
int cm = hexy.ping();
int zaehler = 0;
Serial.println(cm);
    if (cm <= 17 && cm != 0)
    {
      spd = 0;
      turn(-85);
      delay(100);
      zaehler += 1;
      
      if (zaehler == 2)
     {
       turn(175);
       zaehler = 0;  
      } 
     
      
    }
    else
    {
     spd = 200;
      
    }

   // makeShow();
}


//Verfuegbare Funktionen:
//Wenn spd positiv ist, rennt Hexy, wenn negativ rueckwaerts, wenn 0 bleibt sie stehen.

//turn(int degree)           - Dreht um "degree"-Grad auf der Stelle. //Achtung fehlendes Finetuning!
//disableServos()            - Schaltet alle Servos gnadenlos ab
//standUp()                  - Hexy steht auf
//standUpFull()              - Hexy richtet sich komplett auf und zentriert die Beine
//layForward(int degree)     - Hexy lehnt sich um die Gradzahl nach vorne
//layDown();                 - Hexy hat genug...
//runUntil();



