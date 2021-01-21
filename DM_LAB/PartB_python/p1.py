import pandas as pd
import numpy as np
import seaborn as sns
import sklearn
import matplotlib.pyplot as plt

data = pd.read_csv('CustomerData.csv')
data.info()
data.head()
data.tail()
data.describe()
data.isna().sum()

data['gender'].fillna(data.gender.mode()[0],inplace=True)
data['category'].fillna(data.category.mode()[0],inplace=True)

data.fillna(data.mean(),inplace=True)
data.isna().sum()

data.dropna(axis=0,inplace=True)
data.drop(columns=('customer_id'),axis=1,inplace=True)
data.head()




sns.histplot(data=data, x='spending score')
sns.boxplot(data=data, x='items purchased (monthly)')
sns.scatterplot(data=data, x='annual income (lakhs)',y='items purchased (monthly)', hue='gender')
sns.barplot(data=data, x='age', y='items purchased (monthly)')