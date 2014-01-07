<?php

$mode = getenv('APP_MODE');

switch ($mode) {
    case "production":
        $connectionSettings = array(
            'connection_string' => 'mysql:host=localhost;dbname=DBNAME',
            'username' => 'MYSQL_USER',
            'password' => 'TOP_SECRET'
        );
        break;
    default:
        $connectionSettings = array(
            'connection_string' => 'mysql:host=localhost;dbname=DBNAME',
            'username' => 'root',
            'password' => 'admin'
        );
        break;
}

?>