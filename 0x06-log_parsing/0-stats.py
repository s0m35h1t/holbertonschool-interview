#!/usr/bin/python3
'''line by line and computes metrics'''
import sys


f_size = 0
status_codes = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}

try:
    for i, line in enumerate(sys.stdin, 1):
        infos_list = line.split()
        if len(infos_list) > 2:
            try:
                f_size += int(infos_list[-1])
            except Exception as e:
                raise e
            try:
                if infos_list[-2] in status_codes:
                    if isinstance(int(infos_list[-2]), int):
                        status_codes[infos_list[-2]] += 1
            except Exception as e:
                raise e
        if i % 10 == 0:
            print('File size: {}'.format(f_size))
            for k in sorted(status_codes):
                if status_codes[k] != 0:
                    print('{}: {}'.format(k, status_codes[k]))
except KeyboardInterrupt:
    pass
print('File size: {}'.format(f_size))
for k in sorted(status_codes):
    if status_codes[k] != 0:
        print('{}: {}'.format(k, status_codes[k]))
