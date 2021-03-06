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
    n_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        mask = 1 << 7
        if n_bytes == 0:
            while(mask & num):
                n_bytes += 1
                mask = mask >> 1
            if(n_bytes == 0):
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False
        n_bytes -= 1
    return (n_bytes == 0)
