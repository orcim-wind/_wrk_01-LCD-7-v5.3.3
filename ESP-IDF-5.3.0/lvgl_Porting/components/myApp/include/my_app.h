#ifndef MY_APP_H
#define MY_APP_H

#include "lvgl/lvgl.h"  // Include LVGL per i widget

/**
 * @brief Inizializza e avvia la demo myApp con widget LVGL.
 * 
 * Questa funzione crea un layout semplice con button, label e slider.
 * Assumi che lvgl_init() e il display siano già configurati nel main.
 */
void my_app_demo_start(void);

#endif // MY_APP_H