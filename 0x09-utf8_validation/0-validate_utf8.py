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
    ct = 0
    for i in data:
        bi = '{:08b}'.format(i)
        if ct == 0:
            if bi.startswith('0'): continue
            elif bi.startswith('110'): ct = 1
            elif bi.startswith('1110'): ct = 2
            elif bi.startswith('11110'): ct = 3
            else: return False
        else:
            if not bi.startswith('10'): return False
            ct -= 1
    return ct == 0
