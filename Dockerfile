FROM ubuntu:22.04
RUN apt-get update && apt-get install -y build-essential cmake libssl-dev git
WORKDIR /app
COPY . /app
RUN mkdir -p build && cd build && cmake .. && make
EXPOSE 8000
CMD ["/app/build/node"]
