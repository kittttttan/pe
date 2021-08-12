<?php

namespace Tests;

use Pe\Pe3;
use PHPUnit\Framework\TestCase;

class Pe3Test extends TestCase
{
    public function testCalc()
    {
        $this->assertEquals([71, 839, 1471, 6857], Pe3::calc(600851475143));
    }
}
