#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zmk/event_manager.h>
#include <zmk/events/hid_indicators_changed.h>
#include <zmk/hid_indicators.h>
#include <zmk/rgb_underglow.h>
#include <zmk/caps_word.h>

#define COLOR_OFF   {0,0,0}
#define COLOR_ON    {0, 0, 100}

static void set_capslock_led(bool caps_on) {
    caps_on ? (zmk_caps_word_state = true): (zmk_caps_word_state = false);
}

static int capslock_listener_cb(const zmk_event_t *eh) {
    zmk_hid_indicators_t indicators = zmk_hid_indicators_get_current_profile();
    bool caps_on = indicators & HID_USAGE_LED_CAPS_LOCK;
    set_capslock_led(caps_on);
    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(capslock_listener, capslock_listener_cb);
ZMK_SUBSCRIPTION(capslock_listener, zmk_hid_indicators_changed);

static int capslock_init(const struct device *dev) {
    ARG_UNUSED(dev);
    set_capslock_led(false);
    return 0;
}

SYS_INIT(capslock_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
