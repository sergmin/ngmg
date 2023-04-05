R:
cd \Kniga\ngmg\Kniga

git pull
git add .

set /p ID=<tagID.txt
set /a id=%ID%+1
echo id > tagID.txt

git commit -m "auto commit %id%"
git tag -a Kniga_tag_%id% -m "auto_created_tag_%id%"
git push
git push Kniga_tag_%id%