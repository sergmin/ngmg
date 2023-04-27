R:
cd R:\Акулина\Git\ngmg\Akulina
git add .
git commit -m "Commit with bat"
git pull

set /p tagId=<A_tag_id.txt
set /a id=%tagId%+1
echo %id% > A_tag_id.txt
echo %id% 
set name=Akulina_tag_v%id%
echo %name%
git tag -a %name% -m "Akulina tag"

git push origin %name%
git push origin %main%
pause