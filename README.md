# Запуск программы
Пример: ./dz1 ../dataset/title.akas.tsv ../dataset/title.ratings.tsv ../dataset/title.basics.tsv 2021
             файл с русскими названиями          файл рейтинг        файл с основной информацией  год 
# Для получения файлов воспользоваться:
./download.sh

# Задание
Программа должна принимать необходимые для работы имена распакованных файлов в качестве аргументов командной строки и выводить данные в стандартный вывод.
Программа не должна брать в расчет фильмы для взрослых, и , если в варианте используется рейтинг, не должна учитывать рейтинг фильмов с числом оценок меньше 1000.
Программа не должна использовать интерактивный ввод с клавиатуры, например, "введите имя файла", "введите необходимый год", "ведите q чтобы выйти" - такими программами не удобно пользоваться и их разработка занимает больше времени.

# Мой вариант:
Вывести русские названия (при наличии) самых рейтинговые фильмов вышедших в год, переданный в аргументах командной строки
