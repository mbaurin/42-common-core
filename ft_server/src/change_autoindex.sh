#!/bin/bash
if [ $1 = "false" ]; then
    sed -i 's/autoindex on;/autoindex off;/g' /etc/nginx/sites-available/default
    service nginx restart
    echo "Autoindex Off"
elif [ $1 = "true" ]; then
    sed -i 's/autoindex off;/autoindex on;/g' /etc/nginx/sites-available/default
    service nginx restart
    echo "Autoindex On"
else
    echo "Wrong Parameters"
fi
