@echo off

set /p commit_message="Enter message commit: "

git add .
git commit -m "%commit_message%"
git tag -a v1.0 -m "Description tag"
git push origin master --tags

echo "Change success"
pause