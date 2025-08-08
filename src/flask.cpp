#include <Arduino.h>
#include <LEDController.h>


/* LED initialization */
LEDController red(9),
              green(6),
              blue(5);


/* Mode specific configuration variables */
LEDController *main_led      = NULL,
              *secondary_led = NULL;

uint8_t       main_led_intensity_max,
              main_led_intensity_min,
              secondary_led_intensity_max,
              secondary_led_intensity_min;

uint16_t      main_led_duration_min,
              main_led_duration_max,
              secondary_led_duration_min,
              secondary_led_duration_max;


/* State variables */
uint8_t       main_led_intensity,
              secondary_led_intensity;


/*
 * Initialize configuration variables
 * according to mode
 */
void initMode(uint8_t mode) {
  switch(mode) {

    /* Estus Flask */
    default:
      main_led                    = &red;
      secondary_led               = &green;
      main_led_intensity_min      = 255;
      main_led_intensity_max      = 255;
      main_led_duration_min       = 2000;
      main_led_duration_max       = 2000;
      secondary_led_intensity_min = 0;
      secondary_led_intensity_max = 64;
      secondary_led_duration_min  = 100;
      secondary_led_duration_max  = 1000;
      break;

    /* Ashen Estus Flask */
    case 0:
      main_led                    = &blue;
      secondary_led               = &green;
      main_led_intensity_min      = 192;
      main_led_intensity_max      = 255;
      main_led_duration_min       = 1000;
      main_led_duration_max       = 5000;
      secondary_led_intensity_min = 0;
      secondary_led_intensity_max = 128;
      secondary_led_duration_min  = 250;
      secondary_led_duration_max  = 2000;
      break;

  }
}


/*
 * Boot sequence
 */
void setup () {

  /* Seed the RNG */
  randomSeed(analogRead(0));

  /* Get a random mode and initialize it */
  uint8_t mode = random(0, 4);
  initMode(mode);

}


/*
 * Main loop
 */
void loop() {

  /* Generate cycle specific values for intensity and duration */
  uint8_t main_led_intensity_new       = random(main_led_intensity_min, main_led_intensity_max+1);
  uint16_t main_led_duration_new       = random(main_led_duration_min, main_led_duration_max+1);
  uint8_t secondary_led_intensity_new  = random(secondary_led_intensity_min, secondary_led_intensity_max+1);
  uint16_t secondary_led_duration_new  = random(secondary_led_duration_min, secondary_led_duration_max+1);

  /* Change LED intensity accordingly */
  main_led->stepDim(main_led_duration_new, main_led_intensity, main_led_intensity_new);
  secondary_led->stepDim(secondary_led_duration_new, secondary_led_intensity, secondary_led_intensity_new);


  /* Store this cycle's intensity values in memory for next cycle's transition */
  main_led_intensity                   = main_led_intensity_new;
  secondary_led_intensity              = secondary_led_intensity_new;

}
