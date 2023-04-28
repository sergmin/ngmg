@echo off

set /p commit_message="Enter commit message: "

for /f "tokens=2 delims=_" %%i in ('git tag -l "turkin_tag_*" ^| sort /r /n') do (
    set /a next_tag=%%i+1
    goto :done
)

set next_tag=1

:done
set next_tag=turkin_tag_%next_tag%

echo %next_tag%

git add .
git commit -m "%commit_message%"
git tag -a %next_tag% -m "Description tag"
git push origin main --tags
