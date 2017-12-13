#include <NeoSynth.h>

//#include "neolib.h" // why does uncommenting this break audio?!

NeoSynth synth;    //-Make a synth

typedef struct {
  int note;
  int duration;
} notesType;

const notesType aNotes[] = {
//  {0, 125}, // why does uncommenting this completely mess up the timing?!
  // 1
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  // 2
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  // 3
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125},
  {NOTE_A4, 125}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_GS4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125}, {NOTE_A4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 250}, {NOTE_GS4, 125}, {NOTE_G4, 125},
  {NOTE_G4, 125}, {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_GS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  {NOTE_FS4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125}, {NOTE_G4, 125},
  // solo
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_E5, 1500},
  {NOTE_A5, 250}, {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_E5, 1500},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_E5, 250}, {NOTE_A5, 250}, {NOTE_G5, 2000},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_E5, 1500},
  {NOTE_A5, 250}, {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_E5, 1500},
  {NOTE_A4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 125}, {NOTE_E5, 250}, {NOTE_A5, 250}, {NOTE_AS5, 2500}, {NOTE_G5, 250}, {NOTE_A5, 500},
  // pause before looping
  {0, 2000}
};

int totalNotes;

static uint16_t timeCalibrationCounter  = 0;
unsigned long lastTime = 0;            // variable to store the last time we sent a chord

void setup()
{
  synth.begin();
  synth.setupVoice(0,TRIANGLE,60,ENVELOPE1,80,64);
  synth.setupVoice(1,SQUARE,62,ENVELOPE0,90,64);
  synth.setupVoice(2,NOISE,64,ENVELOPE2,30,64);
  synth.setupVoice(3,TRIANGLE,60,ENVELOPE0,80,64);
  
// FIXME: array size calculation doesn't properly work..
//  totalNotes = sizeof(aNotes) / sizeof(notesType); 
  totalNotes = 84; 
  
  timeCalibrationCounter = 0;
}


void loop()
{
    unsigned long m = synth.millis();

    if (m-lastTime >= aNotes[timeCalibrationCounter-1].duration ){
           synth.mTrigger(0,aNotes[timeCalibrationCounter].note+20);
           lastTime = synth.millis(); // cant use millis from arduino - iox
           timeCalibrationCounter++;
           if (timeCalibrationCounter >= totalNotes) timeCalibrationCounter = 0;
    }

}



//disable millis
//make timer available for NeoSynth
int main(void)
{
    //init();
    setup();
    for (;;)
        loop();
    return 0;
} 

