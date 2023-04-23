@echo OFF

CALL ./build.bat

ctest --test-dir ./build --output-on-failure --verbose
