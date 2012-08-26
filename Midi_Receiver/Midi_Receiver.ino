#include <MIDI.h>  // Add Midi Library



// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  int onoff = LOW;
  
  if (velocity > 0) { // velocity 0 = off
    onoff = HIGH;
  } else {
    onoff = LOW;
  }
  
   switch (pitch) {
    case 48:
      digitalWrite(1,onoff);
      break;
    case 50:
      digitalWrite(2,onoff);
      break;
    case 52:
      digitalWrite(3,onoff);
      break;
    case 53:
      digitalWrite(4,onoff);
      break;
    case 55:
      digitalWrite(5,onoff);
      break;
    case 57:
      digitalWrite(6,onoff);
      break;
    case 59:
      digitalWrite(7,onoff);
      break;
    case 60:
      digitalWrite(8,onoff);
      break;
    case 62:
      digitalWrite(9,onoff);
      break;
    case 64:
      digitalWrite(10,onoff);
      break;
    case 65:
      digitalWrite(11,onoff);
      break;
    case 67:
      digitalWrite(12,onoff);
      break;
  }
    

//
  //if (velocity == 0) {//A NOTE ON message with a velocity = Zero is actualy a NOTE OFF
    //digitalWrite(LED,LOW);//Turn LED off
  //}
}

void setup() {

  pinMode (1, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (2, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (3, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (14, OUTPUT);
  pinMode (15, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
// OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
// to respond to channel 2 notes only.
  MIDI.setHandleNoteOff(MyHandleNoteOn);
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function I want called when a Note ON command
  // is received. in this case it's "MyHandleNoteOn".
}

void loop() { // Main loop
  MIDI.read(); // Continually check what Midi Commands have been received.
}
