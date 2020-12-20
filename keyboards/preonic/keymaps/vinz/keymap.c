/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

enum unicode_names {
    EA1,
    EA1M,
    EA2,
    EA2M,
    AA1,
    AA1M,
    EA3,
    EA3M,
    CA1,
    CA1M,
    OA1,
    OA1M,
    AA2,
    AA2M,
    IA1,
    IA1M,
    UA1,
    UA1M,
    UA2,
    UA2M,
    IA2,
    IA2M,
    UA3,
    UA3M,
    EA4,
    EA4M,
    OA2,
    OA2M,
    EURO
};

const uint32_t PROGMEM unicode_map[] = {
    [EA1]  = 0x00E9,    // é
    [EA1M] = 0x00C9,    // É
    [EA2]  = 0x00E8,    // è
    [EA2M] = 0x00C8,    // È
    [AA1]  = 0x00E0,    // à
    [AA1M] = 0x00C0,    // À
    [EA3]  = 0x00EA,    // ê
    [EA3M] = 0x00CA,    // Ê
    [CA1]  = 0x00E7,    // ç
    [CA1M] = 0x00C7,    // Ç
    [OA1]  = 0x00F4,    // ô
    [OA1M] = 0x00D4,    // Ô
    [AA2]  = 0x00E2,    // â
    [AA2M] = 0x00C2,    // Â
    [IA1]  = 0x00EE,    // î
    [IA1M] = 0x00CE,    // Î
    [UA1]  = 0x00FB,    // û
    [UA1M] = 0x00DB,    // Û
    [UA2]  = 0x00F9,    // ù
    [UA2M] = 0x00D9,    // Ù
    [IA2]  = 0x00EF,    // ï
    [IA2M] = 0x00CF,    //
    [UA3]  = 0x00FC,    // ü
    [UA3M] = 0x00DC,    // 
    [EA4]  = 0x00EB,    // ë
    [EA4M] = 0x00CB,    // Ë
    [OA2]  = 0x0153,    // œ
    [OA2M] = 0x0152,    // Œ
    [EURO] = 0x20AC,    // €
};

#define FR_EA1 XP(EA1, EA1M)
#define FR_EA2 XP(EA2, EA2M)
#define FR_AA1 XP(AA1, AA1M)
#define FR_EA3 XP(EA3, EA3M)
#define FR_CA1 XP(CA1, CA1M)
#define FR_OA1 XP(OA1, OA1M)
#define FR_AA2 XP(AA2, AA2M)
#define FR_IA1 XP(IA1, IA1M)
#define FR_UA1 XP(UA1, UA1M)
#define FR_UA2 XP(UA2, UA2M)
#define FR_IA2 XP(IA2, IA2M)
#define FR_UA3 XP(UA3, UA3M)
#define FR_EA4 XP(EA4, EA4M)
#define FR_OA2 XP(OA2, OA2M)
#define EURO   X(EURO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | PgUp | PgDn | Alt  |Space |Lower |Raise |Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_PGUP, KC_PGDN, KC_LALT, KC_SPC,  LOWER,   RAISE,   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Mute |  F1  |   â  |   ê  |   €  |  F5  |   ü  |   ù  |   ï  |   œ  |      |PrtScr|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   é  |      |   {  |   }  |   û  |   î  |   ô  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LGUI |   à  |      |   è  |   (  |   [  |   ]  |   )  |   ~  |   +  |   |  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |      |      |   `  |   =  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home | End  |      |      |      |      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_MUTE, KC_F1,   FR_AA2,  FR_EA3,  EURO,    KC_F5,   FR_UA3,  FR_UA2,  FR_IA2,  FR_OA2,  _______, KC_PSCR,
  _______, _______, _______, FR_EA1,  _______, KC_LCBR, KC_RCBR, FR_UA1,  FR_IA1,  FR_OA1,  _______, KC_DEL,
  KC_LGUI, FR_AA1,  _______, FR_EA2,  KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_TILD, KC_PLUS, KC_PIPE, _______,
  _______, _______, _______, FR_CA1,  _______, _______, _______, _______, KC_GRV,  KC_EQL,  KC_BSLS, _______,
  _______, KC_HOME, KC_END,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RGUI |      |      |      |      |      |      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home | End  |      |      |      |      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  KC_RGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_DQUO,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
  _______, KC_HOME, KC_END,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |UC_WIN|      |      |      |      | Mod+ | Hue+ | Bri+ | Sat+ |BLtog |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CapsLk|      |UC_MAC|      |Insert|      |      | Mod- | Hue- | Bri- | Sat- |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |UC_LNX|      |      |      |      |Static|      |      |      |RGBtog|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, RESET,   UC_M_WC, _______, _______, _______, _______, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, BL_TOGG,
  KC_CAPS, _______, UC_M_MA, _______, KC_INS,  _______, _______, RGB_RMOD,RGB_HUD, RGB_VAD, RGB_SAD, _______,
  _______, _______, UC_M_LN, _______, _______, _______, _______, RGB_M_P, _______, _______, _______, RGB_TOG,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


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
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_VOLD);
      unregister_code(KC_VOLD);
    } else {
      register_code(KC_VOLU);
      unregister_code(KC_VOLU);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
