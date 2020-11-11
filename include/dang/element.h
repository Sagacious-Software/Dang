#ifndef ELEMENT_H
#define ELEMENT_H

#include <gosh/window.h>
#include <gosh/backend.h>

#include "cursor.h"

struct element_t;

typedef void destroy_element_method_t (struct element_t *element);
typedef void draw_element_method_t    (struct element_t *element,
                                       image_t image,
                                       region_t element_region,
                                       region_t draw_region);

/* gui element */
typedef struct element_t {

    cursor_type_t cursor;

    /* abstract methods */
    destroy_element_method_t *destroy_element_method;
    draw_element_method_t    *draw_element_method;

} element_t;

/* element destructor */
void destroy_element (element_t *element);

/* open a window containing the element */
window_t *present_element (element_t *element,
                           backend_t *backend,
                           region_t region,
                           char *title);

#endif /* ELEMENT_H */
