<?php
require 'vendor/autoload.php';

$app = new \Slim\Slim();

$app->get('/:name', function ($name) {
    echo "Hello, $name";
});

$app->run();

?>