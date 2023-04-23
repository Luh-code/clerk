@echo off
IF NOT EXIST "%cd%\build\" MKDIR "%cd%\build\"
SET "buildpath=%cd%\build\"
SET "srcpath=%cd%\."

cmake -S "%srcpath%" -B "%buildpath%" %*
