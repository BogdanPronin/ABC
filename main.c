#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int bees = 5; // Количество стай пчёл(потоков)

const int numSections = 21; // Количество участков леса

pthread_mutex_t mutex; // Мьютекс для синхронизации доступа к разделяемым ресурсам

// Структура, содержащая информацию об участке леса
typedef struct {
    int visited; // Флаг, показывающий, был ли участок уже посещен стаей
} section_t;

unsigned int searchTime = 4; // Время поиска Винни-Пуха на участке

int winniSection = 9; // Участок в котором прячется Винни-Пух

section_t sections[numSections]; // Массив участков леса
// Функция, выполняемая каждым потоком (стаей пчел)
void *bee_thread(void *thread_id) {
    long tid = (long)thread_id; // Номер текущего потока
    while (1) {
        // Берем мьютекс
        pthread_mutex_lock(&mutex);
        // Проходим по всем участкам леса, пока не найдем Винни-Пуха
        for (int i = 1; i < numSections; i++) {
            if (!sections[i].visited) { // Если участок не был еще посещен
                sections[i].visited = 1; // Отмечаем его как посещенный
                printf("Стая %ld просматривает участок %d...\n", tid + 1, i);
                // Разблокируем мьютекс
                pthread_mutex_unlock(&mutex);
                // Стая ищет Винни-пуха определенное количество времени
                sleep(searchTime);
                pthread_mutex_lock(&mutex);
                // Проверяем, найден ли Винни-Пух на этом участке
                if (i == winniSection) {
                    printf("Стая %ld нашла Винни-пуха на участке %d!\n", tid + 1, i);
                    // Наказываем Винни-Пуха
                    pthread_mutex_unlock(&mutex);
                    exit(NULL); // Завершаем поток
                }
            }
        }
        // Освобождаем мьютекс
        pthread_mutex_unlock(&mutex);
        break;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Ввод количества стай пчёл (потоков)
    while (1){
        printf("Введите количество стай пчёл (1-80): ");
        scanf("%d", &bees);
        if (bees >= 1 && bees <= 80) {
            break;
        } else {
            printf("Некорректный ввод\n");
        }
    }

    // Ввод времени сколько пчёлы будут искать Винни-Пуха на участке
    while (1){
        printf("Введите время сколько пчёлы будут искать Винни-Пуха на участке (1-60 сек): ");
        scanf("%d", &searchTime);
        if (searchTime >= 1 && searchTime <= 60) {
            break;
        } else {
            printf("Некорректный ввод\n");
        }
    }

    // Ввод учатска, где прячется Винни-Пух
    while (1){
        printf("Введите участок где прячется Винни-Пух (1-20): ");
        scanf("%d", &winniSection);
        if (winniSection >= 1 && winniSection <= 20) {
            break;
        } else {
            printf("Некорректный ввод\n");
        }
    }

    pthread_t threads[bees]; // Массив потоков (стаей пчел)
    long t; // Номер текущего потока
    // Инициализируем мьютекс
    pthread_mutex_init(&mutex, NULL);
    // Создаем потоки (стаи пчел)
    for (t = 0; t < bees; t++) {
        pthread_create(&threads[t], NULL, bee_thread, (void *)t);
    }
    // Ожидаем завершение всех потоков
    for (t = 0; t < bees; t++) {
        pthread_join(threads[t], NULL);
    }
    // Уничтожаем мьютекс
    pthread_mutex_destroy(&mutex);
    return 0;
}