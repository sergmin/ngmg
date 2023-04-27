@echo off

set /p commit_message="Enter commit message: "

setlocal EnableDelayedExpansion
set /a tag_number=0
for /f "tokens=2 delims=" %%a in ('git tag ^| findstr /r /c:"turkin_tag[0-9]*$" ^| sort /r') do (
set "last_tag=%%a"
echo Last tag: !last_tag!
set /a tag_number=!last_tag:~-1!+1
echo New tag number: !tag_number!
goto :break
)

echo %tag_number%
set /a tag_number2=tag_number+1
echo %tag_number2%
git add .
git commit -m "%commit_message%"
git tag -a turkin_tag_%tag_number2% -m "Description tag"
git pull origin main
git push origin main --tags

echo "Change success."
pause