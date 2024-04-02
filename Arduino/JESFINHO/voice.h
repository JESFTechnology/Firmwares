void playHelloTone(int speakerPin) {
  // The "Hello" tone consists of two frequencies: 600 Hz and 800 Hz
  // Play each frequency for 250 ms

  // Play 600 Hz tone
  tone(speakerPin, 600, 250);
  delay(250);

  // Stop the tone
  noTone(speakerPin);

  // Play 800 Hz tone
  tone(speakerPin, 800, 250);
  delay(250);

  // Stop the tone
  noTone(speakerPin);
}
