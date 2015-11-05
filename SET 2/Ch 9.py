# MATASANO CRYPTO CHALLENGE
# SET 2 CHALLENGE 9
# Implement PKCS#7 padding
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#
##########################
from Crypto.Cipher import AES
import sys
plaintext = 'YELLOW SUBMARINE' #5
print (sys.getsizeof(plaintext))



key = 'YELLOW SUBMARINE' #16


def pad_plaintext(string, key):
	bytestring = str.encode(string)
	print (bytestring)
	print (len(bytestring))
	R = (len(bytestring) % len(key))
	print (('R= %d') % R)
	if len(bytestring) < len(key):
		padded = string.ljust( len(key), '0')
		padded = str.encode(padded)
	if len(bytestring) > len(key):
		padded = string.ljust(len(bytestring)+(len(key)-R), '0')
	print ('final length = %d' % len(padded))
	return (padded)
	
padded = (pad_plaintext(plaintext,key))
print (padded)
print (len(padded))
