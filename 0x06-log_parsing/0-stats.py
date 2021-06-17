#!/usr/bin/python3
"""
scripy that reads stdin line by line
"""
if __name__ == "__main__":
    import sys
    import signal

    fs = fileSize = 0
    statCount = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
                 "404": 0, "405": 0, "500": 0}

    def handleTen(statCount, fileSize):
        print("File size: {}".format(fileSize))
        for key in sorted(statCount.keys()):
            if statCount[key] == 0:
                continue
            print("{}: {}".format(key, statCount[key]))

    try:
        for line in sys.stdin:
            fs += 1
            split = line.split(" ")
            try:
                status = split[-2]
                fileSize += int(split[-1])

                if status in statCount:
                    statCount[status] += 1
            except Exception:
                pass

            if fs % 10 == 0:
                handleTen(statCount, fileSize)

        else:
            handleTen(statCount, fileSize)

    except (KeyboardInterrupt, SystemExit):
        handleTen(statCount, fileSize)
        raise
