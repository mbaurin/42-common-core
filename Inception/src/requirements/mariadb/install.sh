#!/bin/bash

if [[ ! -d /var/lib/mysql/inception_db ]]; then
    mysql_install_db --ldata=/var/lib/mysql --user=mysql

    service mysql start

    mysql -u root -e "CREATE DATABASE inception_db;
        CREATE USER '$DB_USER' IDENTIFIED BY '$DB_PASSWORD';
        GRANT ALL PRIVILEGES ON inception_db.* TO '$DB_USER'@'%';
        UPDATE mysql.user SET plugin = '' WHERE user = 'root' AND host = 'localhost';
        FLUSH PRIVILEGES;"

    mysqladmin -u root password "root"

fi

/bin/sh /usr/bin/mysqld_safe
