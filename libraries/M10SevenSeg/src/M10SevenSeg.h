/*
###############################################################################
# Copyright (c) 2018, PulseRain Technology LLC 
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License (LGPL) as 
# published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
# or FITNESS FOR A PARTICULAR PURPOSE.  
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################
*/

#ifndef M10SEVENSEG_H
#define M10SEVENSEG_H

#include "Arduino.h"


typedef struct {
    void (*init) () __reentrant;
    void (*onOff)(uint8_t on_off_mask) __reentrant;
    void (*byteHex) (uint8_t num) __reentrant;
    void (*decimalPoint)(uint8_t mask) __reentrant;
} SEVEN_SEG_STRUCT;

extern const SEVEN_SEG_STRUCT SEVEN_SEG;

#endif
