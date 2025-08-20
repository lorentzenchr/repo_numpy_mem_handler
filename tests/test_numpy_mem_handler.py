import numpy as np

from numpy_mem_handler import get_current_handler


def test_change_numpy_allocator():
    # This should not error!
    get_current_handler()
