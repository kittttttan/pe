<?php

class Pe2Test extends PHPUnit_Framework_TestCase
{
    public function testCalc()
    {
        $this->assertEquals(4613732, Pe2::calc());
    }
}
