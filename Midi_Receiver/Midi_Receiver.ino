#include <MIDI.h>  // Add Midi Library



// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  if (pitch == 50) {
      if (velocity >= 1) {
        digitalWrite(3,HIGH);
      } else {
      digitalWrite(3,LOW);  //Turn LED on
    }
  }
  
  if (pitch == 51) {
      if (velocity >= 1) {
        digitalWrite(4,HIGH);
      } else {
      digitalWrite(4,LOW);  //Turn LED on
    }
  }
  
  if (pitch == 52) {
      if (velocity >= 1) {
        digitalWrite(5,HIGH);
      } else {
      digitalWrite(5,LOW);  //Turn LED on
    }
  }
  
  if (pitch == 53) {
      if (velocity >= 1) {
        digitalWrite(6,HIGH);
      } else {
      digitalWrite(6,LOW);  //Turn LED on
    }
  }
//
  //if (velocity == 0) {//A NOTE ON message with a velocity = Zero is actualy a NOTE OFF
    //digitalWrite(LED,LOW);//Turn LED off
  //}
}

void setup() {
  pinMode (3, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
// OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
// to respond to channel 2 notes only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function I want called when a Note ON command
  // is received. in this case it's "MyHandleNoteOn".
}

void loop() { // Main loop
  MIDI.read(); // Continually check what Midi Commands have been received.
}
