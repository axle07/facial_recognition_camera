#ifndef GLOBALS_H
#define GLOBALS_H

#include <stddef.h>
#include "esp_http_server.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  size_t index;
  size_t count;
  int sum;
  int *values;
} ra_filter_t;

extern ra_filter_t ra_filter;
ra_filter_t *ra_filter_init(ra_filter_t *filter, size_t sample_size);

extern httpd_handle_t stream_httpd;
extern httpd_handle_t camera_httpd;

#ifdef __cplusplus
}
#endif

#endif // GLOBALS_H
