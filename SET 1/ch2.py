# MATASANO CRYPTO CHALLENGE
# SET 1 CHALLENGE 2
# Fixed XOR
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#
##########################
some_string = '1c0111001f010100061a024b53535009181c'
xor_string = '686974207468652062756c6c277320657965'

def eqlength_xor(x,y):

   hex_decoded = int(x,16)
   print("hex_decoded %d" % (hex_decoded))

   xor_decoded =int(xor_string,16)
   print ("xor_decoded %d"%(xor_decoded))

   xor_product = hex_decoded ^ xor_decoded

   answer = hex(xor_product)[2::]
   return answer

print (eqlength_xor(some_string,xor_string))