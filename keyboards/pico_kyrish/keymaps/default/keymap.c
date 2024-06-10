// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layer_number {
  _COLEMAK = 0,
  _MPV,
  _KEYPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};


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
#define mo_raise        MO(_RAISE)
#define mo_tg_raise     TT(_RAISE)
#define ctrl_esc        LCTL_T(KC_ESC) 
#define kp_tab          LT(_KEYPAD, KC_TAB)
#define kp_toggle       TG(_KEYPAD)
#define mpv_toggle      TG(_MPV)
#define lowers_bs       LT(_LOWER, KC_BSPC)
#define l_shft          OSM(MOD_LSFT)
#define ent_sft         LSFT_T(KC_ENT)

#define esc             KC_ESC
#define l_flower        LSFT(KC_LBRC)
#define r_flower        LSFT(KC_RBRC)

// qmk keycodes
#define tgl_boot        QK_BOOT     // put into bootloader mode for flashing
#define reset_kb        QK_RBT      // reset keeb. does NOT put in bootloader


// // Tap dance functionality

// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP
// } td_state_t;


// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_t;


// enum {
//     TAB_KP_LYR,
// }

// td_state_t cur_dance(tap_dance_state_t *state);

// void ql_finished(tap_dance_state_t *state, void *user_data);
// void ql_reset(tap_dance_state_t *state, void *user_data);

// tap_dance_action_t tap_dance_actions[] = {
//     [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
// }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // COLEMAK base layer
    [_COLEMAK] = LAYOUT_ortho_4x12(
        kp_tab,          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                          KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_QUOT,
        ctrl_esc,        LGUI_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LCTL_T(KC_T),   MEH_T(KC_G),                                                   HYPR_T(KC_M),   LCTL_T(KC_N),   LSFT_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),   KC_MINS,
        l_shft,          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,          ctrl_esc,   KC_DEL,   QK_LEAD,    KC_BSPC,      KC_K,           KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_EQL,
                                                                         LALT_T(KC_ENT), KC_LGUI,       lowers_bs,  KC_SPC,   ent_sft,    mo_tg_raise,  KC_LGUI,        KC_BSLS
    ),

    // Lower (Symbols & function keys)
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_CIRC,    KC_AMPR,         KC_ASTR,        KC_LPRN,         KC_RPRN,        KC_BSPC,                                                      KC_LBRC,     KC_F7,       KC_F8,        KC_F9,        KC_LPRN,        KC_RPRN,
        KC_GRV,     LGUI_T(KC_EXLM), LALT_T(KC_AT),  LSFT_T(KC_HASH), CTL_T(KC_DLR),  MEH_T(KC_PERC),                                               KC_RBRC,     KC_F4,       KC_F5,        KC_F6,        l_flower,       XXXXXXX,
        KC_BTN1,    KC_MS_L,         KC_MS_D,        KC_MS_U,         KC_MS_R,        KC_BTN2,        _______,     KC_BSLS,   KC_TILD,   KC_PIPE,   KC_SLSH,     KC_F1,       KC_F2,        KC_F3,        r_flower,       XXXXXXX,
                                                                      _______,        _______,        _______,     _______,   _______,   _______,   _______,     _______
    ),

    // Raise (nav & related)
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_BTN1,     KC_MS_L,        KC_MS_D,        KC_MS_U,       KC_MS_R,        KC_BTN2,                                                      KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_MS_WH_UP,    KC_BTN1,
        _______,     KC_LGUI,        KC_LALT,        KC_LSFT,       KC_LCTL,        KC_FIND,                                                      KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_DOWN,  KC_PSCR,
        _______,     KC_UNDO,        KC_CUT,         KC_COPY,       XXXXXXX,        KC_PASTE,      _______,    _______,  _______,    _______,     XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                    _______,        _______,       _______,    _______,  _______,    _______,     _______,        _______
    ),

    // Adjust 
    [_ADJUST] = LAYOUT_ortho_4x12(
        _______,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,                                                      XXXXXXX,        KC_F10,         KC_F11,         KC_F12,         XXXXXXX,        XXXXXXX,
        _______,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,                                                      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        _______,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,     _______,    _______,  _______,    _______,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                    _______,        _______,     _______,    _______,  _______,    _______,       _______,        _______
    ),

    // keypad with media control 
    [_KEYPAD] = LAYOUT_ortho_4x12(
        _______,    XXXXXXX,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_VOLU,                                                      XXXXXXX,        KC_7,           KC_8,           KC_9,           KC_PAST,        KC_PSLS,
        _______,    XXXXXXX,        XXXXXXX,        mpv_toggle,     kp_toggle,      KC_VOLD,                                                      XXXXXXX,        KC_4,           KC_5,           KC_6,           KC_PPLS,        KC_PMNS,
        reset_kb,   tgl_boot,       XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MUTE,       _______,    _______,  _______,    _______,     KC_0,           KC_1,           KC_2,           KC_3,           KC_PDOT,        KC_PENT,
                                                                    LALT_T(KC_ENT), KC_LGUI,       lowers_bs,  KC_SPC,   ent_sft,    mo_tg_raise, KC_LGUI,        KC_BSLS
    ),

    // mpv movies
    [_MPV] = LAYOUT_ortho_4x12(
        kp_tab,     KC_Q,           KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_VOLU,                                                            esc,               KC_KP_7,           KC_KP_8,           KC_KP_9,           KC_BSPC,        XXXXXXX,
        _______,    XXXXXXX,        XXXXXXX,        mpv_toggle,     kp_toggle,      KC_VOLD,                                                            KC_Q,              KC_KP_4,           KC_KP_5,           KC_KP_6,           KC_PGUP,        XXXXXXX,
        reset_kb,   tgl_boot,       XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MUTE,       _______,    _______,  RCTL(KC_DEL),    KC_DEL,       KC_KP_0,           KC_KP_1,           KC_KP_2,           KC_KP_3,           KC_PGDN,        XXXXXXX,
                                                                    LALT_T(KC_ENT), KC_LGUI,       lowers_bs,  KC_SPC,   _______,         _______,      RSFT(KC_ENT),      XXXXXXX
    )
};


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


// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (!state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) return TD_DOUBLE_TAP;
//     else return TO_UNKNOWN;
// }

// static td_tap_t ql_tap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };

// void ql_finished(tap_dance_state_t *state, void *user_data) {
//     ql_tap_state.state = cur_dance(state);
//     switch (ql_tap_state.state) {
//         case TD_SINGLE_TAP:
//             tap_code(KC_TAB);
//             break;
//         case TD_SINGLE_HOLD:
//             layer_on(_KEYPAD);
//             break;
//         case TD_DOUBLE_TAP:
//             if (layer_state_is(_KEYPAD)) {
//                 layer_off(_KEYPAD);
//             } else {
//                 layer_on(_KEYPAD);
//             }
//             break;
//         default:
//             break;
//     }
// }
