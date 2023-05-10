import subprocess
import re


subprocess.check_call(['git', 'fetch', '--tags'])
tags = subprocess.check_output(['git', 'tag']).decode().split()
last_tag = max((t for t in tags if t.startswith('tur_tag')), default='tur_tag_0')
last_number = int(re.findall(r'\d+', last_tag)[-1])
subprocess.check_call(['git', 'pull'])
new_tag = f"tur_tag_{last_number+1}"
subprocess.check_call(['git', 'tag', new_tag])
subprocess.check_call(['git', 'push', '--tags'])