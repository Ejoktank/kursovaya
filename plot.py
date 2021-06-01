import matplotlib
import matplotlib.pyplot as plt

ax = plt.axes()
# ax.grid()
ax.xaxis.set_major_locator(matplotlib.ticker.MaxNLocator(20))
ax.yaxis.set_major_locator(matplotlib.ticker.MaxNLocator(30))

x = []
with open('outt.txt', 'r') as xFile:
    for line in xFile:
            x.append(line.split('\n')[0])

files = ['outy0.txt', 'outy1.txt', 'outy2.txt', 'outy3.txt']
colors = ['b', 'g', 'r', 'k']
ziped = zip(files, colors)

for file, color in ziped:
    y = []
    inner_list = []

    with open(file, 'r') as f:
        for line in f:
            inner_list.append(line.split('\n')[0])


    y.append(inner_list)

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
