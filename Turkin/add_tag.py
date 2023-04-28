import subprocess

# Получаем список существующих тегов
tags = subprocess.check_output(['git', 'tag']).decode().split()

# Ищем последний тег вида "turkin_tag*"
last_tag = max((t for t in tags if t.startswith('turkin_tag')), default='turkin_tag0')

# Получаем номер последнего тега
last_number = int(last_tag.split('turkin_tag')[-1])

# Создаем новый тег с номером на 1 больше последнего, если его еще нет в удаленном репозитории
new_tag = f"turkin_tag{last_number+1}"
if new_tag not in subprocess.check_output(['git', 'ls-remote', '--tags', 'origin']).decode():
    subprocess.check_call(['git', 'tag', new_tag])
