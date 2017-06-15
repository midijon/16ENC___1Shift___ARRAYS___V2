#include <Encoder.h>
#include <Bounce.h>

const int buttonPin = 0;
const int ledPin = 32;

int buttonState = 0

Bounce bouncer = Bounce( buttonPin, 5 );

Encoder Enc1(1,2);
int value1;
Encoder Enc2(3,4);
int value2;
Encoder Enc3(5,6);
int value3;
Encoder Enc4(7,8);
int value4;
Encoder Enc5(9,10);
int value5;
Encoder Enc6(11,12);
int value6;
Encoder Enc7(14,15);
int value7;
Encoder Enc8(16,17);
int value8;
Encoder Enc9(18,19);
int value9;
Encoder Enc10(20,21);
int value10;
Encoder Enc11(22,23);
int value11;
Encoder Enc12(24,25);
int value12;
Encoder Enc13(26,27);
int value13;
Encoder Enc14(28,29);
int value14;
Encoder Enc15(30,31);
int value15;
Encoder Enc16(33,34);
int value16;

  long Enc1_previous = -999;
  long Enc2_previous = -999;
  long Enc3_previous = -999;
  long Enc4_previous = -999;
  long Enc5_previous = -999;
  long Enc6_previous = -999;
  long Enc7_previous = -999;
  long Enc8_previous = -999;
  long Enc9_previous = -999;
  long Enc10_previous = -999;
  long Enc11_previous = -999;
  long Enc12_previous = -999;
  long Enc13_previous = -999;
  long Enc14_previous = -999;
  long Enc15_previous = -999;
  long Enc16_previous = -999;

const int MIDI_CC_ENC[16] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65};
const int MIDI_CC_ENC_value[16] = {value1, value2, value3, value4, value5, value6, value7, value8, value9, value10, value11, value12, value13, value14, value15, value16};
const int MIDI_CC_ENC_SHIFT[16] = {66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81};
const int MIDI_CC_ENC_SHIFT_value[16] = {value1, value2, value3, value4, value5, value6, value7, value8, value9, value10, value11, value12, value13, value14, value15, value16};
const int ENC_LIST[16] = {Enc1, Enc2, Enc3, Enc4, Enc5, Enc6, Enc7, Enc8, Enc9, Enc10, Enc11, Enc12, Enc13, Enc14, Enc15, Enc16};
const int ENC_PREVIOUS[16] = {Enc1_previous, Enc2_previous, Enc3_previous, Enc4_previous, Enc5_previous, Enc6_previous, Enc7_previous, Enc8_previous, Enc9_previous, Enc10_previous, Enc11_previous, Enc12_previous, Enc13_previous, Enc14_previous, Enc15_previous, Enc16_previous};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, INPUT_PULLUP);
}

void loop() {

bouncer.update( );
int value = bouncer.read();
if (buttonState == LOW) 
{
  digitalWrite(ledPin, HIGH );
} 
else if (buttonState == HIGH)
{
  digitalWrite(ledPin, LOW );
}

for (int i = 0; i < 16; i++)
{
  if (buttonState == LOW)
  {
  MIDI_CC_ENC_SHIFT_value[i] = ENC_LIST[i].read();
    if(MIDI_CC_ENC_SHIFT_value[i] > 127) {  ENC_LIST[i].write(127);   }
    else if(MIDI_CC_ENC_SHIFT_value[i] <0) {  ENC_LIST[i].write(0);   }

  MIDI_CC_ENC_SHIFT_value[i] = constrain(MIDI_CC_ENC_SHIFT[i], 0, 127);
    if (MIDI_CC_ENC_SHIFT_value[i] !=ENC_PREVIOUS[i]) {  ENC_PREVIOUS[i] = MIDI_CC_ENC_SHIFT_value[i];  usbMIDI.sendControlChange(MIDI_CC_ENC_SHIFT[i], MIDI_CC_ENC_SHIFT_value[i], 1);   }
  }
  else if (buttonPin == HIGH)
  {
  MIDI_CC_ENC_value[i] = ENC_LIST[i].read();
    if(MIDI_CC_ENC_value[i] > 127) {  ENC_LIST[i].write(127);   }
    else if(MIDI_CC_ENC_value[i] < 0) {  ENC_LIST[i].write(0);   }

  MIDI_CC_ENC_value[i] = constrain(MIDI_CC_ENC_value[i], 0, 127);
    if (MIDI_CC_ENC_value[i] !=ENC_PREVIOUS[i]) {  ENC_PREVIOUS[i] = MIDI_CC_ENC_value[i];  usbMIDI.sendControlChange(MIDI_CC_ENC[i], MIDI_CC_ENC_value[i], 1);   }    
  }
}

}
