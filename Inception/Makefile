GREEN = \033[32m
END = \033[0m
BOLD = \033[1m

all:
	sudo docker-compose -f ./src/docker-compose.yml up -d --build

info:
	echo "$(GREEN)$(BOLD)images status :$(END)"
		-sudo docker images
	echo "$(GREEN)$(BOLD)docker-compose status :$(END)"
		-sudo docker-compose -f ./src/docker-compose.yml ps
	echo "$(GREEN)$(BOLD)docker status :$(END)"
		-sudo docker ps -a
	echo "$(GREEN)$(BOLD)volume status :$(END)"
		-sudo docker volume ls
	echo "$(GREEN)$(BOLD)network status :$(END)"
		-sudo docker network ls

stop:
	sudo docker-compose -f ./src/docker-compose.yml stop

restart:
	sudo docker-compose -f ./src/docker-compose.yml restart

clean:
	sudo docker-compose -f ./src/docker-compose.yml down
	sudo docker volume rm src_db
	sudo docker volume rm src_wordpress

fclean: clean
	sudo docker system prune -a --force

.SILENT: info

.PHONY: all, info, stop, restart, clean, fclean
