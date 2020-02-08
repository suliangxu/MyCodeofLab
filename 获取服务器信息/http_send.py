import requests
import json
import time
import os

r = requests.post('http://yapi.demo.qunar.com/mock/79868/api/post')
print(r.content)

a = json.loads(r.content.decode('utf-8'))

interval = a['interval']
file_content = a['file_content']
err_info = a['err_info']
file_name = a['file_name']

with open(file_name, 'w') as f:
    f.write(file_content)

print("Error occur: " + err_info)
cmd = 'python {}'.format(file_name)
while True:
    back = os.popen(cmd).readlines()
    if 'Error' in back:
        print("Error occur: " + err_info)
    else:
        print(back)
    time.sleep(interval)