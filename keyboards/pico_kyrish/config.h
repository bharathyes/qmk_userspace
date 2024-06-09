// Copyright 2024 bharathyes (@bharathyes)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define GRAVE_ESC_GUI_OVERRIDE

// TAP HOLD
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2  			// TT layer shift momentary OR toggle ON/OFF if tapped thrice
#define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD_PER_KEY


#define ONESHOT_TAP_TOGGLE 2 	/* tapping said times holds key until tapped once again */
#define ONESHOT_TIMEOUT 2500 	/* time (in ms) before the one shot key is released */

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 340
#define LEADER_NO_TIMEOUT
