@echo off
rem title
title bak file Deleter
set /p pushKey=".bak�t�@�C�����폜���܂��B��낵���ł����H(y/n)"
if "%pushKey%" == "y" goto KILL

if "%pushKey%" == "Y" goto KILL

if "%pushKey%" == "yes" goto KILL

if "%pushKey%" == "YES" goto KILL
rem NO�Ȃ�I��
goto EXT

rem .bak�t�@�C������
:KILL
for /r %%i in ( *.bak ) do ( if exist "%%i" ( del /s /q "%%i"))
goto EXT

:EXT