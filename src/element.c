#include <stdlib.h>

#include <dang/element.h>

void destroy_element (element_t *element) {

    element->destroy_element_method (element);
}

window_t *present_element (element_t *element,
                           backend_t *backend,
                           region_t region,
                           char *title) {

    return element->present_element_method (element, backend, region, title);
}

void element_window_callback (window_t *window, event_t event, void *data) {

    /*element_t *element = (element_t *) data;*/

    /* TODO: convert window events to element events and propogate them !!!! */
}
