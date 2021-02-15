import pandas as pd
from sklearn import preprocessing
import numpy as np
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('CustomerData.csv')
df = df.bfill()

#df.dropna(axis=0,inplace = True)

df.hist() 
plt.show()

df.plot.bar() 

plt.bar(df['age'], df['annual income (lakhs)']) 

plt.xlabel("Age") 
plt.ylabel("age group") 
plt.show() 
df.head()


sns.boxplot(df['age'])
sns.scatterplot(data = df, x='annual income (lakhs)',y='items purchased (monthly)', hue='gender')
#sns.scatterplot(data = df, x = df.age, y = df['annual income (lakhs)'])



