/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// ways to set the master side 
#define MASTER_LEFT
// #define MASTER_RIGHT
// https://docusaurus.qmk.fm/feature_split_keyboard#handedness-by-eeprom
// #define EE_HANDS


#undef RGBLED_NUM

#define GRAVE_ESC_GUI_OVERRIDE

// enables QK_MAKE
#define ENABLE_COMPILE_KEYCODE

// TAP HOLD
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2  			// TT layer shift momentary OR toggle ON/OFF if tapped thrice
#define QUICK_TAP_TERM 0
// #define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// #define HOLD_ON_OTHER_KEY_PRESS  
//  conflicts with permissive hold

// exploring 
// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD 


#define ONESHOT_TAP_TOGGLE 2 	/* tapping said times holds key until tapped once again */
#define ONESHOT_TIMEOUT 2500 	/* time (in ms) before the one shot key is released */

/*
	Issues with MOD TAP
	Explore later
	https://docs.qmk.fm/#/feature_auto_shift?id=retro-shift
*/
#define AUTO_SHIFT_TIMEOUT 160
#define NO_AUTO_SHIFT_SPECIAL
#define RETRO_SHIFT	500		// to enable auto shift for tap mod keys too

// CAPS WORD 
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 4000 
#define CAPS_WORD_INVERT_ON_SHIFT		// continue on shift key


#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 340
#define LEADER_NO_TIMEOUT


// Dynamic Macro Recording
#define DYNAMIC_MACRO_USER_CALL		// stop recording without reset key
#define DYNAMIC_MACRO_NO_NESTING    // prevents recording recursive macros 
									//  PS: macro 1 in macro2 and vice versa is still possible



// #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
// #define UNICODE_KEY_LNX