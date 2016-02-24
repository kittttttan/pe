@echo off
vendor\bin\phpcs --report=full --standard=PSR2 --extensions=php src > phpcs.log
