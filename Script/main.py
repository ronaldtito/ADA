from base64 import encode
import ctypes


cfilelib = ctypes.CDLL('C:\Users\rarno\Documents\GitHub\Script\cfilelib.so',encoding = 'UTF-8')

a = cfilelib.boom()