from scipy.interpolate import interp1d
import matplotlib.pyplot as plt
import numpy as np
x = [0,1000,5000,10000,20000,50000,100000,200000,500000,1000000]


y1 = [0,1751,14545,31334,81466,188530,443870,790628,1734103,3897005]
y2 = [0,1030,5901,16084,28085,62311,143785,264726,644976,1315167]
y3 = [0,725,8859,11335,26230,70970,155444,504051,1181133,2683880]
y4 = [0,624,5373,6842,13046,30981,65176,125509,342013,659483]



f1 = interp1d(x,y1,kind ='cubic')
f2 = interp1d(x,y2,kind ='cubic')
f3 = interp1d(x,y3,kind ='cubic')
f4 = interp1d(x,y4,kind ='cubic')


xnew = np.linspace(0,10,num=1001,endpoint=True)

plt.plot(x,f1(x),x,f2(x),x,f3(x),x,f4(x))
plt.legend(['HeapSort','MergeSort','ShellSort','RadixSort'])
plt.show()
