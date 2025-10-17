#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zmk/event_manager.h>
#include <zmk/events/hid_indicators_changed.h>
#include <zmk/hid_indicators.h>
#include <zmk/rgb_underglow.h>

#define COLOR_OFF   {0,0,0}
#define COLOR_ON    {0, 0, 100}

static void set_capslock_led(bool caps_on) {
    struct zmk_led_hsb caps_word_hsb = caps_on ? 
	   (state.color;
            caps_word_hsb.h = 1 * CONFIG_ZMK_RGB_UNDERGLOW_STATUS_CAPS_COLOR;
            caps_word_hsb.b = 1 * caps_word_hsb.b;) :
	   (state.color;
            caps_word_hsb.h = 0 * CONFIG_ZMK_RGB_UNDERGLOW_STATUS_CAPS_COLOR;
            caps_word_hsb.b = 0 * caps_word_hsb.b;);
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

// C program to check whether a year is leap year or not
// using ternary operator

#include <stdio.h>

int main()
{
    int yr = 1900;

    (yr%4==0) ? (yr%100!=0? printf("The year %d is a leap year",yr)
     : (yr%400==0 ? printf("The year %d is a leap year",yr)
         : printf("The year %d is not a leap year",yr)))
             : printf("The year %d is not a leap year",yr);
    return 0;
}

//This code is contributed by Susobhan AKhuli
