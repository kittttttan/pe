<?php

class Pe1Test extends PHPUnit_Framework_TestCase
{
    public function testCalc()
    {
        $this->assertEquals(234168, Pe1::calc());
        $this->assertEquals(234168, Pe1::sum());
    }
}
