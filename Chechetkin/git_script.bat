r:
cd R:\Chechetkin\git\ngmg\Chechetkin
git add .
git commit

git pull
git checkout main

set /p tagname="������� �������� ����"
set /p tagdescr="������� �������� ����"
git tag -f -a  %tagname% -m "%tagdescr%" 

git push
pause