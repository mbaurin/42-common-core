<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress_user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'S0&|`EnG@cfY-5O0R5?]&!VW;PH,/gNeS/F+_A:]9m6Jg{$$f&ia*&4n)1~{L}p9');
define('SECURE_AUTH_KEY',  'p@p^z-tD</{M`Zyqb/RcBx[9KZ}v~qHEM%x&qB@f~l?yl)33VtY.-4`{MwIzJQ(Y');
define('LOGGED_IN_KEY',    'b|y@^&A9vLtC8mPh6-;3C8?fN*}3v|Z(xGP|;Y&K|<di+za}$o]y^lZQb0Ckh$sJ');
define('NONCE_KEY',        'Tj^[SbFWNQ84]kH|-IZfTtmAy#}SG;R>c5pp0L}q.^=P~6W_:Z7D7~0y368HP^7m');
define('AUTH_SALT',        '?v]>gl!ZRQHE2Al5X,lG+*,KxGS9[p*d&%jmc.P$(WbT&zvRLA@HQ}_ed)]JS9>|');
define('SECURE_AUTH_SALT', 'u@e<mT8,{f;O|1x mx?y[f[0r+6s)}Cz*l0T ;h&2u<CRLog|&)1b?Me1yY|Tthr');
define('LOGGED_IN_SALT',   '-H*zJ-ln2qkcpe`0>fYg8(+s8:vK}?^d U7m^o|NBEp[RY)?4QR=~Lwu ex[|GKd');
define('NONCE_SALT',       '1<dod<EIer409X=|RW?,Uc5F1#-^]r1y(~m=p.LEhPzT<I[~eN8AEG63sT}5t:+_');

/**#@-*/

/**
 * WordPress Database Table prefix.
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

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
