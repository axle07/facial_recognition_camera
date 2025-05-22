#ifdef __cplusplus
extern "C" {
#endif

#include "camera_control.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // Added for snprintf
#include "esp_log.h"

camera_fb_t *camera_capture_frame() {
    return esp_camera_fb_get();
}

int camera_set_parameter(const char *name, int value) {
    sensor_t *s = esp_camera_sensor_get();
    if (!s || !name) return -1;
    if (strcmp(name, "framesize") == 0) {
        if (s->pixformat == PIXFORMAT_JPEG) return s->set_framesize(s, (framesize_t)value);
    } else if (strcmp(name, "quality") == 0) {
        return s->set_quality(s, value);
    } else if (strcmp(name, "contrast") == 0) {
        return s->set_contrast(s, value);
    } else if (strcmp(name, "brightness") == 0) {
        return s->set_brightness(s, value);
    } else if (strcmp(name, "saturation") == 0) {
        return s->set_saturation(s, value);
    } else if (strcmp(name, "gainceiling") == 0) {
        return s->set_gainceiling(s, (gainceiling_t)value);
    } else if (strcmp(name, "colorbar") == 0) {
        return s->set_colorbar(s, value);
    } else if (strcmp(name, "awb") == 0) {
        return s->set_whitebal(s, value);
    } else if (strcmp(name, "agc") == 0) {
        return s->set_gain_ctrl(s, value);
    } else if (strcmp(name, "aec") == 0) {
        return s->set_exposure_ctrl(s, value);
    } else if (strcmp(name, "hmirror") == 0) {
        return s->set_hmirror(s, value);
    } else if (strcmp(name, "vflip") == 0) {
        return s->set_vflip(s, value);
    } else if (strcmp(name, "awb_gain") == 0) {
        return s->set_awb_gain(s, value);
    } else if (strcmp(name, "agc_gain") == 0) {
        return s->set_agc_gain(s, value);
    } else if (strcmp(name, "aec_value") == 0) {
        return s->set_aec_value(s, value);
    } else if (strcmp(name, "aec2") == 0) {
        return s->set_aec2(s, value);
    } else if (strcmp(name, "dcw") == 0) {
        return s->set_dcw(s, value);
    } else if (strcmp(name, "bpc") == 0) {
        return s->set_bpc(s, value);
    } else if (strcmp(name, "wpc") == 0) {
        return s->set_wpc(s, value);
    } else if (strcmp(name, "raw_gma") == 0) {
        return s->set_raw_gma(s, value);
    } else if (strcmp(name, "lenc") == 0) {
        return s->set_lenc(s, value);
    } else if (strcmp(name, "special_effect") == 0) {
        return s->set_special_effect(s, value);
    } else if (strcmp(name, "wb_mode") == 0) {
        return s->set_wb_mode(s, value);
    } else if (strcmp(name, "ae_level") == 0) {
        return s->set_ae_level(s, value);
    }
    return -1;
}

char *camera_get_status_json() {
    sensor_t *s = esp_camera_sensor_get();
    if (!s) return NULL;
    char *json = (char *)malloc(1024);
    if (!json) return NULL;
    snprintf(json, 1024,
        "{"
        "\"framesize\":%u,"
        "\"quality\":%u,"
        "\"brightness\":%d,"
        "\"contrast\":%d,"
        "\"saturation\":%d,"
        "\"sharpness\":%d,"
        "\"special_effect\":%u,"
        "\"wb_mode\":%u,"
        "\"awb\":%u,"
        "\"awb_gain\":%u,"
        "\"aec\":%u,"
        "\"aec2\":%u,"
        "\"ae_level\":%d,"
        "\"aec_value\":%u,"
        "\"agc\":%u,"
        "\"agc_gain\":%u,"
        "\"gainceiling\":%u,"
        "\"bpc\":%u,"
        "\"wpc\":%u,"
        "\"raw_gma\":%u,"
        "\"lenc\":%u,"
        "\"hmirror\":%u,"
        "\"dcw\":%u,"
        "\"colorbar\":%u"
        "}",
        s->status.framesize,
        s->status.quality,
        s->status.brightness,
        s->status.contrast,
        s->status.saturation,
        s->status.sharpness,
        s->status.special_effect,
        s->status.wb_mode,
        s->status.awb,
        s->status.awb_gain,
        s->status.aec,
        s->status.aec2,
        s->status.ae_level,
        s->status.aec_value,
        s->status.agc,
        s->status.agc_gain,
        s->status.gainceiling,
        s->status.bpc,
        s->status.wpc,
        s->status.raw_gma,
        s->status.lenc,
        s->status.hmirror,
        s->status.dcw,
        s->status.colorbar
    );
    return json;
}

#ifdef __cplusplus
}
#endif
