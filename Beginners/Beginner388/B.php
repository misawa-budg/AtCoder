<?php

list($N, $D) = explode(" ", trim(fgets(STDIN)));

$snakes = [];
for ($i = 0; $i < $N; $i++) {
    list($width, $length) = explode(" ", trim(fgets(STDIN)));
    $snakes[] = [
        'width' => $width,
        'length' => $length,
        'weight' => $width * $length,
    ];
}

for ($i = 1; $i < $D; $i++) {
    $maxWeight = 0;
    for ($j = 0; $j < $N; $j++) {
        $snakes[$j]['weight'] += $snakes[$j]['width'];
        if ($snakes[$j]['weight'] > $maxWeight) {
            $maxWeight = $snakes[$j]['weight'];
        }
    }
    echo $maxWeight . PHP_EOL;
}
