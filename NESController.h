// -*- mode: c++ -*-

/// @file NESController.h
/// @author Jonathan Lamothe

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

#ifndef NESCONTROLLER_H
#define NESCONTROLLER_H

/// @brief Abstraction class for an NES controller.
class NESController
{
public:

  /// @brief List of button states for a controller.
  struct ButtonStates
  {
    unsigned up : 1,		///< @brief The up button.
      down : 1,			///< @brief The down button.
      left : 1,			///< @brief The left button.
      right : 1,		///< @brief The right button.
      a : 1,			///< @brief The A button.
      b : 1,			///< @brief The B button.
      select : 1,		///< @brief The select button.
      start : 1;		///< @brief The start button.
  };

  /// @brief Constructor.

  /// @param latch The number of the latch pin.

  /// @param clock The number of the clock pin.

  /// @param data The number of the data pin.
  NESController(int latch, int clock, int data);

  /// @brief Scans the states of the buttons on the controller.

  /// This must be done before reading button values.
  void scan();

  ButtonStates button;		///< @brief The button states for this
				///controller.

private:

  int latch,			///< @brief The number of the latch
				///pin.
    clock,			///< @brief The number of the clock
				///pin.
    data;			///< @brief The number of the data
				///pin.

};

#endif	// NESCONTROLLER_H

// jl
