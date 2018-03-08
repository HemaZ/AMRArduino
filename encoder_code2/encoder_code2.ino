 int quarter_revolutionsR = 0;
 int quarter_revolutionsL = 0;
 int rpmR = 0;
 int rpmL = 0;
 unsigned long lastmillisR = 0;
 unsigned long lastmillisL = 0;
 int revsR=0;
 int revsL=0;
 void setup(){
 Serial.begin(115200); 
 attachInterrupt(0, rpm_fanR, RISING);
 attachInterrupt(1, rpm_fanL, RISING);
 }
 void loop(){
 if (millis() - lastmillisR == 1000){ //Uptade every one second, this will be equal to reading frecuency (Hz).
 detachInterrupt(0);//Disable interrupt when calculating
 revsR=quarter_revolutionsR/20;
 rpmR = revsR * 60; // Convert frecuency to RPM, note: this works for one interruption per full rotation. For two interrups per full rotation use quarter_revolutions * 30.
 Serial.print("Right Wheel RPM =\t"); //print the word "RPM" and tab.
 Serial.print(rpmR); // print the rpm value.
 Serial.print("\t Hz=\t"); //print the word "Hz".
 Serial.println(revsR); //print revolutions per second or Hz. And print new line or enter.
 quarter_revolutionsR = 0; // Restart the RPM counter
 lastmillisR = millis(); // Uptade lasmillis
 attachInterrupt(0, rpm_fanR, RISING); //enable interrupt
  }

 if (millis() - lastmillisL == 1000){ //Uptade every one second, this will be equal to reading frecuency (Hz).
 detachInterrupt(1);//Disable interrupt when calculating
 revsL=quarter_revolutionsL/20;
 rpmL = revsL * 60; // Convert frecuency to RPM, note: this works for one interruption per full rotation. For two interrups per full rotation use quarter_revolutions * 30.
 Serial.print("Left wheel RPM =\t"); //print the word "RPM" and tab.
 Serial.print(rpmL); // print the rpm value.
 Serial.print("\t Hz=\t"); //print the word "Hz".
 Serial.println(revsL); //print revolutions per second or Hz. And print new line or enter.
 quarter_revolutionsL = 0; // Restart the RPM counter
 lastmillisL = millis(); // Uptade lasmillis
 attachInterrupt(1, rpm_fanL, RISING); //enable interrupt
  }

  
 }
 // this code will be executed every time the interrupt 0 (pin2) gets low.
 void rpm_fanR(){
  quarter_revolutionsR++;
 }
  void rpm_fanL(){
  quarter_revolutionsL++;
 }
