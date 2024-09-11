#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Użycie: %s <rozmiar bufora> <plik.src> <plik.trg>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int buffer_size = atoi(argv[1]);
    char *src_filename = argv[2];
    char *trg_filename = argv[3];

    FILE *src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        perror("Błąd otwierania pliku źródłowego");
        exit(EXIT_FAILURE);
    }

    FILE *trg_file = fopen(trg_filename, "wb");
    if (trg_file == NULL) {
        perror("Błąd otwierania pliku docelowego");
        fclose(src_file);
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(buffer_size);
    if (buffer == NULL) {
        perror("Błąd alokacji bufora");
        fclose(src_file);
        fclose(trg_file);
        exit(EXIT_FAILURE);
    }

    clock_t start_time = clock();

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, buffer_size, src_file)) > 0) {
        fwrite(buffer, 1, bytesRead, trg_file);
    }

    clock_t end_time = clock();

    fclose(src_file);
    fclose(trg_file);
    free(buffer);

    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Czas kopiowania: %.6f sekund\n", total_time);

    return 0;
}