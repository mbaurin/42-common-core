FROM debian:buster

ENV AUTOINDEX on

RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y nginx
RUN apt-get install openssl
RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN apt-get install -y php-mbstring php-zip php-gd
RUN apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

COPY src/start.sh ./
COPY src/change_autoindex.sh ./
COPY src/wp-config.php ./
COPY src/config.inc.php ./
COPY src/default ./

CMD bash /start.sh

EXPOSE 80
EXPOSE 443
