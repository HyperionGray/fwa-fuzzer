import ctypes

_handle = ctypes.CDLL('C:/Users/Garrett McParrot/CLionProjects/fwa-fuzzer/fwa.dll')
mutate_func = _handle.mutate
mutate_func.argtypes = (ctypes.POINTER(ctypes.c_char), ctypes.c_int)

def mutate(mutate_file, max_mutate):
    mutate_func(ctypes.c_char_p(mutate_file), ctypes.c_int(max_mutate))
    return 0


if __name__ == "__main__":
    _filename = ctypes.c_char_p(b"CMakeLists.txt")
    mutate(ctypes.byref(_filename), 10)
