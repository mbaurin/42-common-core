<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'inception_db' );

/** Database username */
define( 'DB_USER', 'inception_user');

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('WP_ALLOW_REPAIR', true);

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'X)hU~7tt^Yo,Yf$<|qV+|<!S]X!f0eTnHooEI+Md~?S|W>?:4hArs*d`@xCXitrd');
define('SECURE_AUTH_KEY',  'VLWD>+*N)8TM|K#qX1RO9?.+->YhS9>knZ?F6hb]Camp nbyhlE2zFPm;LB=,TpG');
define('LOGGED_IN_KEY',    'b9q`)BR/u*7)[S>*]p(hs-8r5V?WA|E}ofdz!RUU+0N_1Ah#=GxDR!5( Z?c+ChW');
define('NONCE_KEY',        'JKvw,*_+W/u  P!}NhB{Di|4;O2>s/TtJ%P?, vyJ?;*mgv[L(si:01+NDPsc@bE');
define('AUTH_SALT',        'r=-Mv|YJ+Bx^8r6Gam>HDiMzGeCbU~Q1.I/;2Y.&y;,|rh]K[3d)Kz[f9`Zo1Q^q');
define('SECURE_AUTH_SALT', 'V1LH-FxlXp3S^q$x!?Z$/7oN<G!*4%NDyq8Uk|?nx`Lon[U-5T/zpI/ObBva9cB}');
define('LOGGED_IN_SALT',   '`|LKyU{lD7@n JMUX`|JQ_;XGfM*I;Ns:Rr,FyI[l:cez(|Pd.,D9H7M$$+8>~49');
define('NONCE_SALT',       '.~G42pS0X.ogh@?In^-G)_9W,N?7d]K}|(:xSM=Akj:n~]-T(t%7skd/WA(wE8L[');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';