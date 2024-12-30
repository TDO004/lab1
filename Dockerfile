# Используем минимальный образ Alpine
FROM alpine:latest

# Устанавливаем необходимые пакеты
RUN apk update && apk add --no-cache g++ git bash libstdc++

# Устанавливаем рабочую директорию
WORKDIR /app

# Клонируем репозиторий
RUN git clone https://github.com/TDO004/lab1.git .

# Компилируем программу
RUN g++ -o cpu_load cpu_load.cpp

# Создаём директорию для вывода
RUN mkdir -p /output

# Настраиваем вывод результата в файл
CMD ["sh", "-c", "./cpu_load > /output/result.txt"]