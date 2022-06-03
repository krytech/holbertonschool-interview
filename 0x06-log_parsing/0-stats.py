#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys


def print_it(size, status_code):
    """print it"""
    print("File size: {}".format(size))
    for key, value in sorted(status_code.items()):
        if (value != 0):
            print("{}: {}".format(key, value))


if __name__ == '__main__':
    """init code to print the parsed data"""
    size = 0
    i = 0
    status_code = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    try:
        for line in sys.stdin:
            i += 1
            if (len(line.split()) < 2):
                continue
            code = line.split()[-2]
            size += int(line.split()[-1])
            if code in status_code:
                status_code[code] += 1
            if (i % 10 == 0):
                print_it(size, status_code)
        print_it(size, status_code)
    except KeyboardInterrupt:
        print_it(size, status_code)
        raise
