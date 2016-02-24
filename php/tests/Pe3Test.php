<?php

class Pe3Test extends PHPUnit_Framework_TestCase
{
    public function testCalc()
    {
        $this->assertEquals(array(71, 839, 1471, 6857), Pe3::calc());
    }
}
