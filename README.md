# C++ Blockchain (Educational)


Простий освітній блокчейн на C++17. Проєкт демонструє базові компоненти:
- Block (SHA-256 hash)
- Blockchain з простим Proof-of-Work (змінна `DIFFICULTY`)
- HTTP API (мінімалістичний, використовуючи header-only `cpp-httplib`)


## Вимоги
- g++ (>=9) або clang
- CMake >=3.10
- OpenSSL dev (для SHA-256): libssl-dev


## Команди


```bash
mkdir build && cd build
cmake ..
make
./bin/node # запустить вузол на порту 8000


# або за допомогою Makefile
make run


# запустити тести
make test
