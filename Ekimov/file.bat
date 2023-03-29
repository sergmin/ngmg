R:
cd \Ekimov\git\ngmg\Ekimov
git add .
git commit 
git pull

git add .
git merge

set /P My_Tag="My_Tag: "
echo %My_Tag%
set /P Komment="Komment_for_tag: "
echo %Komment%
git tag -a -f %My_Tag% -m "%Komment%"

git commit
git push origin --tags
git push
pause