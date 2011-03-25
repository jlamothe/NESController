/// @file NESController.cpp
/// @author Jonathan Lamothe

#include "NESController.h"

#include <WProgram.h>

/// @brief Number of microseconds for a latch pulse.
#define LATCH_TIME 12

/// @brief Number of microseconds for a clock pulse.
#define CLOCK_TIME 6

NESController::NESController(int latch, int clock, int data)
{

  // Save the pin numbers:
  this->latch = latch;
  this->clock = clock;
  this->data = data;

  // Initialize the pins:
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, INPUT);
  digitalWrite(latch, LOW);
  digitalWrite(clock, LOW);
  digitalWrite(data, LOW);

}

void NESController::scan()
{

  // Read A button:
  digitalWrite(latch, HIGH);
  delayMicroseconds(LATCH_TIME);
  digitalWrite(latch, LOW);
  button.a = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read B button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.b = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read select button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.select = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read the start button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.start = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read the up button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.up = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read the down button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.down = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read the left button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.left = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Read the right button:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  button.right = (digitalRead(data) == LOW) ? 1 : 0;
  delayMicroseconds(CLOCK_TIME);

  // Purge:
  digitalWrite(clock, HIGH);
  delayMicroseconds(CLOCK_TIME);
  digitalWrite(clock, LOW);
  delayMicroseconds(CLOCK_TIME);

}

// jl
