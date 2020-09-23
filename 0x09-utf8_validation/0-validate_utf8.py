#!/usr/bin/python3
"""UTF-8 Validation """


def validUTF8(data):
    """determines if a given data set
    represents a valid UTF-8 encoding
    Args:
        data:set can contain multiple characters
    Return:
        True if data is a valid UTF-8 encoding,
        else return False
    """
    # b = 0
    # for x in data:
    #     x = bin(x)[2:].zfill(8)
    #     if b:
    #         if x.startswith("10"):
    #             b -= 1
    #         else:
    #             return False
    #     else:
    #         b = x.find("0")
    #         if b == -1 or b == 1 or b > 4:
    #             return False
    #         if b:
    #             b -= 1
    # return b == 0
    utf = ''.join([bin(byte)[2:].zfill(8) for byte in data])
    return bool(re.search(
        r'^((0[01]{7})|(110[01]{5}10[01]{6})|(1110[01]{4}(10[01]{6}){2})|(11110[01]{3}(10[01]{6}){3}))+$', utf))
