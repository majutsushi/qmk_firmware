#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NUMK 3 // number pad

enum custom_keycodes {
    EPRM = SAFE_RANGE,
    VRSN,
    SSPC,
    LSPO_C,  /* custom version of KC_LSPO */
    RSPC_C,  /* custom version of KC_RSPC */
    RCTL_Q,  /* Ctrl/' */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  L1  |           | NUMK |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | App  |           | App  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc/Ctl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '/Ctl |
 * |--------+------+------+------+------+------| Grv  |           | RGui |------+------+------+------+------+--------|
 * | Shift/(|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | Shift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Shift|  '"  |  L1  | [/Gui|Sp/Alt|                                       | Space| ]/Gui|  L1  |   ]  | Shift|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  | LGui |       | Alt  |  Ins   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |  L2  |Bckspc|------|       |------|  RAlt  |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,     KC_3,   KC_4,   KC_5,   TG(SYMB),
        KC_TAB,         KC_Q,         KC_W,     KC_E,   KC_R,   KC_T,   KC_APP,
        LCTL_T(KC_ESC), KC_A,         KC_S,     KC_D,   KC_F,   KC_G,
        LSPO_C,         KC_Z,         KC_X,     KC_C,   KC_V,   KC_B,   KC_GRV,
        KC_LSFT,        KC_QUOT,      MO(SYMB), GUI_T(KC_LBRC), ALT_T(KC_SPC),
                                               KC_DELT,  KC_LGUI,
                                                              KC_HOME,
                                               MO(MDIA),KC_BSPC,KC_END,
        // right hand
             TG(NUMK),    KC_6,   KC_7,   KC_8,          KC_9,    KC_0,             KC_MINS,
             KC_APP,      KC_Y,   KC_U,   KC_I,          KC_O,    KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,          KC_L,    KC_SCLN,          RCTL_Q,
             KC_RGUI,     KC_N,   KC_M,   KC_COMM,       KC_DOT,  KC_SLSH,          RSPC_C,
                                  SSPC,   GUI_T(KC_RBRC),MO(SYMB),KC_RBRC,          KC_RSFT,
             KC_LALT,        KC_INS,
             KC_PGUP,
             KC_PGDN, KC_RALT,KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |WheelU|      |           |      |      | LClk | MClk | RClk |      |   12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|WheelD|------|           |------| Left | Down |  Up  | Right|      |PrintScr|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |VolDn |VolUp |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |Brwser|      |       | Prev |      |      |
 *                                 |      |Back  |------|       |------| Mute | Play |
 *                                 |      |      |      |       | Next |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_WBAK, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
       KC_TRNS,  KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2,  KC_TRNS, KC_F12,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_PSCR,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_VOLD, KC_VOLU,
       KC_MPRV,
       KC_MNXT, KC_MUTE, KC_MPLY
),
/* Keymap 3: Numberic keypad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | NumL |   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMK
[NUMK] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                                                                    KC_TRNS,     KC_TRNS,
                                                                                 KC_TRNS,
                                                       KC_TRNS,     KC_TRNS,     KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,       KC_NUMLOCK,    KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,  KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_KP_7,       KC_KP_8,     KC_KP_9,        KC_KP_PLUS,   KC_TRNS,
                KC_TRNS,       KC_KP_4,       KC_KP_5,     KC_KP_6,        KC_KP_PLUS,   KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_KP_1,       KC_KP_2,     KC_KP_3,        KC_KP_ENTER,  KC_TRNS,
                               KC_KP_0,       KC_KP_0,     KC_KP_DOT,      KC_KP_ENTER,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS
),
};

static bool shift_interrupted[2] = {0, 0};
static uint16_t scs_timer[2] = {0, 0};
static bool ctrl_interrupted[2] = {0, 0};
static uint16_t ctrl_timer[2] = {0, 0};
static bool rctrl_active = false;
static bool lshift_rctrl_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t right_shift_mask;

    switch (keycode) {
        case SSPC:
            if (record->event.pressed) {
                right_shift_mask = get_mods() & MOD_BIT(KC_RSFT);
                if (!right_shift_mask)
                    register_code(KC_SPC);
            } else {
                if (right_shift_mask) {
                    register_mods(MOD_BIT(KC_LSFT));
                    register_code16(KC_RPRN);
                    unregister_code16(KC_RPRN);
                    unregister_mods(MOD_BIT(KC_LSFT));
                    register_code(KC_SPC);
                }
                unregister_code(KC_SPC);
            }
            return false;
        case LSPO_C:
            if (record->event.pressed) {
                shift_interrupted[0] = false;
                scs_timer[0] = timer_read();
                register_mods(MOD_BIT(KC_LSFT));
            } else {
                if (!shift_interrupted[0] && !(rctrl_active) && timer_elapsed(scs_timer[0]) < TAPPING_TERM) {
                    register_code(KC_9);
                    unregister_code(KC_9);
                }
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case RSPC_C:
            if (record->event.pressed) {
                shift_interrupted[1] = false;
                scs_timer[1] = timer_read();
                register_mods(MOD_BIT(KC_RSFT));
            } else {
                if (!shift_interrupted[1] && timer_elapsed(scs_timer[1]) < TAPPING_TERM) {
                    register_code(KC_0);
                    unregister_code(KC_0);
                }
                unregister_mods(MOD_BIT(KC_RSFT));
            }
            return false;
        case RCTL_Q:
            if (record->event.pressed) {
                ctrl_interrupted[1] = false;
                ctrl_timer[1] = timer_read();
                rctrl_active = true;
                lshift_rctrl_active = get_mods() & MOD_BIT(KC_LSFT);
            } else {
                rctrl_active = false;
                if (!ctrl_interrupted[1] && timer_elapsed(ctrl_timer[1]) < TAPPING_TERM) {
                    if (lshift_rctrl_active) {
                        register_code16(KC_DQUO);
                        unregister_code16(KC_DQUO);
                        lshift_rctrl_active = false;
                    } else {
                        register_code(KC_QUOT);
                        unregister_code(KC_QUOT);
                    }
                }
                unregister_mods(MOD_BIT(KC_RCTL));
            }
            return false;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
        default:
            shift_interrupted[0] = true;
            shift_interrupted[1] = true;
            ctrl_interrupted[0] = true;
            ctrl_interrupted[1] = true;
            break;
    }

    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // If numlock is not on, press the button to turn it on
    if (!(host_keyboard_leds() & (1 << USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if (rctrl_active) {
        if (timer_elapsed(ctrl_timer[1]) > TAPPING_TERM) {
            register_mods(MOD_BIT(KC_RCTL));
            rctrl_active = false;
        }
    }

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};

// Force num lock to always be on
/* void led_set_keymap(uint8_t usb_led) { */
/*     if (!(usb_led & (1 << USB_LED_NUM_LOCK))) { */
/*         register_code(KC_NUMLOCK); */
/*         unregister_code(KC_NUMLOCK); */
/*     } */
/* } */
