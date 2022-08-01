import time


class AngeryException(Exception):
    __module__ = Exception.__module__

    def __str__(self):
        return "宝宝森气气了😡"


print()
print("{\_/}")
print("( •.•)")
print("/ >💖 你要我的“做slides.py”?")
print("\n-----------------------\n")

response = input("要！(Enter 'y'): ")
print()

if response.strip() != "y":
    print(" {\_/}")
    print("(>ᴖ< )")
    print(" 💖< \  不要就不要 哼")
    print("\n---------- 完 ----------\n")
    raise AngeryException()
else:
    print("{\_/}")
    print("( •-•)")
    print("💖< \  先给我一个亲亲")
    print("\n-----------------------\n")

    time.sleep(11.13)

    print("{\_/}")
    print("( •ᴗ•)")
    print("/ >💖 好啦 给你给你♥️")
    print("\n---------- 完 ----------\n")
