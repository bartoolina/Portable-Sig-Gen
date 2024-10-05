#include "main.h"
#include "hw_button.h"

static void buttonIdleRoutine(ButtonKey_t *key);
static void buttonDebounceRoutine(ButtonKey_t *key);
static void buttonPressedRoutine(ButtonKey_t *key);
static void buttonLongPressedRoutine(ButtonKey_t *key);

typedef void (*ButtonRoutine_t)(ButtonKey_t *);

ButtonRoutine_t button_routine[MAX_STATE] = {
    buttonIdleRoutine,
    buttonDebounceRoutine,
    buttonPressedRoutine,
    buttonLongPressedRoutine,
    buttonLongPressedRoutine,
};

void buttonHandler(ButtonKey_t *key)
{
    button_routine[key->state](key);
}

static void buttonIdleRoutine(ButtonKey_t *key)
{
    if (key->pushed_state == HAL_GPIO_ReadPin(key->gpio_port, key->gpio_pin))
    {
        key->state = DEBOUNCE;
        key->last_tick = HAL_GetTick();
    }
}

static void buttonDebounceRoutine(ButtonKey_t *key)
{
    if (HAL_GetTick() - key->last_tick < key->timer_debounce)
    {
        return;
    }

    if (key->pushed_state != HAL_GPIO_ReadPin(key->gpio_port, key->gpio_pin))
    {
        key->state = IDLE;
        return;
    }

    key->state = PRESSED;
    key->last_tick = HAL_GetTick();
}

static void buttonPressedRoutine(ButtonKey_t *key)
{
    if (key->pushed_state != HAL_GPIO_ReadPin(key->gpio_port, key->gpio_pin))
    {
        key->state = IDLE;
        if (key->buttonPressed)
        {
            key->buttonPressed(key);
        }
        return;
    }

    if (HAL_GetTick() - key->last_tick < key->timer_long_pressed)
    {
        return;
    }

    key->state = LONGPRESSED;
    key->last_tick = HAL_GetTick();
    if (key->buttonLongPressed)
    {
        key->buttonLongPressed(key);
    }
}
static void buttonLongPressedRoutine(ButtonKey_t *key)
{
    if (key->pushed_state != HAL_GPIO_ReadPin(key->gpio_port, key->gpio_pin))
    {
        key->state = IDLE;
        if (key->buttonLongReleased)
        {
            key->buttonLongReleased(key);
        }
        return;
    }

    if (HAL_GetTick() - key->last_tick < key->timer_repeat_delay)
    {
        return;
    }

    key->state = REPEAT;
    key->last_tick = HAL_GetTick();
    if (key->buttonLongRepeat)
    {
        key->buttonLongRepeat(key);
    }
}