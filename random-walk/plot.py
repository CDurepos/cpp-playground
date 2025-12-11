import pandas as pd
import plotly.express as px
import matplotlib.pyplot as plt

df = pd.read_csv("./walk.csv")
dim = len( df.columns )

if dim == 3:
    fig = px.line_3d(df, x="x", y="y", z="z")
    fig.show()

else:
    if dim == 2:
        plt.plot(df["x"], df["y"])

    elif dim == 1:
        plt.plot(df["x"], range( len( df["x"] ) ) )

    plt.show()