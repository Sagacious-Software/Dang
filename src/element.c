#include <stdlib.h>

#include <dang/element.h>

/* draw an element in a window */
void draw_element (element_t *element, window_t *window) {

    element->draw_element_method (element,
                                  window->image,
                                  window->region,
                                  window->region);
    update_window_region (window, window->region);
}

void element_window_callback (window_t *window, event_t event, void *data) {

    element_t *element = (element_t *) data;

    switch (event.type) {

        case EVENT_CREATE:
        case EVENT_RESIZE:
            draw_element (element, window);
            break;

        case EVENT_DESTROY:
            /* TODO */
            break;

        case EVENT_SHOW:
            /* TODO */
            break;

        case EVENT_HIDE:
            /* TODO */
            break;

        case EVENT_MOVE:
            /* TODO */
            break;

        case EVENT_MOUSE:
            /* TODO */
            break;

        case EVENT_KEYBOARD:
            /* TODO */
            break;

        case EVENT_TEXT:
            /* TODO */
            break;

        case EVENT_VBLANK:
            /* TODO */
            break;

        default:
            break;
    }
}

void destroy_element (element_t *element) {

    element->destroy_element_method (element);
}

window_t *present_element (element_t *element,
                           backend_t *backend,
                           region_t region,
                           char *title) {

    return create_window (backend, region, title, element_window_callback, element);
}
