@echo off
rem �^�C�g���̐ݒ�
title RemoveSVNFolder
rem ��������
set /p pushKey=".svn�t�H���_���폜���܂��B��낵���ł����H(y/n)"
if "%pushKey%" == "y" goto KILL

if "%pushKey%" == "Y" goto KILL

if "%pushKey%" == "yes" goto KILL

if "%pushKey%" == "YES" goto KILL
rem NO�Ȃ�I��
goto EXT

rem .svn�t�H���_����
:KILL
for /r %%A in ( _svn ) do ( if exist "%%A" ( rmdir /s /q "%%A"))
for /r %%i in ( .svn ) do ( if exist "%%i" ( rmdir /s /q "%%i"))
goto EXT

:EXT