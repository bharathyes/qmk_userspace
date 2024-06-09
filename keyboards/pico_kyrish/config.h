// Copyright 2024 bharathyes (@bharathyes)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define GRAVE_ESC_GUI_OVERRIDE

// TAP HOLD
#define TAPPING_TERM 200
// #define TAPPING_TOGGLE 2  			// TT layer shift momentary OR toggle ON/OFF if tapped thrice
// #define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY


#define ONESHOT_TAP_TOGGLE 2 	/* tapping said times holds key until tapped once again */
#define ONESHOT_TIMEOUT 2500 	/* time (in ms) before the one shot key is released */


// CAPS WORD 
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 4000 
#define CAPS_WORD_INVERT_ON_SHIFT		// continue on shift key


#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 340
#define LEADER_NO_TIMEOUT
