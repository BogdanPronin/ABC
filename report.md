# Отчёт домашнего задания №4
## _Вариант 27_
### Выполнил Пронин  Богдан
---
# Условие задачи
Лес поделен на 20 участков. На одном из участков прячется Винни-Пух. Пчёлы разделились в стаи и ищут Винни-Пуха на участке какое-то время. Если не находят - переходят на следующий. Создать многопоточное приложение, моделирующее поиски Винни-Пуха

# Модель параллельных вычислений

Программа использует модель вычисления **Взаимодействующие равные**. А именно модель **"портфель задач"**. Программа реализуема с помощью разделяемой переменной, доступ к которой в один момент времени имеет только один процесс. Переменная numSections, которая хранит количество доступных пчёлам (потокам) участков леса.

# Входные данные

При запуске пользователь может передать входные данные через консоль:

1. Количество стай пчёл (1-80):
2. Время сколько пчёлы будут искать Винни-Пуха на участке (1-60 сек):
3. Участок где прячется Винни-Пух (1-20):

Если данные не соответствуют диапозону значений, то будет выведено сообщение **"Некорректный ввод"** и всё равно придётся ввести корректно.

# Результаты работы

```sh
Введите количество стай пчёл (1-80): 3
Введите время сколько пчёлы будут искать Винни-Пуха на участке (1-60 сек): 2
Введите участок где прячется Винни-Пух (1-20): 20
Стая 3 просматривает участок 1...
Стая 2 просматривает участок 2...
Стая 1 просматривает участок 3...
Стая 3 просматривает участок 4...
Стая 1 просматривает участок 5...
Стая 2 просматривает участок 6...
Стая 3 просматривает участок 7...
Стая 1 просматривает участок 8...
Стая 2 просматривает участок 9...
Стая 3 просматривает участок 10...
Стая 1 просматривает участок 11...
Стая 2 просматривает участок 12...
Стая 1 просматривает участок 13...
Стая 3 просматривает участок 14...
Стая 2 просматривает участок 15...
Стая 1 просматривает участок 16...
Стая 3 просматривает участок 17...
Стая 2 просматривает участок 18...
Стая 1 просматривает участок 19...
Стая 3 просматривает участок 20...
Стая 3 нашла Винни-пуха на участке 20!
```
