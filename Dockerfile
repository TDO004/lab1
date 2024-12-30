# ���������� ����������� ����� Alpine
FROM alpine:latest

# ������������� ����������� ������
RUN apk update && apk add --no-cache g++ git bash libstdc++

# ������������� ������� ����������
WORKDIR /app

# ��������� �����������
RUN git clone https://github.com/TDO004/lab1.git .

# ����������� ���������
RUN g++ -o cpu_load cpu_load.cpp

# ������ ���������� ��� ������
RUN mkdir -p /output

# ����������� ����� ���������� � ����
CMD ["sh", "-c", "./cpu_load > /output/result.txt"]