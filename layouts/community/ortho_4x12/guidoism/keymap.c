#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOVEMENT,
  _NUMPAD,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOVEMENT,
  NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_planck_mit(
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_COLN, KC_ENT,
LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
MOVEMENT, KC_NO, KC_LALT, KC_LGUI, LOWER, LSFT_T(KC_SPC), RAISE, KC_RGUI, KC_RALT, KC_SCLN, KC_NO),

  [_LOWER] = LAYOUT_planck_mit(
KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, KC_NO, KC_UNDO,
KC_TRNS, KC_NO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_DQUO, KC_QUOT, KC_PIPE,
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

  [_RAISE] = LAYOUT_planck_mit(
KC_GRV, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_TRNS,
KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_PMNS, KC_PEQL, KC_NO, KC_NO, KC_BSLS,
KC_TRNS, KC_LT, KC_GT, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_MOVEMENT] = LAYOUT_planck_mit(
RESET, DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_TRNS,
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_TRNS,
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_NUMPAD] = LAYOUT_planck_mit(
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_TRNS,
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PAST, KC_TRNS,
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PCMM, KC_P0, KC_PDOT, KC_PPLS, KC_TRNS)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
	update_tri_layer(_LOWER, _MOVEMENT, _NUMPAD);
      } else {
        layer_off(_LOWER);
	update_tri_layer(_LOWER, _MOVEMENT, _NUMPAD);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case MOVEMENT:
      if (record->event.pressed) {
        layer_on(_MOVEMENT);
	update_tri_layer(_LOWER, _MOVEMENT, _NUMPAD);
      } else {
        layer_off(_MOVEMENT);
	update_tri_layer(_LOWER, _MOVEMENT, _NUMPAD);
      }
      return false;
      break;
  }
  return true;
}
