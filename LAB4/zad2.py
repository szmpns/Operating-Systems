import numpy as np
import psutil
import os

def print_memory_usage():
    process = psutil.Process(os.getpid())
    memory_usage = process.memory_info().rss / (1024 * 1024)  # Zuzycie pamieci w MB
    print(f"Memory Usage: {memory_usage:.2f} MB")

def main():
    array_of_arrays = [np.zeros((1000, 1000), dtype=float)]

    print_memory_usage()

    input("Press Enter to expand the array...")

    new_array = np.zeros((1000, 1000), dtype=float)
    array_of_arrays.append(new_array)

    print_memory_usage()

    input("Press Enter to exit the program...")

if __name__ == "__main__":
    main()

