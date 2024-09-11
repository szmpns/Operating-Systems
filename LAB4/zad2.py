import numpy as np

def print_memory_usage():
    print("Memory Usage:")
    print(np.array([1]))

def main():
    array_of_arrays = [np.zeros((1000, 1000), dtype=float)]

    print_memory_usage()

    input("Naciśnij Enter, aby rozszerzyć tablicę...")

    new_array = np.zeros((1000, 1000), dtype=float)
    array_of_arrays.append(new_array)

    print_memory_usage()

    input("Naciśnij Enter, aby zakończyć program...")

if __name__ == "__main__":
    main()

