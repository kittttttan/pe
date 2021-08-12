<?php

namespace Tests;

use Pe\Pe2;
use PHPUnit\Framework\TestCase;

class Pe2Test extends TestCase
{
    public function testCalc()
    {
        $this->assertEquals(4613732, Pe2::calc(4000000));
    }
}
