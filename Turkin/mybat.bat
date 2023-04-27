@echo off

set /p commit_message="Enter commit message: "

setlocal EnableDelayedExpansion

set last_tag=turkin_tag_
for /f "tokens=2 delims=_" %%a in ('git tag -l "turkin_tag_*" ^| findstr /r /c:"turkin_tag_[0-9]*$" ^| sort /r') do (
    set "last_tag=%%a"
    goto :break
)
set /a tag_number=1
if not "%last_tag%" == "turkin_tag_" (
    set /a tag_number=!last_tag:~-1!+1
)

echo Last tag: %last_tag%
echo New tag number: %tag_number%

git add .
git commit -m "%commit_message%"
git tag -a turkin_tag_%tag_number% -m "Description tag"
git pull origin main
git push origin main --tags

echo "Change success."
pause