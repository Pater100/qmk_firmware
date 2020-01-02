#include QMK_KEYBOARD_H

// Helpful defines
#define _______ KC_TRNS

enum custom_keycodes {
	KC_RND = SAFE_RANGE,
	KC_MIU,
	KC_PR,
};

enum unicode_symbol {
	DIAM, //Diameter teken
};

const uint32_t PROGMEM unicode_map[] = {
	[DIAM] = 0x00D8
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_ansi(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, MO(2)),
	[1] = LAYOUT_60_ansi(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO, KC_PGUP, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET),
	[2] = LAYOUT_60_ansi(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SYSTEM_SLEEP, KC_NO, KC_NO, KC_UP, KC_RND, X(DIAM), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PR, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS)
};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_WINC);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case KC_RND:
				SEND_STRING("Patrick@miuden.nl");
				layer_off(2);
			return false;break;
			case KC_MIU:
				SEND_STRING("Metaalindustrie Uden B.V.");
				layer_off(2);
			return false;break;
			case KC_PR:
				SEND_STRING("print()");
				layer_off(2);
			return false;break;
		}
	}
	return true;
};
