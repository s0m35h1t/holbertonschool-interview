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
    def length(n):
        return len('{:08b}'.format(n).split('0', 1)[0])

    i = 0
    while i < len(data):
        le = length(data[i])
        i += 1
        if le == 1 or le > 4:
            return False
        if le > 1:
            for _ in range(le-1):
                if i == len(data) or length(data[i]) != 1:
                    return False
                i += 1
    return True
