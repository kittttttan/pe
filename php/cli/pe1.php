<?php
require_once 'vendor/autoload.php';

use Pe\Pe1;

/**
 * @return void
 */
function help(): void
{
    echo 'php pe1.php [-l] number'."\n";
    echo 'options:'."\n";
    echo '  -l use loop'."\n";
}

/**
 * @return void
 */
function main(): void
{
    $argv = $_SERVER['argv'];
    // var_dump($argv);

    $arg1 = $argv[1] ?? null;
    if ($arg1 === '-h') {
        help();
        return;
    }

    $default_n = 1000;

    $is_loop = false;
    if ($arg1 === '-l') {
        $n = $argv[2] ?? $default_n;
        $is_loop = true;
    } else {
        $n = $argv[1] ?? $default_n;
    }
    if (!is_numeric($n)) {
        help();
        return;
    }

    $n = intval($n);
    $a = $is_loop ? Pe1::with_loop($n) : Pe1::no_loop($n);
    echo "n = $n" . ($is_loop ? ' (with loop)' : '') . "\n";
    echo $a;
}

main();
