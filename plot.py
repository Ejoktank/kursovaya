import matplotlib
import matplotlib.pyplot as plt
import os

ax = plt.axes()
# ax.grid()
ax.xaxis.set_major_locator(matplotlib.ticker.MaxNLocator(20))
ax.yaxis.set_major_locator(matplotlib.ticker.MaxNLocator(30))

x = []

for root, dirs, files in os.walk('build'):
    for file in files:
        if file == 'outt.txt':
            with open(os.path.join(root, file), "r") as xFile:
                for line in xFile:
                    x.append(line.split('\n')[0])


my_files = ['outy0.txt', 'outy1.txt', 'outy2.txt', 'outy3.txt']
colors = ['b', 'g', 'r', 'k']
ziped = zip(my_files, colors)


for root, dirs, files in os.walk('build'):
    for my_file, color in ziped:
        for file in files:
            print(my_file, file)
            if file == my_file:
                y = []
                inner_list = []
                with open(os.path.join(root, file), "r") as auto:
                    for line in auto:
                        inner_list.append(line.split('\n')[0])
                
                y.append(inner_list)
                print(x)
                print(y[0])
                plt.plot(x, y[0], color, linewidth=1)


# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')
# # giving a title to my graph
plt.title('0 0 0 3 без (1 - y[0])')

# show a legend on the plot
plt.legend()

# function to show the plot
plt.show()
