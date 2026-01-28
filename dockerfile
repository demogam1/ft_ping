FROM debian:latest

RUN apt-get update && apt-get install -y gcc make apt-transport-https inetutils-ping bash && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/ft_ping   

COPY . .

RUN make

CMD ["sleep", "infinity"]
