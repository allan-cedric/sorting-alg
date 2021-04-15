#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.interpolate import make_interp_spline

CSV_FILENAME = "./data_evaluate_sorting.csv"
my_data = pd.read_csv(CSV_FILENAME)

labels = ["num_elements", "bubble_sort", "selection_sort", "insertion_sort",
          "merge_sort", "quick_sort", "heap_sort"]

x_data = my_data[labels[0]]
x_data = np.array(x_data)
x_data_smooth = np.linspace(x_data.min(), x_data.max(), x_data.max() - x_data.min() + 1)

y_data = [my_data[label] for label in labels[1:]]
y_data = np.array(y_data)

fig, ax = plt.subplots()
for i in range(1, len(labels)):
    spl = make_interp_spline(x_data, y_data[i - 1], k=3)
    y_data_smooth = spl(x_data_smooth)
    ax.scatter(x_data, y_data[i - 1])
    ax.plot(x_data_smooth, y_data_smooth, label=labels[i])
ax.set_xlabel("Array's size")
ax.set_ylabel("Time(ms)")
ax.set_title("Comparison of all 6 Sorting Algorithms")
ax.legend()

fig.savefig("./comparison_all_graphic.png", bbox_inches="tight")

fig_1, ax_1 = plt.subplots()
for i in range(1, len(labels) - 3):
    spl = make_interp_spline(x_data, y_data[i - 1], k=3)
    y_data_smooth = spl(x_data_smooth)
    ax_1.scatter(x_data, y_data[i - 1])
    ax_1.plot(x_data_smooth, y_data_smooth, label=labels[i])
ax_1.set_xlabel("Array's size")
ax_1.set_ylabel("Time(ms)")
ax_1.set_title("Comparison of Sorting Algorithms O(n^2)")
ax_1.legend()

fig_1.savefig("./comparison_n2_graphic.png", bbox_inches="tight")

fig_2, ax_2 = plt.subplots()
for i in range(4, len(labels)):
    spl = make_interp_spline(x_data, y_data[i - 1], k=3)
    y_data_smooth = spl(x_data_smooth)
    ax_2.scatter(x_data, y_data[i - 1])
    ax_2.plot(x_data_smooth, y_data_smooth, label=labels[i])
ax_2.set_xlabel("Array's size")
ax_2.set_ylabel("Time(ms)")
ax_2.set_title("Comparison of Sorting Algorithms O(n*log n)")
ax_2.legend()

fig_2.savefig("./comparison_nlogn_graphic.png", bbox_inches="tight")

plt.show()
