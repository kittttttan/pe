<?php

namespace Tests;

use Pe\Pe1;
use PHPUnit\Framework\TestCase;

class Pe1Test extends TestCase
{
    public function testCalc()
    {
        $this->assertEquals(234168, Pe1::with_loop(1000));
        $this->assertEquals(234168, Pe1::no_loop(1000));
    }
}
