cdef extern from "src/numpy_mem_handler.h":
    void c_get_current_handler()


def get_current_handler():
    c_get_current_handler()
