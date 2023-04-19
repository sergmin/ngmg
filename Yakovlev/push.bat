R:
cd \Yakovlev\ngmg\Yakovlev

git pull
git add .

set /p ID=<tagID.txt
set /a id=%ID%+1
echo %id% > tagID.txt

git commit -m "auto commit %id%"
git tag -a Yakovlev_tag_%id% -m "auto_created_tag_%id%"
git push origin Yakovlev_tag_%id%
git push origin main