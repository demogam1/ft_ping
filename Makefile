SRC = main.c

all:
	gcc -o ft_ping $(SRC)

docker: 
	docker compose up -d
	docker exec -it ft_ping bash
docker-rebuild:
	docker compose down
	docker compose build --no-cache
	docker compose up -d
	docker exec -it ft_ping bash
docker-stop:
	docker compose down
docker-purge:
	docker compose down
	docker system prune -a --volumes -f
clean:
	rm -f ft_ping

.PHONY: all clean