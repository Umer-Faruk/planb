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

from sklearn.preprocessing import LabelEncoder
data[['gender','purchase type ','category','country']] = data[['gender','purchase type ','category','country']].apply(LabelEncoder().fit_transform)
data.head()

data['age'] = pd.cut(x = data['age'],labels=('child','adult','sc'), bins=(0,18,65,100), include_lowest=True)





 
