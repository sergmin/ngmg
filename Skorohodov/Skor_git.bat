rem чтение, наращивание,запись id
set /p ID=<tag_id.txt
set /a id=%ID%+1
echo %id% > tag_id.txt

rem бат файл Скороходов
d:
cd D:\5)Development\8_git\ngmg\Skorohodov
git pull
git add --all
git commit -m "new_commit_Egor"
git push
git tag "tag%id%_Egor"
git push origin --tags
pause >nul