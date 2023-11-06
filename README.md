Задание №3 для курса C++ Basic

<p align="center"><b>Игра "Угадай число"</b></p>

<p align="center">Установка:</p>

Скачайте репозиторий:
```
$ wget https://github.com/rudikrudik/otus_cpp_basics/archive/refs/heads/gues_the_number.zip
```
Разархируйте файл и перейдите в папку с исходным кодом и скопилируйте:
```
$ g++ -o guess_the_number main.cpp randomNumber.cpp fileIO.cpp consoleIO.cpp
```

Запуск игры:
```
$ ./guess_the_number
```
Параметры запуска:

<b>-table</b>  -распечатывает таблицу рекордов

<b>-max [number]</b> -компьютер загадывает число от 1 до [number]

<b>-level [1 - 3]</b> -уровень сложности, 1 - числа от 1 до 10, 2 от 1 до 50 и 3 от 1 до 100

При запуске без параметров компьютер загадывает числа от 1 до 100

