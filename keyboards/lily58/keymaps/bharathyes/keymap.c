#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _KEYPAD,
};


/*
 * TODO: explore on QMK level "VIM Motions
 *  eg., 20Down should auto emit down 20 times, etc. 
 */  


/* LAYER SWITCHING 
 *  
 * DF(layer)       Set the base (default) layer
 * MO(layer)       Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)
 * OSL(layer)      Momentarily activates layer until a key is pressed. See One Shot Keys for details.
 * LM(layer, mod)  Momentarily turn on layer (like MO) with mod active as well.
 * LT(layer, kc)   Turn on layer when held, kc when tapped
 * TG(layer)       Toggle layer on or off
 * TO(layer)       Turns on layer and turns off all other layers, except the default layer
 * TT(layer)       Normally acts like MO unless it's tapped multiple times, which toggles layer on
 * 
 * ref: https://docusaurus.qmk.fm/feature_layers#switching-and-toggling-layers
 */


// custom defined key codes
#define mo_tg_raise     TT(_RAISE)
#define ctrl_esc        LCTL_T(KC_ESC)
#define kp_tab          LT(_KEYPAD, KC_TAB)
#define lowers_bs       LT(_LOWER, KC_BSPC)
#define l_shft          OSM(MOD_LSFT)
#define ent_sft         LSFT_T(KC_ENT)

#define esc             KC_ESC
#define l_flower        LSFT(KC_LBRC)
#define r_flower        LSFT(KC_RBRC)

// qmk keycodes
#define tgl_boot        QK_BOOT     // put into bootloader mode for flashing
#define reset_kb        QK_RBT      // reset keeb. does NOT put in bootloader
#define eeprom_clear    EE_CLR
#define qmk_make        QK_MAKE

#define pause           KC_PAUSE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* COLEMAK-DH
* ,-------------------------------------------.                    ,-----------------------------------------.
* | ESC    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSP  |
* |-------------------------------------------|                    |-----------------------------------------|
* | kp_tab |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  '   |
* |-------------------------------------------|                    |-----------------------------------------|
* |ctrl_esc|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  -   |
* |-------------------------------------------|Leader |    |  DEL  |-----------------------------------------|
* |LShift  |   Z  |  X   |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  =   |
* `-----------------------------------------/        /      \      \-----------------------------------------'
*                   | LAlt  | LGUI |LOWER | /Space  /        \(Enter) \  |RAISE |      |      |
*                   |(Enter)|      |(BS)  |        /          \ Shift  \ |      |      |      |
*                   `-----------------------------'            '------------------------------'
*/


[_COLEMAK] = LAYOUT(
  esc,          KC_1,   KC_2,   KC_3,    KC_4,     KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  kp_tab,       KC_Q,   KC_W,   KC_F,    KC_P,     KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  ctrl_esc,     LGUI_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LCTL_T(KC_T),   MEH_T(KC_G),  
                HYPR_T(KC_M),   LCTL_T(KC_N),   LSFT_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O), KC_MINS,
  l_shft,       KC_Z,   KC_X,   KC_C,    KC_D,     KC_V,   QK_LEAD,    KC_DEL,     KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
        LALT_T(KC_ENT), KC_LGUI,    lowers_bs,     KC_SPC,             ent_sft,     mo_tg_raise,     XXXXXXX,    XXXXXXX

),


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |-----------------------------------------|                    |-----------------------------------------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |-----------------------------------------|                    |-----------------------------------------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |-----------------------------------------|   [   |    |    ]  |-----------------------------------------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),*/


 /* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RST  | BOOT |      |PAUSE |      | DEL  |                    |   \  | F10  | F11  | F12  |   (  |  BSP |  
 * |-----------------------------------------|                    |-----------------------------------------|
 * |   ^  |   &  |   *  |   (  |   )  |  BS  |                    |   [  |  F7  |  F8  |  F9  |   )  |      |
 * |-----------------------------------------|                    |-----------------------------------------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ]  |  F4  |  F5  |  F6  |   {  |      |
 * |-----------------------------------------|   ~   |    |   |   |-----------------------------------------|
 * | MB_1 | MB_L | MB_D | MB_U | MB_R | MB_2 |-------|    |-------|   /  |  F1  |  F2  |  F3  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt  | LGUI |LOWER | /Space  /        \(Enter) \  |RAISE |      |      |
 *                   |(Enter)|      |(BS)  |        /          \ Shift  \ |      |      |      |
 *                   `-----------------------------'            '------------------------------'
 */

