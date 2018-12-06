@echo off

set solutiondir=%~1
set target=%~2

echo Copiando archivos...

xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-window-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-system-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-graphics-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\openal32.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-audio-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\STP\bin\STP-d.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\STP\bin\zlibd.dll" "%target%" /E /Y /S
mkdir "%target%res\assets"
xcopy "%solutiondir%res\assets" "%target%res\assets" /E /Y /S
xcopy "%solutiondir%libs\TGUI-0.8\bin" "%target%" /E /Y /S
echo Copia finalizada
