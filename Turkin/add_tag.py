import subprocess

# Обновляем информацию о тегах в локальном репозитории
subprocess.check_call(['git', 'fetch', '--tags'])

# Получаем список существующих тегов
tags = subprocess.check_output(['git', 'tag']).decode().split()

# Ищем последний тег вида "turkin_tag*"
# last_tag = max((t for t in tags if t.startswith('turkin_tag_')), default='turkin_tag_0')
turkin_tags = [t for t in tags if t.startswith('turkin_tag')]
last_tag = sorted(turkin_tags)[-1] if turkin_tags else 'turkin_tag_0'

# Получаем номер последнего тега
# last_number = int(last_tag.split('turkin_tag')[-1])
last_number = int(''.join(filter(str.isdigit, last_tag)))

# Проверяем есть ли изменения в удаленном репозитории и обновляем локальный репозиторий
subprocess.check_call(['git', 'pull'])

# Создаем новый тег с номером на 1 больше последнего
new_tag = f"turkin_tag_{last_number+1}"
subprocess.check_call(['git', 'tag', new_tag])

# Отправляем тег в удаленный репозиторий
subprocess.check_call(['git', 'push', '--tags'])