[_LOWER] = LAYOUT(
    reset_kb,   tgl_boot,   XXXXXXX,    pause,      XXXXXXX,    KC_DEL,                     KC_BSLS,    KC_F10,     KC_F11,     KC_F12, KC_LPRN,    KC_BSPC,
    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_BSPC,                    KC_LBRC,    KC_F7,      KC_F8,      KC_F9,  KC_RPRN,    XXXXXXX,
    KC_GRV,     LGUI_T(KC_EXLM),    LALT_T(KC_AT),  LSFT_T(KC_HASH),    CTL_T(KC_DLR),  MEH_T(KC_PERC),
                                                                                            KC_RBRC,    KC_F4,      KC_F5,      KC_F6,  l_flower,   XXXXXXX,
    KC_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_BTN2, KC_TILD, KC_PIPE,  KC_SLSH,    KC_F1,      KC_F2,      KC_F3,  r_flower,   XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),


/* RAISE
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |REC_M1 |REC_M2|      | MB_U |      |REC_STP|                   |      |      |      |      |      |      |
 * |------------------------------------------|                    |-----------------------------------------|
 * |       | MB_1 | MB_L | MB_D | MB_R |      |                    | PGUP | HOME |  Up  |  END | SC_U | MB_1 |
 * |------------------------------------------|                    |-----------------------------------------|
 * |MACRO_1| GUI  | ALT  | SHFT | CTRL | FIND |-------.    ,-------| PGDN | Left | Down |Right | SCR_D| PSCR |
 * |------------------------------------------|       |    |       |-----------------------------------------|
 * |MACRO_2| UNDO | CUT  | COPY |      |PASTE |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt  | LGUI |LOWER | /Space  /        \(Enter) \  |RAISE |      |      |
 *                   |(Enter)|      |(BS)  |        /          \ Shift  \ |      |      |      |
 *                   `-----------------------------'            '------------------------------'
 */

[_RAISE] = LAYOUT(
  DM_REC1, DM_REC2, XXXXXXX, KC_MS_U, XXXXXXX, DM_RSTP,                     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,
  XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                     KC_PGUP, KC_HOME, KC_UP,    KC_END,     KC_MS_WH_UP,    KC_BTN1,
  DM_PLY1, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_FIND,                     KC_PGDN, KC_LEFT, KC_DOWN,  KC_RIGHT,   KC_MS_WH_DOWN,  KC_PSCR,
  DM_PLY2, KC_UNDO, KC_CUT,  KC_COPY, XXXXXXX, KC_PASTE, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),


/* ADJUST
 * ,-----------------------------------------.                        ,-----------------------------------------.
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |-----------------------------------------|                        |-----------------------------------------|
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |-----------------------------------------|                        |-----------------------------------------|
 * |      |      |      |      |      |      |--------.      ,--------|      |      |      |      |      |      |
 * |-----------------------------------------|        |      |        |-----------------------------------------|
 * |      |      |      |      |      |      |--------|      |--------|      |      |      |      |      |      |
 * `-----------------------------------------/        /      \        \-----------------------------------------'
 *                   | LAlt  | LGUI |LOWER | /Space  /        \(Enter) \  |RAISE |      |      |
 *                   |(Enter)|      |(BS)  |        /          \ Shift  \ |      |      |      |
 *                   `-----------------------------'            '------------------------------'
 */

  [_ADJUST] = LAYOUT(
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),
  /* KEYPAD
 * ,-----------------------------------------.                      ,-----------------------------------------.
 * |      |      |      |      |      | MUTE |                      |      |      |      |  /   |      | BSP  |
 * |-----------------------------------------|                      |-----------------------------------------|
 * |      |      | Prev | Play | Next | V_UP |                      |      |   7  |   8  |   9  |   *  |      |
 * |-----------------------------------------|                      |-----------------------------------------|
 * |      |      |      |      |      | V_DN |--------.     ,-------|      |   4  |   5  |   6  |   -  |      |
 * |-----------------------------------------|        |     |       |-----------------------------------------|
 * |      |      |      |      |      |      |--------|     |-------|   0  |   1  |   2  |   3  |   +  |      |
 * `-----------------------------------------/        /      \      \-----------------------------------------'
 *                   | LAlt  | LGUI |LOWER | /Space  /        \(Enter) \  |RAISE |      |      |
 *                   |(Enter)|      |(BS)  |        /          \ Shift  \ |      |      |      |
 *                   `-----------------------------'            '------------------------------'
 */

  [_KEYPAD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, XXXXXXX, KC_BSPC,
  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PAST, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                   XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PMNS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_PPLS, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};



