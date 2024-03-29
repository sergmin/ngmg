@echo off
set /p commit_message="Enter commit message: "
setlocal EnableDelayedExpansion
set /a tag_number=0
for /f "delims=" %%a in ('git tag ^| findstr /r /c:"Glebov_tag_[0-9]*" ^| sort') do (
    set "last_tag=%%a"
    set /a tag_number=!last_tag:~-1!
)
set /a tag_number+=1
git add .
git commit -m "%commit_message%"
git tag -a Glebov_tag_%tag_number% -m "Description tag"
git pull origin main
git push origin main --tags
pause
echo "Change success."