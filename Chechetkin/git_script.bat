r:
cd R:\Chechetkin\git\ngmg\Chechetkin
git add .

set /p commit_msg="Commit message: "

git commit -m "%commit_msg%"

git pull
git checkout main

set /p tagname="Enter tag name: "
set /p tagdescr="Enter tag decription: "
git tag -f -a  %tagname% -m "%tagdescr%" 

git push origin --tags
git push
pause