#ifndef CAMERA_CONTROL_H
#define CAMERA_CONTROL_H

#include "esp_err.h"
#include "esp_camera.h"
#include "esp_http_server.h"

#ifdef __cplusplus
extern "C" {
#endif

// Capture a frame and return the frame buffer pointer (caller must return it)
camera_fb_t *camera_capture_frame();

// Set a camera parameter by name (e.g., framesize, quality, brightness, etc.)
int camera_set_parameter(const char *name, int value);

// Get camera status as a JSON string (caller must free)
char *camera_get_status_json();

#ifdef __cplusplus
}
#endif

#endif // CAMERA_CONTROL_H
