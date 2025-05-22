#include "globals.h"
#include <stdlib.h>
#include <string.h>

ra_filter_t ra_filter;

ra_filter_t *ra_filter_init(ra_filter_t *filter, size_t sample_size) {
  memset(filter, 0, sizeof(ra_filter_t));
  filter->values = (int *)malloc(sample_size * sizeof(int));
  if (!filter->values) {
    return NULL;
  }
  memset(filter->values, 0, sample_size * sizeof(int));
  filter->size = sample_size;
  return filter;
}

httpd_handle_t stream_httpd = NULL;
httpd_handle_t camera_httpd = NULL;