/*

TODO:
Features to explore


// for thumb cluster
MT(MOD_LSFT, KC_BSPC) for backspace on tap and shift on hold;
LT(_FUN, KC_ENT) for enter on tap and switching to the _FUN layer on hold;
LT(_SYB, KC_SPC) for space on tap and switching to the _SYB layer on hold.


// TAP DANCE GUIDE
https://docs.qmk.fm/#/feature_tap_dance
https://thomasbaart.nl/2018/12/13/qmk-basics-tap-dance/


// RESET and BOOTLOADER
https://docs.qmk.fm/#/ref_functions?id=resetting-the-keyboard


// LEADER key
https://docs.qmk.fm/#/feature_leader_key
#define ENABLE_COMPILE_KEYCODE


// AUDIO
https://docs.qmk.fm/#/feature_audio

*/


//**************** UNICODE *********************//


#ifdef UNICODE_COMMON

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    THUMBUP
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [THUMBUP]   =   0x1F44D, // 
};

#endif


//**************** LEADER *********************//

#ifdef LEADER_ENABLE

void leader_start_user(void) {
    // Do something when the leader key is pressed
}


// TODO: correct intelliJ action keymaps
void leader_end_user(void) {
    // ESC
    if (leader_sequence_one_key(KC_ESC))
        tap_code16(KC_PAUSE);  
    // O K
    else if (leader_sequence_two_keys(KC_O, KC_K))
        SEND_STRING("Okay."); 
    // P U
    else if (leader_sequence_two_keys(KC_P, KC_U))
        SEND_STRING("bharathyes");
    // P G
    else if (leader_sequence_two_keys(KC_P, KC_G))
        SEND_STRING("bharathyes.in@gmail.com");
    // P 
    else if (leader_sequence_two_keys(KC_P, KC_O))
        SEND_STRING("bharathyes@outlook.com");
    // W E
    else if (leader_sequence_two_keys(KC_W, KC_E))
        SEND_STRING("bharathyes@techconative.com");
    // D U
    else if (leader_sequence_two_keys(KC_D, KC_U))
        SEND_STRING("bsrinivasan");
    // D E
    else if (leader_sequence_two_keys(KC_D, KC_E))
        SEND_STRING("bsrinivasan@dalet.com");
    // D D G
    else if (leader_sequence_three_keys(KC_D, KC_D, KC_G))
        SEND_STRING("https://start.duckduckgo.com\n");
    // G M (open Git IntelliJ)
    else if (leader_sequence_two_keys(KC_G, KC_M))
        tap_code16(LCTL(LSFT(LALT(KC_GRAVE))));
    // I D  (run menu IntelliJ)
    else if (leader_sequence_two_keys(KC_I, KC_D))
        SEND_STRING(SS_LALT(SS_LSFT("d")));
    // I R (start in debug)
    else if (leader_sequence_two_keys(KC_I, KC_R))
        SEND_STRING(SS_LALT(SS_LSFT("x")));
    // I C  (run select menu)
    else if (leader_sequence_two_keys(KC_I, KC_C))
        tap_code16(LALT(LSFT(KC_F10)));
    // I X  (debug select menu)
    else if (leader_sequence_two_keys(KC_I, KC_X))
        tap_code16(LALT(LSFT(KC_F9)));
    // I S (stop application)
    else if (leader_sequence_two_keys(KC_I, KC_S))
        tap_code16(LCTL(KC_F2));
    // I D M  (mute debug points)
    else if (leader_sequence_three_keys(KC_I, KC_D, KC_M))
        tap_code16(LCTL(LALT(LSFT(KC_F12))));
    // C H S  (hot swap code)
    else if (leader_sequence_three_keys(KC_C, KC_H, KC_S))
        tap_code16(LCTL(LSFT(KC_F9)));
    // P I
    else if (leader_sequence_two_keys(KC_P, KC_I))
        SEND_STRING("qw@4134");
    // F I
    else if (leader_sequence_two_keys(KC_F, KC_I))
        SEND_STRING("qWa@413A");
}


