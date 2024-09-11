# [another.c](./another.c)

**PL:**  
Ten program wykorzystuje funkcję `system` do wykonania polecenia systemowego `ls -al /var/log/`. 

**ENG:**  
This program uses the `system` function to execute the system command `ls -al /var/log/`.

# [brother.c](./brother.c)

**PL:**  
Ten program tworzy trzy procesy, z których każdy reprezentuje jedno zagnieżdżone dziecko. Pierwsze dziecko tworzy drugie dziecko, a rodzic tworzy trzecie dziecko. Każdy proces wyświetla swoje PID oraz PID rodzica (PPID). Dodatkowo, drugie dziecko używa polecenia systemowego "ps" do wyświetlenia informacji o procesach o nazwie "brother".

Po utworzeniu struktury drzewa procesów, program używa polecenia systemowego "pstree" do wyświetlenia drzewa procesów dla oryginalnego procesu rodzicielskiego. Warto zauważyć, że program korzysta z funkcji `wait()` do poczekania na zakończenie trzeciego dziecka przed zakończeniem działania programu.

**ENG:**  
This program creates three processes, each representing a nested child. The first child creates the second child, and the parent creates the third child. Each process displays its PID and its parent's PID (PPID). Additionally, the second child uses the system command "ps" to display information about processes named "brother."

After the process tree structure is created, the program uses the "pstree" system command to display the process tree for the original parent process. It is worth noting that the program uses the `wait()` function to wait for the third child to finish before the program terminates.

# [catchsignal.c](./catchsignal.c)

**PL:**  
Program rejestruje obsługę kilku sygnałów za pomocą funkcji `sigaction` i następnie w nieskończonej pętli oczekuje na ich nadejście. Główna funkcja obsługi sygnałów, `signal_handler`, wypisuje informacje o otrzymanym sygnale, w tym jego nazwę i numer.

W kodzie użyte są następujące sygnały:
- SIGINT: Ctrl+C (Wciśnij Ctrl+c podczas działania programu)
- SIGTERM: Sygnał zakończenia (w nowym oknie wpisz: `kill -SIGTERM <PID procesu>`)
- SIGUSR1: Użytkowniczy sygnał 1 (w nowym oknie wpisz: `kill -SIGUSR1 <PID procesu>`)

Działanie:

```
Waiting for signals...
^CReceived signal: Interrupt (2)
Received signal: Terminated (15)
Received signal: User defined signal 1 (10)
```

`PID procesu` możesz sprawdzić manualnie lub wpisując `ps aux | grep {nazwa_programu}` w nowym oknie.

Program jest zorganizowany w sposób umożliwiający dodanie obsługi dodatkowych sygnałów. Pętla while utrzymuje proces aktywnym, umożliwiając ciągłe nasłuchiwanie sygnałów.

Aby zakończyć działanie programu, wpisz: `kill -9 <PID procesu>` w nowym oknie terminala.

Wynik:

```
zsh: killed     ./{nazwa_programu}
```

**ENG:**  
The program registers the handling of several signals using the `sigaction` function and then waits for them in an infinite loop. The main signal handler function, `signal_handler`, prints information about the received signal, including its name and number.

The following signals are used in the code:
- SIGINT: Ctrl+C (Press Ctrl+C while the program is running)
- SIGTERM: Termination signal (In a new terminal window, type: `kill -SIGTERM <process PID>`)
- SIGUSR1: User-defined signal 1 (In a new terminal window, type: `kill -SIGUSR1 <process PID>`)

Output example:

```
Waiting for signals...
^CReceived signal: Interrupt (2)
Received signal: Terminated (15)
Received signal: User defined signal 1 (10)
```

You can check the `process PID` manually or by typing `ps aux | grep {program_name}` in a new terminal window.

The program is designed to allow additional signal handling. The while loop keeps the process running, continuously listening for signals.

To terminate the program, type `kill -9 <process PID>` in a new terminal window.

Result:

```
zsh: killed     ./{program_name}
```

# [child.c](./child.c)

**PL:**  
Program tworzy proces potomny za pomocą funkcji `fork()`, następnie rozdziela swoje działanie na dwa procesy: proces rodzica i proces dziecka. Proces rodzica wyświetla swój PID oraz PID swojego dziecka, a proces dziecka wyświetla swój PID oraz PID swojego rodzica. Aby kontynuować działanie programu naciskaj `Enter`.

**ENG:**  
The program creates a child process using the `fork()` function, then splits its execution into two processes: the parent process and the child process. The parent process displays its PID and the PID of its child, while the child process displays its own PID and the PID of its parent. To continue the program's execution, press `Enter`.

# [exec.c](./exec.c)

**PL:**  
Program próbuje uruchomić program `child`, zastępując nim bieżący proces. Przekazuje argument `"new"` do programu `child`, który staje się jego pierwszym argumentem. Pamiętaj, aby mieć w tym samym katalogu wcześniej skompilowany program `child.c` jako `child`(`gcc child.c -o child`). 

**ENG:**  
The program attempts to run the `child` program, replacing the current process with it. It passes the argument `"new"` to the `child` program, which becomes its first argument. Remember to have the `child.c` program compiled as `child` in the same directory (`gcc child.c -o child`).

# [grandchild.c](./grandchild.c)

**PL:**  
Program tworzy dwa procesy potomne za pomocą funkcji `fork()`, gdzie pierwszy proces potomny tworzy kolejny proces. Każdy proces wyświetla swoje PID oraz PID swojego rodzica, a na końcu program wywołuje komendę `pstree`, aby zobaczyć strukturę drzewa procesów. Program pozwala obserwować hierarchię procesów, gdzie oryginalny rodzic tworzy pierwsze dziecko, a ono tworzy kolejne.

Aby kontynuować działanie programu naciskaj `Enter`.

**ENG:**  
The program creates two child processes using the `fork()` function, where the first child process creates another process. Each process displays its PID and the PID of its parent, and at the end, the program runs the `pstree` command to display the process tree structure. The program allows you to observe the process hierarchy, where the original parent creates the first child, which then creates another.

To continue the program's execution, press `Enter`.

# [sendsignal.c](./sendsignal.c)

**PL:**  
Ten program umożliwia wysyłanie sygnałów do procesów na podstawie ich **PID** i numeru sygnału. Może być użyty np. do przerwania działania programu (wysyłając `SIGINT`), zakończenia procesu (`SIGTERM` lub `SIGKILL`), czy też zatrzymania i wznowienia jego pracy (`SIGSTOP` i `SIGCONT`). To narzędzie przydaje się przy zarządzaniu procesami w systemie, np. gdy chcemy spokojnie zakończyć proces lub natychmiast go wymusić. 

**ENG:**  
This program allows sending signals to processes based on their **PID** and signal number. It can be used, for example, to interrupt a running program (by sending `SIGINT`), terminate a process (`SIGTERM` or `SIGKILL`), or pause and resume its execution (`SIGSTOP` and `SIGCONT`). This tool is useful for managing processes in the system, such as when you want to gracefully terminate a process or forcibly kill it.