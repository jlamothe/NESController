// -*- c++-mode -*-

// NES Controller Library

// Copyright (C) 2011 Jonathan Lamothe <jonathan@jlamothe.net>

// This program is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see: http://www.gnu.org/licenses/

// * * *

// This program scans the buttons on a NES controller and sets outputs
// HIGH or LOW based on the button states.

#include <NESController.h>

// Define pin numbers:
#define LATCH 2
#define CLOCK 3
#define DATA 4
#define UP 5
#define DOWN 6
#define LEFT 7
#define RIGHT 8
#define A 9
#define B 10
#define SELECT 11
#define START 12

NESController nesc(LATCH, CLOCK, DATA);

void setup()
{
  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(SELECT, OUTPUT);
  pinMode(START, OUTPUT);
  delay(1000);
}

void loop()
{
  nesc.scan();
  digitalWrite(UP, nesc.button.up ? HIGH : LOW);
  digitalWrite(DOWN, nesc.button.down ? HIGH : LOW);
  digitalWrite(LEFT, nesc.button.left ? HIGH : LOW);
  digitalWrite(RIGHT, nesc.button.right ? HIGH : LOW);
  digitalWrite(A, nesc.button.a ? HIGH : LOW);
  digitalWrite(B, nesc.button.b ? HIGH : LOW);
  digitalWrite(SELECT, nesc.button.select ? HIGH : LOW);
  digitalWrite(START, nesc.button.start ? HIGH : LOW);
}

// jl
