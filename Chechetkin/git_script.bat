r:
cd R:\Chechetkin\git\ngmg\Chechetkin
git add .
git commit
set /p tagname=
git tag  %tagname% 
git pull
git checkout main
git push
pause