# Используем минимальный образ Alpine
FROM alpine:latest

RUN apk update


RUN apk add --no-cache g++ git bash

WORKDIR /app

COPY cpu_load.cpp .

RUN gcc cpu_load.cpp -o cpu_load

CMD ["./cpu_load"]
