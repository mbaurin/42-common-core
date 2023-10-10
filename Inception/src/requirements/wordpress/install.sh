#!/bin/bash

chmod 777 -R /var/www

wp core download  --locale=fr_FR --skip-content --user=$WP_ROOT --path=$WP_PATH
cd $WP_PATH
wp config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=$DB_HOST --path=$WP_PATH

wp core install --url=https://mbaurin.42.fr/ --title=inception --admin_user=$WP_ROOT --admin_password=$WP_ROOT --admin_email=test@gmail.com --allow-root
wp user create $DB_USER user@gmail.com --user_pass=$DB_PASSWORD --role=editor --allow-root
wp theme install twentytwentytwo --activate

php-fpm7 -F -R
