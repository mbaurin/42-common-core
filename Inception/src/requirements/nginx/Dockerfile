FROM debian:buster

RUN apt-get update \
&& apt-get upgrade -y \
&& apt-get install -y nginx openssl \
&& apt-get clean

COPY ./default /etc/nginx/sites-enabled/default

RUN openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=France/L=Lyon/O=42/OU=42Lyon/CN=mbaurin" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]