#endif /* LEADER */

// Lower + Raise gives Adjust layer
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE


/*  Send 'delete' when 'Shift+Backspace' is pressed.
*    https://docs.qmk.fm/#/feature_key_overrides?id=simple-example
*
* const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
* This globally defines all key overrides to be used
* const key_override_t **key_overrides = (const key_override_t *[]){
*     &delete_key_override,
*     NULL* Null terminate the array of overrides!
* };
*/



// PERMISSIVE HOLD MODE
//  ref: https://docs.qmk.fm/#/tap_hold?id=permissive-hold

// provide granular decision hold vs tap per key
// TRUE - prefer HOLD ; FALSE - TAP (default)
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LT(_KEYPAD, KC_TAB):
        case LT(_LOWER, KC_BSPC):
        case LSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}

// extend the tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return TAPPING_TERM + 250;
        case mo_tg_raise:
            return 70;
        default:
            return TAPPING_TERM;
    }
}




/*
 * CUSTOM MACROS method
 * ---------------------
 * 1. Interrupt or extend key events. 
 * 2. Add custom key codes.
 *  REF : https://docs.qmk.fm/#/custom_quantum_functions?id=example-process_record_user-implementation
 * 
 *  ALSO : dynamic macros recording without reset key. 
 *   Press the corresponding macro key to stop recording
 *  ref: https://docusaurus.qmk.fm/feature_dynamic_macros#dynamic_macro_user_call
 */


// SAFE_RANGE assigns a unique number everytime
/* enum my_keycodes {
  FOO = SAFE_RANGE, 
  BAR
};
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    // stop dynamic macro recording without reset key.
    // WIP : keymap.c:424:10: error: implicit declaration of function 'process_record_dynamic_macro'; did you mean 'process_dynamic_macro'?
    // uint16_t macro_kc = (keycode == lowers_bs ? DM_RSTP : keycode);
    // if (!process_record_dynamic_macro(macro_kc, record)) {
    //     return false;
    // }


  // if (record->event.pressed) {
  //   #ifdef OLED_ENABLE
  //   set_keylog(keycode, record);
  //   #endif
  //   // set_timelog();
  // }

    // Mod Tap intercepted. Modded tap behaviour limitation override.
    //  ref: https://docusaurus.qmk.fm/mod_tap#intercepting-mod-taps
  switch (keycode) {
    case LGUI_T(KC_EXLM):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_EXLM); 
            return false;        
        }
        break;
    case LALT_T(KC_AT):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_AT); 
            return false;        
        }
        break;
    case LSFT_T(KC_HASH):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_HASH); 
            return false;        
        }
        break;
    case CTL_T(KC_DLR):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_DLR); 
            return false;        
        }
        break;
    case MEH_T(KC_PERC):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_PERC); 
            return false;        
        }
        break;
    // case FOO:
    //   if (record->event.pressed) {
    //     // Do something when pressed
    //   } else {
    //     // Do something else when release
    //   }
    //   return false; // Skip all further processing of this key
    // case KC_ENTER:
    //   // Play a tone when enter is pressed
    //   if (record->event.pressed) {
    //     PLAY_SONG(tone_qwerty);
    //   }
    //   return true; // Let QMK send the enter press/release events
  }
  return true; // Process all other keycodes normally
}
