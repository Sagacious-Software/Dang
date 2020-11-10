#include <stdlib.h>

#include <dang/dummy_element.h>
#include <kit/util.h>

int main (int argc, char **argv) {

    backend_t *backend;
    window_t *window;
    element_t *element;

    /* create the root gui element */
    element = (element_t *) create_dummy_element (make_color_rgb (1, 0.8, 0.3));

    /* create the windowing backend */
    assert ((backend = create_backend (BACKEND_AUTO)),
            "Failure to create Gosh backend.\n");

    /* present the root gui element as a window on the screen */
    assert ((window = present_element (element,
                                       backend,
                                       make_region (0, 0, 640, 480),
                                       "Dang Demo")),
            "Failure to create Gosh window.\n");

    /* enter the run loop */
    backend_run (backend, NULL, NULL);

    /* clean up */
    destroy_element (element);
    destroy_window (window);
    destroy_backend (backend);

    return EXIT_SUCCESS;
}
