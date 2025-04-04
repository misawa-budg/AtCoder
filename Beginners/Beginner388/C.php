<?php

function lower_bound($array, $target) {
    $left = 0;
    $right = count($array);
    while ($left < $right) {
        $mid = (int)(($left + $right) / 2);
        if ($array[$mid] < $target) {
            $left = $mid + 1;
        } else {
            $right = $mid;
        }
    }
    return $left;
}

$N = intval(trim(fgets(STDIN)));
$mochies = explode(" ", trim(fgets(STDIN)));
$mochies = array_map('intval', $mochies);

$count = 0;
for ($i = 0; $i < $N; $i++) {
    $target = $mochies[$i] * 2;
    $lb = lower_bound($mochies, $target);
    if ($lb >= $N) {
        break;
    }
    $count += $N - $lb;
}

echo $count . PHP_EOL;
