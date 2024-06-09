// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layer_number {
  _COLEMAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _KEYPAD,
};

// custom defined key codes
#define mo_tg_raise     TT(_RAISE)
#define ctrl_esc        LCTL_T(KC_ESC) 
#define ctrl_bs         LCTL_T(KC_BKSP) 
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

    // COLEMAK base layer
    [_COLEMAK] = LAYOUT_ortho_4x12(
        KC_TAB,     KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                          KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_QUOT,
        ctrl_esc,   LGUI_T(KC_A),   LALT_T(KC_R),   LSFT_T(KC_S),   LCTL_T(KC_T),   MEH_T(KC_G),                                                   HYPR_T(KC_M),   LCTL_T(KC_N),   LSFT_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),   KC_MINS,
        l_shft,     KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,          esc,        KC_DEL,   QK_LEAD,    KC_BSPC,      KC_K,           KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_EQL,
                                                                    LALT_T(KC_ENT), KC_LGUI,       lowers_bs,  KC_SPC,   ent_sft,    mo_tg_raise,  KC_LGUI,        KC_PSLS
    ),

    // Lower (Symbols & function keys)
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_CIRC,    KC_AMPR,         KC_ASTR,        KC_LPRN,         KC_RPRN,        KC_BSPC,                                                      KC_LBRC,     KC_F7,       KC_F8,        KC_F9,        KC_LPRN,        KC_RPRN,
        KC_GRV,     LGUI_T(KC_EXLM), LALT_T(KC_AT),  LSFT_T(KC_HASH), CTL_T(KC_DLR),  MEH_T(KC_PERC),                                               KC_RBRC,     KC_F4,       KC_F5,        KC_F6,        l_flower,       XXXXXXX,
        KC_BTN1,    KC_MS_L,         KC_MS_D,        KC_MS_U,         KC_MS_R,        KC_BTN2,        XXXXXXX,     KC_BSLS,   KC_TILD,   KC_PIPE,   KC_SLSH,     KC_F1,       KC_F2,        KC_F3,        r_flower,       XXXXXXX,
                                                                      _______,        _______,        _______,     _______,   _______,   _______,   _______,     _______
    ),

    // Raise (nav & related)
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_BTN1,     KC_MS_L,        KC_MS_D,        KC_MS_U,       KC_MS_R,        KC_BTN2,                                                      KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_MS_WH_UP,    KC_BTN1,
        XXXXXXX,     KC_LGUI,        KC_LALT,        KC_LSFT,       KC_LCTL,        KC_FIND,                                                      KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_DOWN,  KC_PSCR,
        XXXXXXX,     KC_UNDO,        KC_CUT,         KC_COPY,       XXXXXXX,        KC_PASTE,      _______,    _______,  _______,    _______,     XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                    _______,        _______,       _______,    _______,  _______,    _______,     _______,        _______
    ),

    // Adjust 
    [_ADJUST] = LAYOUT_ortho_4x12(
        XXXXXXX,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,                                                      XXXXXXX,        KC_F10,         KC_F11,         KC_F12,        XXXXXXX,        XXXXXXX,
        XXXXXXX,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,                                                      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,     _______,    _______,  _______,    _______,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                    _______,        _______,     _______,    _______,  _______,    _______,       _______,        _______
    ),

    // Adjust 
    [_KEYPAD] = LAYOUT_ortho_4x12(
        XXXXXXX,     XXXXXXX,        KC_MPRV,        KC_MPLY,       KC_MNXT,        KC_VOLU,                                                      XXXXXXX,        KC_7,           KC_8,           KC_9,           KC_PAST,        XXXXXXX,
        XXXXXXX,     XXXXXXX,        XXXXXXX,        XXXXXXX,       XXXXXXX,        KC_VOLD,                                                      XXXXXXX,        KC_4,           KC_5,           KC_6,           KC_PMNS,        XXXXXXX,
        reset_kb,   tgl_boot,        XXXXXXX,        XXXXXXX,       XXXXXXX,        KC_MUTE,       _______,    _______,  _______,    _______,     KC_0,           KC_1,           KC_2,           KC_3,           KC_PPLS,        XXXXXXX,
                                                                    _______,        _______,       _______,    _______,  _______,    _______,     _______,        _______
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

