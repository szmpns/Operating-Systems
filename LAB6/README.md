# [zadanie_2.py](./zadanie_2.py)

**PL:**  
Ten program optymalizuje produkcję, wykorzystując programowanie liniowe do wyznaczenia optymalnych ilości produktów na podstawie dostępnych materiałów, maszyn i czasu produkcji.

**ENG:**  
This program optimizes production using linear programming to determine the optimal quantities of products based on available materials, machines, and production time.

# [zadanie_5.c - Problem ucztujących filozofów / Dining philosophers problem](./zadanie_5.c)

https://en.wikipedia.org/wiki/Dining_philosophers_problem

**PL:**  
Ten program w C symuluje problem filozofów przy stole, gdzie każdy filozof (wątek) cyklicznie myśli i je, blokując dwa sąsiadujące widelce (mutexy) przed jedzeniem. Program używa wielowątkowości, aby każdy filozof mógł współbieżnie próbować podnieść widelce, jednocześnie zapewniając synchronizację, aby uniknąć konfliktów. Mutexy są inicjowane przed startem wątków i niszczone po zakończeniu działania wszystkich filozofów.

**ENG:**  
This C program simulates the dining philosophers problem, where each philosopher (thread) alternates between thinking and eating, locking two adjacent forks (mutexes) before eating. The program uses multithreading to allow each philosopher to concurrently attempt to pick up forks while ensuring synchronization to avoid conflicts. The mutexes are initialized before the threads start and are destroyed after all philosophers finish their execution.