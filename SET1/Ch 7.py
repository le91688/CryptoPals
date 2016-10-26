# MATASANO CRYPTO CHALLENGE
# SET 1 CHALLENGE 7
# AES in ECB mode
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#
##########################
from Crypto.Cipher import AES
import base64
key = 'YELLOW SUBMARINE'



txt = open('7.txt')
stuff = txt.read()
bytes = str.encode(stuff)
#print stuff
bytes= base64.b64decode(bytes)
#print stuff


def decrypt_AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.decrypt(string)
    newStringThing = msg.decode(encoding='UTF-8')
    return newStringThing

print (decrypt_AES_ECB(key,bytes))


