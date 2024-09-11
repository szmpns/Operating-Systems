# [sendsignal.c](./stackheap.c)

**PL:**  
Ten kod demonstruje różnicę między statyczną i dynamiczną alokacją pamięci w C. W funkcji `statyczna()` tablica jest tworzona na stosie, co powoduje automatyczne zwolnienie pamięci po zakończeniu funkcji. W funkcji `dynamiczna()` tablica jest dynamicznie alokowana na stercie za pomocą `malloc()`, a pamięć musi być ręcznie zwolniona za pomocą `free()`. Kod pozwala zobaczyć, jak różne metody alokacji pamięci wpływają na zarządzanie pamięcią w programie.

**ENG:**  
This code demonstrates the difference between static and dynamic memory allocation in C. In the `statyczna()` function, the array is created on the stack, which results in automatic memory deallocation when the function ends. In the `dynamiczna()` function, the array is dynamically allocated on the heap using `malloc()`, and the memory must be manually freed using `free()`. The code illustrates how different memory allocation methods affect memory management in a program.

# [zad2.py](./zad2.py)

**PL:**
Ten program tworzy listę z jedną tablicą `numpy` o rozmiarze 1000x1000 i mierzy zużycie pamięci przez proces przy użyciu modułu `psutil`. Po pierwszym pomiarze pamięci czeka na naciśnięcie klawisza `Enter`. Po naciśnięciu `Enter` dodaje do listy kolejną tablicę o takim samym rozmiarze. Ponownie mierzy i wyświetla zużycie pamięci po rozszerzeniu tablicy. Na koniec trzeba znów nacisnąć `Enter`, aby zakończyć program.

**ENG:**  
This program creates a list with a `numpy` array of size 1000x1000 and measures the memory usage of the process using the `psutil` module. After the first memory measurement, it waits for the user to press `Enter`. Upon pressing `Enter`, it adds another array of the same size to the list. The program then measures and displays the memory usage again after expanding the array. Finally, the user must press `Enter` again to exit the program.