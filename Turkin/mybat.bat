@echo off

set /p commit_message="Enter commit message: "

setlocal EnableDelayedExpansion

set "last_tag=turkin_tag_"
set "last_tag_number=0"

for /f "tokens=2 delims=_" %%a in ('git tag ^| findstr /r /c:"turkin_tag_[0-9]*$" ^| sort /r') do (
    set "last_tag=%%a"
    set /a "last_tag_number=%%a"
    goto :break
)

set /a "new_tag_number=last_tag_number+1"
set "new_tag=turkin_tag_%new_tag_number%"

echo New tag: %new_tag%

git add .
git commit -m "%commit_message%"
git tag -a %new_tag% -m "Description tag"
git pull origin main
git push origin main --tags

echo "Change success."
pause

:break
