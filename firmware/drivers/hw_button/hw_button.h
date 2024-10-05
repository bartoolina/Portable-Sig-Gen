#pragma once

#define BTN_DEFAULT_DEBOUNCE_MS 20
#define BTN_DEFAULT_LONGPRESSED_MS 1000
#define BTN_DEFAULT_REPEAT_MS 200

// States for state machine
typedef enum
{
    IDLE = 0,
    DEBOUNCE,
    PRESSED,
    LONGPRESSED,
    REPEAT,
    MAX_STATE
} ButtonState_t;

// Struct for button
typedef struct ButtonKey_s ButtonKey_t;
typedef void (*btn_callback_t)(ButtonKey_t *key);

struct ButtonKey_s
{
    uint8_t id;          // Button name/number
    ButtonState_t state; // Button current state

    GPIO_TypeDef *gpio_port; // GPIO Port for a button
    uint16_t gpio_pin;       // GPIO Pin for a button
    GPIO_PinState pushed_state;

    uint32_t last_tick;          // Last remembered time before steps
    uint32_t timer_debounce;     // Fixed, settable time for debounce timer
    uint32_t timer_long_pressed; // Fixed, adjustable time for long press timer
    uint32_t timer_repeat_delay; // Fixed, adjustable interval time

    btn_callback_t buttonPressed;      // A callback for button pressed
    btn_callback_t buttonLongPressed;  // A callback for long pressed
    btn_callback_t buttonLongReleased; // A callback for button released
    btn_callback_t buttonLongRepeat;   // A callback for repeat
};

// Public functions

void buttonHandler(ButtonKey_t *key);
