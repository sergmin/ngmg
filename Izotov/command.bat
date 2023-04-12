R:
cd \Izotov\github\ngmg1\ngmg1\Izotov
git add .
git commit -m "Commit with bat"
git pull

set /p tagId=<tag_Izotov.txt
set /a id=%tagId%+1
echo %id% > tag_Izotov.txt
echo %id% 
set name=tag_Izotov_v%id%
echo %name%
git tag -a %name% -m "Izotov tag"

git push origin %name%
git push origin %main%
pause