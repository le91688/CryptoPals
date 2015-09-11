__author__ = 'larry'
plaintext = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal"

key = 'ICE'


def repeating_key_xor(plaintext, key):
    key.split()
    key = list(map(ord, key))
    # print key

    plaintext = map(ord, plaintext)
    # print plaintext



    encrypted = []
    i = 0

    for p in plaintext:
        encrypted.append(key[i] ^ p)
        i += 1
        if i == 3:
            i = 0

    # print encrypted


    hexed = map(hex, encrypted)
    # print hexed

    encrypted = [x.strip('0x') for x in hexed]

    final = ''.join(encrypted)

    string = '0x%s' % final

    return (string)


result = repeating_key_xor(plaintext, key)
print('for plaintext =%s' % plaintext)
print('and XOR key =%s' % key)
print('RESULT =')
print(result)

