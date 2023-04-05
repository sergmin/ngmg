set /p commit_message="Enter message commit: "

setlocal EnableDelayedExpansion
set /a tag_number=0
for /f "delims=" %%a in ('git tag ^| sort /r') do (
    set "last_tag=%%a"
    set /a tag_number=!last_tag:~-1!+1
    goto :break
)
:break
git add .
git commit -m "%commit_message%"
git tag -a v1.%tag_number% -m "Description tag"
git push origin main --tags

echo "Change success."
pause