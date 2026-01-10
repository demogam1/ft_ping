SRC = main.c

all:
	gcc -o ft_ping $(SRC)

docker: 
	docker compose up -d
	docker exec -it ft_ping bash

clean:
	rm -f ft_ping

.PHONY: all clean