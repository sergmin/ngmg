r:
cd R:\Chechetkin\git\ngmg\Chechetkin
git add .
git commit

git pull
git checkout main

set /p tagname="¬ведите название тега"
set /p tagdescr="¬ведите название тега"
git tag -f -a  %tagname% -m "%tagdescr%" 

git push
pause