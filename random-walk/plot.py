import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("./walk.csv")
plt.plot(df["time"], df["pos"])
plt.show()