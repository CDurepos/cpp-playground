import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("monte-carlo.csv")
df.hist(bins=20)

plt.text(
    0.95, 0.95,
    f"Mean: {np.mean(df["final_pos"]):.4f}\n" \
    f"Variance: {np.var(df["final_pos"]):4f}\n" \
    f"Std Dev: {np.var(df["final_pos"])**(1/2):4f}",
    transform=plt.gca().transAxes,
    fontsize=12,
    verticalalignment='top',
    horizontalalignment='right',
    bbox=dict(facecolor='white', alpha=0.8)
)

plt.show()